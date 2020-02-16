#include "Sturm.cpp"


int main() {
    t = read_accuracy();
    [d1, d2] = read_interval_boundaries();
    Coefficients = read_coefficients();


    construct_Sturm_chain(Coefficients);

    return(0);
}