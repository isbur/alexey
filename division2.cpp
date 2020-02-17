/*! \fn dividePolynomialByPolynomial
*   \brief Try to make a division
*   
*   \param iNumerator( vector< Type >& ) The dividend ; updated if the remainder is 0
*   \param iDenominator( const vector< Type > ) The divisor
*   \return bool: True if iNumerator is divisible by iDenominator. In this case, iNumerator is updated to the quotient
*/
template <typename Type> 
bool dividePolynomialByPolynomial( vector< Type >& iNumerator, const vector< Type >& iDenominator )
{
    unsigned int dN( iNumerator.size( ) - 1 ), dD( iDenominator.size( ) - 1 );
 
    if( dN < dD || ( dD == 0 && iDenominator[0] != 0 ) )
        return false;
     
    vector< Type > iWorking( iNumerator ), iQuotient;
     
    unsigned int i;
    Type iTemp;
     
    while( dN >= dD )
    {
        if( iWorking[ dN ] % iDenominator[ dD ] != 0 )
            return false;
         
        iTemp = iWorking[ dN ] / iDenominator[ dD ];
        iQuotient.insert( iQuotient.begin( ), iTemp );
         
        for( i = 0; i <= dD; i++ )           iWorking[dN - i] -= iTemp * iDenominator[dD - i];               dN--;               while( iWorking[ dN ] == 0 && dN >= 1 && dN >= dD )
        {
            iQuotient.insert( iQuotient.begin( ), 0 );
            dN--;
        }
    }
     
    for( i = 0; i <= dN; i++ )
    {
        if( iWorking[i] != 0 )
            return false;
    }
     
    iNumerator = iQuotient;
     
    return true;
}