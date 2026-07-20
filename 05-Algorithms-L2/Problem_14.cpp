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


void PrintNumberPattern(int Number)
{
    for ( int i=Number ; i>=1 ; i--)
    {
        for (int j=1 ; j<=i ; j++)
        {
            cout << char(i+64) ;
        }

        cout << endl ;
    }
}

int main() 
{

    PrintNumberPattern(ReadPositiveNumber("Please, Enter The Number?")) ;

    return 0;
}
