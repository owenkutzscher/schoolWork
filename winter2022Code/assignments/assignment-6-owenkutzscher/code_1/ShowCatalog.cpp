#include "ShowCatalog.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;







ShowCatalog::ShowCatalog() {
    root = nullptr;
    // TODO
}



void destroyNode(ShowItem *s)
{
    // aight how we gon do this?
    // HERES HOW WE GON DO THIS, DALE -Pitbull

    // post order traversal4


    

    if(s!=NULL)       // same as if s!= NULL
    {
    destroyNode(s -> left);

    destroyNode(s -> right);
    
    delete s;
    s = nullptr;
    }
}



ShowCatalog::~ShowCatalog() {
    // TODO

    destroyNode(root);
    //root = nullptr;
}




void printerHelper(ShowItem *s)
{
    //cout << "owens thing is going" << endl;
    if(s == NULL)
    {
        return;
    }   // pre order
    cout << "Show: " << s->title << " " << s->userRating<< endl;
    printerHelper(s -> left);
    printerHelper(s -> right);
}

void ShowCatalog::printShowCatalog() {
    // TODO

    // print in alphabetical order prob
    // so print In order

    if(root == NULL)
    {
        cout << "Tree is Empty. Cannot print" << endl;
    }
    else
    {
        printerHelper(root);
    }

    
}








void getShowHelper(ShowItem *s, string title)
{
    if (s == nullptr)
    {
        cout << "Show not found." << endl;
    }
    else if (s->title == title)
    {
        cout << "Show Info:" << endl;
        cout << "==================" << endl;
        cout << "Title :" << s-> title << endl;
        cout << "Year :" << s-> year << endl;
        cout << "Show Rating :" << s -> showRating << endl;
        cout << "User Rating :" << s -> userRating << endl;
    }
    else if (s->title > title)      // left
    {
        getShowHelper(s -> left, title);
    }
    else if (s->title < title)      // right
    {
        getShowHelper(s -> right, title);
    }
    
}


void ShowCatalog::getShow(string title) {
    // TODO
    
    getShowHelper(root, title);
}











// cant pass in the pointer!!! Need to pass in variables
// wait can you pass in the pointer?!?!
ShowItem* addShowHelper(ShowItem *s, string title, int year, string showRating, float userRating)
{
    if(s == nullptr){
        ShowItem *owen = new ShowItem(title, year, showRating, userRating);
        return owen;
    }

    else if(s -> title > title)
    {
        // left
        s -> left = addShowHelper(s -> left,  title, year, showRating, userRating);
    }
    else if(s->title<title)
    {
        // right
        s -> right = addShowHelper(s -> right,  title, year, showRating, userRating);
    }


    return s;
}



void ShowCatalog::addShowItem(string title, int year, string showRating, float userRating) {
    // TODO



    root = addShowHelper(root, title, year, showRating, userRating);
    
}








// this does check if
void pLNHelper(ShowItem *s)     // in order 
{
    if(s)       // simplified: base case if s == NULL return
    { 
        pLNHelper(s->left);     // left
        if(s->left == NULL && s->right == NULL)
        {
            cout << s->title << endl;
            return;
        }
        pLNHelper(s->right);       // right
    }
}

void ShowCatalog::printLeafNodes() {
    // TODO
    ShowItem *s = root;
    pLNHelper(s);
}














// NOTE: attempt 1 making a fuction look super nice.
    // need to start doing this more! So much easier to read!!!!!!

void searchShowsHelper(ShowItem *s, char titleChar)     // pre order
{
    if(s)   // if s != NULL     //  Base case if s == NULL return. (stop at NULLs after leaf nodes)
    {
        if (s->title[0] == titleChar)   // if our 
            cout << s->title << "(" << s->year << ") " << s->userRating << endl;
        
        searchShowsHelper(s->left, titleChar);       // left
        searchShowsHelper(s->right, titleChar);       //right
    }
}

void ShowCatalog::searchShows(char titleChar) {
    if(root == NULL){
        cout << "Tree is empty. Cannot search shows" << endl;
        return;
    }

    cout << "Shows that starts with " << titleChar << ":" << endl;
    searchShowsHelper(root, titleChar);
}












void dNSRHelper(int &count, string showRating, ShowItem *s)    // in order traversal but order doesnt matter
{
    if(s)       // simplified: base case if s == NULL return
    {
        dNSRHelper(count, showRating, s->left);     // left

        if(s -> showRating == showRating)
            count++;
        
        dNSRHelper(count, showRating, s->right);       // right
    }
}

void ShowCatalog::displayNumShowRating(int &count, string showRating) {
    ShowItem *s = root;      // used to iterate through BST in dNSRHelper
    dNSRHelper(count, showRating, s);
}
