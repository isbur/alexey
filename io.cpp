#include <fstream>
#include <utility>
#include <vector>
using namespace std;
#include "split_string.cpp"

int read_data(double &t, pair <double, double> &boundaries, vector <vector <double> > &Polynomials){

    ifstream input_file;

    string s;

    vector<string> polynomial_string;
    vector<double> polynomial;


    input_file.open("input.txt");

    // read_accuracy()
    getline(input_file, s);
    stringstream ss1(s);
    ss1 >> t;
    // read_interval_boundaries();
    getline(input_file, s);
    stringstream ss2(s);
    ss2 >> boundaries.first >> boundaries.second;
    // read_coefficients();
    while(getline(input_file, s)){
        // split string
        split(s, polynomial_string);
        // transform to vector of doubles

        transform(
            polynomial_string.begin(),
            polynomial_string.end(),
            back_inserter(polynomial),
            [](string &str){return stod(str);}
        );

        Polynomials.push_back(polynomial);
    }


    input_file.close();

    return 0;
}