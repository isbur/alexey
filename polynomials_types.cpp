#pragma once

#include <utility>
#include <vector>
using namespace std;

typedef vector<double> Poly;
typedef pair<Poly, Poly> Big_Pair;
// let's stop messing up with Poly_plus and just let be Poly of size equal to its degree + 1
typedef pair<Poly, int> Poly_plus;
typedef pair<Poly_plus, Poly_plus> Big_Pair_Plus;
