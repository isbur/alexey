/*
 * https://rosettacode.org/wiki/Polynomial_long_division#C.2B.2B
 */
#pragma once

#include <iostream>
#include <iterator>
#include <utility>
#include <vector>

using namespace std;
#include "polynomials.cpp"

// does:  prints all members of vector
// input: c - ASCII char with the name of the vector
//        A - reference to polynomial (vector)
void Print(char name, const Poly &A) {
	cout << name << "(" << A.size()-1 << ") = [ ";
	copy(A.begin(), A.end(), ostream_iterator<decltype(A[0])>(cout, " "));
	cout << "]\n";
}


Big_Pair divide_polynom_A_by_polynom_B(Poly_plus N_plus, Poly_plus D_plus) {
    Poly N = N_plus.first;
    size_t dN = N_plus.second;
    Poly D = D_plus.first;
    size_t dD = D_plus.second;

	Poly d, q, r;        // vectors - N / D == q && N % D == r
	size_t dd, dq, dr; // degrees of vectors
	size_t i;                  // loop counter

	// setting the degrees of vectors
	dq = dN-dD;  
	dr = dN-dD;

	if( dD < 1 || dN < 1 ) {
		cerr << "Error: degree of D and N must be positive.\n";
		//return 1;
	}

	// allocation and initialization of vectors
	d.resize(dN+1);
	q.resize(dq+1);
	r.resize(dr+1);

	cout << "-- Procedure --" << endl << endl;
	if( dN >= dD ) {
		while(dN >= dD) {
			// d equals D shifted right
			d.assign(d.size(), 0);

			for( i = 0 ; i <= dD ; i++ )
				d[i+dN-dD] = D[i];
			dd = dN;

			Print( 'd', d );

			// calculating one element of q
			q[dN-dD] = N[dN]/d[dd];

			Print( 'q', q );

			// d equals d * q[dN-dD]
			for( i = 0 ; i < dq + 1 ; i++ )
				d[i] = d[i] * q[dN-dD];

			Print( 'd', d );

			// N equals N - d
			for( i = 0 ; i < dN + 1 ; i++ )
				N[i] = N[i] - d[i];
			dN--;

			Print( 'N', N );
			cout << "-----------------------" << endl << endl;

		}
	}

	// r equals N 
	for( i = 0 ; i <= dN ; i++ )
		r[i] = N[i];

	cout << "=========================" << endl << endl;
	cout << "-- Result --" << endl << endl;

    
	Print( 'q', q );
    cout << endl << dq << endl;
	Print( 'r', r );
    cout << endl << dr << endl;

    return Big_Pair{
        Poly_plus{q, dq},
        Poly_plus{r, get_degree(r)}
    };
}

