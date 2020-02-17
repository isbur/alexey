#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "single_include/catch.hpp"


#include "io.cpp"
TEST_CASE( "Data are read", "[data]" ) {

    ofstream output_file;
    
    vector <string> contents{
        "0.01",
        "-1 1",
        "1, -3, 2"  // (x-1)*(x-2)
    };

    for(vector <string> :: iterator it = begin(contents); it != end(contents); it++){

    }

/*
    REQUIRE( Factorial(1) == 1 );
    REQUIRE( Factorial(2) == 2 );
    REQUIRE( Factorial(3) == 6 );
    REQUIRE( Factorial(10) == 3628800 );
    */
}