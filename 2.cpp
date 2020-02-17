#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
using namespace std;

#include "io.cpp"
//#include "Sturm.cpp"


int main() {
    
    double t;
    pair <double, double> boundaries;
    vector < vector <int> > Polynomials;

    read_data(t, boundaries, Polynomials); 


    //construct_Sturm_chain(Coefficients);

    return(0);
}
