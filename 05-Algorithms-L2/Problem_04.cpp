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

void PrintNumbers(int Number)
{

    for (int i=1 ; i <= Number ; i++)
    {
        if (IsPerfectNumber(i))
            cout << i << endl ;
    }
}


int main() 
{

    PrintNumbers(ReadPositiveNumber("Plese Enter The Number?")) ;

    return 0;
}
