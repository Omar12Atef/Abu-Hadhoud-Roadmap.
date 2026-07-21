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

void PrintInvertedLetter(int Number)
{
    for (int i=1 ; i<=Number ; i++)
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

    PrintInvertedLetter(ReadPositiveNumber("Please, Enter The Number")) ;

    return 0;
}
