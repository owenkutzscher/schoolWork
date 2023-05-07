#include "../code_2/EnqueueDequeue.hpp"
#include <iostream>

using namespace std;

/*
 * Purpose: displays a menu with options
 * @param none
 * @return none
 */
void menu(){
	cout << "*----------------------------------------*" << endl;
	cout << "Choose an option:" << endl;
    cout << "1. Enqueue new shows (Add shows to the queue)" << endl;
	cout << "2. Dequeue (Retrieve shows from the queue)" << endl;
	cout << "3. Return the queue size and exit" << endl;
	cout << "*----------------------------------------*" << endl;
}

int main(int argc, char const *argv[])
{
    // DO NOT MODIFY THIS.
    if(argc > 0)
    {
        freopen(argv[1],"r",stdin);
    }
    
    /* TODO */


    // use getline for all inputs!!!

    int breakCounter = 100;     // if an infinite loop happens then we can break after 100 cycles

    bool stopRunning = false;
    string userInput = "";
    int intUserInput = 0;   // I want to practice a swith statement, so we gotta convert to int
    EnqueueDequeue owensQueue =  EnqueueDequeue();


    // case 1
    int numShowsToEnqueue;



    while(stopRunning == false && breakCounter > 0)
    {
        breakCounter--;

        menu();


        // get user input
        getline(cin, userInput);

        if(userInput != "1" && userInput != "2" && userInput != "3")
        {
            cout << "Enter a valid option (1 or 2 or 3)" << endl;
        }
        else
        {
            intUserInput = stoi(userInput);

            switch(intUserInput)
            {
            case 1:
            
                cout << "Enter the number of shows to be enqueued:" << endl;
                getline(cin, userInput);

                numShowsToEnqueue = stoi(userInput);

                for(int i = 0; i < numShowsToEnqueue; i++)
                {
                    cout << "Show" << i+1 << ":" << endl;
                    
                    getline(cin, userInput);
                    owensQueue.enqueue(userInput);
                }
                break;






            // bipin!

            case 2:
                cout << "Enter the number of shows to be dequeued:" << endl;
                getline(cin, userInput);

                numShowsToEnqueue = stoi(userInput);

                for(int i = 0; i < numShowsToEnqueue; i++)
                {
                    if(owensQueue.queueSize() == 0){
                        cout << "No more shows to retrieve from queue" << endl;
                        break;
                    }
                    getline(cin, userInput);
                    cout << "Retrieved: " << owensQueue.peek() << endl;
                    owensQueue.dequeue();
                }

                break;







            default:
                cout << "Number of shows in the queue:" << owensQueue.queueSize() << endl;
                stopRunning = true;
                break;
                
            }
        }
    }

    
    return 0;
}