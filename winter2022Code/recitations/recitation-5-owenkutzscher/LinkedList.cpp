#include "LinkedList.hpp"

using namespace std;


// Search for a specified key and return a pointer to that node
//MANDETORY_TODO: complete this function
// Given the key this function will find the node where the key is present
// If found it will return the node, else NULL
Node* LinkedList::searchList(int key) {

    Node* ptr = head;
    while (ptr != NULL && ptr->key != key)
    {
        ptr = ptr->next;
    }
    return ptr;
}

void LinkedList::insert(Node* prev, int newKey){

  //Check if head is Null i.e list is empty
  if(head == NULL){
    head = new Node;
    head->key = newKey;
    head->next = NULL;
  }

  // if list is not empty, look for prev and append our node there
  else if(prev == NULL)
  {
      Node* newNode = new Node;
      newNode->key = newKey;
      newNode->next = head;
      head = newNode;
  }

  else{

      Node* newNode = new Node;
      newNode->key = newKey;
      newNode->next = prev->next;
      prev->next = newNode;

    }
}



// Print the keys in your list
void LinkedList::printList(){
  Node* temp = head;

  if(temp == NULL){
    return;
  }

  while(temp->next != NULL){
    cout<< temp->key <<" -> ";
    temp = temp->next;
  }

  cout<<temp->key<<endl;
}


// TODO: SILVER PROBLEM (mandetory)
// Delete node at a particular index
bool LinkedList::deleteAtIndex(int n)
{
  bool isDeleted = false;

  if(head == NULL){
    cout<< "List is already empty"<<endl;
    return isDeleted;
  }



    Node *pres = head;
	Node *prev = NULL;

     // Special case to delete the head
    if (n == 0) {
       //todo
      
      head = head -> next;
      delete pres;
      isDeleted = true;
    }
    else 
    {


    //TODO

    int index = n;

    while(index != 0 && pres -> next != NULL)
    {
      prev = pres;
      pres = pres -> next;
      index--;
    }

    if(index == 0)   // if (pres -> next)
    {
      prev -> next = pres -> next;
      delete pres;

      isDeleted = true;
    }
    }
    
    
      

	return isDeleted;
}

//TODO:GOLD PROBLEM (optional)
LinkedList::~LinkedList()
{
    //TODO

    /*

    while(head != NULL)   // while head != null
    {
      
      cout << "giving head: " << head
      deleteAtIndex(0);
    }

    */


    cout<<"network deleted"<<endl;
    
}