#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "../code_1/array_double.hpp"

using namespace std;








////////////////////// SPLIT FUNCTION BELOW ///////////////////////////////////////////////////////////

int split(string str, char seperator, string arr[], int arrSIZE){
    //this will be the num pieces out string is split into
    int numPieces = 0;

    int validSeperatorCount = 0;



    //first, lets see if its an empty string, if so
    // numPieces, the return val, is 0 and just dont do anything else
    if(str == ""){
        
        //cout << "bruh there wasnt even a single guy in there what the heck" << endl;
        numPieces = 0;

    }else{

        //start looping and looking through the string for a seperator
        int strSize = str.length();
        for(int i = 0; i < strSize; i++){
            //cout << "testing the char: " << str[i] << endl;

            //lets see if its a seperator
            char c = str[i];
            if(c == seperator){
                //cout << "ayy we caught a seperator, in the act" << endl;

                //we found a seperator, sick
                //lets make sure it doesnt have anything weird with it

                //if the seperator is at the beginning or end, dont do anything
                if((i == 0) || (i == strSize)){
                    //cout << "ayy seperator what are you doing at the beginning/end?!!!" << endl;
                    bool keepGoing = 1;
                    while(keepGoing == 1){
                        if(str[i+1] == seperator){
                            i++;
                            //cout << "hell na no seperator repeating at thebeginning" << endl;
                        }else{
                            keepGoing = 0;
                        }
                    }
                }else{
                    
                    //cool, the seperator isnt at the beginning or the end

                    //wait, what if there were say 3 seperator in a row at the beginning?
                    // test for that
                    //actually we dont need to, if it was at the beginning, then it will do i++
                    // that way we are where we need to be

                    //if the seperator is followed by more seperators, that reach the
                    // end, then dont do anything
                        bool keepGoing = 1;
                        while(keepGoing == 1){
                            if(str[i+1] == seperator){
                                i++;
                                //cout << "hell na no seperator repeating" << endl;
                                if(i == strSize-1){
                                    //if the seperators went till the end then they are invalid
                                    //so take 1 off the count becuse we will be adding 1 on later regarless
                                    //cout << "those seperators went till the end so they are invalid" << endl;
                                    validSeperatorCount--;
                                }
                            }else{
                                keepGoing = 0;
                            }
                        }
                    
                    

                        //if the seperator has more seperators in front of it, then count
                        // it, and skip over the seperators against this one
                        //actually we dont need to do anything!
                        //the loop above checks for all instances of a seperator repeating

                        //if it doesnt have any seperators in front of it,
                        // and it passed all the tests, then count it
                        validSeperatorCount++;

                }
                
            }
        }







        //loop ends here
        //cool we finished looping and finding seperators

        //now count the number of pieces, since we have the number of seperators
        numPieces = validSeperatorCount + 1;

        //if we finished looping, and there was no seperators,
        // then numPieces is 1, we will return that, and now place the whole
        // string in the array as the first element
        if(numPieces == 1){
            arr[0] = str;
        }else if(numPieces > arrSIZE){




            //well the dint state this in the problem so now I have to do this I guess
            //alright we have to add elements into the array until the array is full

            string itemToAdd = "";
            bool addAndReset = 0;
            int z =0;

            int spaceLeft = arrSIZE;

            //bool endOnSeperator = 0;
            while(spaceLeft > 0){
            for(int p = 0; p < strSize; p++){

                char c = str[p];
                
                //cout << "im lookin at the value: " << c << "Im on p = " << p << endl;

                //if its a seperator just skip over it
                while(c == seperator){
                    
                    if(addAndReset == 1){
                        //since we found a seperator, 
                        // lets add the item weve been building into our array
                        //real quick tho, make sure the item to add isnt empty
                        if(itemToAdd != ""){
                            //cout << "im adding the item: " << itemToAdd << endl;
                            arr[z] = itemToAdd;
                            itemToAdd = "";
                            spaceLeft--;
                        }
                        z++;
                    }
                    
                    addAndReset = 0;

                    p++;
                    c = str[p];
                    //if(p == strSize){
                    //    endOnSeperator = 1;
                    //}
                }

                itemToAdd.push_back(c);


                addAndReset = 1;
            }
            }



            
            
            //else if the string is split into more pieces than the size of 
            // the array, then numPieces, return val, is -1
            // and i guess just dont change the array
            numPieces = -1;
            //cout << "banana" << endl;


            
        }else{
            //sick, you passed those tests
            //now loop though and shove guys into an array wherever the
            // seperator ends

            string itemToAdd = "";
            bool addAndReset = 0;
            int z =0;

            bool endOnSeperator = 0;

            for(int p = 0; p < strSize; p++){

                char c = str[p];
                
                //cout << "im lookin at the value: " << c << "Im on p = " << p << endl;

                //if its a seperator just skip over it
                while(c == seperator){
                    
                    if(addAndReset == 1){
                        //since we found a seperator, 
                        // lets add the item weve been building into our array
                        //real quick tho, make sure the item to add isnt empty
                        if(itemToAdd != ""){
                            //cout << "im adding the item: " << itemToAdd << endl;
                            arr[z] = itemToAdd;
                            itemToAdd = "";
                        }
                        z++;
                    }
                    
                    addAndReset = 0;

                    p++;
                    c = str[p];
                    if(p == strSize){
                        endOnSeperator = 1;
                    }
                }

                itemToAdd.push_back(c);


                addAndReset = 1;


            }

            if(endOnSeperator == 0){
                if(addAndReset == 1){
                            //since we found a seperator, 
                            // lets add the item weve been building into our array
                            //real quick tho, make sure the item to add isnt empty
                            if(itemToAdd != ""){
                                //cout << "im adding the item: " << itemToAdd << endl;
                                arr[z] = itemToAdd;
                                itemToAdd = "";
                            }
                            z++;
                        }
                }
            }
            

        
    }


    //cout << "valid seperator count: " << validSeperatorCount << endl;
    //return num pieces string was split into
    return numPieces;
}













//////////////// SPLIT FUNCTION ABOVE /////////////////////////////////////////////////////////////////




// this checks if a movie is already in the movieArr
bool checkIfMovieInMovieArr(string movieName, movieRecord *&movieArray, int &arrCapacity){

    bool movieFound = false;
    for(int i = 0; i < arrCapacity; i++)
    {
        if(movieArray[i].movieName == movieName)
        {
            movieFound = true;
        }
    }

    return movieFound;
}


// this checks if a movie is already in the movieArr
int findLocationDuplicateMovie(string movieName, movieRecord *&movieArray, int &arrCapacity){

    int location = 0;
    for(int i = 0; i < arrCapacity; i++)
    {
        if(movieArray[i].movieName == movieName)
        {
            location = i;
            break;
        }
    }

    return location;
}


int calculateTimesDoubled(int movieArrCapacity)
{
    int count = 0;
    
    movieArrCapacity /= 10;

    while(movieArrCapacity > 1)
    {
        count++;
        movieArrCapacity /= 2;
    }

    return count;
}










int main(int argc, char* argv[])
{

    
    


    //if incorrect number arguments passed, print this and exit
    if(argc < 4)
    {
        cout << 
        "Usage: ./run_app_1 <inputfilename> <MPA rating> <N>" 
        << endl;
    }
    else
{




    // movie variables
    int movieCount = 0; // cout of movies in movieArr
    int movieArrCapacity = 10;
    movieRecord *movieArr;
    movieArr = new movieRecord[movieArrCapacity];
    int locationOfDuplicateMovie = 0;



    // variables for taking the line of text
    ifstream currentFile(argv[1]);
    string line = " ";
    string tempArr[3];






    // opening the line of text
    if(currentFile.is_open())
    {
        while(getline(currentFile, line))
        {
            if(line.length() != 0)
            {






            // split the line with split funcion
            split(line, '\t', tempArr, 3);
            
            
                // is this movie the correct rating?
                if(tempArr[2] != argv[2]){

                    // check if the movie exits in movieArr
                    if(checkIfMovieInMovieArr(tempArr[0], movieArr, movieArrCapacity))
                    {
                        // if the movie is in movieArr then:
                        // // add rating to average,
                        // // and update movie count


                        // find location of the duplicate movie in movieArr
                        locationOfDuplicateMovie = findLocationDuplicateMovie(
                            tempArr[0], movieArr, movieArrCapacity);
                        
                        
                        // update movie average

                        movieArr[locationOfDuplicateMovie].avgUserRating = 
                        movieArr[locationOfDuplicateMovie].avgUserRating*movieArr[locationOfDuplicateMovie].movieCount;

                        movieArr[locationOfDuplicateMovie].avgUserRating = 
                        movieArr[locationOfDuplicateMovie].avgUserRating + stof(tempArr[1]);

                        movieArr[locationOfDuplicateMovie].movieCount++;

                        movieArr[locationOfDuplicateMovie].avgUserRating = 
                        movieArr[locationOfDuplicateMovie].avgUserRating / movieArr[locationOfDuplicateMovie].movieCount;



                
                        

                    }
                    else
                    {
                        // the movie hasn't been added to movieArr
                        // add it!

                        

                        ////////// DOUBLE movieArr IF NOT ENOUGH SPACE /////////////
                        if(movieCount >= movieArrCapacity)
                        {
                            //cout << "movieArr is full, doubling the arr" << endl;
                            doubleArray(movieArr, movieArrCapacity);

                        }
                        
                        // make the movie struct to add
                        movieRecord newMovie;
                        newMovie.movieName = tempArr[0];
                        newMovie.avgUserRating = stof(tempArr[1]);
                        newMovie.movieCount = 1;
                        
                        // add the newMovie
                        movieArr[movieCount] = newMovie;
                        movieCount++;
                        // cout << "added a movie named: " << newMovie.movieName << endl;
                    }
                }
            }
        }
    }



    ///////// SORTING movieArr ///////////////////////////////////
    sortArray(movieArr, movieCount);







    ///////////////// PRINTING BELOW //////////////////////////
    cout << "Array doubled: " << calculateTimesDoubled(movieArrCapacity) << endl;
    cout << "Distinct # of movies except " << argv[2] << ": " << movieCount << endl;
    cout << "Total # of movies excluding " << argv[2] << " ratings: " << getTotalMoviesCount(movieArr, movieCount) << endl;
    
    printTopNMovies(movieArr, stoi(argv[3]));


    




    // derefrence the pointers
    delete[] movieArr;
    movieArr = nullptr;









}
return 0;
}
