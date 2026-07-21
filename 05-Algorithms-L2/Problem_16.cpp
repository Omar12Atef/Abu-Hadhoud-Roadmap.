#include <iostream>
using namespace std;

// int ReadPositiveNumber(string Message)
// {
//     int Number ;

//     do
//     {
//         cout << Message << endl ;
//         cin >> Number ;
//     } while (Number <= 0) ;

//     return Number ;
// }

void PrintWordsFrom_AAA_To_ZZZ()
{
    for (int i = 65 ; i <= 90 ; i++)
    {
        for (int j = 65 ; j <= 90 ; j++)
        {
            for (int k = 65 ; k <= 90 ; k++)
            {
                cout << char(i) << char(j) << char(k) << endl ;
            }

        }

        cout << "_____________________\n" ;

    }
}

int main() 
{

    PrintWordsFrom_AAA_To_ZZZ() ;

    return 0;
}
