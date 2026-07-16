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

int SumOfDigits(int Number)
{
    int reminder = 0 ;
    int sum = 0 ;

    while (Number > 0)
    {
        reminder = Number % 10 ;
        Number = Number / 10 ;
        sum = sum + reminder ;
    }

    return sum ;
}

void PrintSum(int Number)
{
    cout << "Sum Of Digits = " << SumOfDigits(Number) ;
}

int main() 
{

    PrintSum(ReadPositiveNumber("Enter The Number?")) ;

    return 0;
}
