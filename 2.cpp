#include <iostream>
#include <fstream>
#include <utility>
using namespace std;
#include "Sturm.cpp"


int read_data(double* t, pair <double, double>* boundaries, polynomial <double>** P);


int main() {
    
    double t;
    pair <double, double> boundaries;
    polynomial <double>* Polynomials;

    read_data(&t, &boundaries, &Polynomials); 


    construct_Sturm_chain(Coefficients);

    return(0);
}


int read_data(double* t, pair <double, double>* boundaries, polynomial <double>** Polynomials){

    ifstream input_file;

    input_file.open("input.txt");

    // read_accuracy()
    input_file >> *t;
    // read_interval_boundaries();
    input_file >> *d1 >> *d2;
    // read_coefficients();


    input_file.close();

    return 0;
}