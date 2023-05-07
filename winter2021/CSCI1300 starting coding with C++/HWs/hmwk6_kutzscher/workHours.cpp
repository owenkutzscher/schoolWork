//CSCI1300 Fall 2021
//Author: Owen Kutzscher
//Recitation: 117? - N. Sistla
//Homework 5 - Problem 2

//pseudo code:
/*

//side note
//next time write more functions so that its not just one giant function

int workHours(string fileName, string names[], int hours[][], int hoursSIZE){
    //string fileName - the string name of the file
    //string names[] - an array to store the names of employees
    //int hours[][] - 2D array, row is each employee, 12 columns for
    // monthly work hours
    //int hoursSIZE - the size of hours[][]

    ////
    //returns -1 if the file cant be opened
    //else, return the number of employees stored in names
    ////
    //prints:
    //"employee name": avg monthly work hours *rounded to 1 decimal palce
    ////



    //aight lets get her goin

    //first see if the file can be opened,
    // if it cant be opened return -1 
    //else...
        //go through the file and store the names of the employees in
        // the names[] array
        //each time you store a name add one to the numNames variable
        //we will need to return that later

        //and then store their work hours in hours[][]
        //this is nice because the position of the name in one array
        // corosponds to the pos of their work hours in the larger array

        //ok now its time to return and print things
        //first off, return numNames
        
        //secondly, print out some stuff
        //I wrote this down above, but ill do it again just to make it easy
        //prints:
        //"employee name": avg monthly work hours *rounded to 1 decimal palce
    

    //end of function
    //things have already been returned so no need to be concerned
}



*/














#include <iostream>

#include <fstream>
#include <cstring>
using namespace std;












//you guys say to not include any #includes
//but how the fuck do you expect us to round to 1 decimal point without
// using <iomanip> ?????
//another thing, you guys need to be way more specific on the ways that the .txt
// file can be changed. If you dont tell us we have no way of knowing what you will do to it
#include <iomanip>
int workHours(string fileName, string names[], int hours[][12], const int SIZE){
    //string fileName - the string name of the file
    //string names[] - an array to store the names of employees
    //int hours[][] - 2D array, row is each employee, 12 columns for
    // monthly work hours
    //int SIZE - the size of the arrays

    ////
    //returns -1 if the file cant be opened
    //else, return the number of employees stored in names
    ////
    //prints:
    //"employee name": avg monthly work hours *rounded to 1 decimal palce
    ////

//its what we will be returning
            int numNames = 0;

    //aight lets get her goin

    

    //first see if the file can be opened,
    // if it cant be opened return -1 

    //create the variable for our file we are opening
    ifstream realFile(fileName);

    

    if(!realFile.is_open()){

        //dang we couldnt open it
        //cout << "Could not open file." << endl;
        return -1;
        //if theres an error, then assign numNames -1 and return that


    }else{
        //sick it opened successfully
        //cout << "file opened successfully" << endl;

        //this will be used to keep track of the number of names
            

        //go through the file and store the names of the employees in
        // the names[] array
        //each time you store a name add one to the numNames variable
        //we will need to return that later

        
            int lineNum = 0;
            

        while (!realFile.eof()){
            //this will be used to keep track of what line we are on
            //all the even lines starting with zero are going to be names
            
            string line = " ";
            
            
            
            
            //get input
            getline(realFile, line);

            if(lineNum % 2 == 0){
                //we are on a line with a name on it
                //cout << "we got a name here: " << line << endl;


                //real quick make sure its not empty
                if(line.empty()){
                    lineNum++;
                }else{
                    //store the names of the employees in
                    // the names[] array
                    names[lineNum / 2] = line;


                    //each time you store a name add one to the numNames variable
                    //we will need to return that later
                    numNames++;

                }
                
                



            }else{

                //ayyyy if its not even its odd
                //were on an odd row so we must be on a row with numbers of work hours

                //lets store their work hours in hours[][]
                //this is nice because the position of the name in one array
                // corosponds to the pos of their work hours in the larger array
                
                //ah shit we gotta filter it
                //like
                //there are hella commas in there and we just want the numbers
                //lets go through, whenever its the end of an int then just shove it in

                string shoveItIn = " ";

                int placeToShoveIn = 0;
                int row = 0;
                int column = 0;


                //cout << "the line length is: " << line.length() << endl;
                for(int i = 0; i < line.length(); i++){
                    if(line.substr(i, 1) == "0" || line.substr(i, 1) == "1" ||
                    line.substr(i, 1) == "2" || line.substr(i, 1) == "3" ||
                    line.substr(i, 1) == "4" || line.substr(i, 1) == "5" ||
                    line.substr(i, 1) == "6" || line.substr(i, 1) == "7" ||
                    line.substr(i, 1) == "8" || line.substr(i, 1) == "9" ){
                        //sick the thing we got is a number
                        //cout << "we got a numba: " << line.substr(i, 1) << endl;
                        

                        //wait dont shove it in unless theres room
                        if(!(i >= SIZE)){
                            //hold up if we reset shoveItIn then just make that its contents
                            //if not then append it
                            if(shoveItIn == " "){
                                shoveItIn = line.substr(i, 1);
                            }else{
                                shoveItIn.append(line.substr(i, 1));
                            }

                            //also hold up, if this is the very last number, then shove it in
                            if(i == line.length()-1){
                                hours[row][column+1] = stoi(shoveItIn);
                                shoveItIn = " ";
                            }
                        }
                        
                        
                    }else{

                        //that means the thing were on is not a number
                        //so lets shove in our number we found to the array
                        // and then reset it
                        //if its empty tho then dont shove it in

                        //wait dont shove it in unless theres room
                        //if(!(i >= SIZE)){

                        if(shoveItIn != " "){
                            //cout << "im going to shove in: " << shoveItIn << endl;

                            row = (lineNum - 1) / 2;
                            column = placeToShoveIn;
                            //cout << "im shoving in: " << shoveItIn << " at position: " << placeToShoveIn << endl;

                            //lastly, we will cast shoveItIn as an int
                            hours[row][column] = stoi(shoveItIn);
                            shoveItIn = " ";
                            placeToShoveIn++;
                        }

                        //}
                        

                        
                    }
                }
            }

            //bout to go to a new line so line++
            lineNum++;
            
        }




        

        //ok now its time to return and print things
        //first off, return numNames
        //actually just for the sake of it lookin pretty we'll put the return at the end
        
        //secondly, print out some stuff
        //I wrote this down above, but ill do it again just to make it easy
        //prints:
        //"employee name": avg monthly work hours *rounded to 1 decimal palce
        
        //cout << "the number of names is: " << numNames << endl;
double avg = 0.0;
        for(int w = 0; w < numNames; w++){

            if(!(w >= SIZE)){
                
                //lets figure out the avarage real quick
                
                for(int j = 0; j < 12; j++){
                    //cout << "hours[w][j] is: " << hours[w][j] << endl;
                    //cout << "added up values are: " << avg << endl;
                    avg = avg + hours[w][j];
                }
                
                avg = avg/12.0;

                cout << names[w];
                cout << fixed;
                cout << setprecision(1);
                cout << ": " << avg << endl;

                //reset the avg
                avg = 0;
            }
        }
            
        


        //ok now return names
        return numNames;
    }
    

    //end of function
    //things have already been returned so no need to be concerned
}



































int main(){


    string response;
    cout << "fuckin, gimmie the txt file and stuff" << endl;
    //cin >> response;

    //
    response = "work_hours.txt";

    
    const int SIZE = 2;
    string names[SIZE]; 
    int hours[SIZE][12];

    //cout << "running the function" << endl;
    cout << workHours(response, names, hours, SIZE) << endl;

/*
    cout << "lets print the arrays rn" << endl;
    for(int u = 0; u < 3; u++){
        cout << names[u] << endl;
        for(int k = 0; k < 12; k++){
            cout << hours[u][k] << " ";
        }
        cout << endl;
    }
*/
    

    //if we use the demonstration txt file the expected output is
    /*
    John: 69.6
    Alek: 26.3
    Kate: 54.5
    //and then the function returns: 3
    */

   //cout << "ima print num names real quick... " << endl;




}