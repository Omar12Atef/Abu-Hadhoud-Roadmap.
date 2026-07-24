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

void swap ( int &a , int &b)
{
    int temp = a ;
    a = b ;
    b = temp ;
}

int RandomNumber (int From , int To)
{
    int Random = rand() % (To - From + 1) + From ;

    return Random ;
}

void FillArrayWith_1ToN (int arr[100] , int arrLength)
{
    for (int i = 0 ; i < arrLength ; i++)
    {
        arr[i] = i + 1 ;
    }
}

void ShuffleArray (int arr[100] , int arrLength)
{
    for (int i = 0 ; i < arrLength ; i++)
    {
        int RandomIndex = RandomNumber(1 , arrLength) ;

        swap (arr[i] , arr[RandomIndex]) ;
    }
}

void PrintArray (int arr[100] , int arrLength)
{
    for (int i = 0 ; i < arrLength ; i++)
    {
        cout << arr[i] << " " ;
    }
}







int main() 
{
    srand((unsigned) time (NULL)) ;

    int arr[100] , arrLength ;

    arrLength = ReadPositiveNumber("Please, Enter Number Of Elements :") ;

    FillArrayWith_1ToN(arr , arrLength) ;

    cout << "Array Elements Before Shufle : \n" ;
    PrintArray(arr , arrLength) ;

    ShuffleArray(arr , arrLength) ;

    cout << "\nArray Elements After Shuffle : \n" ;
    PrintArray(arr , arrLength) ;

    return 0;
}
