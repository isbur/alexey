#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "single_include/catch.hpp"

#include<iostream>
#include<fstream>
#include<utility>

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


#include "Sturm.cpp"
TEST_CASE("Derivatives are evaluated", "[derivative]"){
    
    REQUIRE(
        derivative(vector<double>{1, -3, 2}) == 
        vector<double>{2, -3, 0}
    );
    
    REQUIRE(
        derivative(vector<double>{1, 1, 1, 1, 1, 1, 1}) == 
        vector<double>{6, 5, 4, 3, 2, 1, 0}
    );
}


TEST_CASE("Unary minus works", "[minus]"){
    vector<double> V;
    V = vector<double>{1, 2, 1};
    unary_minus(V);
    REQUIRE(
        V == vector<double>{-1, -2, -1}
    );
}


TEST_CASE("Polynomial degrees are determined correctly", "[degree]"){
    REQUIRE(
        get_degree(vector<double>{1, 2, 1}) ==
        2
    );
    REQUIRE(
        get_degree(vector<double>{1, 2, 1, 0, 0, 0, 0}) ==
        2
    );
    REQUIRE(
        get_degree(vector<double>{1, 0, 0, 0, 0, 0, 0}) ==
        0
    );
}


TEST_CASE("Sturm chain is constructed", "[Sturm]"){
    
    REQUIRE(
        construct_Sturm_chain(
            vector<double>{1, -4, 3},
            2
        ) == 
        vector<
            pair<
                vector<double>, int
            >
        > {
            pair<vector<double>, int>{
                {1, -4, 3},
                2
            },
            pair<vector<double>, int>{
                {2, -4, 0},
                1
            },
            pair<vector<double>, int>{
                {1, 0, 0},
                0
            },
        }   
    );
    
    REQUIRE(
        derivative(vector<double>{1, 1, 1, 1, 1, 1, 1}) == 
        vector<double>{6, 5, 4, 3, 2, 1, 0}
    );
}


/*
#include "division2.cpp"
TEST_CASE("Polynomials are divided", "[pd]"){
    vector<double> numerator{1, -3, 2};
    vector<double> denominator{0, 1, -1};
    dividePolynomialByPolynomial(numerator, denominator);
    REQUIRE(numerator == vector<double>{0, 1, -2});
    REQUIRE(denominator == vector<double>{0, 0, 0});
}
*/


/*
#include "division_rosetta.cpp"
TEST_CASE("Polynomials are divided", "[pd]"){

    /*=========================================
    vector<double> numerator{1, -3, 2};
    vector<double> denominator{0, 1, -1};
    divide_polynom_A_by_polynom_B(numerator, denominator);
    divide_polynom_A_by_polynom_B(
        vector<double>{2, -3, 1}, 
        vector<double>{-1, 1, 0}
    );
    divide_polynom_A_by_polynom_B(
        vector<double>{-42, 0, -12, 1}, 
        vector<double>{-3, 1, 0, 0}
    );
    /*===========================================
    divide_polynom_A_by_polynom_B(
        vector<double>{1, -12, 0, -42}, 
        vector<double>{1, -3, 0, 0},
        3,
        1
    );
    divide_polynom_A_by_polynom_B(
        vector<double>{1, -3, 2}, 
        vector<double>{1, -1, 0},
        2,
        1
    );
    divide_polynom_A_by_polynom_B(
        vector<double>{1, -12, 0, 81}, 
        vector<double>{1, -3, 0, 0},
        3,
        1
    );
    REQUIRE(
        divide_polynom_A_by_polynom_B(
            vector<double>{2, -9, 21, -26, 12}, 
            vector<double>{2, -3, 0, 0, 0},
            4,
            1
        ) == pair<vector<double>,vector<double> >{
            vector<double>{1, -3, 6, -4}, 
            vector<double>{0, 0, 0, 0}
        }
    );
}
*/