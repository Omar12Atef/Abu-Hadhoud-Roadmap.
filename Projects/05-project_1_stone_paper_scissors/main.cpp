#include <iostream>
using namespace std;

enum enGameChoice { Stone = 1 , Paper = 2 , Scissor = 3 } ;
enum enWinner { Player = 1 , Computer = 2 , Draw = 3 } ;


struct stRoundInfo
{
    int RoundNumber = 0 ;
    enGameChoice PlayerChoise ;
    enGameChoice ComputerChoise ;
    enWinner Winner ;
    string WinnerName ;
} ;


struct stGameResult
{
    int NumberOfRounds ;
    int PlayerWinTimes ;
    int ComputerWinTimes ;
    int DrawTimes ;
    enWinner Winner ;
    string WinnerName = "" ;
} ;


int ReadHowManyRounds()
{
    int Number = 0 ;

    do
    {
        cout << "How Many Rounds 1 to 10 ? " ;
        cin >> Number ;
    } while (Number < 1 || Number > 10) ;

    return Number ;
}


enGameChoice ReadPlayerChoise()
{
    int Choise ;

    do
    {
        cout << "Your Choise: [1]:stone , [2]:paper , [3]:Scissor.\n" ;
        cin >> Choise ;
    } while (Choise < 1 || Choise > 3) ;

    return (enGameChoice) Choise ;
}


int RandomNumber (int From , int To)
{
    int random = rand() % (To - From + 1) + From ;

    return random ;
}


enGameChoice GetComputerChoise()
{
    return enGameChoice(RandomNumber(1 , 3)) ;
}


enWinner WhoWonTheRound(stRoundInfo RoundInfo)
{
    if (RoundInfo.PlayerChoise == RoundInfo.ComputerChoise)
        return enWinner::Draw ;
    
    else if((RoundInfo.PlayerChoise == enGameChoice::Stone && RoundInfo.ComputerChoise == enGameChoice::Scissor) ||
            (RoundInfo.PlayerChoise == enGameChoice::Paper && RoundInfo.ComputerChoise == enGameChoice::Stone) ||
            (RoundInfo.PlayerChoise == enGameChoice::Scissor && RoundInfo.ComputerChoise == enGameChoice::Paper))
                return enWinner::Player ;
    else
        return enWinner::Computer ;
}


enWinner WhoWonTheGame(int PlayerWins , int ComputerWins , int Draws)
{
    if (PlayerWins > ComputerWins)
        return enWinner::Player ;

    else if (ComputerWins > PlayerWins)
        return enWinner::Computer ;
    
    else
        return enWinner::Draw ;
}


string WinnerName(enWinner Winner)
{
    string arrWinnerName[3] = {"player" , "Computer" , "Draw"} ;
    return arrWinnerName[Winner - 1] ;
}


string ChoiceName(enGameChoice Choice)
{
    string arrChoiceName[3] = {"Stone" , "Paper" , "Scissor"} ;
    return arrChoiceName[Choice - 1] ;
}


stRoundInfo FillRoundInfo(int GameRound)
{
    stRoundInfo RoundInfo ;

    RoundInfo.RoundNumber = GameRound ;
    RoundInfo.PlayerChoise = ReadPlayerChoise() ;
    RoundInfo.ComputerChoise = GetComputerChoise() ;
    RoundInfo.Winner = WhoWonTheRound(RoundInfo) ;
    RoundInfo.WinnerName = WinnerName(RoundInfo.Winner) ;

    return RoundInfo ;
}


stGameResult FillGameResult(int TotalRounds , int PlayerWins , int ComputerWins , int Draws)
{
    stGameResult GameResult ;

    GameResult.NumberOfRounds = TotalRounds ;
    GameResult.PlayerWinTimes = PlayerWins ;
    GameResult.ComputerWinTimes = ComputerWins ;
    GameResult.DrawTimes = Draws ;
    GameResult.Winner = WhoWonTheGame(PlayerWins , ComputerWins , Draws) ;
    GameResult.WinnerName = WinnerName(GameResult.Winner) ;

    return GameResult ;
}


void PrintGameOverScreen()
{
    cout << "\n\t\t\t-----------------------------------------------\n\n" ;
    cout << "\t\t\t\t\t\t      Game Over+++ \n\n" ;
    cout << "\t\t\t-----------------------------------------------\n\n" ;
}


void PrintRoundResult(stRoundInfo RoundInfo)
{
    cout << "\n----------Round [" << RoundInfo.RoundNumber << "]----------\n\n" ;
    cout << "Player Choise   : " << ChoiceName(RoundInfo.PlayerChoise) << endl ;
    cout << "Computer Choice : " << ChoiceName(RoundInfo.ComputerChoise) << endl ;
    cout << "Round Winner    : " << RoundInfo.WinnerName  << endl ;
    cout << "-----------------------------\n" ;
}


void PrintGameResults(stGameResult GameResult)
{
    cout << "-------------------- [Game Results] -----------------------\n\n" ;
    cout << "Game Rounds        : " << GameResult.NumberOfRounds << endl ;
    cout << "Player Won Times   : " << GameResult.PlayerWinTimes << endl ;
    cout << "Computer Won Times : " << GameResult.ComputerWinTimes << endl ;
    cout << "Draws Times        : " << GameResult.DrawTimes << endl ;
    cout << "Final Winner       : " << GameResult.WinnerName << endl ;
    cout << "\n---------------------------------------------------------\n\n" ;
}


void StartGame()
{
    char PlayAgain = 'Y' ;


    do
    {
        int HowManyRounds = ReadHowManyRounds() ;
        int PlayerWinTimes = 0 , ComputerWinTimes = 0 , DrawTimes = 0 ;

        for (int round = 1 ; round <= HowManyRounds ; round++)
        {
            cout << "\nRound [" << round << "] begins :\n\n" ;
            stRoundInfo RoundInfo = FillRoundInfo(round) ;
            PrintRoundResult(RoundInfo) ;

            if (RoundInfo.Winner == enWinner::Player)
                PlayerWinTimes++ ;
            
            else if (RoundInfo.Winner == enWinner::Computer)
                ComputerWinTimes++ ;
            
            else
                DrawTimes++ ;
        }

        PrintGameOverScreen() ;

        stGameResult GameResults = FillGameResult(HowManyRounds , PlayerWinTimes , ComputerWinTimes , DrawTimes) ;
        PrintGameResults(GameResults) ;

        cout << "Do you want to play again? Y/N ? " ;
        cin >> PlayAgain ;

    } while (PlayAgain == 'Y' || PlayAgain == 'y') ;
}


int main() 
{

    srand((unsigned)time(NULL)) ;

    StartGame() ;

    return 0;
}
