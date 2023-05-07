#include "EnqueueDequeue.hpp"

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

EnqueueDequeue::EnqueueDequeue(){
	/* Already implemented, don't change */
    queueFront = -1;
	queueEnd = -1;
}

bool EnqueueDequeue::isEmpty(){
	//TODO
	if(counter == 0){
		return true;
	}
	else
	{
		return false;
	}
}

bool EnqueueDequeue::isFull(){
	//TODO
    
	if(counter == SIZE)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void EnqueueDequeue::enqueue(std::string show){
	//TODO

	
	
	
	if(isFull())	// case queue full
	{
		cout << "Queue full, cannot add a new show" << endl;
		return;
	}
	else if(queueEnd==-1)
	
	{
		queueEnd = 0;
		queueFront = 0;
		queue[queueEnd]=show;
	}
	else
	{
		queueEnd = (queueEnd+1)%(SIZE);
		queue[queueEnd] = show;
		
	}
	counter++;
	
	
	

	
	





	/*
	// we could do this way better with % !!!!!!!!!!!!


	// adjust the enque value, later add in the show
	
	
	if(isFull())	// case queue full
	{
		cout << "Queue full, cannot add a new show" << endl;
		return;
	}
	else if(isEmpty())	// case queue empty
	{

		// queueFront and queueEnd are suposed to be -1 by default
		// why is there a test case for this???
		// so annying



			// not sure if suposed to reset vals
		// prev:0
		queueFront = 0;		// set both front and end indexes to 0 to reset
		queueEnd = 0;
		

	}
	else if(queueEnd == SIZE - 1)	// case queueEnd at last element in queue array //prev: no +1
	{
		queueEnd = 0;	// bring queueEnd index back around prev:0
	}
	else	// basic case
	{
		queueEnd++;
	}


	queue[queueEnd] = show;		// finally add the show to the end of queue		//prev: no+1
	counter++; 
	*/
}


void EnqueueDequeue::dequeue(){
	//TODO





	if(isEmpty())		// case queue is empty
	{
		cout << "Queue empty, cannot dequeue show" << endl;

		return;
	}
	if (queueEnd==queueFront||counter==1)
	{
		queueEnd=-1;
		queueFront=-1;
	}
	else{
		queueFront = (queueFront+1)%(SIZE);
	}
	counter--;











	/*
	if(isEmpty())		// case queue is empty
	{
		cout << "Queue empty, cannot dequeue show" << endl;
		return;
	}



	queue[queueFront] = "";	// dequeue the show at queueFront position	//prev: no +1
	counter--;


	// now move the value of queueFront

	if(queueFront == SIZE - 1)	//prev: no +1
	{
		queueFront = 0;	// prev:0
	}
	else
	{
		queueFront++;
	}
	*/
}


string EnqueueDequeue::peek(){




	//TODO


	if(isEmpty())
	{
		cout << "Queue empty, cannot peek" << endl;
		return "";
	}

	return queue[queueFront];
}


int EnqueueDequeue::queueSize(){
    //TODO
    return counter;
}