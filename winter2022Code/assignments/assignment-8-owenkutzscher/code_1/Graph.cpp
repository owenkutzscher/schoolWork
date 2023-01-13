#include "Graph.hpp"
#include <vector>
#include <queue>
#include <iostream>

using namespace std;








// adds a vertex
void Graph::addVertex(string name){
    vertex *v = new vertex();
    v->name = name;
    vertices.push_back(v);
}





// youll never guess what this one does.
void Graph::addEdge(string v1, string v2)   // adds edges between 2 vertexs
{
    vertex *v1Ver = nullptr;    // these are pointers to the vertexs
    vertex *v2Ver = nullptr ;

    adjVertex adj1;     // these are what will go into the opposite vertex
    adjVertex adj2;

    for(int i = 0; i < vertices.size(); i++)    // search for vertex 1 and 2
    {
        if(vertices[i]->name == v1){
            v1Ver = vertices[i];
            adj1.v = vertices[i];
        }
            
        if(vertices[i]->name == v2){
            v2Ver = vertices[i];
            adj2.v = vertices[i];
        }
            
    }
    
    if(v1Ver && v2Ver){         // if both vertex found, add edge between them
        v1Ver->adj.push_back(adj2);
        v2Ver->adj.push_back(adj1);
    }
}









void Graph::displayEdges()
{
    for(vector<vertex*>::iterator itCurr = vertices.begin();
    itCurr != vertices.end(); ++itCurr)
    {
        cout << (*itCurr)->name << " --> ";    // print name vertex

        vector<adjVertex> currAdj = (*itCurr)->adj;

        for(vector<adjVertex>::iterator itEdge = currAdj.begin();
        itEdge != currAdj.end(); ++itEdge)
        {
            cout << (*itEdge).v->name << " ";       // print edge vertexs names

        }

        cout << endl;   // go to next line
    }
}










// removes items from vectorQueue updating it for next round of BFT
vector<vertex*> removeInstances(vector<vertex*> vectorQueue, vertex* eraseVertex)
{ 
    vector<vertex*> vectorQueueR = vectorQueue;     // vectorQueue to return
    vertex *currVertex = nullptr;
    int size = vectorQueueR.size();

    int i = 0;
    while(i < size)
    {
        currVertex = vectorQueueR[i];

        if(currVertex->name == eraseVertex->name)
        {
            //vectorQueueR.erase(vectorQueueR.begin() + i);
            vectorQueueR.erase(next(begin(vectorQueueR), + i));
            i--;
        }

        size = vectorQueueR.size();
        i++;
    }
    return vectorQueueR;
}

// adds items to vectorQueue updating it for next round of BFT
vector<vertex*> addAdjVert(vector<vertex*> vectorQueue, vertex* addAdjVertex)
{
    vertex *currVertex  = nullptr;
    vector<vertex*> vectorQueueR = vectorQueue;     // vectorQueue to return

    for(int i = 0; i < addAdjVertex->adj.size(); i++)
    {
        currVertex = addAdjVertex->adj[i].v;

        if(!currVertex->visited)    // check if the adjVertx has been visited
        {
            vectorQueueR.push_back(currVertex);
        }
    }
    return vectorQueueR;
}

void Graph::breadthFirstTraverse(string sourceVertex){
    // WOW OKKKKKK SOOO
    // DISTANCE IS A THING WE CAN KEEP TRACK OF INSIDE EACH VERTEX 
    // SO JUST DO IT RECURSIVELY AND ASSIGN EACH THING
    // PRINT AT THE END
    // TOO LAZY TO DO IT NOW.....


    vertex *sourceVertexPtr = nullptr;   // vertex pointer to access sourceVertex
    vector<vertex*> vectorQueue;    // takes vertexes and is cleared out each round of the BFT
    vector<vertex*> vectorQueueNextRound;   //
    int vQSizeForRound = 0;     // used to keep track of the initial size of vectorQueue each round of BFT
    int distance = 0;   // distance from sourceVertexPtrex
    vertex *currVertex = nullptr;      // a vertex we will print and do things to

    
    // find  source vertex
    for(vector<vertex*>::iterator itCurr = vertices.begin();
    itCurr != vertices.end(); ++itCurr)
    {
        if((*itCurr)->name == sourceVertex)
        {
            cout << "Starting vertex (root): " << sourceVertex << "-> ";

            sourceVertexPtr = (*itCurr);
            distance++;
            sourceVertexPtr->visited = true;
            vectorQueue = addAdjVert(vectorQueue, sourceVertexPtr);  // populate vectorQueue for first round of BFT
            vectorQueue = removeInstances(vectorQueue, sourceVertexPtr);
        }
    }

    // this function is gross...
    // not sure how to clean it up!


    if(!sourceVertexPtr)      // case sourceVertexPtrex not found
        return;
        
    while(vectorQueue.size() > 0)
    {
        while(vectorQueue.size() > 0)
        {
            currVertex = vectorQueue[0];
            cout << currVertex->name << "(" << distance << ") ";

            currVertex->visited = true;
            vectorQueueNextRound = addAdjVert(vectorQueueNextRound, currVertex);    // populate adj vertexes for next round


            // delete this vertex from all the queues
            vectorQueue = removeInstances(vectorQueue, currVertex);
            vectorQueueNextRound = removeInstances(vectorQueueNextRound, currVertex);
        }

        distance++;     // we are now going to vertexs 1 more distance away
        vectorQueue = vectorQueueNextRound;     // update vectorQueue with items for next round
        vectorQueueNextRound.clear();      // make this fresh to fill on the next round
    }
    
    
    cout << endl;   // go to next line
    cout << endl; 
}









/*
string::source : source vertex (starting city)
int::k : distance that you can travel from source city with remaining fuel
*/
vector<string> Graph::findReachableCitiesWithinDistanceK(string source, int k){
    //TODO

    vector<string> reachableCities;



    /////////////////////////////////////


    vertex *sourceVertexPtr = nullptr;   // vertex pointer to access sourceVertex
    vector<vertex*> vectorQueue;    // takes vertexes and is cleared out each round of the BFT
    vector<vertex*> vectorQueueNextRound;   //
    int vQSizeForRound = 0;     // used to keep track of the initial size of vectorQueue each round of BFT
    int distance = 0;   // distance from sourceVertexPtrex
    vertex *currVertex = nullptr;      // a vertex we will print and do things to

    
    // find  source vertex
    for(vector<vertex*>::iterator itCurr = vertices.begin();
    itCurr != vertices.end(); ++itCurr)
    {
        if((*itCurr)->name == source)
        {
            //cout << "Starting vertex (root): " << sourceVertex << "-> ";

            sourceVertexPtr = (*itCurr);
            distance++;
            sourceVertexPtr->visited = true;
            vectorQueue = addAdjVert(vectorQueue, sourceVertexPtr);  // populate vectorQueue for first round of BFT
            vectorQueue = removeInstances(vectorQueue, sourceVertexPtr);
        }
    }

    // this function is gross...
    // not sure how to clean it up!


    if(sourceVertexPtr)      // case sourceVertexPtrex not found
    {
        
        while(vectorQueue.size() > 0)
        {
            while(vectorQueue.size() > 0)
            {
                currVertex = vectorQueue[vectorQueue.size() - 1];   ////// it wants us to go in reverse order
                //cout << currVertex->name << "(" << distance << ") ";

                //////
                if(distance == k){
                    reachableCities.push_back(currVertex->name);
                }
                //////

                currVertex->visited = true;
                vectorQueueNextRound = addAdjVert(vectorQueueNextRound, currVertex);    // populate adj vertexes for next round

                // delete this vertex from all the queues
                vectorQueue = removeInstances(vectorQueue, currVertex);
                vectorQueueNextRound = removeInstances(vectorQueueNextRound, currVertex);
            }

            distance++;     // we are now going to vertexs 1 more distance away
            vectorQueue = vectorQueueNextRound;     // update vectorQueue with items for next round
            vectorQueueNextRound.clear();      // make this fresh to fill on the next round
        }
    }



    /////////////////////////////



    return reachableCities;
}
