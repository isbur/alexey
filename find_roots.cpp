#include <vector>
using namespace std;

#include "Sturm.cpp"


bool all_roots_are_located(vector <int> Sturm_collection);
double find_single_root(Poly P, double a, double b, double t);
/*
 * https://www.codespeedy.com/cpp-program-to-implement-bisection-method/
 */
vector<double> find_roots(Sturm_chain Sturm_chain, pair<double, double> boundaries, double threshold){
    double a = boundaries.first, b = boundaries.second;
    double t = threshold;

    vector <int> Sturm_collection;
    vector <double> Points;

    vector <double> Roots;


    Sturm_collection.push_back(
        get_Sturm_number(Sturm_chain, a)
    );
    Points.push_back(a);
    Sturm_collection.push_back(
        get_Sturm_number(Sturm_chain, b)
    );
    Points.push_back(b);


    if (Sturm_collection[0] == Sturm_collection[1]) {
        return vector <double> {};
    }
    int total_number_of_roots = Sturm_collection[0] - Sturm_collection[1];
    
    
    while(!all_roots_are_located(Sturm_collection)){
        int i = 1;
        while (Sturm_collection[i] - Sturm_collection[i - 1] > -2) {    // not very effective but quick to write
            Points.insert(
                Points.begin()+i,
                (Points[i] + Points[i - 1]) / 2
            );
            Sturm_collection.insert(
                Sturm_collection.begin()+i,
                get_Sturm_number(Sturm_chain, Points[i])    // new point
            );
        }
    }


    int j = 1;
    for (int i = total_number_of_roots; i > -1 ; i--) {
        do j++;
        while ( Sturm_collection[j] == Sturm_collection[j - 1] && j < Sturm_collection.size() );
        Roots.push_back(
            find_single_root(Sturm_chain[0], Points[j-1], Points[j], threshold)
        );
    }

    return Roots;
}


bool all_roots_are_located(vector <int> Sturm_collection) {
    for (int i = 1; i < Sturm_collection.size(); i++){
        if ( Sturm_collection[i] - Sturm_collection[i - 1] < -1 ) {
            return false;
        }
    }
    return true;
}


double find_single_root(Poly P, double a, double b, double t) {
    double c;
    double P_a, P_b, P_c;
    //int i = 0;
    while (
        b - a > t //&&
        //i < 5
    ) {
        
        c = (a + b) / 2;
        cout << "Points:" << endl;
        cout << a << " " << b << " " << c << endl;

        P_a = substitute(P, a);
        P_b = substitute(P, b);
        P_c = substitute(P, c);
        if (P_a * P_c <= 0){
            b = c;
        } else {
            a = c;
        }
        
        cout << "Values:" << endl;
        cout << P_a << " " << P_b << " " << P_c << endl;
        cout << endl << endl;

        //i++;
    }
    return a;
}