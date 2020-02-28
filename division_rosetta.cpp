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


Big_Pair_Plus rosetta_division(Poly N, size_t dN, Poly D, size_t dD);
void Print(char name, const Poly &A);
Poly rosettify(Poly N, Poly D);
Poly derosettify(Poly N);


Big_Pair divide_polynom_A_by_polynom_B(Poly N, Poly D) {

    size_t dN = N.size() - 1;
    size_t dD = D.size() - 1;

    Big_Pair_Plus Answer = rosetta_division(
        N,
        dN, 
        rosettify(N, D),
        dD
    );

    return Big_Pair{
        Answer.first.first,
        derosettify( Answer.second.first )
    };

}


Big_Pair_Plus rosetta_division(Poly N, size_t dN, Poly D, size_t dD){

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

    return Big_Pair_Plus{
        Poly_plus{q, dq}, 
        Poly_plus{r, dr}
    };
}


// does:  prints all members of vector
// input: c - ASCII char with the name of the vector
//        A - reference to polynomial (vector)
void Print(char name, const Poly &A) {
	cout << name << "(" << A.size()-1 << ") = [ ";
	copy(A.begin(), A.end(), ostream_iterator<decltype(A[0])>(cout, " "));
	cout << "]\n";
}


Poly rosettify(Poly N, Poly D) {
    Poly new_D = D;
    for (int i = D.size(); i < N.size(); i++){
        new_D.push_back(0);
    }
    return new_D;
}


Poly derosettify(Poly N){
    int i = N.size() - 1;
    while(i > 0 && N[i] == 0){
        N.pop_back();
        i--;
    }
    return N;
}