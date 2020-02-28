#pragma once

#include "polynomials_types.cpp"

#include <cmath>


Poly derivative(Poly P){
    Poly dP;
    int i = P.size() - 1;
    for(double term: P) {
        dP.push_back(term * i);
        i--;
    }
    dP.pop_back();
    return dP;
}


int get_degree(Poly P){
    return P.size() - 1;
}


double substitute(Poly P, double x){
    double answer = 0;
    for(int i = 0; i < P.size(); i++){
        answer = answer + pow(x, i) * P[P.size()-(i+1)];
    }
    return answer;
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


