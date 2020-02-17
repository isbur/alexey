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


/*
void divide_polynom_A_by_polynom_B(A, B){

}
*/

/*
void construct_Sturm_chain(vector<double> P) {
    vector <vector <double> > Sturm_chain;
    Sturm_chain.push_back(P);
    Sturm_chain.push_back( derivative(P) );
    double i = 2;
    while(new_polynom != 1){
        new_polynom = divide_polynom_A_by_polynom_B(P[i-1], P[i]);
        i++;
    }
}
*/
