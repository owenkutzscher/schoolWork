//-----------------------------------------------------------------------------
// CSCI2270 Course Project
//
// Identification: HashChaining.cpp
//-----------------------------------------------------------------------------

#include "HashChaining.h"

using namespace std;




/**********************************************************
 * COMMENTING SECTION
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 *********************************************************/
 









////////////////////// SPLIT FUNCTION BELOW ///////////////////////////////////////////////////////////
/**
 * splitC - "splits" a string into components and inserts into an array
 * 
 * @param str
 * @param seperator
 * @param arr
 * @param arrSIZE
 * @return int
 **/
int splitC(string str, char seperator, string arr[], int arrSIZE){
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
                            if(itemToAdd != ""){
                                arr[z] = itemToAdd;
                                itemToAdd = "";
                            }
                            z++;
                        }
                }
            }
    }
    return numPieces;
}

//////////////// SPLIT FUNCTION ABOVE /////////////////////////////////////////////////////////////////










/**
 * HashOpenAddressing - creates a hash table (to be used with chaining)
 * 
 * @param size
 * @return int 
 **/ 
HashChaining::HashChaining(int size)
{
    hashTableSize = size;
    hashTable = new Course*[hashTableSize];
}

void destroyChain(Course *&c)
{
    if(c)       // same as if s!= NULL
    {
        destroyChain(c->next);
        delete c;
        c = nullptr;
    }
}

/**
 * ~HashOpenAddrressing - frees memory allocated to hash table with chaining
 **/
HashChaining::~HashChaining()
{
    
    for(int i=0; i<hashTableSize; i++)
    {
        if(hashTable[i])
        {
            destroyChain(hashTable[i]);
            delete[] hashTable[i];
            hashTable[i] = nullptr;
        }
        
    }
    
    delete[] hashTable;
}








/**
 * hash - calculates the hash of a key
 * 
 * @param courseNumber
 * @return int
 **/
int HashChaining::hash(int courseNumber)
{
    return courseNumber%hashTableSize;
}

/**
 * bulkInsert - populates a hash table with contents of a csv file (chaining)
 * 
 * @param filename
 **/
void HashChaining::bulkInsert(string filename)
{
    // variables for extracting lines from csv file
    ifstream currentFile(filename);
    string line = " ";
    string splitLine[7];
    bool firstLine = false;      // prevents from reading first line, which has no data

    int totalCollisions = 0;       // these count the number of collisions and searches
    int totalSearches = 0;

    // opening the line of text
    if(currentFile.is_open()){
        while(getline(currentFile, line)){
            if(line.length() != 0){     // we will assume that if length >0 then valid line
                if(firstLine == true){      // skip first line in the csv file it has no data
                    splitC(line, ',', splitLine, 7);

                    // format for all lines in the entered .csv file
                    //  0     1    2          3           4       5    6
                    // 2021,CSCI,1200,INTRO TO COMPUTING,lnariso,Liz,Naris

                    int newYear = stoi(splitLine[0]);
                    string newDepartment = splitLine[1];
                    int newCourseNum = stoi(splitLine[2]);
                    string newCourseName = splitLine[3];
                    string pId = splitLine[4];
                    string pName = splitLine[5]+" "+splitLine[6];

                    Professor *newProf = new Professor(pId,pName);

                    Course *newCourse = new Course(newYear, newDepartment, newCourseNum, 
                        newCourseName, newProf);
                    
                    profDb.addProfessor(pId, pName);
                    profDb.searchProfessor(pId)->coursesTaught.push_back(newCourse);



                    int hashIndex = hash(newCourseNum);



                    Course *curr = hashTable[hashIndex];
                    Course *prev = nullptr;

                    if(curr)
                    {
                        totalCollisions++;
                        while(curr)
                        {
                            totalSearches++;
                            prev = curr;
                            curr = curr->next;
                        }
                        prev->next = newCourse;
                    }
                    else
                    {
                        hashTable[hashIndex] = newCourse;
                    }
                }
                firstLine = true;   // so we don't read the first line
            }
        }
    }

    cout << "Collisions using chaining: " << totalCollisions << endl;
    cout << "Search operations using chaining: " << totalSearches << endl;
    cout << endl;
}







/**
 * search - finds a specific course in hash table (chaining)
 * 
 * @param courseYear
 * @param courseNumber
 * @param profId
 **/
void HashChaining::search(int courseYear, int courseNumber, string profId)
{
    int searchOpps = 0;
    int hashIndex = hash(courseNumber); 
    Course *curr = hashTable[hashIndex];
    Course *prev = nullptr;
    bool courseFound = false;

    if(curr)
    {
        searchOpps++;
        courseFound = (curr->courseNum == courseNumber
        && curr->year == courseYear && curr->prof->profId == profId);  
    }
    
    while(curr && !courseFound)
    {
        curr = curr->next;
        searchOpps++;
        courseFound = (curr->courseNum == courseNumber
        && curr->year == courseYear
        && curr->prof->profId == profId);        
    }    


    
    if(!courseFound)
        cout << "The entered course was not found" << endl;
    else
    {
        searchOpps--;
        cout << "[CHAINING] Search for a course" << endl;
        cout << "-------------------------------------" << endl;
        cout << "Search operations using chaining: " << searchOpps << endl;


        // cout << displayCourseInfo(hashTable[index]) << endl;
        // PROJECT COULD BE IMPROVED
        // ^this is annoying. The fuction is declared after this one so I can't use it yet

        // year // course name // course number // professor name
        cout<<curr->year<<" "<<curr->courseName<<" "<<curr->courseNum<<" "<<curr->prof->profName << endl;
        cout << endl;
        
    }
}





/**
 * displayAllCourses - prints out all courses in a hash table (chaining)
 **/
void HashChaining::displayAllCourses()
{
    Course *c = nullptr;
    // while loop w displayCourseInfo
    for(int i=0; i<hashTableSize; i++)
    {
        if(hashTable[i] != 0)
        {
            c = hashTable[i];
            while(c)
            {
                displayCourseInfo(c);  
                c = c->next;
            }
        }
    }
        
            
}

/**
 * displayCourseInfo - prints to terminal all info a course contains (chaining)
 * 
 * @param c
 **/
void HashChaining::displayCourseInfo(Course* c)
{
    // year // course name // course number // professor name
    cout<<c->year<<" "<<c->courseName<<" "<<c->courseNum<<" "<<c->prof->profName << endl;
    cout << endl;
}