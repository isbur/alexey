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


int get_degree(vector<double> P){
    int i = P.size() - 1;
    while(P[i] == 0) {

        i--;
    }

    return i;
}


double unary_minus_for_items(double item){
    return -item;
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


vector <vector <double> > construct_Sturm_chain(vector<double> P) {
    vector <vector <double> > Sturm_chain;
    vector<double> remainder;
    vector<double> zero_vector(P.size());


    

    Sturm_chain.push_back(P);
    Sturm_chain.push_back( derivative(P) );
    double i = 1;
    while(
        Sturm_chain[i] != vector<double>(Sturm_chain[i].size()) &&
         i < P.size() + 3
    ) {
        remainder = divide_polynom_A_by_polynom_B(
            Sturm_chain[i-1], 
            Sturm_chain[i],
            get_degree(Sturm_chain[i-1]),
            get_degree(Sturm_chain[i])
        ).second;
        unary_minus(remainder);
        Sturm_chain.push_back( remainder );
        i++;
    }
    
    return Sturm_chain;
}

