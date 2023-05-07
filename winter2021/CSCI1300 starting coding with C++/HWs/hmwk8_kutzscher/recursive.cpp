//CSCI 1300 
//Author: Owen Kutzscher
//Recitation 117 - Naga Sai Meenakshi Sistla
//Project 3 - Player Class

/*


pre pseudo code:

try out recursion on simply printing a vector
investegate how to do it

then try making a recursive function to add 1 to a total till we reach a number, then return the total

then from there we can solve the problem with probably somewhat reletive ease




pseudo code

fillCumulativeSumRECURSIVE!!!
its actually the same as the iterative guy ngl. I just used a funcion
 with recursion wherever theres a function wherever a loop exists!

if the input is less than 0 print invalid input
    idk what they mean by "invalid input" so we'll figure 
    that one out later

find sum of guys in the vector rn
    make that its own funciton
if the cumulative sum is less than N
    insert sum into the end of the vector
    repeat finding the sum
else, stop

print out the vector

*/




#include <vector>
#include <iostream>
#include <cstring>
using namespace std;

void fillCumulativeSumRecursive();
int addEmUp();
void printStuff();
vector<int> shoveGuysIn();





void printStuff(vector<int> v, int index){

    if(index == v.size()){
        return;
    }else{
        cout << v.at(index) << " ";
        printStuff(v, index+1);
    }

    
}


int addEmUp(vector<int> v, int index, int total){
    int returnGuy = total;


    if(index == v.size()){
        return returnGuy;
    }else{
        total += v.at(index);
        returnGuy = addEmUp(v, index + 1, total);
        return returnGuy;
    }
}

vector<int> shoveGuysIn(vector<int> v, int N){
    

    int sum = addEmUp(v,0,0);

    vector<int> newV;

    if(sum >= N){
        //we're done
        //cout << "returned: ";
        //printStuff(v, 0);
        return v;
    }else{
        v.push_back(sum);
        newV = shoveGuysIn(v, N);
        return newV;
    }
}




void fillCumulativeSumRecursive(int N){
    


    //vector<int> testerV = {1, 2, 3, 5};


    // if the input is less than 0 print invalid input
    if(N < 0){
        cout << "Invalid input." << endl;
    }else{
        
        vector<int> v = {1};

        vector<int> finalV;

        finalV = shoveGuysIn(v, N);

        //cout << "went though..." << endl;

        printStuff(finalV, 0);
        cout << endl;
    }



    //int total = addEmUp(testerV, 0, 0);
    //cout << "total is: " << total << endl;

    //printStuff(testerV, 0);
    //cout << endl;
}


int main(){

    int N = 4;
    fillCumulativeSumIterative(9);
    

    return 0;
}