#include <iostream>
using namespace std;

enum enCharType { CapitalLetter=1 , SmallLetter=2 , SpecialLetter=3 , Digit=4} ;

int ReadPositiveNumber(string Message)
{
    int Number ;

    do
    {
        cout << Message << endl ;
        cin >> Number ;
    } while (Number <= 0) ;

    return Number ;
}

int RandomNumber(int From , int To)
{
    int random = rand() % (To - From + 1) + From ;
    return random ;
}

char GetRandomCharacter( enCharType CharType)
{
    switch (CharType)
    {
        case CapitalLetter :
        {
            return char (RandomNumber(65 , 90)) ;
            break ;
        }

        case SmallLetter :
        {
            return char (RandomNumber(97 , 122)) ;
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

string GenerateWord(enCharType CharType , int Length)
{
    string word = "" ;

    for (int i = 0 ; i < Length ; i++)
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

void FillArrayWithKeys(string arr[100] , int arrlength)
{
    for (int i = 0 ; i < arrlength ; i++)
    {
        arr[i] = GenerateKey() ;
    }
}

void PrintStringArray(string arr[100] , int arrlength)
{
    cout << "Array Elements : \n\n" ;
    
    for (int i = 0 ; i < arrlength ; i ++)
    {
        cout << "Array[" << i << "] : " << arr[i] ;
        cout << "\n" ;
    }

}


int main() 
{
    srand ((unsigned) time (NULL)) ;

    string arr[100] ;
    int arrlength = 0 ;

    arrlength = ReadPositiveNumber("Please Enter Number Of Keys?") ;

    FillArrayWithKeys(arr , arrlength) ;

    PrintStringArray(arr , arrlength) ;

    return 0;
}
