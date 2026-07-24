#include <iostream>
using namespace std;

int ReadPositiveNumber (string Message)
{
    int Number ;
    do
    {
        cout << Message << endl ;
        cin >> Number ;
    } while (Number <= 0) ;

    return Number ;
}

int RandomNumber (int From , int To)
{
    int Random = rand() % (To - From + 1) + From ;

    return Random ;
}

void FillArrayWithRandomNumbers(int arr[100] , int arrLength)
{
    for (int i = 0 ; i < arrLength ; i++)
    {
        arr[i] = RandomNumber(1,100) ;
    }
}


void PrintArray (int arr[100] , int arrLength)
{
    for (int i = 0 ; i < arrLength ; i++)
    {
        cout << arr[i] << " " ;
    }
}


void CopyArrayInReversedOrder (int arr1[100] , int arr2[100] , int arrLength)
{
    for (int i = 0 ; i < arrLength ; i++)
    {
        arr2[i] = arr1[arrLength - 1 - i] ;
    }
}




int main() 
{
    srand((unsigned) time (NULL)) ;

    int arr1[100] , arr2[100] , arrLength ;

    arrLength = ReadPositiveNumber("Please, Enter Number Of Elements :") ;

    FillArrayWithRandomNumbers(arr1 , arrLength) ;

    cout << "Original Array Elements : \n" ;
    PrintArray(arr1 , arrLength) ;

    CopyArrayInReversedOrder(arr1 , arr2 , arrLength) ;

    cout << "\nArray After Reversed : \n" ;
    PrintArray(arr2 , arrLength) ;

    return 0;
}
