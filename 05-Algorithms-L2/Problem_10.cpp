#include <iostream>
using namespace std;

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

int ReverseNumber(int Number)
{
    int reminder = 0 ;
    int Number2 = 0 ;

    while (Number > 0)
    {
        reminder = Number % 10 ;
        Number = Number / 10 ;
        Number2 = Number2 * 10 + reminder ;
    }

    return Number2 ;
}

void PrintNumbers(int Number2)
{
    int reminder = 0 ;

    while (Number2 > 0)
    {
        reminder = Number2 % 10 ;
        Number2 = Number2 / 10 ;
        cout << reminder << endl ;
    }
}


int main() 
{

    int Number = ReadPositiveNumber("Enter a Number?") ;
    PrintNumbers(ReverseNumber(Number)) ;
    return 0;
}
