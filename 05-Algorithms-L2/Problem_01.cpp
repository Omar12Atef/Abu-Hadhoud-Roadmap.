#include <iostream>
using namespace std;


void PrintHeader()
{
    cout << "\t\t Multiplication Table From 1 to 10\n\n" ;
    cout << "\t\t" ;
    for (int i=1 ; i<=10 ; i++)
    {
        cout  << i << "\t" ;
    }

    cout << "\n_______________________________________________\n" ;

}

string ColumnSeperator(int i)
{
    if (i<10)
        return "   |" ;
    else
        return "  |" ;
}


void PrintMultiplicationTaple()
{
    PrintHeader() ;

    for (int i=1 ; i<=10 ; i++)
    {
        cout << " " << i << ColumnSeperator(i) << "\t" ;

        for (int j=1 ; j<=10 ; j++)
        {
            cout << i * j << "\t" ;
        }

        cout << endl ;
    }
}




int main() 
{

    PrintMultiplicationTaple() ;


    return 0;
}
