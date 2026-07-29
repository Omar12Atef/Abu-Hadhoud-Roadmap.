#include <iostream>
#include <cmath>

using namespace std;

float ReadNegativeNumber(string Message)
{
    int Number ;

    do
    {
        cout << Message << endl ;
        cin >> Number ;
    } while (Number >= 0) ;

    return Number ;
}

float My_Abs_Result(int Number)
{
    int MyResult = -1 * Number ;

    return MyResult ;
}


int main() 
{

    float Number = ReadNegativeNumber("Please, Enter a Negative Number : ") ;

    cout << "\nMy abs Result : " << My_Abs_Result(Number) ;

    cout <<"\nC++ abs Result : " << abs(Number) ;

    return 0;
}
