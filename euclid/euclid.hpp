/*
 * https://github.com/whisperity/polynomnom/blob/master/src/EuclideanAlgorithm.hpp
 */


#include "add_mult_identity.hpp"

template<typename T>
T euclidean(const T& a_orig, const T& b_orig)
{
    T a = a_orig;
    T b = b_orig;
    T c;

    // Swap the operands if needed
    if (a < b)
    {
        c = a;
        a = b;
        b = c;
    }

    c = a % b; // Get the first remainder
    while (c > id_additive<T>::value)
    {
        // While there is a remainder, always modulo the previous right-hand operand with the previous remainder.
        a = b;
        b = c;
        c = a % b;
    }

    // The last non-zero remainder is the GCD.
    return b;
}