#include "catch/catch.hpp"

#include "Sturm.cpp"

TEST_CASE("Sturm chain is constructed", "[Sturm]"){
    
    Poly a{1, -4, 3};
    Poly b{2, -4};
    Poly c{0.25};
    Sturm_chain A = construct_Sturm_chain(
            Poly{1, -4, 3}
    );
    Sturm_chain B{
        Poly{1, -4, 3},
        Poly{2, -4},
        Poly{0.25}        
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
