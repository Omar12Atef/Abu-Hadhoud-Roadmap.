#include <iostream>
#include <cmath>

using namespace std;

float ReadNumber(string Message)
{
    float Number ;

    cout << "Enter The Number : " ;
    cin >> Number ;

    return Number ;
}

float GetFractionPart(float Number)
{
    return Number - int (Number) ;
}

int MyRound(float Number)
{
    int IntPart = int (Number) ;

    float FractionPart = GetFractionPart(Number) ;

    if (abs(FractionPart) >= 0.5)
    {
        if (Number > 0)
        {
            return ++IntPart ;
        }
        else
        {
            return --IntPart ;
        }
    }
    else
    {
        return IntPart ;
    }
}



int main() 
{

    float Number = ReadNumber("Please, Enter a Float Number : ") ;

    cout << "\nMy Round Result : " << MyRound(Number) ;
    cout << "\nC++ Round Result : "<< round(Number) ;

    return 0;
}
