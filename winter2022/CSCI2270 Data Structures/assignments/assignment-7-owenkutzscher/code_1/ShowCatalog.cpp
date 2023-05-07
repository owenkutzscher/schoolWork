#include "ShowCatalog.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

/* Completed functions. DO NOT MODIFY*/
ShowCatalog::ShowCatalog()
{
    root = nullptr;
}

/* Completed functions. DO NOT MODIFY*/
void destroyNode(ShowItem *current)
{
    if (current != nullptr)
    {
        destroyNode(current->left);
        destroyNode(current->right);

        delete current;
        current = nullptr;
    }
}

/* Completed functions. DO NOT MODIFY*/
ShowCatalog::~ShowCatalog()
{
    destroyNode(root);
}

/* Completed functions. DO NOT MODIFY*/
void printShowHelper(ShowItem *m)
{
    if (m != nullptr)
    {
        cout << "Show: " << m->title << " " << m->userRating << endl;
        printShowHelper(m->left);
        printShowHelper(m->right);
    }
}

/* Completed functions. DO NOT MODIFY*/
void ShowCatalog::printShowCatalog()
{
    if (root == nullptr)
    {
        cout << "Tree is Empty. Cannot print" << endl;
        return;
    }
    printShowHelper(root);
}

/* Completed functions. DO NOT MODIFY*/
ShowItem *getShowHelper(ShowItem *current, string title)
{
    if (current == NULL)
        return NULL;

    if (current->title == title)
        return current;

    if (current->title > title)
        return getShowHelper(current->left, title);

    return getShowHelper(current->right, title);
}

/* Completed functions. DO NOT MODIFY*/
void ShowCatalog::getShow(string title)
{
    ShowItem *node = getShowHelper(root, title);
    if (node != nullptr)
    {
        cout << "Show Info:" << endl;
        cout << "==================" << endl;
        cout << "Title :" << node->title << endl;
        cout << "Year :" << node->year << endl;
        cout << "Show Rating :" << node->showRating << endl;
        cout << "User Rating :" << node->userRating << endl;
        return;
    }

    cout << "Show not found." << endl;
}

/* Completed functions. DO NOT MODIFY*/
ShowItem *addNodeHelper(ShowItem *current, ShowItem *newNode)
{
    if (current == nullptr)
    {
        return newNode;
    }

    if (current->title > newNode->title)
    {
        current->left = addNodeHelper(current->left, newNode);
    }
    else
    {
        current->right = addNodeHelper(current->right, newNode);
    }

    return current;
}

/* Completed functions. DO NOT MODIFY*/
void ShowCatalog::addShowItem(string title, int year, string showRating, float userRating)
{
    if (root == nullptr)
    {
        root = new ShowItem(title, year, showRating, userRating);
        return;
    }

    root = addNodeHelper(root, new ShowItem(title, year, showRating, userRating));
}














 
ShowItem* findDeepestLeftest(ShowItem *currNode)
{
    if(!currNode)
        return nullptr;
    
    if(currNode->left == nullptr)
        return currNode;

    return findDeepestLeftest(currNode->left);
}
 
ShowItem* removeShowHelper(ShowItem *currNode, string nameToDelete)
{
    if(!currNode)      // base case
        return nullptr;

    // below would be cool to implement, 
    // we would find the node to delete way faster...
    // but it would ony work if the BST is in order
    // and I feel that might not be the case
    // so I won't implement that here, nor in any other functions
    // actually, its a BST it will be in order. I'm just lazy ://///
    /*
    if(currNode->title > nameToDelete)
        currNode->left = removeShowHelper(currNode->left, nameToDelete);
    
    if(currNode->title < nameToDelete)
        currNode->right = removeShowHelper(currNode->right, nameToDelete);
    */
    
    
    // left
    currNode->left = removeShowHelper(currNode->left, nameToDelete);
    
 
    // check to delete current node (s), if so check for certain cases...
    if(currNode->title == nameToDelete)    
    {
        if(currNode->left == nullptr && currNode->right == nullptr)     // case (leaf node) left node is NULL, right is NULL
        {
            delete currNode;
            currNode = nullptr;
            return nullptr;
        }
        else if(currNode->left != nullptr && currNode->right == nullptr)       // case left node stays in BST, right is NULL
        {    
            ShowItem *tempNode = currNode->left;
            delete currNode;
            currNode = nullptr;
            return tempNode;
        }
        else if(currNode->left == nullptr && currNode->right != nullptr)    // case left node is NULL, right node stays in BST
        {
            ShowItem *tempNode = currNode->right;
            delete currNode;
            currNode = nullptr;
            return tempNode;  
        }
        else        // case left node stays in BST, right node stays in BST
        {  
            ShowItem *lowestNodeRight = findDeepestLeftest(currNode->right);
            ShowItem *copyLowestNodeRight = new ShowItem(lowestNodeRight->title, lowestNodeRight->year, lowestNodeRight->showRating, lowestNodeRight->userRating);

            currNode->right = removeShowHelper(currNode->right, lowestNodeRight->title);
            
            copyLowestNodeRight->left = currNode->left;
            copyLowestNodeRight->right = currNode->right;

            delete currNode;
            currNode = nullptr;

            return copyLowestNodeRight;
        }
    }


    
    // right
    currNode->right = removeShowHelper(currNode->right, nameToDelete);
    return currNode;   // if nameToDelete never found then return s
    
}
 
// removes a show with certain name
void ShowCatalog::removeShow(std::string title)
{
    root = removeShowHelper(root, title);
}
 
 
 
 
 
 
 
 
 
 
 
 
 ShowItem* rightRotateHelper(ShowItem *currNode, string nameToRotate)
{
    if(!currNode)      // base case
        return nullptr;
 
 
 
    // left
    currNode->left = rightRotateHelper(currNode->left, nameToRotate);
    //
 
    if(currNode->title == nameToRotate)    
    {
        if(currNode->left == nullptr){
            // just dont rotate if the one coming in would be nullptr
        }
        else
        {       // right rotation
            ShowItem *x = currNode->left;
            ShowItem *y = currNode;
            y->left = x->right;
            x->right = y;
            return x;
        }
    }
 
    // right
    currNode->right = rightRotateHelper(currNode->right, nameToRotate);
    //

    return currNode;   // if never found show to rotate return the show we entered
}

void ShowCatalog::rightRotate(std::string title)
{
    root = rightRotateHelper(root, title);
}
 
 
 





ShowItem* leftRotateHelper(ShowItem *currNode, string nameToRotate)
{
    if(!currNode)      // base case
        return nullptr;
 
 
 
    // left
    currNode->left = leftRotateHelper(currNode->left, nameToRotate);
    //
 
    if(currNode->title == nameToRotate)    
    {
        if(currNode->right == nullptr){
            // dont rotate if node coming sin is nullptr
        }
        else
        {       // left rotation
            ShowItem *x = currNode;
            ShowItem *y = currNode->right;
            x->right = y->left;
            y->left = x;
            return y;
        }
    }
 
 
 
    // right
    currNode->right = leftRotateHelper(currNode->right, nameToRotate);
    //

    return currNode;   // if never found show to rotate return the show we entered
}

void ShowCatalog::leftRotate(std::string title)
{
    root = leftRotateHelper(root, title);
}
 

