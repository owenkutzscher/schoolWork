//CSCI1300 Fall 2021
//Author: Owen Kutzscher
//Recitation: 117? - N. Sistla
//Project 1 - Problem 6

//pseudo code:
/*

function
    calculate the likenessScores for each person
    depending on their scores, print different responses



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


void findWinner(string seq1, string seq2, string seq3, string goldSeq){
    //calculate the likenessScores for each person

    //first lets make some variables to assign these guys to
    //Likness Score # of player 
    double LS1 = 0.0;
    double LS2 = 0.0;
    double LS3 = 0.0;

    //now lets actually calculate and assign the likeness scores

    LS1 = bestLikenessScore(seq1, goldSeq);
    LS2 = bestLikenessScore(seq2, goldSeq);
    LS3 = bestLikenessScore(seq3, goldSeq);

    //cout << "aight, here are the scores goint 1 2 3: " << endl;
    //cout << LS1 << endl;
    //cout << LS2 << endl;
    //cout << LS3 << endl;


    //depending on their scores, print different responses

    
    if(LS1 == 0 && LS2 == 0 && LS3 == 0){
        //first, if they all got a score of zero...
        cout << "Better luck next time everyone!" << endl;
    }else if(LS1 == LS2 && LS2 == LS3){
        //if they all have the same score...
        cout << "Congratulations everyone! You have all won!" << endl;
    }else if(LS1 == LS2 || LS2 == LS3 || LS1 == LS3){
        //if two of em have the same score...
        //hold up, we need to figure out which two have the same score

        int sameScoreA = 0;
        int sameScoreB = 0;

        //now lets assign those variables, and do a print stament with the two players
        if(LS1 == LS2){
            sameScoreA = 1;
            sameScoreB = 2;
        }else if(LS2 == LS3){
            sameScoreA = 2;
            sameScoreB = 3;
        }else{
            sameScoreA = 1;
            sameScoreB = 3;
        }

        cout << "Congratulations Players " << sameScoreA
        << " and " << sameScoreB << "! You have won!" << endl;
    }else{
        //theres a clear winer

        int winner = 0;

        if(LS1 > LS2 && LS1 > LS3){
            winner = 1;
        }else if(LS2 > LS1 && LS2 > LS3){
            winner = 2;
        }else{
            winner = 3;
        }

        cout << "Congratulations Player " << winner
        << "! You have won!" << endl;

    } 
}


int main(){
    

    string uno = "H2DTHTSAS7CA";
    string dos = "D7H2SQCAH7";
    string tres = "CJDAH7C5";
    string goldSeqqq = "DTH7SA";

    //string uno = "S7H8SJD9H8CJD9";
    //string dos = "H8C6D6";

    cout << "entering the set of stuff, should print congrats p1 ya one!!" << endl;
   findWinner(uno, dos, tres, goldSeqqq);

    
    

    return 0;
}