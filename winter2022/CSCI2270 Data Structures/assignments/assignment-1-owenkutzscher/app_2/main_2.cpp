#include <iostream>
#include <fstream>
#include "../code_2/fundamentals_2.hpp"
#include <sstream>
#include <string>

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

int main(int argc, char* argv[]) {
    // TODO

    // were getting 4 cmd line args
        // name of the input .csv file
        // name of the output .csv file
        // a lower bound for avg emission
        // an upper bound for avg emmission



    // first read from the input file
        // co2_emission.csv
    // getline
    // stringstream object

    string line = " ";
    string tempArr[6];
    emissionInfo emissionArr[119];
    int index = 0;

    
    ifstream emissionFile(argv[1]);

    //cout << "about to open the file" << endl;

    if(emissionFile.is_open())
    {
        while(getline(emissionFile, line))
        {
            // convert each entry into its apropriate data type yuh stod stof
            split(line, ',', tempArr, 6);



            // call insertEmissionInfo to update the co2_emissions array
            insertEmissionInfo(emissionArr, 
            tempArr[0], stod(tempArr[1]), 
            stod(tempArr[2]), stod(tempArr[3]), 
            stod(tempArr[4]), stod(tempArr[5]), 
            index);

            index++;

            //// works real good up to here!



        }
    }else
    {
        cout << "Failed to open the file." << endl;
    }





    ////////// WRITING TO A FILE BELOW //////////////////////////////////////////////////////////////////


    ofstream outputFile(argv[2]);

    double lower_bound = stod(argv[3]);
    double upper_bound = stod(argv[4]);


    if(outputFile.is_open())
    {
        
            // now writing to an external file
            // use ofstream
            // csv means Comma Seperated Values
            // literally just look at the expected output files n copy them
            // BUT ALSO have the countries where emission_average >= 
            // lower_bound and <= upper_bound those are cmd line arguments
            // dont forget to close the output file when done writing to it
            // dont forget to cout to the terminal for absolutley no reason

            // 1 // first just print all the values to a .csv file
            // // AND CLOSE THE FILE WHEN DONE
            // 2 // then add in the checking of the average making sure its in a
            // // specific range
            // 3 // then finally make sure it prints to the terminal correctly

            // writing to output.csv


            for(int i = 0; i < index; i++)
            {
                if((emissionArr[i].average >= lower_bound) && 
                (emissionArr[i].average <= upper_bound)){
                    outputFile << emissionArr[i].countryName;
                    outputFile << ",";
                    outputFile << emissionArr[i].average;
                    outputFile << ",";
                    outputFile << calcEmissionZone(emissionArr[i].average);
                    outputFile << endl;

                    cout << emissionArr[i].countryName;
                    cout << ",";
                    cout << emissionArr[i].average;
                    cout << ",";
                    cout << calcEmissionZone(emissionArr[i].average);
                    cout << endl;
                }
            }
    }else
    {
        cout << "Failed to open the file." << endl;
    }

    outputFile.close();













    return 0;
}