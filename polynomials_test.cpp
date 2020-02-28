#include "catch/catch.hpp"

#include "polynomials.cpp"


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


#include "polynomials.cpp"
TEST_CASE("Polynomial degrees are determined correctly", "[degree]"){
    REQUIRE(get_degree(
        Poly{1, 2, 1}
    ) == 2);
    REQUIRE(get_degree(
        Poly{1, 2, 1, 0, 0, 0, 0}
    ) == 2);
    REQUIRE(get_degree(
        Poly{1, 0, 0, 0, 0, 0, 0}
    ) == 0);
    REQUIRE(get_degree(
        Poly{1}
    ) == 0);
    REQUIRE(get_degree(
        Poly{0}
    ) == 0);
}


TEST_CASE("Unary minus works", "[minus]"){
    Poly V{1, 2, 1};
    REQUIRE(
        unary_minus(V) == Poly{-1, -2, -1}
    );
}
