#include <iostream>
using namespace std;

int ReadPositiveNumber()
{
    int Number ;

    do
    {
        cout << "ُEnter Thr Number : " ;
        cin >> Number ;
    } while (Number <= 0) ;

    return Number ; 
}

void AddElementToArray(int Number , int arr[100] , int &ArrLength)
{
    ArrLength ++ ;
    arr[ArrLength - 1] = Number ;
}


void InputUserNumberInArray(int arr[100] , int &ArrLength)
{
    bool AddMore ;

    do
    {

        AddElementToArray(ReadPositiveNumber() , arr , ArrLength) ;

        cout << "Do you want to add more numbers? [0] : No , [1] : yes? " ;
        cin >> AddMore ;

    } while (AddMore) ;
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
    int arr[100] , ArrLength = 0 ;

    InputUserNumberInArray(arr , ArrLength) ;

    cout << "\nArray Elements : " << ArrLength ;
    cout << "\nArray Elements : " ;
    PrintArray(arr , ArrLength) ;
    return 0;
}
