#include <iostream>
#include <cmath>

using namespace std;

enum enPrimeNotPrime { prime=1 , NotPrime=2 } ;

int ReadPositiveNumber(string Message)
{
    int Number ;

    do
    {
        cout << Message << endl ;
        cin >> Number ; 
    } while (Number<=0) ;

    return Number ;
}


enPrimeNotPrime CheckPrime(int Number)
{
    int M = round(Number/2) ;
    
    for (int counter=2 ; counter<=M ; counter++)
    {
        if (Number % counter == 0)
            return NotPrime ;
    }
    return prime ;
}


void PrintPrimeNumbersFrom1ToN(int Number)
{
    cout << "\nPrime Number From 1 To " << Number << " are : \n" ;

    for (int i=2 ; i<=Number ; i++)
    {
        if (CheckPrime(i) == prime)
        {
            cout << i << endl ;
        }
    }
}


int main() 
{

    PrintPrimeNumbersFrom1ToN(ReadPositiveNumber("Enter a Positive Number?")) ;    

    return 0;
}
