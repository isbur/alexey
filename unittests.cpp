#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "single_include/catch.hpp"

#include<iostream>
#include<fstream>

#include "io.cpp"
TEST_CASE( "Data are read", "[data]" ) {

    /*
     * Preparing input file
     */
    ofstream output_file;
    
    vector <string> contents{
        "0.01",
        "-1 1",
        "1 -3 2"  // (x-1)*(x-2)
    };

    output_file.open("input.txt");
    for(vector <string> :: iterator it = begin(contents); it != end(contents); it++){
        output_file << *it << "\n";
    }
    output_file.close();
    /*
     * Preparing for test
     */
    double t;
    pair <double, double> boundaries;
    vector < vector <double> > Polynomials;
    read_data(t, boundaries, Polynomials); 

    REQUIRE(t == 0.01);
    REQUIRE(boundaries == pair<double, double>{-1, 1});
    REQUIRE(Polynomials == vector <vector <double> >{
        vector<double>{1, -3, 2}
    });
}


#include "split_string.cpp"
TEST_CASE( "String is split", "[stov]" ) {
    string s = "1 2 1";
    vector<string> polynomial_string;
    split(s, polynomial_string);
    REQUIRE(polynomial_string == vector<string>{"1", "2", "1"});
}


TEST_CASE( "Getline() function exploration", "[glexp]") {
    ifstream input_file;
    string s, test_string;
    stringstream ss;
    double t, d1, d2;

    /*
    input_file.open("input.txt");
    getline(input_file, s);
    REQUIRE(s == "0.01");
    ss << s;
    ss >> test_string;
    REQUIRE(test_string == "0.01");
    ss << s;
    ss >> setprecision(5) >> t;
    REQUIRE(t == 0.01);
    

    getline(input_file, s);
    REQUIRE(s == "-1 1");
    //ss << s;
    ss >> d1 >> d2;
    REQUIRE(d1 == -1);
    REQUIRE(d1 == 1);
    */
    
    input_file.close();
}