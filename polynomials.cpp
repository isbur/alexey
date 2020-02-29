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


/*
 * https://stackoverflow.com/a/8581865/10216512
 */
template <typename T>
inline void Print(vector <T> vec){

    std::ostringstream oss;

    if (!vec.empty())
    {
        // Convert all but the last element to avoid a trailing ","
        std::copy(vec.begin(), vec.end()-1,
            std::ostream_iterator<double>(oss, ","));

        // Now add the last element with no delimiter
        oss << vec.back();
    }

    std::cout << "(" << oss.str() << ")" << std::endl;
    
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


