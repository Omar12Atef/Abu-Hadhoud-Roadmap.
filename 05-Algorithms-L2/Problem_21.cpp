#include <iostream>
using namespace std;

enum enCharType { SmallLetter=1 , CapitalLetter=2 , SpecialLetter = 3 , Digit = 4} ;

int RandomNumber (int From , int To)
{
    int random = rand() % (To - From + 1) + From ;

    return random ;
}


int ReadPosotiveNumber(string Message)
{
    int Number ;

    do
    {
        cout << Message << endl ;
        cin >> Number ;
    } while ( Number <= 0 ) ;

    return Number ;
}


char GetRandomCharacter(enCharType CharType)
{
    switch (CharType)
    {
        case SmallLetter :
        {
            return char (RandomNumber(97 , 122)) ;
            break ;
        }

        case CapitalLetter :
        {
            return char (RandomNumber(65 , 90)) ;
            break ;
        }

        case SpecialLetter :
        {
            return char (RandomNumber(33 , 47)) ;
            break ;
        }

        case Digit :
        {
            return char (RandomNumber(48 , 57)) ;
            break ;
        }

        default :
        return 0 ;
    }
}


string GenerateWord(enCharType CharType , short length)
{
    string word = "" ;

    for (int i=1 ; i<=length ; i++)
    {
        word = word + GetRandomCharacter(CharType) ;
    }

    return word ;
}


string GenerateKey()
{
    string key = "" ;

    for (int i=1 ; i<=4 ; i++)
    {
        key = key + GenerateWord(CapitalLetter , 4) ;

        if (i < 4)
            key = key + "-" ;
    }

    return key ;
}


void PrintKeys(int NumberOfKeys)
{
    cout << "\n" ;

    for (int i=1 ; i<=NumberOfKeys ; i++)
    {
        cout << "Key [" << i << "] : " << GenerateKey() << endl ;
    }
}



int main() 
{

    srand((unsigned)time(NULL)) ;

    PrintKeys(ReadPosotiveNumber("Please Enter Number Of Keys?")) ;

    return 0;
}
