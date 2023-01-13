//CSCI 1300 
//Author: Owen Kutzscher
//Recitation 117 - Naga Sai Meenakshi Sistla
//Practicum 3

#include <iomanip>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <time.h>
#include <array>
#include <iostream>



//#include "Movie.h"

using namespace std;






class Movie{

    public:
    //deafult constuctors
    Movie();
    //paramaterizzed deafult constructor
    Movie(string, string, int);

    //getters

    string getTitle();
    string getStudio();
    int getTickets();

    //setters

    void setTitle(string);
    void setStudio(string);
    void setTickets(int);

    //any other guys

    double grossRevenue(double);




    private:

    string title;
    string studio;
    int tickets;

};







//////////////////////////////////////////////////
////////////////////////////////////////////


//default constructors
Movie::Movie(){
    //initializes all stats
    //ex: zombieDamage = 1;
    title = "";
    studio = "";
    tickets = 0;
    
}
Movie::Movie(string tit, string sut, int tic){
    //sets some guys to be initialized
    title = tit;
    studio = sut;
    tickets = tic;
}


//getters

string Movie::getTitle(){
    return title;
}
string Movie::getStudio(){
    return studio;
}
int Movie::getTickets(){
    return tickets;
}



//setters

void Movie::setTitle(string tit){
    title = tit;
}
void Movie::setStudio(string stu){
    studio = stu;
}
void Movie::setTickets(int tic){
    tickets = tic;
}


//other

double Movie::grossRevenue(double price){
    int revenue;
    revenue = ((1.00)*price) * ((1.00)*tickets);
    return revenue;
}


