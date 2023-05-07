#include <stdio.h>
#include "cs1300bmp.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "Filter.h"

using namespace std;

#include "rdtsc.h"


//
// Forward declare the functions
//
Filter * readFilter(string filename);
double applyFilter(Filter *filter, cs1300bmp *input, cs1300bmp *output);

int
main(int argc, char **argv)
{

  if ( argc < 2) {
    fprintf(stderr,"Usage: %s filter inputfile1 inputfile2 .... \n", argv[0]);
  }

  //
  // Convert to C++ strings to simplify manipulation
  //
  string filtername = argv[1];

  //
  // remove any ".filter" in the filtername
  //
  string filterOutputName = filtername;
  string::size_type loc = filterOutputName.find(".filter");
  if (loc != string::npos) {
    //
    // Remove the ".filter" name, which should occur on all the provided filters
    //
    filterOutputName = filtername.substr(0, loc);
  }

  Filter *filter = readFilter(filtername);

  double sum = 0.0;
  int samples = 0;

  for (int inNum = 2; inNum < argc; inNum++) {
    string inputFilename = argv[inNum];
    string outputFilename = "filtered-" + filterOutputName + "-" + inputFilename;
    struct cs1300bmp *input = new struct cs1300bmp;
    struct cs1300bmp *output = new struct cs1300bmp;
    int ok = cs1300bmp_readfile( (char *) inputFilename.c_str(), input);

    if ( ok ) {
      double sample = applyFilter(filter, input, output);
      sum += sample;
      samples++;
      cs1300bmp_writefile((char *) outputFilename.c_str(), output);
    }
    delete input;
    delete output;
  }
  fprintf(stdout, "Average cycles per sample is %f\n", sum / samples);

}

class Filter *
readFilter(string filename)
{
  ifstream input(filename.c_str());

  if ( ! input.bad() ) {
    int size = 0;
    input >> size;
    Filter *filter = new Filter(size);
    int div;
    input >> div;
    filter -> setDivisor(div);
    for (int i=0; i < size; i++) {
      for (int j=0; j < size; j++) {
	int value;
	input >> value;
	filter -> set(i,j,value);
      }
    }
    return filter;
  } else {
    cerr << "Bad input in readFilter:" << filename << endl;
    exit(-1);
  }
}


double
applyFilter(class Filter *filter, cs1300bmp *input, cs1300bmp *output)
{
    // ***THINGS WE COULD DO***
        // NO, reduction in strength: SHIFT instead of multiplicaiton and division
        // NO, unroll a layer of the plane row col for loop!!!
        // NO, order the fields in order so the are stored in mem most efficiently

    // ***THINGS WE NEED TO DO***
        // label all the things we did with the correct optimization terms and why they speed up code

    long long cycStart, cycStop;

    
    cycStart = rdtscll();
    
    
    
    // *** No longer needs to execute functions each time in loop, code movement/motion?
        // makes faster becuase each function call wastes memroy and time, call to a set variable is much quicker
    // *** All "int" replaced with "short"
        // Short takes up less space than int, faster to transfer it around
        // cache takes multiple calls to get the say long vs a short is quicker / less transfers of data to the cache
    short iHeight = input -> height;
    short iWidth = input -> width;
    //short sizeee = filter -> getSize();
    short divisorrr = filter -> getDivisor();
    output -> width = input -> width;
    output -> height = input -> height;

    // *** Weird! the code is faster when we have this as an "int" and not a "short"
        // No clue why. [BEYOND SCOPE OF CLASS] Maybe "structure fields order" like fields stored most efficiently?
    
    // *** Replace "output -> color[plane][row][col]" with outputSum
        // Variable is faster to access than repeadedly calling a specific place in an array.
        // Also, cache will grab lots of the array and makes the cache less efficient overall.
    int outputSum = 0;  
    
    
    // *** REPEAT No longer needs to execute functions each time in loop, code movement/motion?
        // makes faster becuase each function call wastes memroy and time, call to a set variable is much quicker
    short g00 = filter -> get(0, 0);
    short g01 = filter -> get(0, 1);
    short g02 = filter -> get(0, 2);
    
    short g10 = filter -> get(1, 0);
    short g11 = filter -> get(1, 1);
    short g12 = filter -> get(1, 2);
    
    short g20 = filter -> get(2, 0);
    short g21 = filter -> get(2, 1);
    short g22 = filter -> get(2, 2);
    
    
    
        


      
  
  
    //MREEDL my boiiiiiiiiiiii
    // *** Rearrange the for loops, plane row col, i j, this comes from contiguous memory, spacial locality
        // Memory for an array is stored sequentially, in this order the cache can grab more
        // than just a single element, makes the loop much faster
    
    // *** row++ is faster than row=row+1
        // ++ is an "increment opperator", takes less time to load compared to grabbing "row"
        // from memory many times (using summation instructions)
        // ++row would be even better, ++row doesnt return previous value of row
    
  // *** pragma omp parallel!!!!!
      // THREADS: are the smallest sequence of programing instruciotns a "scheduler" can manage
      // tells compiler to parallelize the code. So it 
      // "parallel" code will be executed with multiple threads
      // "for" divides the loop iterations to be executed across multiple threads
      // SUMMERY: make a bunch of threads, each loop iteration gets assigned a diff threrad
      // when they are all done, all threads merged back together
    
  #pragma omp parallel for
  for(int plane = 0; plane < 3; plane++) {
    for(int row = 1; row < iHeight - 1; row++) {
      for(int col = 1; col < iWidth - 1; col++) {
          
          outputSum = 0;

          
          // *** ?loop unrolling? Unroll the entire inner i, j loop into its instructions
              // each cycle of the loop is doing what each line of the unrolled loop does
              // fewer instructions executed

          /* i=0, j=0 */ outputSum += (input -> color[plane][row + 0 - 1][col + 0 - 1] * g00);
          /* i=0, j=1 */ outputSum += (input -> color[plane][row + 0 - 1][col + 1 - 1] * g01);
          /* i=0, j=2 */ outputSum += (input -> color[plane][row + 0 - 1][col + 2 - 1] * g02);

          /* i=1, j=0 */ outputSum += (input -> color[plane][row + 1 - 1][col + 0 - 1] * g10);
          /* i=1, j=1 */ outputSum += (input -> color[plane][row + 1 - 1][col + 1 - 1] * g11);
          /* i=1, j=2 */ outputSum += (input -> color[plane][row + 1 - 1][col + 2 - 1] * g12);

          /* i=2, j=0 */ outputSum += (input -> color[plane][row + 2 - 1][col + 0 - 1] * g20);
          /* i=2, j=1 */ outputSum += (input -> color[plane][row + 2 - 1][col + 1 - 1] * g21);
          /* i=2, j=2 */ outputSum += (input -> color[plane][row + 2 - 1][col + 2 - 1] * g22);
          
          
          // *** /= instead of x = x/4
              // means:
              // find place in memry called output sum, divide it by divisorrr
              // VS the other way you do a lot of storing of the origional and an accumulator
          outputSum /= divisorrr;
          
          
          
          // *** "if, if, if" not as fast as "if, else if, else"
              // when one if is activated, the rest are bypassed
          if ( outputSum  < 0 ) { output -> color[plane][row][col] = 0; }
          else if ( outputSum  > 255 ) { output -> color[plane][row][col] = 255; }
          else {output -> color[plane][row][col] = outputSum; }
          

          
          // *** this statment is pointless same as x=x
              // code with no point still takes time to execute
          //output -> color[plane][row][col] = output -> color[plane][row][col];
          
      }
    }
  }

  cycStop = rdtscll();
  double diff = cycStop - cycStart;
  double diffPerPixel = diff / (output -> width * output -> height);
  fprintf(stderr, "Took %f cycles to process, or %f cycles per pixel\n", diff, diff / (output -> width * output -> height));
  return diffPerPixel;
}
