#include <vector>
using namespace std;

#include "Sturm.cpp"


bool all_roots_are_located(vector <int> Sturm_collection);
double find_single_root(Poly P, double a, double b, double t);
/*
 * https://www.codespeedy.com/cpp-program-to-implement-bisection-method/
 */
vector<double> find_roots(Sturm_chain Sturm_chain, pair<double, double> boundaries, double threshold){

    cout << endl << "Inside find_roots(...)" << endl;
    Print(Sturm_chain[0]);

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
    int total_number_of_roots_on_given_interval = Sturm_collection[0] - Sturm_collection[1];

    cout << "Total number of roots on given interval:" << endl << total_number_of_roots_on_given_interval << endl;
    
    
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


    cout << "Sturm_collection: " << endl;
    Print(Sturm_collection);
    for (int i = 1; i < Sturm_collection.size(); i++){
        if( Sturm_collection[i] - Sturm_collection[i - 1] == -1 ) {
            double root = find_single_root(Sturm_chain[0], Points[i-1], Points[i], threshold);
            cout << "Root: " << root << endl;
            Roots.push_back(root);
        }
    }

    return Roots;
}


bool all_roots_are_located(vector <int> Sturm_collection) {
    for (int i = 1; i < Sturm_collection.size(); i++){
        if ( Sturm_collection[i] - Sturm_collection[i - 1] < -1 ) {
            return false;
        }
    }

    cout << "Current Strum collection:" << endl;
    Print(Sturm_collection);
    
    return true;
}


// Assume there really is a root?
double find_single_root(Poly P, double a, double b, double t) {
    double c;
    double P_a, P_b, P_c;
    //int i = 0;
    while (
        b - a > t / 2//&&
        //i < 5
    ) {
        
        c = (a + b) / 2;

        /*
        cout << "Points:" << endl;
        cout << a << " " << b << " " << c << endl;
        */

        P_a = substitute(P, a);
        P_b = substitute(P, b);
        P_c = substitute(P, c);
        if (P_a * P_c <= 0){
            b = c;
        } else {
            a = c;
        }
        
        /*
        cout << "Values:" << endl;
        cout << P_a << " " << P_b << " " << P_c << endl;
        cout << endl << endl;
        */

        //i++;
    }
    return a;
}