#include <iostream>
using namespace std;

int RandonNumber(int From , int To)
{
    int randNumber = rand() % (To - From + 1) + From ;
    return randNumber ;
}

int main() 
{

srand((unsigned)time(NULL)) ;

cout << RandonNumber( 1 , 5) << endl ;
cout << RandonNumber( 1 , 5) << endl ;
cout << RandonNumber( 1 , 5) << endl ;
cout << RandonNumber( 1 , 5) << endl ;
cout << RandonNumber( 1 , 5) << endl ;
cout << RandonNumber( 1 , 5) << endl ;



    return 0;
}
