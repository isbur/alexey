#include "catch/catch.hpp"

#include "polynomials.cpp"


TEST_CASE("Derivatives are evaluated", "[derivative]"){
    
    REQUIRE(
        derivative(vector<double>{1, -3, 2}) == 
        vector<double>{2, -3}
    );
    
    REQUIRE(
        derivative(vector<double>{1, 1, 1, 1, 1, 1, 1}) == 
        vector<double>{6, 5, 4, 3, 2, 1}
    );
}


#include "polynomials.cpp"


TEST_CASE("Value is substituted to polynomial", "[substitute]"){
    Poly N;

    N = Poly{1};
    REQUIRE(
        substitute(N, 0) == 1
    );
    REQUIRE(
        substitute(N, 10) == 1
    );
    REQUIRE(
        substitute(N, 100) == 1
    );

    N = Poly{1, 1};
    REQUIRE(
        substitute(N, 0) == 1
    );
    REQUIRE(
        substitute(N, 10) == 11
    );

    N = Poly{1, 0, 1};
    REQUIRE(
        substitute(N, 10) == 101
    );

    N = Poly{1, 0};
    REQUIRE(
        substitute(N, 1) == 1
    );
    REQUIRE(
        substitute(N, 0) == 0
    );
    REQUIRE(
        substitute(N, -1) == -1
    );
    REQUIRE(
        substitute(N, 10) == 10
    );
}


TEST_CASE("Unary minus works", "[minus]"){
    Poly V{1, 2, 1};
    REQUIRE(
        unary_minus(V) == Poly{-1, -2, -1}
    );
}
