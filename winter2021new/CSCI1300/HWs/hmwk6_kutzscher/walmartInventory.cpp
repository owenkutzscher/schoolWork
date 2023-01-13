//CSCI1300 Fall 2021
//Author: Owen Kutzscher
//Recitation: 117? - N. Sistla
//Homework 5 - Problem 1

//pseudo code:
/*

read file name

open .txt file and output:
number of lines
    count each one and make sure you arent counting the empty ones

go through and read each line, keeping track of the most 
expensive products name and its price, and same for least expensive
return the name and price
make sure if two are tied then just use the first one


the name of the most expensive product in the file

the name of the least expensive



*/


#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;






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




















int countNumLines(string fileName){
    //we dont need to check if we can open the file because we already checked in main

    //we will return this guy
    int numLines = 0;

    string line = " ";

    //create the variable for our file we are opening
    ifstream in_file(fileName);


    //while its not the end of the file, go through and proscess the filr
        while (!in_file.eof()){
            
            
            //get input
            getline(in_file, line);

            //cout << "line length rn is: " << line.length() << endl;
            
            //if we want to check for more things, like say check for lines with only spaces
            // then we can add that later
            //en empty line has length 1
            if(line.length() > 1){
                numLines++;
            }
        }

    return numLines;
}







string findMostExpensive(string fileName, int option){

    //real quick, that option guy is just to save space, option 1 is find most expensive,
    //option 2 is find least expensive

    //ok we will be using the string splitter function for this guy...

    //sooo
    //lets go through the text file line by line
    //for each line well split it into an array, where the second term is the price
    //then we'll go through and clean up that number, make sure there arent any
    // spaces or weird things on it
    //then we'll compare the number to the current best, if its *MORE* expensive then we'll
    // make its name the name of the mostExpensive
    //then just return mostExpensive

    string mostExpensive = " ";
    int mostExpensivePrice = 0;

    






    //we'll use this variable to keep track of the lines
    string line = " ";

    //create the variable for our file we are opening
    ifstream in_file(fileName);
    

    //lets declare some cariables so we can use the splitter fucntion
    /////
    string strToSplit = " ";
    //the seperator will be a comma!
    char seperator = ',';
    //our array will have 2 spots, one for the name, one for the price
    int arrSIZE = 2;
    string arr[arrSIZE];

    //cout << "aight lets test this guy" << endl;

    //heres the function commented out below
    //split(strToSplit, seperator, arr, arrSIZE);
    /////

    //this is just for the first time around to assign the variables the first values in the file
    bool firstTimeAround = 0;

    //this will be used to store a value in the file and clean it up
    string cleanUp = " ";

    //this is another variable for cleaning up
    //its the point where we find a space
    int spacePos = 0;



    //while its not the end of the file, go through and proscess the file
    while (!in_file.eof()){
        
        
        //get input
        getline(in_file, line);

        //cout << "line length rn is: " << line.length() << endl;
        
        //if we want to check for more things, like say check for lines with only spaces
        // then we can add that later
        //en empty line has length 1
        if(line.length() > 1){
            
            //cool its not an empty line
            strToSplit = line;
            split(strToSplit, seperator, arr, arrSIZE);


            //aight lets filter it real quick and make sure that there arent
            //any spaces in the number we thought we selected
            //first lets assign a string the value
            cleanUp = arr[1];
            
            //and now the way this is layed out, there will probably be spaces in the front of the number
            // and then after the number there wont be anything
            // so we'll just worry about the spaces before the number
            //lets loop though until we hit a number
            //then we'll just tale everything from that point on and 
            // shove it into an int!
            for(int i = 0; i < cleanUp.length(); i++){
                if(cleanUp.substr(i,1) != " "){
                    spacePos = i;
                    i = cleanUp.length();
                }
            }

            //ayy now all we gotta do is clean it up, remove the spaces
            cleanUp = cleanUp.substr(spacePos, cleanUp.length() - spacePos);

            //now assign the cleaned up guy to the origional
            arr[1] = cleanUp;;
            




            

            //this is just to print out the prices
            //cout << "the price i found is " << arr[1] << endl;

            //add a string and int to our variables tjust to get started
            //that way we have a lowest value set from the start
            if(firstTimeAround == 0){
                mostExpensive = arr[0];
                mostExpensivePrice = stoi(arr[1]);
                firstTimeAround = 1;
            }else{
                //ok its not the first time around
                //so lets check out them prices and if its a more expensive item, make it the new mostExpensive

                //oh yea also if they chose option 2 then find the least expensive
                if(option == 1){
                    if(stoi(arr[1]) > mostExpensivePrice){
                        mostExpensive = arr[0];
                        mostExpensivePrice = stoi(arr[1]);
                    }
                }else{
                    //ill just assume if it wasnt option 1 then they wanna do least expensive
                    if(stoi(arr[1]) < mostExpensivePrice){
                        mostExpensive = arr[0];
                        mostExpensivePrice = stoi(arr[1]);
                    }
                }
                
            }
            


            
        }
    }





    
    return mostExpensive;
}














int main(){

    string response = " ";

    cout << "Enter the file name:" << endl;
    cin >> response;
    //response = "example_products.txt";




    //create the variable for our file we are opening
    ifstream in_file(response);


    //in this problem the walmart people gave us a file
    // specificly the items are seperated by lines (if you were typing you'd hit enter)
    // amd the price is seperated from the item by a comma


    



    //first check if it can actually open
    if(!in_file.is_open()){

        //dang we couldnt open it
        cout << "Could not open file." << endl;
    }else{




        //cool, we opened the file successfully
        //cout << "we opened the file successfully" << endl;



        //FIRST
        //lets find the number of lines containting text

        int numLines = 0;
        //we'll enter in the users string response so we dont need to worry abt the in_file not being a string
        numLines = countNumLines(response);
        cout << "The number of lines: " << numLines << endl;


        //cool, we got how many lines the file has
        //now we need to find the most expensive product and return its name
        // if we have another product with the same price then we should just do the first one
        string mostExpensiveProduct = " ";
        string leastExpensiveProduct = " ";
        //we'll enter in the users string response so we dont need to worry abt the in_file not being a string
        mostExpensiveProduct = findMostExpensive(response, 1);
        cout << "The most expensive product: " << mostExpensiveProduct << endl;

        //I added if you put any number other than 1 into the function itll find the least expensive
        leastExpensiveProduct = findMostExpensive(response, 2);
        cout << "The least expensive product: " << leastExpensiveProduct << endl;




        //end of the if statment that was checking if the file can open
    }

    in_file.close();
    return 0;
}