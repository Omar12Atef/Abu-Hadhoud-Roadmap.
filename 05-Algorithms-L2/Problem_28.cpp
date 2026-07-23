#include <iostream>
using namespace std;

int RandomNumber (int From , int To)
{
    int random = rand() % (To - From + 1) + From ;
    return random ;
}


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

void FillArrayWithRandomNumbers(int arr[100] , int ArrLength)
{
    for (int i = 0 ; i < ArrLength ; i++)
    {
        arr[i] = RandomNumber(1 , 100) ;
    }
}

void CopyArr1toArr2(int arr1[100] , int arr2[100] , int ArrLength)
{
    for (int i=0 ; i<ArrLength ; i++)
    {
        arr2[i] = arr1[i] ;
    }
}

void PrintArray(int arr[100] , int ArrLength)
{
    for (int i = 0 ; i < ArrLength ; i++)
    {
        
        cout << arr[i] << " " ;
    }
}


int main() 
{

    srand((unsigned)time(NULL)) ;

    int arr1[100] , arr2[100] , ArrLength ;

    ArrLength = ReadPositiveNumber("Enter The length of array : ") ;
    FillArrayWithRandomNumbers(arr1 , ArrLength) ;

    cout << "Array 1 Elements : " ;
    PrintArray(arr1 , ArrLength) ;

    CopyArr1toArr2(arr1 , arr2 , ArrLength) ;

    cout << "\nArray 2 Elements after copy : \n" ;
    PrintArray(arr2 , ArrLength) ;


    return 0;
}
