#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "single_include/catch.hpp"


#include "io.cpp"
TEST_CASE( "Data are read", "[data]" ) {

    /*
     * Preparing input file
     */
    ofstream output_file;
    
    vector <string> contents{
        "0.01",
        "-1 1",
        "1, -3, 2"  // (x-1)*(x-2)
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
    vector < vector <int> > Polynomials;
    read_data(t, boundaries, Polynomials); 

    REQUIRE(t == 0.01);
    REQUIRE(boundaries == pair<double, double>{-1, 1});
    //REQUIRE(t, contents[0]);
}