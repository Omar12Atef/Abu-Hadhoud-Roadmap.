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

float GetFractionPart(float Number)
{
    return Number - int (Number) ;
}

int MyFloor(float Number)
{
    int IntPart = int (Number) ;
    float FractionPart = GetFractionPart(Number) ;

    if (abs(FractionPart) > 0)
    {
        if (Number > 0)
            return IntPart ;
        else
            return IntPart - 1 ;
    }
    else
        return IntPart ;
}

int main() 
{

    float Number = ReadNumber() ;

    cout << "\nMy Floor Result = " << MyFloor(Number) ;
    cout << "\nC++ Floor Result = " << floor(Number) ;

    return 0;
}
