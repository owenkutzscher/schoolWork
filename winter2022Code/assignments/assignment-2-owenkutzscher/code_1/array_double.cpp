#include "array_double.hpp"
#include <iomanip>
#include <cctype>




bool checkMovieToBeIncluded(string movieMpaRating, string mpaRatingToBeExcluded){
    // TODO // done

    if(movieMpaRating == mpaRatingToBeExcluded)
    {
        return false;
    } 
    else 
    {
        return true;
    }
}







// if movieArr is full, double its size
void doubleArray(movieRecord *&movieArray, int &arrCapacity)
{
    // TODO

    //cout << "doubleArray function has been called!" << endl;

    // *&movieArray ::: treat it like its just movieArray[]
    // &arrCapacity ::: anything done to arrCapacity will affect
    // // the enterd in arrCapacity (... or movieArrCapacity ... ) 


    // double the capacity of the array
	int newCapacity = arrCapacity*2;
    // cout << "arrCapacity is: " << newCapacity << endl;

    // make a new array with the updated arrCapacity
    movieRecord *newArray = new movieRecord[newCapacity];

    // copy all data from oldArray to newArray
	for(int i = 0; i < newCapacity/2; i++){
		newArray[i].movieName = movieArray[i].movieName;
        newArray[i].movieCount = movieArray[i].movieCount;
        newArray[i].avgUserRating = movieArray[i].avgUserRating;


	}

    // free memory asociated with old array "movieArray"
    delete[] movieArray;
    movieArray = newArray;
    arrCapacity = newCapacity;


    // cout << "finished running doubleArray function" << endl;

}








// returns total numebr of movies in document
// distinctMovies is an array of movies without duplicates
int getTotalMoviesCount(movieRecord* distinctMovies, int length) {
    // TODO

    int count = 0;

    for(int i = 0; i < length; i++)
    {
        count += distinctMovies[i].movieCount;
    }

    return count;
}




// sorts the movies array with highest rated movies at the beginning
// if movies have the same rating, sort alphabetically
void sortArray(movieRecord* distinctMovies, int length) {
    
    // bubble sort timeee
    // we will got from back to front. Keeping track of the
    //  postion of the movie w the highest rating
    // then swap the movie at position 0 with the movie w the 
    //  highest rating
    // now go through again up to pos 1
    // continue till we get to the last postion

    int posHighestRating = 0;
    movieRecord tempMovie;
    //float highestAvgRating = distinctMovies[0].avgUserRating;
    
    
    for(int i = 0; i < length; i++)
    {
        
        // compare each movie to this one
        posHighestRating = i;


        // find the movie that has a greater score than the movie at pos i
        for(int k = length - 1; k >= i; k--)
        {   
            
            
            
            //determine if 
            if(distinctMovies[k].avgUserRating >= 
            distinctMovies[posHighestRating].avgUserRating)
            {
                
                // also, if the values are the same, compare
                //  them alphabetically
                // change the > to a >= sign above and check for equal
                // we could do a tolower() for loop to make them all lowercase...
                // ughhh ew


                if( distinctMovies[k].avgUserRating == 
                distinctMovies[posHighestRating].avgUserRating )
                {
                    
                    // since they are equal, check alphabetically > or <
                    if( (distinctMovies[k].movieName) < 
                        (distinctMovies[posHighestRating].movieName) )
                    {
                        
                        /*
                        cout << "heyyy: " << distinctMovies[k].movieName
                        << " at index: " 
                        << k 
                        << " comes before: " 
                        << distinctMovies[posHighestRating].movieName
                        << " at index "
                        << posHighestRating
                        << endl;
                        */
                        
                        posHighestRating = k;
                    }
                }
                else // if avgUserRating not == then it must be >
                {
                    posHighestRating = k;
                }
                
                
            }
        }
        
        // now swap the two values. Index i and index posHighestRating

        // I think we need to assign each value... 
        tempMovie = distinctMovies[i];
        distinctMovies[i] = distinctMovies[posHighestRating];
        distinctMovies[posHighestRating] = tempMovie;
    }
}




// prints the highest rated movies,
// the number of movies printed is entered by the user
// see pdf for specifications on printing
void printTopNMovies(movieRecord* movieArray,int numberOfMovies)
{   
    cout << "Movie Ratings" << endl;
    cout << "---------------------------------------" << endl;
    
    
    // ensure we are printing to 3 decimal places
    int Z = 3;
    cout << fixed << setprecision(Z);
    
    // print a count of numberOfMovies
    for(int i = 0; i < numberOfMovies; i++)
    {


        
        cout << movieArray[i].avgUserRating
        << " "
        << movieArray[i].movieName << endl;
    }
}



