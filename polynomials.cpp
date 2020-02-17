#pragma once

#include "polynomials_types.cpp"


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