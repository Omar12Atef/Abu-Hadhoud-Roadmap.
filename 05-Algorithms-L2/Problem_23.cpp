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



    return 0;
}
