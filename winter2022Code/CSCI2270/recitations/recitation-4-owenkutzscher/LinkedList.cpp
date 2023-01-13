#include "LinkedList.hpp"

using namespace std;

/*******************************
Mandatory: Silver Problem - Implement the insert and search functions
********************************/

// Search for a specified key and return a pointer to that node
//MANDATORY_TODO: complete this function
// Given the key this function will find the node where the key is present
// If found it will return the node, else NULL
Node* LinkedList::searchList(int key) {

    Node* ptr = NULL;
    ptr = head;

    // (*ptr).key = key

    while(ptr -> key != key && ptr != nullptr)
    {
      ptr = ptr -> next;
      // the address of ptr, set it to (*ptr).next which is the 
      // address of the next pointer!!!
    }

    return ptr;
}


// Add a new node to the list
//MANDATORY_TODO: complete this function
// This function will add a node with newKey after the prev node in the linked list
// if prev is null insertion is to be made at head
void LinkedList::insert(Node* prev, int newKey){

  Node *current = new Node();
  current -> key = newKey;
  current -> next = nullptr;

  //Check if head is Null i.e list is empty
  if(prev== NULL){
    current-> next = head;
    head = current;
  }

  // if list is not empty, look for prev and append our node there
  else if(prev -> next == NULL)
  {
    prev -> next = current;
    
  }

  //general insertion
  else{

        current -> next = prev -> next;
        prev -> next = current;
      }
}




/*******************************
Optional: Gold Problem - Implement the swapFirstAndLast function
********************************/

// Swap the first and last nodes (don't just swap the values). Swap the Nodes
bool LinkedList::swapFirstAndLast()
{
    bool isSwapped = false;

    return isSwapped;
}

// Print the keys in your list
void LinkedList::printList(){
  Node* temp = head;

  while(temp->next != NULL){
    cout<< temp->key <<" -> ";
    temp = temp->next;
  }

  cout<<temp->key<<endl;
}
