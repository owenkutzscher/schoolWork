#include <stdio.h>
#include <stdint.h>

extern int mm_init (void);   // done from book (all these are 9.9 memory allocation)
extern void *mm_malloc (uint32_t size); // done from book 
extern void mm_free (void *ptr); // done from book
extern void *mm_realloc(void *ptr, uint32_t size); // DONE

/* 
 * Students work in teams of one or two.  Teams enter their team name, 
 * personal names and login IDs in a struct of this
 * type in their bits.c file.
 */
typedef struct {
    const char *teamname; /* ID1+ID2 or ID1 */
    const char *name1;    /* full name of first member */
    const char *id1;      /* login ID of first member */
    const char *name2;    /* full name of second member (if any) */
    const char *id2;      /* login ID of second member */
} team_t;

extern team_t team;

