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

void PrintInvertedPattern(int Number)
{
    cout << "\n" ;

    for (int i = 1 ; i <= Number ; i++)
    {
        for (int j = 1 ; j < i ; j++)
        {
            cout << " " ;
        }

        for (int k = Number ; k >= i ; k--)
        {
            cout << "*" ;
        }

        cout << "\n" ;
    }
}

int main() 
{
    PrintInvertedPattern(ReadPositiveNumber("Please Enter The Number?")) ;
    return 0;
}
