#include "Puzzle.hpp"
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

// makes a puzzle data struct
Puzzle::Puzzle(int n){
    this->n = n; 
}

void Puzzle::addEdge(int v1, int v2){
    vertex *v1Ptr = nullptr;
    vertex *v2Ptr = nullptr;
    adjVertex v1Adj;
    adjVertex v2Adj;
    bool duplicateFound = false;

    for(int u=0; u<vertices.size(); u++)    // find v1 and v2
    {
        if(vertices[u]->vertexNum == v1)
        {
            v1Ptr = vertices[u];
            v1Adj.v = vertices[u];
        }
        else if(vertices[u]->vertexNum == v2)
        {
            v2Ptr = vertices[u];
            v2Adj.v = vertices[u];
        }   
    }

    if(v1Ptr && v2Ptr){         // if v1 and v2 found, add edge between them
        // check for duplicates first!
        for(int k=0; k<v1Ptr->adj.size(); k++)
            if(v1Ptr->adj[k].v->vertexNum == v2)
                duplicateFound = true;

        for(int k=0; k<v2Ptr->adj.size(); k++)
            if(v2Ptr->adj[k].v->vertexNum == v1)
                duplicateFound = true;

        if(!duplicateFound)
        {
            v1Ptr->adj.push_back(v2Adj);
            v2Ptr->adj.push_back(v1Adj);
        }
    }
}

void Puzzle::addVertex(int num){
    vertex *newVertex = new vertex;
    newVertex->vertexNum = num;
    vertices.push_back(newVertex);

}

// prints the edges of vertices
void Puzzle::displayEdges(){
    for(int u=0; u<vertices.size(); u++)
    {
        cout << vertices[u]->vertexNum << " --> ";
        for(int r=0; r<vertices[u]->adj.size(); r++)
        {
            cout << vertices[u]->adj[r].v->vertexNum << " ";
        }
        cout << endl;
    }
}

// Finds the vertex number from the position of the open path in the maze
int Puzzle::findVertexNumFromPosition(int x, int y){
    // they switched x and y for some reason. >:(

    if(y < 0 || x < 0)
        return -1;
    else if(y + n*x < n*n)
        return y + n*x;
    else
        return -1;
}









// Creates a default maze of all 1s of size n x n, except for positions (0,0) and (n-1, n-1)
void Puzzle::createDefaultPuzzle(){

    // make the puzzle
    puzzle = new int*[n];
    for(int i=0; i<n; i++)
        puzzle[i] = new int[n]; 
    

    // fill the puzzle 
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if((i==0) && (j==0))
                puzzle[j][i] = 0;
            else if(i+1==n && j+1==n)
                puzzle[j][i] = 0;
            else
                puzzle[j][i] = 1;
        }
    }
}









// sets vertex at (i,j) to 0. Starts at (0,0) and goes right and down
void Puzzle::createPath(int i, int j){
    if(j>=0 && i>=0 && j<n && i<n)
        puzzle[i][j] = 0;
}





// puzzle[y][x]
void Puzzle::printPuzzle(){
    for(int y=0; y<n; y++)
    {
        cout << "|";
        for(int k=0; k<n; k++)
        {
            cout << " " << puzzle[y][k] << " |";
        }
        cout << endl;
    }
}

vector<int> Puzzle::findOpenAdjacentPaths(int x, int y){
    // find the open paths that are adjacent to the vertex at x, y
    // fill the adjacent array with the numbers of the adjacent vertices
    vector<int> neighbors; 
    for(int i = x-1; i <= x + 1; i++){
        if(i < 0 || i >= n){
            continue;
        }
        for(int j = y-1; j <= y+1; j++){
            if(j < 0 || j >= n){
                continue;
            }
            // if open path at this adjacent position exists, add to the adjacent array
            if(!(i == x && j == y) && puzzle[i][j] == 0){
                neighbors.push_back(findVertexNumFromPosition(i, j));
            }
        }
    }
    return neighbors;
}










void Puzzle::convertPuzzleToAdjacencyListGraph(){

    int newVertexNum = 0;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){     // iterate through puzzle
            if(puzzle[i][j] == 0)
            {
                newVertexNum = findVertexNumFromPosition(i, j);
                addVertex(newVertexNum);

                vector<int> neighbors = findOpenAdjacentPaths(i, j);

                for(int u=0; u<neighbors.size(); u++)
                    addEdge(newVertexNum, neighbors[u]);
            }
        }
    } 
}













// executes a depth first traversal
bool DFT(vertex *currV, vector<int> &path, int &n)
{
    int endNum = (n*n) - 1;
    bool onPathToEndNum = false;
    bool pathToEndFound = false;   // saves if a path went to the end
    currV->visited = true;      // any vertex reached, mark as visited
    cout << "Reached vertex: " << currV->vertexNum << endl;     

    if(currV->vertexNum == endNum)
    {
        pathToEndFound = true;
        path.insert(path.begin(), currV->vertexNum);
    }
        
    for(int u=0; u<currV->adj.size(); u++){
        if(currV->adj[u].v->visited == false){      // look in the adj that have not been visited

            onPathToEndNum = DFT(currV->adj[u].v, path, n);

            if(onPathToEndNum)     // cout got back on the correct path
            {
                path.insert(path.begin(), currV->vertexNum);
                pathToEndFound = true;
            }  
            else
                cout << "Backtracked to vertex: " << currV->vertexNum << endl;
        }
    }

    return pathToEndFound;
}

bool Puzzle::findPathThroughPuzzle(){
    //TODO
    if(vertices.size() > 0)
    {
        for(int u=0; u<vertices.size(); u++)
        {       // make sure vertex at 0,0 exists in vertices
            if(vertices[u]->vertexNum == 0)
            {
                cout << "Starting at vertex: 0" << endl;
                return DFT(vertices[u], path, n);
            }
                
        }
    }
    
    return false;
}












int findVIndex(int v, vector<vertex*> &vertices)
{
    for(int u=0; u<vertices.size(); u++)
        if(vertices[u]->vertexNum == v)
            return u;
    return -1;
}

bool adjFound(vertex *vert, int adjNum)
{
    for(int u=0; u<vert->adj.size(); u++)
        if(vert->adj[u].v->vertexNum == adjNum)
            return true;
    return false;
}

bool Puzzle::checkIfValidPath()
{
    if(path.size() == 0)
        return false;
    if(path[0] != 0)
        return false;
    if(path[path.size()-1] != (n*n)-1)
        return false;
    
    vertex *currV;
    bool vFound = false;
    int index = 0;
   
    for(int u=0; u<path.size()-1; u++)   // NOTE: (size - 1) because last in path not connected to anything ahead
    {
        index = findVIndex(path[u], vertices);
        if(index > -1)
        {
            currV = vertices[index];
            if(!adjFound(currV, path[u+1]))
                return false;
        }
    }

    return true;    // congradulations the gauntlet of tests was passes
}





// funny this doesnt need to be built hehe
Puzzle::~Puzzle(){
    // refrence code?

    /*
    if (n > 0){
        for(int i = 0; i < n; i++){
            delete[] puzzle[i];
        }
        delete[] puzzle;
    }
    for (unsigned int i = 0; i< vertices.size(); i++){
        delete vertices[i]; 
    }
    */
    
    
}
