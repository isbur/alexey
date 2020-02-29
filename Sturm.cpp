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
        derivative(P)
    );


    double i = 1;
    while(
        get_degree(Sturm_chain.back()) != 0 &&
        i < P.size() + 3    // for dev purposes to avoid endless while
    ) {
        remainder = divide_polynom_A_by_polynom_B(
            Sturm_chain.rbegin()[1],
            Sturm_chain.rbegin()[0]
        ).second;
        
        Sturm_chain.push_back( 
            unary_minus(remainder)
        );
        i++;
    }
    
    for(Poly item: Sturm_chain){
        Print('P', item);
    }
    return Sturm_chain;
}


Sturm_vector construct_Sturm_vector(Sturm_chain Sturm_chain, double x){
    Sturm_vector Sturm_vector;
    for (Poly item: Sturm_chain){
        Sturm_vector.push_back(
            substitute(item, x)
        );
    }
    return Sturm_vector;
}




int result_of_some_investigations(Sturm_vector Sturm_vector, int i);


int count_transpositions(Sturm_vector Sturm_vector) {
    int counter = 0;
    for(int i = 1; i < Sturm_vector.size(); i++) {
        double product = Sturm_vector[i] * Sturm_vector[i - 1];
        if (product < 0){
            counter = counter + 1;
        } else {
            if (product == 0) {
                counter = counter + result_of_some_investigations(Sturm_vector, i);
            }
        }
    }
    return counter;
}


int result_of_some_investigations(Sturm_vector Sturm_vector, int i){
    if (Sturm_vector[i] == 0) {
        return 0;
    } else {
        int j = i - 1;
        while (Sturm_vector[j] == 0 && j > 0){   // find first non-zero
            j--;
        }
        if (Sturm_vector[i] * Sturm_vector[j] < 0) {
            return 1;
        } else {
            return 0;
        }
    }
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