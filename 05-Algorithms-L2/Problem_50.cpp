#include <iostream>
#include <cmath>

using namespace std;

float ReadNumber()
{
    float Number ;

    cout << "Please, Enter float Number : " ;
    cin >> Number ;

    return Number ;
}

float MySqrt(float Number)
{
    return pow(Number , 0.5) ;
}


int main() 
{

    float Number = ReadNumber() ;

    cout << "\nMy Sqrt Result = " << MySqrt(Number) ;
    cout << "\nC++ Floor Result = " << sqrt(Number) ;

    return 0;
}
