#include <iostream>
using namespace std;

string ReadLetters()
{
    string Letter ;

    cout << "Enter The Letters?\n" ;
    cin >> Letter ;

    return Letter ;
}

void GuessLetter(string Letter)
{
    int counter = 0 ;
    string Guess = "" ;

    for (int i = 65 ; i <= 90 ; i++)
    {
        for (int j = 65 ; j <= 90 ; j++)
        {
            for (int k = 65 ; k <= 90 ; k++)
            {
                counter ++ ;

                Guess = Guess + char(i) ;
                Guess = Guess + char(j) ;
                Guess = Guess + char(k) ;

                cout << "Trial [" << counter << "] : " << Guess << endl ;

                if (Guess == Letter)
                {
                    cout << "\nPassword is " << Guess << endl ;
                    cout << "found after " << counter << " Trial(s)" ;
                    return ;
                }

                Guess = "" ;
            }
        }
    }
    
}

int main() 
{

    GuessLetter(ReadLetters()) ;

    return 0;
}
