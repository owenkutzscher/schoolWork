#include <iostream>
#include "BST.hpp"
using namespace std;
#define COUNT 10
/**
Create a node with key as data
**/

Node* BST:: createNode(int data)
{
    Node* newNode = new Node;
    newNode->key = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

BST::BST()
{
    root= NULL;
}

/**
parameterized constructor. It will create the root and put the data in the root.
**/

BST::BST(int data)
{
    root = createNode(data);
    cout<< "New tree created with "<<data<<endl;
}

/**
Destructor
**/

BST::~BST(){
     destroyNode(root);
}


Node* BST::getRoot(){
    return root;
}

 /**
 This function will destroy the subtree rooted at currNode.
 
 Correct Code for the destroyNode function is the following:
 **/
void BST:: destroyNode(Node *currNode){
     if(currNode!=NULL)
     {
         destroyNode(currNode->left);
         destroyNode(currNode->right);

         delete currNode;
         currNode = NULL;
     }
 }

/*
Prints a binary tree in a 2D fashion.
Note: The image of the tree is left rotated by 90 degrees.
*/
void BST::print2DUtilHelper(Node *currNode, int space)
{
    // Base case
    if (currNode == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtilHelper(currNode->right, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", currNode->key);

    // Process left child
    print2DUtilHelper(currNode->left, space);
}

void BST::print2DUtil( int space)
{
  print2DUtilHelper(root, space);
}



//---------------------------- INSERT NODE IN THE TREE --------------------------------------

/**
This function will add the data in the tree rooted at currNode.
We will call this function from addNode.
**/

Node* BST:: addNodeHelper(Node* currNode, int data)
{
    if(currNode == NULL){
        return createNode(data);
    }
    else if(currNode->key < data){
        currNode->right = addNodeHelper(currNode->right,data);
    }
    else if(currNode->key > data){
        currNode->left = addNodeHelper(currNode->left,data);
    }
    return currNode;

}


void BST:: addNode(int data)
{
    root = addNodeHelper(root, data);
    cout<<data<<" has been added"<<endl;
}

//---------------------------- TODO: DELETE NODE FROM THE TREE --------------------------------------

/**
This function will delete the data from the tree rooted at currNode.
We will call this function from deleteNode.
**/

Node* BST::minValueNode(Node* node)
{
    Node* current = node;
  
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;
  
    return current;
}

Node* BST::deleteNodeHelper(Node* currNode, int key)
{
    // TODO: Recitation 8 
    // HINT: You might have to use the minValueNode function for one of the cases.
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
    currNode->left = deleteNodeHelper(currNode->left, key);
    
 
    // check to delete current node (s), if so check for certain cases...
    if(currNode->key == key)    
    {
        if(currNode->left == nullptr && currNode->right == nullptr)     // case (leaf node) left node is NULL, right is NULL
        {
            delete currNode;
            currNode = nullptr;
            return nullptr;
        }
        else if(currNode->left != nullptr && currNode->right == nullptr)       // case left node stays in BST, right is NULL
        {    
            Node *tempNode = currNode->left;
            delete currNode;
            currNode = nullptr;
            return tempNode;
        }
        else if(currNode->left == nullptr && currNode->right != nullptr)    // case left node is NULL, right node stays in BST
        {
            Node *tempNode = currNode->right;
            delete currNode;
            currNode = nullptr;
            return tempNode;  
        }
        else        // case left node stays in BST, right node stays in BST
        {  
            Node *lowestNodeRight = minValueNode(currNode->right);
            Node *copyLowestNodeRight = createNode(lowestNodeRight->key);

            currNode->right = deleteNodeHelper(currNode->right, lowestNodeRight->key);
            
            copyLowestNodeRight->left = currNode->left;
            copyLowestNodeRight->right = currNode->right;

            delete currNode;
            currNode = nullptr;

            return copyLowestNodeRight;
        }
    }


    
    // right
    currNode->right = deleteNodeHelper(currNode->right, key);
    return currNode;   // if nameToDelete never found then return s
    

}


void BST:: deleteNode(int data)
{
    root = deleteNodeHelper(root, data);
}





//-----------------------------------------PRINT TREE (INORDER TRAVERSAL)--------------------------------

/** This function will traverse the tree in-order and print out the node elements.
printTree() function will call this function.
**/

void BST:: printTreeHelper(Node* currNode, string *inorder){
     if(currNode)
     {
        printTreeHelper( currNode->left, inorder);
        (*inorder) += " " + to_string(currNode->key);
        printTreeHelper( currNode->right, inorder);
     }
 }

string BST:: printTree(){
    string inorder = "";
    printTreeHelper(root, &inorder);
    return inorder;
}

 //------------------------------------------------SEARCH A KEY------------------------------------------
 /** This function will search the data in a tree
     We will call this function from searchKey.
 **/

Node* BST::searchKeyHelper(Node* currNode, int data){
    if(currNode == NULL)
        return NULL;

    if(currNode->key == data)
        return currNode;

    if(currNode->key > data)
        return searchKeyHelper(currNode->left, data);

    return searchKeyHelper (currNode->right, data);
}

// This function will return whether a key is in the tree
bool BST::searchKey(int key){
    Node* tree = searchKeyHelper(root, key);
    if(tree != NULL) {
        return true;
    }
    cout<<"Key not present in the tree"<<endl;
    return false;
}

