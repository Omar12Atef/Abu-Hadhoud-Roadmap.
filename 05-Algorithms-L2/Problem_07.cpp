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

void ReverseNumber(int Number)
{
    int reminder = 0 ;

    while (Number > 0)
    {
        reminder = Number % 10 ;
        Number = Number / 10 ;
        cout << reminder ;
    }
}


int main() 
{

    ReverseNumber(ReadPositiveNumber("Enter The Number?")) ;

    return 0;
}
