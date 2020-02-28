#pragma once

#include "polynomials_types.cpp"


Poly derivative(vector<double> P){
    vector<double> dP;
    double new_term;
    int i = P.size() - 1;
    for(double term: P) {
        dP.push_back(term * i);
        i--;
    }
    return dP;
}


int get_degree(Poly P){
    int i = P.size() - 1;
    while(
        P[i] == 0 && // count last zeros
        i > 0   // situation of zero vector handling
    ) {
        i--;
    }

    return i;
}


Poly unary_minus(Poly V){
    Poly W(V.size());
    transform(
        V.begin(),
        V.end(),
        W.begin(),
        [](double &item){return -item;}
    );
    return W;
}


