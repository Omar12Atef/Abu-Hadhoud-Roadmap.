#include <iostream>
using namespace std;

void ReadArray(int arr[100] , int &arrlength)
{
    cout << "Enter Array Length : " ;
    cin >> arrlength ;

    cout << "\nEnter " << arrlength << " Numbers : \n\n" ;

    for (int i = 0 ; i < arrlength ; i++)
    {
        cout << "Element [" << i+1 << "] : " ;
        cin >> arr[i] ;
    }
}

bool IsArrayPalindrome(int arr[100] , int arrlength)
{
    for (int i = 0 ; i < arrlength ; i++)
    {
        if (arr[i] != arr[arrlength - 1 - i])
        {
            return false ;
        }
    }

    return true ;
}

void PrintArray(int arr[100] , int arrlength)
{
    for (int i = 0 ; i < arrlength ; i++)
    {
        cout << arr[i] << " " ;
    }
}

int main() 
{
    int arr[100] , arrlength = 0 ;

    ReadArray(arr , arrlength) ;

    cout << "\nArray Elements : \n" ;
    PrintArray(arr , arrlength) ;

    if (IsArrayPalindrome(arr , arrlength))
    {
        cout << "\n\nYes, Array is Palindrome." ;
    }
    else
    {
        cout << "\n\nNo, Array isn't Palindrome." ;
    }

    return 0;
}
