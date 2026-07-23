#include <iostream>
#include <cmath>

using namespace std;

enum enPrimeNotPrime { prime=1 , NotPrime=2 } ;

int RandomNumber (int From , int To)
{
    int random = rand() % (To - From + 1) + From ;
    return random ;
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

void CopyPrimeNumbers(int arr1[100] , int arr2[100] , int ArrLength , int &Arr2Length)
{
    int j = 0 ;

    for (int i=0 ; i<ArrLength ; i++)
    {
        if (CheckPrime(arr1[i]) == prime)
        {
            arr2[j] = arr1[i] ;
            j ++ ;
        }
    }

    Arr2Length = j ;
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

    int arr1[100] , arr2[100] , ArrLength , Arr2Length ;

    ArrLength = ReadPositiveNumber("Enter The length of array : ") ;
    FillArrayWithRandomNumbers(arr1 , ArrLength) ;

    cout << "Array 1 Elements : " ;
    PrintArray(arr1 , ArrLength) ;

    CopyPrimeNumbers(arr1 , arr2 , ArrLength , Arr2Length) ;

    cout << "\nPrime Numbers in array 1 : \n" ;
    PrintArray(arr2 , Arr2Length) ;


    return 0;
}
