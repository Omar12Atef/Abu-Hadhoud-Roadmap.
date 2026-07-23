#include <iostream>
using namespace std;

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

void ReadArray(int arr[100] , int &ArrLength)
{
    cout << "Enter Numbers of Elements : \n" ;
    cin >> ArrLength ;

    cout << "Enter Array Elements : \n" ;

    for (int i = 0 ; i < ArrLength ; i++)
    {
        cout << "Element [" << i+1 << "] : " ;
        cin >> arr[i] ;
    }
}

void PrintArray(int arr[100] , int ArrLength)
{
    for (int i = 0 ; i < ArrLength ; i++ )
    {
        cout << arr[i] << " " ;
    }
}

int NumberRepeated(int arr[100] , int ArrLength , int Number)
{
    int counter = 0 ;

    for (int i = 0 ; i < ArrLength ; i++ )
    {
        if (Number == arr[i])
        {
            counter ++ ;
        }
    }

    return counter ;
}


int main() 
{

    int arr[100] , NumberToCheck , ArrLength ;

    ReadArray(arr , ArrLength) ;

    NumberToCheck = ReadPositiveNumber("\nEnter The Number you want to check :") ;

    cout << "\nOriginal Array : " ;
    PrintArray(arr , ArrLength) ;

    cout << endl << NumberToCheck << " is repeated " ;
    cout << NumberRepeated(arr , ArrLength , NumberToCheck) ;
    cout << " Time(s)" ;






    return 0;
}
