/*************************************************************/
/*                   ShowsList Definition                    */
/*************************************************************/
/* TODO: Implement the member functions of class ShowsList   */
/*     This class uses a linked-list of Show structs to      */
/*     represent the schedule of shows                       */
/*************************************************************/

#include "ShowsList.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

/*
 * Purpose: Constructor for empty linked list
 * @param none
 * @return none
 */
ShowsList::ShowsList() {
    /*
    DO NOT MODIFY THIS
    This constructor is already complete. 
    */
    head = nullptr;
}

/*
 * Purpose: Check if list is empty
 * @return true if empty; else false
 */
bool ShowsList::isEmpty() {
    /* finished. do not touch. */
    return (head == NULL);
}

/*
 * Purpose: prints the current list of shows nicely
 * @param none
 * @return none
 */
void ShowsList::displayShows() {
    // TODO: Copy-paste your solution from Assignment 3
    
    Show *current = head;
    // test if nothing in the linked list
    if(current != nullptr)
    {
        
        cout << "== CURRENT SHOWS LIST ==" << endl;

        while(current != nullptr)
        {
            cout << current -> name << "-> ";
            current = current -> next;
        }
        cout << "NULL" << endl;
        cout << "===" << endl;

        delete current;
        current = nullptr;

        
    }
    else
    {
        cout << "nothing in path" << endl;
    }
}

/*
 * Purpose: Add a new show to the shows linked list
 *   between the previous and the show that follows it in the list.
 * @param previousShow the show that comes before the new show
 * @param showName name of the new Show
 * @return none
 */
void ShowsList::addShow(Show* previousShow, string showName) {
    // TODO: Copy-paste your solution from Assignment 3

    
    
    // make a new show named showName
    Show *newShow = new Show();
    newShow -> name = showName;
    newShow -> rating = 0.0;
    newShow -> numberRatings = 0;
    newShow -> next = nullptr;
    

    
    if(previousShow == nullptr) // add to head
    {
        cout << "adding: " << showName << " (HEAD)" << endl;
        newShow -> next = head;
        head = newShow;
    }
    else if(previousShow -> next == nullptr) // add to tail
    {
        cout << "adding: " << showName <<  " (prev: " <<
        previousShow -> name << ")" << endl;


        previousShow -> next = newShow;
        // newShow -> next already is set to nullptr
    }
    else 
    {
        cout << "adding: " << showName <<  " (prev: " <<
        previousShow -> name << ")" << endl;

        newShow -> next = previousShow -> next;
        previousShow -> next = newShow;
    }
}

/*
 * Purpose: populates the ShowsList with the predetermined shows
 * @param none
 * @return none
 */
void ShowsList::buildShowsList() {
    // TODO: Copy-paste your solution from Assignment 3
    head=NULL;
    addShow(nullptr, "Friends");
    addShow(searchShow("Friends"), "Ozark");
    addShow(searchShow("Ozark"), "Stranger Things");
    addShow(searchShow("Stranger Things"), "The Boys");
    addShow(searchShow("The Boys"), "Better Call Saul");

}

/*
 * Purpose: Search the ShowsList for the specified show and return a pointer to that node
 * @param showName - name of the show to look for in list
 * @return pointer to node of show, or NULL if not found
 *
 */
Show* ShowsList::searchShow(string showName) {
    // TODO: Copy-paste your solution from Assignment 3

    Show *current = nullptr;
    current = head;


    while( (current != nullptr) && (current -> name != showName) )
    {
        current = current -> next;
    }


    
    return current;
}

/*
 * Purpose: Give a new rating to a show
 * @param receiver - name of the show that is receiving the rating
 * @param rating - the rating that is being given to a show
 * @return none
 */
void ShowsList::addRating(string receiver, double rating) {
    // TODO: Copy-paste your solution from Assignment 3
    Show *current = nullptr;
    
    current = searchShow(receiver);

    if(head == nullptr)     // empty list case
    {
        cout << "Empty list" << endl;
        return;
    }
    else if(current == nullptr)
    {
        cout << "Show not found" << endl;
    }
    else
    {
        current -> numberRatings++;
        current -> rating = 
        (current -> rating *
        (current -> numberRatings-1) + 
        rating) / current -> numberRatings;

        cout << "The rating has been updated: " << 
        current -> rating << endl;
    }
}


/****************************************************/
/*  ASSIGNMENT 4: Functions to be completed below.  */
/****************************************************/


/*
 * Purpose: Delete the Show in the list with the specified name.
 * @param showName - name of the Show to delete in the list.
 * @return none
 */
void ShowsList::removeShows(string showName)       // ew this is so gross
{
    //TODO: Complete this function

    Show *current = nullptr;
    Show *previous = nullptr;
    previous = head;
  
    current = searchShow(showName);

    if(current != nullptr && current != head)     // showName was found and not first node
    {
        while(previous -> next != current)       // look for showName
        {
            previous = previous -> next;
        }
    
        previous -> next = current -> next;
        delete current;
    }
    else if(current != nullptr && current == head)   // case showName is first node
    {
        head = head -> next;
        delete current;
    }
    else
    {
        cout << "Show does not exist." << endl;
    }
}

/*
 * Purpose: deletes all Shows in the list starting from the head of the linked list.

 * @param: none
 * @return: none
 */
void ShowsList::purgeCompleteShowList()
{
    // TODO: Complete this function

    // if list is empty do nothing
    // else, delete each node, set head to null

    

    Show *current = nullptr;
    Show *nextShow = nullptr;
    current = head;
    
    if(current -> next != nullptr)      // check if empty
    {
        while(current -> next != nullptr)
        {
            nextShow = current -> next;
            cout << "deleting: " << current -> name << endl;
            delete current;
            //Show *current = nextShow;
            current = nextShow;
        }
        cout << "deleting: " << current -> name << endl;
        delete current;

        head = nullptr;

        cout << "Deleted show list" << endl;
    }


    
}

/*
* Purpose: Creates a loop from last node to the show name specified.
* @param showName - name of the show to loop back to
* returns the last node before loop creation (to break the loop)
*/
Show* ShowsList::produceGlitch(string showName) 
{
    /*
    DO NOT MODIFY THIS
    This function is already complete. 
    */
    Show* ptr = searchShow(showName);
    Show* temp = head;
    while(temp && temp->next!=NULL){
        temp=temp->next;
    }
    if(ptr && temp)
        temp->next=ptr;
    return temp;
}

/*
 * Purpose: to detect loop in the linked list
 * @return: true if loop is detected, else false
 */
bool ShowsList::findGlitch() 
{
    // TODO: Complete this function

    Show *f = head;      // f will be moving twice as fast as 1
    Show *s = head;      // s is slow, f is fast
    while(f && s && f -> next != nullptr)
    {
        f = f -> next -> next;
        s = s -> next;

        if(f == s)
        {
            return true;
        }

    }
    return false;
}

void ShowsList::rearrangeShowList(int start, int end)
{
    // TODO: Complete this function

    // loop through till the end
    // // variabless: int index, Show current
    // when index = start save a Show to it
    // when index = end save a Show to it

    // now weve hit the end
    // current -> next = startShow
    // one value before startShow -> next = endShow -> next
    // endShow -> next = nullptr

    // make the program before we do the edge cases
    // edge cases
    // if list is empty
    // if start or end are outside size of list
    // if end is on the end then we will need to correct for that
    // if start is 0 then start - 1 doesnt exist...
    // if start or end are outside of the length of the linked list

    Show *current = head; 

    Show *beforeStartPtr = nullptr;
    Show *startPtr = nullptr;
    Show *endPtr = nullptr;
    Show *tailPtr = nullptr;

    int index = 0;
    int length = 0;


    if(!head)       // if head == nullptr list is empty
    {
        return;     // ends the whole function need to use this more 
    }
    


    while(current -> next != nullptr)   // get length and assign variables for use
    {
        
        if(index == start - 1)
            beforeStartPtr = current;
        
        if(index == start)
            startPtr = current;
        
        if(index == end)
            endPtr = current;
        
        
        index++;
        current = current -> next;
    }
    tailPtr = current;
    length = index;






    if(length == 0)     // case empty list
    {

    }
    else if(start > length)    // case start > length
    {

    }
    else if(end > length)     // case end > length
    {
        cout << "Invalid end index" << endl;
    }
    else if(end < start)    // case start > end
    {

    }
    else if(end == length)      // end == length, do nothing
    {
        cout << "Invalid end index" << endl;
    }
    else if(start == 0)     // start = 0 special case
    {
        tailPtr -> next = startPtr;
        head = endPtr -> next;
        endPtr -> next = nullptr;
    }
    else    // run normally
    {
        tailPtr -> next = startPtr;
        beforeStartPtr -> next = endPtr -> next;
        endPtr -> next = nullptr;
    }
}
