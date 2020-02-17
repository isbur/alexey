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

void construct_Sturm_chain(vector<double> P) {
    vector<double> P_0 = P;
    vector<double> P_1 = derivative(P);
    i = 2;
    while(new_polynom != 1){
        new_polynom = divide_polynom_A_by_polynom_B(P_i, P_i+1);
        i++;
    }
}
