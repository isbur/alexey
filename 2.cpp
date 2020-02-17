#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
using namespace std;
//#include "Sturm.cpp"


int read_data(double &t, pair <double, double> &boundaries, vector <vector <int> > &Polynomials);


int main() {
    
    double t;
    pair <double, double> boundaries;
    vector < vector <int> > Polynomials;

    read_data(t, boundaries, Polynomials); 


    //construct_Sturm_chain(Coefficients);

    return(0);
}


int read_data(double &t, pair <double, double> &boundaries, vector <vector <int> > &Polynomials){

    ifstream input_file;


    input_file.open("input.txt");

    // read_accuracy()
    input_file >> t;
    // read_interval_boundaries();
    input_file >> boundaries.first >> boundaries.second;
    // read_coefficients();


    input_file.close();

    return 0;
}