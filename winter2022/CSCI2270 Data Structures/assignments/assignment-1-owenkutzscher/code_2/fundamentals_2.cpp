#include "fundamentals_2.hpp"



string calcEmissionZone(double avg) {
    // TODO

    string returnVal = "";

    if(avg >= 10.0){
        returnVal = "RED";
    }else if(avg >= 5.0 && avg < 10.0){
        returnVal = "ORANGE";
    }else if(avg >= 2.5 && avg < 5.0){
        returnVal = "YELLOW";
    }else{
        returnVal = "GREEN";
    }

    


    return returnVal;
}







void insertEmissionInfo(emissionInfo co2_emissions[], 
string countryName, double emission_in_2015, 
double emission_in_2016, double emission_in_2017, 
double emission_in_2018, double emission_in_2019, 
int index) {
    // TODO
    
    
    
    // make a local emmissionInfo struct
    emissionInfo tempEmissionInfo;
    tempEmissionInfo.countryName = countryName;
    tempEmissionInfo.emission_in_2015 = emission_in_2015;
    tempEmissionInfo.emission_in_2016 = emission_in_2016;
    tempEmissionInfo.emission_in_2017 = emission_in_2017;
    tempEmissionInfo.emission_in_2018 = emission_in_2018;
    tempEmissionInfo.emission_in_2019 = emission_in_2019;

    
    tempEmissionInfo.average = 
    (emission_in_2015 + emission_in_2016 + 
    emission_in_2017 + emission_in_2018 + 
    emission_in_2019) / 5 ;

    co2_emissions[index] = tempEmissionInfo;    
    

    return;
}