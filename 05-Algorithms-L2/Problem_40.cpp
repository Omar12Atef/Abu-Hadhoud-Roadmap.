#include <iostream>
using namespace std;

void FillArray(int arr[100] , int &arrLength)
{
    arrLength = 10 ;
    
    arr[0] = 10 ;
    arr[1] = 10 ;
    arr[2] = 10 ;
    arr[3] = 50 ;
    arr[4] = 50 ;
    arr[5] = 70 ;
    arr[6] = 70 ;
    arr[7] = 70 ;
    arr[8] = 70 ;
    arr[9] = 90 ;
}

void printArray (int arr[100] , int arrLength)
{
    for (int i = 0 ; i < arrLength ; i++)
    {
        cout << arr[i] << " " ;
    }
}

int FindNumberPositionInArray(int Number , int arr[100] , int arrLength)
{
    for (int i = 0 ; i < arrLength ; i++)
    {
        if (arr[i] == Number)
            return i ;
    }

    return -1 ;
}

bool IsNumberInArray(int Number , int arr[100] , int arrLength)
{
    return FindNumberPositionInArray(Number , arr , arrLength) != -1 ;
}

void AddArayElement(int Number , int arr[100] , int &arrLength)
{
    arrLength ++ ;
    arr[arrLength - 1] = Number ;
}

void CopyDistinctNumbersToArray(int arr1[100] , int arr2[100] , int &arrLength , int &arrLength2)
{
    for (int i = 0 ; i < arrLength ; i++)
    {
        if (!IsNumberInArray(arr1[i] , arr2 , arrLength2))
        {
            AddArayElement(arr1[i] , arr2 , arrLength2) ;
        }
    }
}


int main() 
{
    int arr[100] , arr2[100] , arrLength=0 , arrLength2=0 ;

    FillArray(arr , arrLength) ;

    cout << "\nArray 1 Elements : \n" ;
    printArray(arr , arrLength) ;

    CopyDistinctNumbersToArray(arr , arr2 , arrLength , arrLength2) ;

    cout << "\nArray 2 Distinct Elements : \n" ;
    printArray(arr2 , arrLength2) ;



    return 0;
}
