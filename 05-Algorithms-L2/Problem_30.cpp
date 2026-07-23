#include <iostream>
#include <cmath>

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

void FillArrayWithRandomNumbers(int arr[100] , int &ArrLength)
{
    for (int i = 0 ; i < ArrLength ; i++)
    {
        arr[i] = RandomNumber(1 , 100) ;
    }
}

void SumOf_2_Arrays(int arr1[100] , int arr2[100] , int arrSum[100] , int ArrLength)
{
    for (int i = 0 ; i < ArrLength ; i++ )
    {
        arrSum[i] = arr1[i] + arr2[i] ;
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

    int arr1[100] , arr2[100] , arrSum[100] , ArrLength ;

    ArrLength = ReadPositiveNumber("Enter The length of 2 arrayes : ") ;
    
    FillArrayWithRandomNumbers(arr1 , ArrLength) ;
    FillArrayWithRandomNumbers(arr2 , ArrLength) ;

    SumOf_2_Arrays(arr1 , arr2 , arrSum , ArrLength) ;

    cout << "Array 1 Elements : " ;
    PrintArray(arr1 , ArrLength) ;

    cout << "\n\nArray 2 Elements : " ;
    PrintArray(arr2 , ArrLength) ;

    cout << "\n\nSum Of 2 Arrays is : " ;
    PrintArray(arrSum , ArrLength) ;




    return 0;
}
