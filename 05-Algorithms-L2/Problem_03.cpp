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


bool IsPerfectNumber(int Number)
{
    int sum = 0 ;

    for (int i=1 ; i < Number ; i++)
    {
        if (Number % i == 0)
            sum = sum + i ;
    }

    return Number == sum ;
}

void PrintResult(int Number)
{
    if (IsPerfectNumber(Number))
        cout << Number << " Is a Perfect Number.\n" ;
    else
        cout << Number << " Is Not a Perfect Number.\n" ;
}


int main() 
{

    PrintResult(ReadPositiveNumber("Enter The Number?")) ;

    return 0;
}
