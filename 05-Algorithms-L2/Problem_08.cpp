#include <iostream>
using namespace std;

int ReadPositiveNumber(string Message)
{
    int Number ;

    do
    {
        cout << Message << endl ;
        cin >> Number ;
    } while (Number <= 0) ;

    return Number ;
}


int CalculateDigit(int Number , short Digit)
{
    int reminder = 0 ;
    int Freq = 0 ;

    while (Number>0)
    {
        reminder = Number % 10 ;
        Number = Number / 10 ;

        if ( reminder == Digit )
        {
            Freq ++ ;
        }
    }

    return Freq ;
    
}


int main() 
{

    int Number = ReadPositiveNumber("Enter The Number?") ;
    short Digit = ReadPositiveNumber("Enter The Digit?") ;

    cout << "Digit " << Digit << " Frequency is " << CalculateDigit(Number,Digit) << " Times." ;

    return 0;
}
