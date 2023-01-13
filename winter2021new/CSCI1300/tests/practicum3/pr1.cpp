//CSCI 1300 
//Author: Owen Kutzscher
//Recitation 117 - Naga Sai Meenakshi Sistla
//Practicum 3

//pre proscessor
//#ifndef FARM_H
//#define FARM_H


#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std; 




class Farm{

    public:
    //deafult constuctors
    Farm();
    //paramaterizzed deafult constructor
    Farm(string);

    //getters
    string getFarmerName();
    vector<double> getAcreage();
    vector<string> getCrops();

    //setters
    void setFarmerName(string);
    void setAcreage(vector<double>);
    void setCrops(vector<string>);

    //any other guys
    bool AddCrop(double, string);

    double ComputeAverage();

    int CountCrops(double);

    int CountSameCrops(string);




    private:
    //ex: int zombieDamage;
    //if we dont want it to change: 
    //ex: static const int maxZombieHealth = 20;

    string farmerName;
    vector<double> acreage;
    vector<string> crops;

};

#endif





