void derivative(){

}

void divide_polynom_A_by_polynom_B(A, B){

}

void construct_Sturm_chain(polynom P) {
    P_0 = P;
    P_1 = derivative(P);
    while(new_polynom != 1){
        new_polynom = divide_polynom_A_by_polynom_B(P_i, P_i+1);
    }
}