/* 
 * CS:APP Data Lab 
 * 
 * <Owen Kutzscher github: owenkutzscher>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically and a negative shift value results in zero.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES, FOLLOW THE DIRECTIONS in README.md
 */


#endif
/* Copyright (C) 1991-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
/* 




 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 *
 *   can not use if or for loop
 */
int bitAnd(int x, int y) {
  return ~(~x | ~y);
  
  /* 1 DONE */
}




/* 
 * evenBits - return word with all even-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int evenBits(void) {
    int x=0x55;      /* 0101 0101 */
    x=x|x<<8;
    x=x|x<<16;
    return x;        /* 0x5555 5555 */
    
    /* 2 DONE */
}





/*
 * isTmin - returns 1 if x is the minimum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmin(int x) {
    int allZeros = x+x;     // twos comp number added to its self gives 0
    return !allZeros & !!x;     // !!x checks for if x = 0
    
    /* 3 DONE */
}




/* 
 * allEvenBits - return 1 if all even-numbered bits in word set to 1
 *   Examples allEvenBits(0xFFFFFFFE) = 0, allEvenBits(0x55555555) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allEvenBits(int x) {
    int allEven=0x55;      /* 0101 0101 */
    int allEvenDetector=0;
    
    allEven=allEven|allEven<<8;
    allEven=allEven|allEven<<16;        /* 0x5555 5555 */    
    allEvenDetector=x&allEven;     /* isolates the even 0s and 1s from x */
    
    return !(allEvenDetector^allEven);
    /* another way:
    add the number 0xAA (1010 1010...) to x = allOnes
    then return !(~allOnes)
    */
    
    /* 4 DONE */
}




/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
    int shiftVal = n<<3;     /* shiftVal = n*8 */
    int byteOnRight = x>>shiftVal;     // push the byte we want to the right
    int isolatedByte = byteOnRight&0xff; // isolate rightmost byte
    return isolatedByte;
    
    /* 5 DONE */
}




/* 
 * isNegative - return 1 if x < 0, return 0 otherwise 
 *   Example: isNegative(-1) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNegative(int x) {
    return !!(x>>31);
    
    /* 6 DONE */
}




/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
    /* <condition> ? <do if condtion is true> : <do if condition is false> */
    int condition = !!x;   /* condition is now 0x0 or 0x1 */
    condition = condition << 31;
    condition = condition >> 31; /* if x was reduced to 1, make it all 1s*/
    return (y&condition)|(z&(~condition)); // condition masks the incorrect output
    
    /* 7 DONE */
}







/*
 * ezThreeFourths - multiplies by 3/4 rounding toward 0,
 *   Should exactly duplicate effect of C expression (x*3/4),
 *   including overflow behavior.
 *   Examples: ezThreeFourths(11) = 8
 *             ezThreeFourths(-9) = -6
 *             ezThreeFourths(1073741824) = -268435456 (overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 3
*/ 

int ezThreeFourths(int x) {
    int x3 = x+(x<<1);
    int pushTwordsZero = (0x3&(x3>>31)); // if x negative, correct for rounding the wrong direction
    return (x3+pushTwordsZero)>>2;
    
    /* 8 DONE */
}




/* 
 * isNonNegative - return 1 if x >= 0, return 0 otherwise 
 *   Example: isNonNegative(-1) = 0.  isNonNegative(0) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 3
 */
int isNonNegative(int x) {
    x = x >> 31; /* if x is negative, it will now be all 1s */
    return !x;
    
    /* 9 DONE */
}







/* 
 * isNonZero - Check whether x is nonzero using
 *              the legal operators except !
 *   Examples: isNonZero(3) = 1, isNonZero(0) = 0
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4 
 */
int isNonZero(int x) {
    int y = (~x)+1; // twos comp of x is y
    int xSignBit = (x>>31)&0x1;
    int ySignBit = (y>>31)&0x1;
    return xSignBit|ySignBit; // zero will not have a signed bit
    
    /* 10 DONE */
}







/*
 * leftBitCount - returns count of number of consective 1's in
 *     left-hand (most significant) end of word.
 *   Examples: leftBitCount(-1) = 32, leftBitCount(0xFFF0F0F0) = 12
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 50
 *   Rating: 4
 */
int leftBitCount(int x) {

    int full = 0;
    int l16 = 0;
    int l8 = 0;
    int l4 = 0;
    int l2 = 0;
    int l1 = 0; 
    
    int total = 0;    
    
    
    
    full = !(~x);
    total += full; // add 1 to total for least sig 1
    
    l16 = (!(~(x>>16)))<< 4; // l16 = 16 if left 16 bits of x all 1s. l16 = 0 otherwise.
    total = total + l16;
    x <<= l16; // isolate first or second half of x
    l8 = x>>24; // isolate a 8 bits in x
    
    l8 = (!(~l8))<<3;
    total = total + l8;
    x <<= l8;
    l4 = x>>28;
    
    l4 = (!(~l4))<<2;
    total = total + l4;
    x <<= l4;
    l2 = x>>30;
    
    l2 = (!(~l2))<<1;
    total = total + l2;
    x <<= l2;
    l1 = x>>31;
    
    l1 = (!(~l1));
    total = total + l1;
    x <<= l1;
           

    return total; 
    
    /* 11 DONE */
}




/*
 * trueThreeFourths - multiplies by 3/4 rounding toward 0,
 *   avoiding errors due to overflow
 *   Examples: trueThreeFourths(11) = 8
 *             trueThreeFourths(-9) = -6
 *             trueThreeFourths(1073741824) = 805306368 (no overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int trueThreeFourths(int x)
{   
    int twoLeastSig = x&0x3; // dividing first, we loose 2 lease sig bits. Save them here.
    int pushTwordsZero = (x>>31)&0x3; // correct for rounding issue if negative
    
    twoLeastSig = ((twoLeastSig<<1) + twoLeastSig) + pushTwordsZero;
    twoLeastSig = twoLeastSig>>2;
    
    x = x>>2;
    x = (x<<1)+x;
    
    return x+twoLeastSig;
    
    /* 12 DONE */
}







/*
 * Extra credit
 */
/* 
 * float_abs - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_abs(unsigned uf) {
  return 2;
}






/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
  return 2;
}
