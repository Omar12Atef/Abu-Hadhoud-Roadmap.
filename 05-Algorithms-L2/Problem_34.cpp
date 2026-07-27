#include <iostream>
using namespace std;

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

int RandomNumber(int From , int To)
{
    int Random = rand() % (To - From + 1) + From ;

    return Random ;
}

void FillArrayWithRandomNumber(int arr[100] , int ArrLength)
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

int SearchNumberPosition(int arr[100] , int arrLength , int NumberToSearch)
{
    for (int i = 0 ; i < arrLength ; i++)
    {
        if (arr[i] == NumberToSearch)
            return i ;
    }

    return -1 ;
}



int main() 
{
    srand ((unsigned) time (NULL)) ;

    int arr[100] , arrLength , NumberToSearch ;

    arrLength = ReadPositiveNumber("Please, Enter Number Of Elements : ") ;

    FillArrayWithRandomNumber(arr , arrLength) ;

    cout << "\nArray 1 Elements :" << endl ;
    PrintArray(arr , arrLength) ;

    NumberToSearch = ReadPositiveNumber("\n\nPlease, Enter a Number to search for?") ;
    int NumberIndex = SearchNumberPosition(arr , arrLength , NumberToSearch) ;
    cout << "\nNumber you are looking for is : " << NumberToSearch ;

    if (NumberIndex == -1)
    {
        cout << "\nThe Number isn't found." ;
    }
    else
    {
        cout << "\nThe Number found ar position : " << NumberIndex ;
        cout << "\nThe Number found its order : " << NumberIndex + 1 ;
    }
    


    return 0;
}
