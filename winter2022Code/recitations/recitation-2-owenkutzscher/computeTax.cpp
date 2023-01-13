#include <iostream>
#include <string>

#include "taxinfo.hpp"

using namespace std;

int main(int argc, char *argv[]) {

    if (argc < 3){
        cout << "missing command line arguments" << endl;
        return -1;
    }

    /* TODO 2: Collect salary "inSalary" and tax rate "inTaxRate" from command line arguments
    *float inSalary = ...
    *float inTaxRate = ...
    */

   float inSalary = stof(argv[1]);
   float inTaxRate = stof(argv[2]);



    /* TODO 3: Assign data to TaxInfo variable
    *TaxInfo taxCalc;
    * ...
    */

   TaxInfo taxCalc;
   taxCalc.salary = inSalary;
   taxCalc.taxRate = inTaxRate;


    /* TODO 4: Compute Tax using only pointer access
    * ...
    */

   float tax = 0;

   TaxInfo *taxInfoPtr = &taxCalc;

   tax = ((*taxInfoPtr).salary) / (taxInfoPtr -> taxRate);

   float *taxPtr = &tax;

    /* TODO 5: Print salary, tax rate, and tax.
    * ...
    */

   cout << "The salary is : " << (*taxInfoPtr).salary << endl;
   cout << "The tax rate is : " << taxInfoPtr -> taxRate << endl;
   cout << "The tax incurred is : " << *taxPtr << endl;


   ////ayyyy lets go I liked this recitation a lot more than the last. 
   // and I feel like I learned abt pointers

   
 
   return 0;
}
