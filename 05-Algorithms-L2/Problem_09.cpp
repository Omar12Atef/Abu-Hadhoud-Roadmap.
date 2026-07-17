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


int CountDigitFreq(int Number , short Digit)
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


void PrintAllDigitsFreq(int Number)
{

    short DigitFreq = 0 ;
    
    for (int i=1 ; i<10 ; i++)
    {
        DigitFreq = CountDigitFreq(Number , i) ;

        if (DigitFreq > 0)
        {
            cout << "Digit " << i << " Frequency is " << DigitFreq << " Times.\n" ;
        }
    }
}


int main() 
{

    int Number = ReadPositiveNumber("Enter The Number?") ;
    PrintAllDigitsFreq(Number) ;

    return 0;
}
