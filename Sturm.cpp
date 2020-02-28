#include "Sturm_types.cpp"
#include "division_rosetta.cpp"

#include <utility>
#include <vector>
using namespace std;


Sturm_chain construct_Sturm_chain(Poly P) {
    Sturm_chain Sturm_chain;
    Poly remainder;


    Sturm_chain.push_back(P);
    Sturm_chain.push_back(
        derivative(P.first)
    );


    double i = 1;
    while(
        Sturm_chain.back().second != 0 &&
        i < P.first.size() + 3    // for dev purposes to avoid endless while
    ) {
        remainder = divide_polynom_A_by_polynom_B(
            Sturm_chain.rbegin()[1],
            Sturm_chain.rbegin()[0]
        ).second;
        unary_minus(remainder.first);
        Sturm_chain.push_back( remainder );
        i++;
    }
    
    for(Poly_plus item: Sturm_chain){
        Print('P', item.first);
    }
    return Sturm_chain;
}


/*
Sturm_vector construct_Sturm_vector(Sturm_chain Sturm_chain, double x){
    Sturm_vector Sturm_vector;
    for (Poly_plus item: Sturm_chain){
        Sturm_vector.push_back(
            substitute(Poly_plus.first, x)
        );
    }
    return Sturm_vector;
}
*/


int count_transpositions(Sturm_vector Sturm_vector) {
    int counter = 0;
    for(int i = 1; i < Sturm_vector.size(); i++) {
        if (Sturm_vector[i] * Sturm_vector[i - 1] < 0){
            counter = counter + 1;
        }
    }
    return counter;
}


/*
 * https://www.codespeedy.com/cpp-program-to-implement-bisection-method/
 */
vector<double> find_roots(Sturm_chain Sturm_chain, pair<double, double> boundaries, double threshold){
    double a = boundaries.first, b = boundaries.second;
    double t = threshold;

    vector <Sturm_vector> Sturm_collection;
    /*
    while(!all_roots_are_located()){

    }

    while ( (b - a) > t ) {

    }
    */

}