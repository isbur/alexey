#include "catch/catch.hpp"

#include "split_string.cpp"
TEST_CASE( "String is split", "[stov]" ) {
    string s = "1 2 1";
    vector<string> polynomial_string;
    split(s, polynomial_string);
    REQUIRE(polynomial_string == vector<string>{"1", "2", "1"});
}