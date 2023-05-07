//CSCI1300 Fall 2021
//Author: Owen Kutzscher
//Recitation: 117? - N. Sistla
//Project 1 - Problem 4

//pseudo code:
/*

function
    real quick, if the lengths are different, then send back -1
    
        first find num cards with the same suit
            look at ony the odd charicters (1st 3rd ...)
            loop through, for each odd # compare them

        next find num cards with same suit and rank
            look at ony the even charicters (1st 3rd ...) because strigns start at 0
            loop through, for each odd # compare them
                if they are the same suit, then compare the next number i+1
                if that is the same then cool

        calculate score
            ((numSameSuit) / nmCards) + (1 * numCardsSameSuitSameRank)
    
    return score


*/


#include <iostream>
using namespace std;

double calcLikenessScore(string seq1, string seq2){
    //this will be our return value
    double likenessScore = 0.0;

    if(seq1.length() != seq2.length()){
        likenessScore = -1;
    }else{

        //first find num cards with the same suit
        double numSameSuit = 0.0;
        //look at ony the even charicters (1st 3rd ...) strings startt at 0
        for(int i = 0; i < seq1.length(); i++){
            //cout << "I'm checkign for i= " << i << endl;

            //if they are the even characters, then they are a suit
            //it should be odd, but strings start indexing at 0
            if(i%2 == 0){
                
                //if the suits are the same, add 1 to numSameSuit
                if(seq1.substr(i, 1) == seq2.substr(i,1)){
                    //cout << "ayy we found a same suit!" << endl;
                    //cout << "it is: " << seq1.substr(i, 1) << endl;
                    numSameSuit++;
                }
            }
        }

        double numSameSuitAndRank = 0.0;

        //next find num cards with same suit AND rank
        for(int i = 0; i < seq1.length(); i++){

            //if they are the even characters, then they are a suit
            //it should be odd, but strings start indexing at 0
            if(i%2 == 0){
                
                //if the suits are the same keep going
                if(seq1.substr(i, 1) == seq2.substr(i,1)){
                    
                    //if they are the same suit, then compare the next number i+1
                    if(seq1.substr(i+1, 1) == seq2.substr(i+1,1)){
                        //cout <<"ayy this is the first one im checking: " << (seq1.substr(i+1, 1)) << endl;
                        //cout <<"ayy this is the second one im checking: " << (seq2.substr(i+1, 1)) << endl;
                        numSameSuitAndRank++;
                    }
                }
            }
        }
        
        //well, this is the number of cards
        double numCards = seq1.length() / 2;

        //cout << "numSameSuit: " << numSameSuit << endl;
        //cout << "numCards: " << numCards << endl;
        //cout << "numSameSuitAndRank: " << numSameSuitAndRank << endl;


        //calculate score
        likenessScore = (numSameSuit/numCards) + (1 * numSameSuitAndRank);

    
    }

    
    //ughhh ok make it look like 0.00 
    
    
    return likenessScore;
}


int main(){
    
    //string uno = "C4DTSK";
    //string dos = "C4DJSK";

    string uno = "HQDASJ";
    string dos = "DAD8SJ";

    cout << "entering the first set of stuff, should return something" << endl;
    cout << calcLikenessScore(uno, dos) << endl;

    
    

    return 0;
}