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

void PrintPalindrome()
{
    int Number = ReadPositiveNumber("Please Enter The Number?") ;
    int NUmber2 = ReverseNumber(Number) ;

    if (Number == NUmber2)
        cout << "Yes, it is a Palindrome Number." ;
    else
        cout << "No. it is NOT a Palindrome Number." ;
}

int main() 
{
    PrintPalindrome() ;
    return 0;
}
