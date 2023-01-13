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
    // TODO
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
    // TODO

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
