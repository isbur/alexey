#include "catch/catch.hpp"

#include "division_rosetta.cpp"


TEST_CASE("Polynomials are rosettified", "[rosettification]"){
    Poly N{2, -9, 21, -26, 12};
    Poly D{2, -3};
    REQUIRE(
        rosettify(N, D) == Poly{2, -3, 0, 0, 0}
    );
}


TEST_CASE("Successful derosettification", "[derosettification]") {
    REQUIRE(
        derosettify(Poly{0}) == Poly{0}
    );
    REQUIRE(
        derosettify(Poly{1}) == Poly{1}
    );
    REQUIRE(
        derosettify(Poly{0,0,0,0}) == Poly{0}
    );
    REQUIRE(
        derosettify(Poly{1,0,0,0}) == Poly{1}
    );
}


TEST_CASE("Polynomials are divided and correctly put out", "[pd]"){
    Poly N{2, -9, 21, -26, 12};
    Poly D{2, -3};
    REQUIRE(
        divide_polynom_A_by_polynom_B(N, D) == 
        Big_Pair{
            Poly{1, -3, 6, -4}, 
            Poly{0}
        }
    );
}