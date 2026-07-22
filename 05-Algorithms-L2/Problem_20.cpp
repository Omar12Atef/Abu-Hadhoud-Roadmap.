#include <iostream>
using namespace std;

int RandonNumber(int From , int To)
{
    int randNumber = rand() % (To - From + 1) + From ;
    return randNumber ;
}

enum enCharType { SmallLetter=1 , CapitalLetter=2 , SpecialLetter = 3 , Digit = 4} ;

char GetRandomCharacter(enCharType CharType)
{
    switch (CharType)
    {
        case SmallLetter :
        {
            return char (RandonNumber(97 , 122)) ;
            break ;
        }

        case CapitalLetter :
        {
            return char (RandonNumber(65 , 90)) ;
            break ;
        }

        case SpecialLetter :
        {
            return char (RandonNumber(33 , 47)) ;
            break ;
        }

        case Digit :
        {
            return char (RandonNumber(48 , 57)) ;
            break ;
        }

        default :
        return 0 ;
    }
}
int main() 
{

    srand((unsigned)time(NULL)) ;

    cout << GetRandomCharacter(SmallLetter) << endl ;
    cout << GetRandomCharacter(CapitalLetter) << endl ;
    cout << GetRandomCharacter(SpecialLetter) << endl ;
    cout << GetRandomCharacter(Digit) << endl ;





    return 0;
}
