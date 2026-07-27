#include <iostream>
#include <cmath>

using namespace std;

enum enPrimeNotPrime { prime=1 , NotPrime=2 } ;

int ReadPositiveNumber()
{
    int Number ;

    do
    {
        cout << "ُEnter The Number of Elements : " ;
        cin >> Number ;
    } while (Number <= 0) ;

    return Number ; 
}

enPrimeNotPrime CheckPrime(int Number)
{
    int M = round(Number/2) ;
    
    for (int counter=2 ; counter<=M ; counter++)
    {
        if (Number % counter == 0)
            return NotPrime ;
    }
    return prime ;
}

int RandomNumber (int From , int To)
{
    int Random = rand() % (To - From + 1) + From ;

    return Random ;
}

void FillArrayWithRandomNumbers(int arr[100] , int &arrLength)
{
    for (int i = 0 ; i < arrLength ; i++)
    {
        arr[i] = RandomNumber(1,100) ;
    }
}

void AddArayElement(int Number , int arr[100] , int &arrLength)
{
    arrLength ++ ;
    arr[arrLength - 1] = Number ;
}

void CopyPrimeNumbers(int arr1[100] , int arr2[100] , int arrLength , int &arr2length)
{
    for (int i = 0 ; i < arrLength ; i++)
    {
        if (CheckPrime(arr1[i]) == prime)
        {
            AddArayElement(arr1[i] , arr2 , arr2length) ;
        }
    }
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

    srand((unsigned)time(NULL)) ;

    int arr1[100] , arr2[100] , arrLength = 0 , arr2length = 0 ;

    arrLength = ReadPositiveNumber() ;

    FillArrayWithRandomNumbers(arr1 , arrLength) ;
    CopyPrimeNumbers(arr1 , arr2 , arrLength , arr2length) ;

    cout << "\nArray 1 Elements : \n" ;
    printArray(arr1 , arrLength) ;

    cout << "\n\nArray 2 Prime Numbers : \n" ;
    printArray(arr2 , arr2length) ;



    return 0;
}
