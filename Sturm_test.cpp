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


TEST_CASE(
        "Sturm vector is determined correctly and number of transpositions is counted properly", 
        "[Sturm]"
) {
    Sturm_chain A = construct_Sturm_chain(
            Poly{1, -4, 3}
    );
    Sturm_vector a = construct_Sturm_vector(A, 0);
    int Sturm_number = count_transpositions(a);
    REQUIRE(Sturm_number == 2);

    a = construct_Sturm_vector(A, 1);
    Sturm_number = count_transpositions(a);
    REQUIRE(Sturm_number == 1);

    a = construct_Sturm_vector(A, 2);
    Sturm_number = count_transpositions(a);
    REQUIRE(Sturm_number == 1);

    a = construct_Sturm_vector(A, 3);
    Sturm_number = count_transpositions(a);
    REQUIRE(Sturm_number == 0);

    a = construct_Sturm_vector(A, 4);
    Sturm_number = count_transpositions(a);
    REQUIRE(Sturm_number == 0);
}