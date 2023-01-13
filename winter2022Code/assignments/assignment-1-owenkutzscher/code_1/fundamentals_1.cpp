#include "fundamentals_1.hpp"

// this inserts an int into an array and adjusts to all numbers
// are in ascending order
int addToArrayAsc(float sortedArray[], int numElements, float newValue) {
    // TODO done


    // function adds elements to an array keeping the lowest
    // values in the front. Returns the count of the elements
    // in the array. We assume not more than 100 elements
    // will be added and elements will all be greater than 0.

    //cout << "inserting the value: " << newValue << endl;


    ////// plan for the function

    // loop through the current array numElements times
    // until we find a number larger than the current number

    // send each element from that point onwards back 1

    // insert element

    // return numElements++



    int insertPosition = numElements;




    // loop through the current array numElements times
    // until we find a number larger than the current number
    for( int i = 0; i < numElements; i++ ){
        // may need to do numElements - 1 or something...
        
        if( sortedArray[i] > newValue ){
            insertPosition = i;
            break;
        }

        
    }






    // send each element from insertPosition onwards back 1
    //LATER

    for(int i = numElements; i >= insertPosition; i--){
        
        sortedArray[i+1] = sortedArray[i];
    }



    

    // insert element
    sortedArray[insertPosition] = newValue;

    numElements++;




    // return numCount++
    return numElements;
}

