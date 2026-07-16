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

void PrinReverseNumber(int Number)
{
    int reminder = 0 ;

    while (Number > 0)
    {
        reminder = Number % 10 ;
        Number = Number / 10 ;
        cout << reminder << endl ;
    }
}

int main() 
{

    PrinReverseNumber(ReadPositiveNumber("Please Enter The Number?")) ;

    return 0;
}
