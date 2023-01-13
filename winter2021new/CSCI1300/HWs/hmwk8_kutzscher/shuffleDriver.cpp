//CSCI 1300 
//Author: Owen Kutzscher
//Recitation 117 - Naga Sai Meenakshi Sistla
//Project 3 - Player Class

/*

pseudo code

schuffle

takes 2 vectors int values

returns a vector of int vals

alternate shoving vals into the new vec, starting from vec 2
if we reach  the end of a vector then just stop shoving in its vals
and continue shoving in the other one

we'll do this by making a while loop. It will have an "even or odd"
index that decides to add in v2 or v1.
it'll also have 2 idex variables, one for each vector
lastly, if we are at the end of the vector then don't
add anything from it

if the vectors entered are the same size, then turn on the switch variable, 
which switches if were looking for % 2 or !%2

*/




#include <vector>
#include <iostream>
#include <cstring>
using namespace std;

vector<int> shuffle();




vector<int> shuffle(vector<int> v1, vector<int> v2){
    vector<int> vReturn;

    // alternate shoving vals into the new vec, starting from vec 2
    // if we reach  the end of a vector then just stop shoving in its vals
    // and continue shoving in the other one

    //we'll do this by making a while loop. It will have an "even or odd"
    // index that decides to add in v2 or v1.
    //it'll also have 2 idex variables, one for each vector
    //lastly, if we are at the end of the vector then don't
    // add anything from it

    int totalV12Size = v1.size() + v2.size();

    //used to keep track of where were inserting things into v1 and v2
    int v1Index = 0;
    int v2Index = 0;

    //cout << "total size of both of em is: " << totalV12Size << endl;

    // if the vectors entered are the same size, then turn on the switch variable, 
    //  which switches if were looking for % 2 or !%2
    bool switchEm = 0;

    if(v1.size() == v2.size()){
        switchEm = 1;
    }


    int index = 0;
    while(index < totalV12Size){

        //cout << "looped through a time" << endl;

        if(switchEm == 1){
            if(!( index % 2 == 0 )){
                //if were on the first index or alternating, then do v2

                //check if we finished looking at v2 tho
                if(v2.size() <= v2Index){
                    //index--;
                    totalV12Size++;
                }else{
                    vReturn.push_back( v2.at(   (v2.size() - v2Index)-1   ));
                    v2Index++;
                }
                
            }else{
                //we wanna do v1

                //check if we finished looking at v1 tho
                if(v1.size() <= v1Index){
                    //index--;
                    totalV12Size++;
                }else{
                    vReturn.push_back(v1.at(   (v1.size() - v1Index)-1   ));
                    v1Index++;
                }
            }

            index++;

        }else{

        
            if(index % 2 == 0){
                //if were on the first index or alternating, then do v2

                //check if we finished looking at v2 tho
                if(v2.size() <= v2Index){
                    //index--;
                    totalV12Size++;
                }else{
                    vReturn.push_back( v2.at(   (v2.size() - v2Index)-1   ));
                    v2Index++;
                }
                
            }else{
                //we wanna do v1

                //check if we finished looking at v1 tho
                if(v1.size() <= v1Index){
                    //index--;
                    totalV12Size++;
                }else{
                    vReturn.push_back(v1.at(   (v1.size() - v1Index)-1   ));
                    v1Index++;
                }
            }

            index++;
        }
    }


    return vReturn;
}




int main(){

    // example 1
    vector<int> v1{6, 5, 99, 125};
    vector<int> v2{1, 3, 69, 45};
    vector<int> v3 = shuffle(v1,v2);
    for (int i=0; i < v3.size(); i++) {
        cout << v3[i] << " ";
    }

    return 0;
}