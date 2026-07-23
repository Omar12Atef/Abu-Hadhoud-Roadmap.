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

int SumOfArrayElements (int arr[100] , int ArrLength)
{

    int sum = 0 ;
    for (int i = 0 ; i < ArrLength ; i++)
    {
        sum = sum + arr[i] ;
    }

    return sum ;
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

    int arr[100] , ArrLength ;

    ArrLength = ReadPositiveNumber("Enter The length of array : ") ;
    FillArrayWithRandomNumbers(arr , ArrLength) ;

    cout << "Array Elements : " ;
    PrintArray(arr , ArrLength) ;

    cout << "\nSum of All Numbers is : " << SumOfArrayElements(arr , ArrLength) ;



    return 0;
}
