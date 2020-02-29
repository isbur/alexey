#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
using namespace std;

#include "polynomials.cpp"
#include "io.cpp"
#include "Sturm.cpp"


int main() {
    
    double t;
    pair <double, double> boundaries;
    vector <Poly> Polynomials;
    Sturm_chain Sturm_chain;
    Sturm_vector Sturm_vector;
    

    read_data(t, boundaries, Polynomials); 

    for (Poly item: Polynomials) {
        Sturm_chain = construct_Sturm_chain(Poly_plus{item, get_degree(item)});
        Sturm_vector = construct_Sturm_vector()
    }


    return(0);
}
