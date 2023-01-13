//CSCI1300 Fall 2021
//Author: Owen Kutzscher
//Recitation: 117? - N. Sistla
//Project 1 - Problem 5

//pseudo code:
/*

function
    go though seq1 and go through ALL substrings
        compare to the golden sequence
        if its better than the last best score, save as the best



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



double bestLikenessScore(string seq1, string goldSeq){
    //were gunna calulate the best possible likeness score
    //the best one wwill be the variable below, that's what we will return
    double bestLikenessScore = 0.0;

    
    //first lets make sure that seq1 is longer than or the same
    //lenght as the goldenSeq
    if(seq1.length() < goldSeq.length()){
        bestLikenessScore = -1;
    }else{

        //lets loop though seq1 and go through ALL substrings that are
        //the same length as the golden sequence
        //well actually were going to be a little lazyier
        //were going to just go  though in order 
        
        //this temp score we will use to compare two scores
        double tempScore = 0.0;
        //this tempSeq we will use to take a specific seq out of
        //seq1
        string tempSeq = " ";
        
        for(int i = 0; i < (seq1.length() - goldSeq.length()) + 1; i++){
            int GSLength = goldSeq.length();
            
            //cout << "seq1 test is: " << seq1.substr(i, GSLength) << endl;
            
            //now that weve got a sequence to compare to the golden one
            //lets comepare them
            tempSeq = seq1.substr(i, GSLength);
            tempScore = calcLikenessScore(tempSeq, goldSeq);

            //cout << "tempScore: " << tempScore << endl;

            if(tempScore > bestLikenessScore){
                bestLikenessScore = tempScore;
            }
            

        }

            
    }
    
    



    return bestLikenessScore;
}





int main(){
    

    string uno = "S7H8SJD9H8CJD9";
    string dos = "H8C6D6";

    //string uno = "S7H8SJD9H8CJD9";
    //string dos = "H8C6D6";

    cout << "entering the first set of stuff, should return 2" << endl;
    cout << bestLikenessScore(uno, dos) << endl;

    
    

    return 0;
}