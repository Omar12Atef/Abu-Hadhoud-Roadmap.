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

int MyFloor(float Number)
{
    if (Number > 0)
    {
        return int(Number) ;
    }
    else
    {
        return int(Number) - 1 ;
    }
}

int main() 
{

    float Number = ReadNumber() ;

    cout << "\nMy Floor Result = " << MyFloor(Number) ;
    cout << "\nC++ Floor Result = " << floor(Number) ;

    return 0;
}
