#include <iostream>
using namespace std;

void FillArray(int arr[100] , int &arrLength)
{
    cout << "Enter Arr Length : \n" ;
    cin >> arrLength ;

    cout << "\nEnter " << arrLength << " Numbers : \n\n" ;

    for (int i = 0 ; i < arrLength ; i++)
    {
        cout << "Element [" << i+1 << "] : " ;
        cin >> arr[i] ;
    }
}

bool IsArrayPalindrome(int arr[100] , int arrLength)
{
    for (int i = 0 ; i < arrLength ; i++)
    {
        if (arr[i] != arr[arrLength - 1- i])
        {
            return false ;
        }
    }

    return true ;

}



void printArray (int arr[100] , int arrLength)
{
    for (int i = 0 ; i < arrLength ; i++)
    {
        cout << arr[i] << " " ;
    }
}


int main() 
{
    int arr[100] , arrLength=0 ;

    FillArray(arr , arrLength) ;

    cout << "\nArray 1 Elements : \n" ;
    printArray(arr , arrLength) ;

    if (IsArrayPalindrome(arr  , arrLength))
    {
        cout << "\n\nYes, Array is palindrome.\n" ;
    }
    else
    {
        cout << "\n\nNo, Array isn't palindrome.\n" ;
    }



    return 0;
}
