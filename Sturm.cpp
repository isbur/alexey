#include "division_rosetta.cpp"


vector<double> derivative(vector<double> P){
    vector<double> dP;
    double new_term;
    int i = P.size() - 1;
    for(double term: P) {
        dP.push_back(term * i);
        i--;
    }
    return dP;
}


int unary_minus(vector<double> &V){
    transform(
        V.begin(),
        V.end(),
        V.begin(),
        [](double &item){return -item;}
    );
    return 0;
}


/*
void divide_polynom_A_by_polynom_B(A, B){

}
*/


Sturm_chain construct_Sturm_chain(Poly_plus P) {
    Sturm_chain Sturm_chain;
    Poly_plus remainder;


    Sturm_chain.push_back(P);
    Sturm_chain.push_back(
        Poly_plus{derivative(P.first), P.second - 1}
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

