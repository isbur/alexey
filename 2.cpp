#include <iostream>
#include <fstream>
using namespace std;
#include "Sturm.cpp"


int main() {
    ifstream input_file;
    double t, d1, d2;
    double* Coefficients;

    input_file.open("input.txt");
    // read_accuracy()
    input_file >> t;
    // read_interval_boundaries();
    input_file >> d1 >> d2;
    // read_coefficients();
    Coefficients = 


    construct_Sturm_chain(Coefficients);

    return(0);
}