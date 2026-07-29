#include <iostream>
using namespace std;

int ReadNumber()
{
    int arrlength ;

    cout << "Enter Array Length : " ;
    cin >> arrlength ;

    return arrlength ;
}

int RandomNumber(int From , int To)
{
    int random = rand() % (To - From + 1) + From ;
    return random ;
}

void FillArrayWithRandomNumbers(int arr[100] , int &arrlength)
{
    for (int i = 0 ; i < arrlength ; i++)
    {
        arr[i] = RandomNumber(1 , 100) ;
    }
}

int OddCount(int arr[100] , int &arrlength)
{
    int counter = 0 ;

    for (int i = 0 ; i < arrlength ; i++)
    {
        if (arr[i] % 2 != 0)
        {
            counter++ ;
        }
    }

    return counter ;
}

void PrintArray(int arr[100] , int &arrlength)
{
    for (int i = 0 ; i < arrlength ; i++)
    {
        cout << arr[i] << " " ;
    }
}

int main() 
{
    srand((unsigned)time(NULL)) ;

    int arr[100] ;

    int arrlength = ReadNumber() ;

    FillArrayWithRandomNumbers(arr , arrlength) ;

    cout << "\nArray Elements :\n" ;
    PrintArray(arr , arrlength) ;

    cout << "\n\nOdd Numbers count is : " ;
    cout << OddCount(arr , arrlength) ;

    return 0;
}
