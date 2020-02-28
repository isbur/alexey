#include "catch/catch.hpp"

#include "Sturm.cpp"

TEST_CASE("Sturm chain is constructed", "[Sturm]"){
    
    Poly a{1, -4, 3};
    Poly b{2, -4, 0};
    Poly c{0.25, -0, 0};
    Sturm_chain A = construct_Sturm_chain(
            Poly_plus{Poly{1, -4, 3}, 2}
    );
    Sturm_chain B{
        Poly_plus{Poly{1, -4, 3}, 2},
        Poly_plus{Poly{2, -4, 0}, 1},
        Poly_plus{Poly{0.25, -0}, 0}        
    } ;
    REQUIRE(A == B);
    REQUIRE(A.size() == 3);
    REQUIRE(
        get_degree(a) == 2
    );
    REQUIRE(
        get_degree(b) == 1
    );
    REQUIRE(
        get_degree(c) == 0
    );
}
