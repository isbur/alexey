#include "catch/catch.hpp"

#include "find_roots.cpp"

#include <utility>
using namespace std;


TEST_CASE(
        "All roots are located with Sturm theorem", 
        "[froot]"
) {
    REQUIRE(
        all_roots_are_located(vector <int> {2, 0}) == false
    );
    REQUIRE(
        all_roots_are_located(vector <int> {2, 2, 2, 0, 0}) == false
    );
    REQUIRE(
        all_roots_are_located(vector <int> {2, 1, 0}) == true
    );
    REQUIRE(
        all_roots_are_located(vector <int> {2, 2, 2, 1, 1, 0}) == true
    );

}


TEST_CASE(
        "Roots are found", 
        "[froot]"
) {
    Sturm_chain A = construct_Sturm_chain(
            Poly{1}
    );
    pair<double, double> boundaries{-1, 1};
    double threshold = 0.001;
    REQUIRE(
        find_roots(A, boundaries, threshold) == vector <double>{}
    );
}


TEST_CASE(
        "Single root is found correctly", 
        "[froot]"
) {
    Poly P{1, 0};
    double a = -1;
    double b = 1;
    double t = 0.001;
    double answer = find_single_root(P, a, b, t);
    REQUIRE(answer > -t);
    REQUIRE(answer < t);
}