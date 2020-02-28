#include "catch/catch.hpp"

#include "division_rosetta.cpp"

TEST_CASE("Polynomials are divided", "[pd]"){
    REQUIRE(
        divide_polynom_A_by_polynom_B(
            Poly_plus{Poly{2, -9, 21, -26, 12}, 4},
            Poly_plus{Poly{2, -3, 0, 0, 0}, 1}
        ) == Big_Pair{
            Poly_plus{Poly{1, -3, 6, -4}, 3}, 
            Poly_plus{Poly{0, 0, 0, 0}, 0}
        }
    );
}