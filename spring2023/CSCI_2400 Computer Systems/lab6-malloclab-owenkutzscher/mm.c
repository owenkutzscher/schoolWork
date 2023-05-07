/* 
 * mm-implicit.c -  Simple allocator based on implicit free lists, 
 *                  first fit placement, and boundary tag coalescing. 
 *
 * Each block has header and footer of the form:
 * 
 *      31                     3  2  1  0 
 *      -----------------------------------
 *     | s  s  s  s  ... s  s  s  0  0  a/f
 *      ----------------------------------- 
 * 
 * where s are the meaningful size bits and a/f is set 
 * iff the block is allocated. The list has the following form:
 *
 * begin                                                          end
 * heap                                                           heap  
 *  -----------------------------------------------------------------   
 * |  pad   | hdr(8:a) | ftr(8:a) | zero or more usr blks | hdr(8:a) |
 *  -----------------------------------------------------------------
 *          |       prologue      |                       | epilogue |
 *          |         block       |                       | block    |
 *
 * The allocated prologue and epilogue blocks are overhead that
 * eliminate edge conditions during coalescing.
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <memory.h>
#include "mm.h"
#include "memlib.h"
#include "math.h"

/*********************************************************
 * NOTE TO STUDENTS: Before you do anything else, please
 * provide your team information in the following struct.
 ********************************************************/
team_t team = {
    /* Team Name:  */
    "Bob Marley",
    /* Full name 1 */
    "Owen Kutzscher",
    /* email 1 */
    "owku9329@colorado.edu",
    /* full name 2 */
    "Leo Su",
    /* email 2 */
    "iksu4562@colorado.edu"};

/////////////////////////////////////////////////////////////////////////////
// Constants and macros
//
// These correspond to the material in Figure 9.43 of the text
// The macros have been turned into C++ inline functions to
// make debugging code easier.
//
/////////////////////////////////////////////////////////////////////////////
#define WSIZE 4             /* word size (bytes) */
#define DSIZE 8             /* doubleword size (bytes) */
#define CHUNKSIZE (1 << 12) /* initial heap size (bytes) */
#define OVERHEAD 8          /* overhead of header and footer (bytes) */

static inline int getHeadIndex(int);
static inline int getHeadIndex(int size)
{
  return ceil(log2(size));
}

// indicated what memory is free, free list
typedef struct freeNode
{
  struct freeNode *next;
  struct freeNode *prev;
} freeN;

freeN freeListArr[31];

// fucntions for this list guy

void attach(freeN *newNode, int size)
{
  // int headIndex = getHeadIndex(size);

  freeN *head = &freeListArr[getHeadIndex(size)];

  newNode->next = head->next;
  newNode->prev = head;
  head->next->prev = newNode;
  head->next = newNode;
}

void detach(freeN *deleteNode)
{
  freeN *prevNode = deleteNode->prev;
  freeN *nextNode = deleteNode->next;

  prevNode->next = nextNode;
  nextNode->prev = prevNode;

  deleteNode->next = NULL;
  deleteNode->prev = NULL;
}

// segregated list approach
// linked list structrue
// yep
// find Ishawn

static inline int MAX(int x, int y)
{
  return x > y ? x : y;
}

//
// Pack a size and allocated bit into a word
// We mask of the "alloc" field to insure only
// the lower bit is used
//
static inline uint32_t PACK(uint32_t size, int alloc)
{
  return ((size) | (alloc & 0x1));
}

//
// Read and write a word at address p
//
static inline uint32_t GET(void *p) { return *(uint32_t *)p; }
static inline void PUT(void *p, uint32_t val)
{
  *((uint32_t *)p) = val;
}

//
// Read the size and allocated fields from address p
//
static inline uint32_t GET_SIZE(void *p)
{
  return GET(p) & ~0x7;
}

static inline int GET_ALLOC(void *p)
{
  return GET(p) & 0x1;
}

//
// Given block ptr bp, compute address of its header and footer
//
static inline void *HDRP(void *bp)
{

  return ((char *)bp) - WSIZE;
}
static inline void *FTRP(void *bp)
{
  return ((char *)(bp) + GET_SIZE(HDRP(bp)) - DSIZE);
}

//
// Given block ptr bp, compute address of next and previous blocks
//
static inline void *NEXT_BLKP(void *bp)
{
  return ((char *)(bp) + GET_SIZE(((char *)(bp)-WSIZE)));
}

static inline void *PREV_BLKP(void *bp)
{
  return ((char *)(bp)-GET_SIZE(((char *)(bp)-DSIZE)));
}

/////////////////////////////////////////////////////////////////////////////
//
// Global Variables
//

static char *heap_listp; /* pointer to first block */

//
// function prototypes for internal helper routines
//
static void *extend_heap(uint32_t words);
static void place(void *bp, uint32_t asize);
static void *find_fit(uint32_t asize);
static void *coalesce(void *bp);
static void printblock(void *bp);
static void checkblock(void *bp);

//
// mm_init - Initialize the memory manager
//
int mm_init(void)
{
  //
  // You need to provide this
  //

  /* Create the initial empty heap */
  if ((heap_listp = mem_sbrk(4 * WSIZE)) == (void *)-1)
    return -1;

  PUT(heap_listp, 0);                            /* Alignment padding */
  PUT(heap_listp + (1 * WSIZE), PACK(DSIZE, 1)); /* Prologue header */
  PUT(heap_listp + (2 * WSIZE), PACK(DSIZE, 1)); /* Prologue footer */
  PUT(heap_listp + (3 * WSIZE), PACK(0, 1));     /* Epilogue header */
  heap_listp += (2 * WSIZE);

  for (int i = 0; i < 31; i++)
  {
    freeListArr[i].prev = &freeListArr[i];
    freeListArr[i].next = &freeListArr[i];
  }

  /* Extend the empty heap with a free block of CHUMSIZE bytes */
  if (extend_heap(CHUNKSIZE / WSIZE) == NULL)
    return -1;
  return 0;
}

//
// extend_heap - Extend heap with free block and return its block pointer
//
static void *extend_heap(uint32_t words)
{
  //
  // You need to provide this
  //

  char *bp;
  size_t size;

  /* Allocate an even number of words to maintain alignment */
  size = (words % 2) ? (words + 1) * WSIZE : words * WSIZE;
  if ((long)(bp = mem_sbrk(size)) == -1)
    return NULL;

  /* Initialize free block header/footer and the epilogue header */
  PUT(HDRP(bp), PACK(size, 0));         /* Free block header */
  PUT(FTRP(bp), PACK(size, 0));         /* Free block footer */
  PUT(HDRP(NEXT_BLKP(bp)), PACK(0, 1)); /* New epilogue header */
  freeN *newPtr = (freeN *)coalesce(bp);

  attach(newPtr, size);

  /* Coalesce if the previous block was free */
  return (void *)newPtr;
}

//
// Practice problem 9.8
//
// find_fit - Find a fit for a block with asize bytes
//
static void *find_fit(uint32_t asize)
{
  freeN *bp;
  for (int i = getHeadIndex(asize); i < 31; i++)
  {
    for (bp = freeListArr[i].next; bp != &freeListArr[i]; bp = bp->next)
    {
      if (asize <= GET_SIZE(HDRP(bp)))
      {
        return bp;
      }
    }
  }

  return NULL; /* no fit */
}

//
// mm_free - Free a block
//
void mm_free(void *bp)
{
  //
  // You need to provide this
  //

  size_t size = GET_SIZE(HDRP(bp));

  PUT(HDRP(bp), PACK(size, 0));
  PUT(FTRP(bp), PACK(size, 0));
  //the purpose of this is to find remaining free blocks and add to the list
  freeN *newFree = (freeN *)coalesce(bp);

  //append freeList
  attach(newFree, size);
}

//
// coalesce - boundary tag coalescing. Return ptr to coalesced block
//
static void *coalesce(void *bp)
{
  size_t prev = GET_ALLOC(FTRP(PREV_BLKP(bp)));
  size_t next = GET_ALLOC(HDRP(NEXT_BLKP(bp)));
  size_t size = GET_SIZE(HDRP(bp));
  if (prev && next)
  {
    return bp;
  }
  else if (prev && !next)
  {
    detach((freeN *)NEXT_BLKP(bp));
    size += GET_SIZE(HDRP(NEXT_BLKP(bp)));
    PUT(HDRP(bp), PACK(size, 0));
    PUT(FTRP(bp), PACK(size, 0));
  }
  else if (!prev && next)
  {
    detach((freeN *)(PREV_BLKP(bp)));
    size += GET_SIZE(HDRP(PREV_BLKP(bp)));
    PUT(FTRP(bp), PACK(size, 0));
    PUT(HDRP(PREV_BLKP(bp)), PACK(size, 0));
    bp = PREV_BLKP(bp);
  }
  else
  {
    detach((freeN *)NEXT_BLKP(bp));
    detach((freeN *)(PREV_BLKP(bp)));
    size += GET_SIZE(HDRP(NEXT_BLKP(bp))) + GET_SIZE(HDRP(PREV_BLKP(bp)));
    PUT(HDRP(PREV_BLKP(bp)), PACK(size, 0));
    PUT(FTRP(NEXT_BLKP(bp)), PACK(size, 0));
    bp = PREV_BLKP(bp);
  }

  return bp;
}

//
// mm_malloc - Allocate a block with at least size bytes of payload
//
void *mm_malloc(uint32_t size)
{
  //
  // You need to provide this
  //

  size_t asize;      /* Adjusted block size */
  size_t extendsize; /* Amount to extend heap if no fit */
  char *bp;

  /* Ignore spurious requests */
  if (size == 0)
    return NULL;

  /* Adjust block size to include overhead and alignment reqs. */
  if (size <= DSIZE)
    asize = 2 * DSIZE;
  else
    asize = DSIZE * ((size + (DSIZE) + (DSIZE - 1)) / DSIZE);

  /* Search the free list for a fit */
  if ((bp = find_fit(asize)) != NULL)
  {
    detach((freeN *)bp);
    place(bp, asize);
    return bp;
  }

  /* No fit found. Get more memory and place the block */
  extendsize = MAX(asize, CHUNKSIZE);
  if ((bp = extend_heap(extendsize / WSIZE)) == NULL)
    return NULL;
  detach((freeN *)bp);
  place(bp, asize);
  return bp;

  return NULL;
}

//
//
// Practice problem 9.9
//
// place - Place block of asize bytes at start of free block bp
//         and split if remainder would be at least minimum block size
//
static void place(void *bp, uint32_t asize)
{
  size_t current_size = GET_SIZE(HDRP(bp));
  size_t min_size = sizeof(freeN) + OVERHEAD;
  if ((current_size - asize) >= min_size)
  {
    PUT(HDRP(bp), PACK(asize, 1));
    PUT(FTRP(bp), PACK(asize, 1));
    bp = NEXT_BLKP(bp);
    PUT(HDRP(bp), PACK((current_size-asize), 0));
    PUT(FTRP(bp), PACK((current_size-asize), 0));
    attach((freeN*)bp, (current_size-asize));
  }
  else
  {
    PUT(HDRP(bp), PACK(current_size, 1));
    PUT(FTRP(bp), PACK(current_size, 1));
  }
}

//
// mm_realloc -- implemented for you
//
void *mm_realloc(void *ptr, uint32_t size)
{
  void *newp;
  uint32_t copySize;

  newp = mm_malloc(size);
  if (newp == NULL)
  {
    printf("ERROR: mm_malloc failed in mm_realloc\n");
    exit(1);
  }
  copySize = GET_SIZE(HDRP(ptr));
  if (size < copySize)
  {
    copySize = size;
  }
  memcpy(newp, ptr, copySize);
  mm_free(ptr);
  return newp;

  //     void *newp;
  //     uint32_t copySize;

  //     size_t min_size = MAX(size, sizeof(Node)) + OVERHEAD;
  //     copySize = GET_SIZE(HDRP(ptr));

  //     if(min_size == copySize){
  //         return ptr;
  //     }else if(min_size < copySize){
  //         place(ptr, min_size);
  //         return ptr;
  //     }else{
  //         newp = mm_malloc(size);
  //         if(newp == NULL){
  //             printf("error: mm_malloc failed in mm_realloc\n");
  //             exit(1);
  //         }
  //         copySize = GET_SIZE(HDRP(ptr));
  //         if(size < copySize){
  //             copySize = size;
  //         }
  //         memcpy(newp, ptr, copySize);
  //         mm_free(ptr);
  //         return newp;
  //     }
}

//
// mm_checkheap - Check the heap for consistency
//
void mm_checkheap(int verbose)
{
  //
  // This provided implementation assumes you're using the structure
  // of the sample solution in the text. If not, omit this code
  // and provide your own mm_checkheap
  //
  void *bp = heap_listp;

  if (verbose)
  {
    printf("Heap (%p):\n", heap_listp);
  }

  if ((GET_SIZE(HDRP(heap_listp)) != DSIZE) || !GET_ALLOC(HDRP(heap_listp)))
  {*
    printf("Bad prologue header\n");
  }
  checkblock(heap_listp);

  for (bp = heap_listp; GET_SIZE(HDRP(bp)) > 0; bp = NEXT_BLKP(bp))
  {
    if (verbose)
    {
      printblock(bp);
    }
    checkblock(bp);
  }

  if (verbose)
  {
    printblock(bp);
  }

  if ((GET_SIZE(HDRP(bp)) != 0) || !(GET_ALLOC(HDRP(bp))))
  {
    printf("Bad epilogue header\n");
  }
}

static void printblock(void *bp)
{
  uint32_t hsize, halloc, fsize, falloc;

  hsize = GET_SIZE(HDRP(bp));
  halloc = GET_ALLOC(HDRP(bp));
  fsize = GET_SIZE(FTRP(bp));
  falloc = GET_ALLOC(FTRP(bp));

  if (hsize == 0)
  {
    printf("%p: EOL\n", bp);
    return;
  }

  printf("%p: header: [%d:%c] footer: [%d:%c]\n",
         bp,
         (int)hsize, (halloc ? 'a' : 'f'),
         (int)fsize, (falloc ? 'a' : 'f'));
}

static void checkblock(void *bp)
{
  if ((uintptr_t)bp % 8)
  {
    printf("Error: %p is not doubleword aligned\n", bp);
  }
  if (GET(HDRP(bp)) != GET(FTRP(bp)))
  {
    printf("Error: header does not match footer\n");
  }
}
