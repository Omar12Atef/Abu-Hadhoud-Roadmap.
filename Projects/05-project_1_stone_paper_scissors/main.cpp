#include <iostream>
using namespace std;

enum enGameChoise { Stone = 1, Paper = 2, Scissor = 3 };
enum enWinner { Player = 1, Computer = 2, Draw = 3 };

struct stRoundInfo
{
    int RoundNumber = 0;
    enGameChoise PlayerChoise;
    enGameChoise ComputerChoise;
    enWinner Winner;
    string WinnerName;
};

struct stGameResult
{
    int NumberOfRounds;
    int PlayerWinTimes;
    int ComputerWinTimes;
    int DrawTimes;
    enWinner Winner;
    string WinnerName;
};

int RandomNumber(int From, int To)
{
    int random = rand() % (To - From + 1) + From;
    return random;
}

int HowManyRouonds()
{
    int Rounds;

    do
    {
        cout << "How many rounds do you want? (1 to 10) ? ";
        cin >> Rounds;
    } while (Rounds < 1 || Rounds > 10);

    return Rounds;
}

enGameChoise ReadPlayerChoise()
{
    int Choise;

    do
    {
        cout << "Your choise: [1]:Stone, [2]:Paper, [3]:Scissor. ";
        cin >> Choise;

    } while (Choise < 1 || Choise > 3);

    return (enGameChoise)Choise;
}

enGameChoise ComputerChoise()
{
    return (enGameChoise)RandomNumber(1,3);
}

enWinner WhoWonTheRound(enGameChoise PlayerChoise , enGameChoise ComputerChoise)
{
    if (PlayerChoise == ComputerChoise)
        return enWinner::Draw;

    if ((PlayerChoise == Stone && ComputerChoise == Scissor) ||
        (PlayerChoise == Paper && ComputerChoise == Stone) ||
        (PlayerChoise == Scissor && ComputerChoise == Paper))
            return enWinner::Player;

    return enWinner::Computer;
}

enWinner WhoWonTheGame(int PlayerWinTimes , int ComputerWinTimes)
{
    if (PlayerWinTimes > ComputerWinTimes)
        return enWinner::Player;
    else if (ComputerWinTimes > PlayerWinTimes)
        return enWinner::Computer;
    else
        return enWinner::Draw;
}

string StringWinnerName(enWinner Winner)
{
    string arrWinnerName[3] = { "Player" , "Computer" , "Draw" };
    return arrWinnerName[Winner - 1];
}

string StringChoiceName(enGameChoise Choice)
{
    string arrChoiceName[3] = { "Stone" , "Paper" , "Scissor" };
    return arrChoiceName[Choice - 1];
}

stRoundInfo FillRoundInfo(int NumberOfRound)
{
    stRoundInfo RoundInfo;

    RoundInfo.RoundNumber = NumberOfRound;
    RoundInfo.PlayerChoise = ReadPlayerChoise();
    RoundInfo.ComputerChoise = ComputerChoise();
    RoundInfo.Winner = WhoWonTheRound(RoundInfo.PlayerChoise, RoundInfo.ComputerChoise);
    RoundInfo.WinnerName = StringWinnerName(RoundInfo.Winner);

    return RoundInfo;
}

stGameResult FillGameResults(int NumberOfRounds , int PlayerWinTimes , int ComputerWinTimes , int DrawTimes)
{
    stGameResult GameResult;

    GameResult.NumberOfRounds = NumberOfRounds;
    GameResult.PlayerWinTimes = PlayerWinTimes;
    GameResult.ComputerWinTimes = ComputerWinTimes;
    GameResult.DrawTimes = DrawTimes;
    GameResult.Winner = WhoWonTheGame(PlayerWinTimes, ComputerWinTimes);
    GameResult.WinnerName = StringWinnerName(GameResult.Winner);

    return GameResult;
}

void PrintRoundInfo(stRoundInfo RoundInfo)
{
    cout << "\n---------- Round[" << RoundInfo.RoundNumber << "]----------\n\n";
    cout << "Player Choice   : " << StringChoiceName(RoundInfo.PlayerChoise) << endl;
    cout << "Computer Choice : " << StringChoiceName(RoundInfo.ComputerChoise) << endl;
    cout << "Round Winner    : " << RoundInfo.WinnerName << endl;
    cout << "\n-----------------------------\n\n";
}

void PrintGameResults(stGameResult GameResult)
{

    cout << "\t\t\t------------------------------\n\n";
    cout << "\t\t\t\t+++ Game Over +++\n\n";
    cout << "\t\t\t------------------------------\n\n";

    cout << "----------------- [Game Results] -----------------\n\n";

    cout << "Game Rounds : " << GameResult.NumberOfRounds << endl;
    cout << "Player Won Times : " << GameResult.PlayerWinTimes << endl;
    cout << "Copmuter Won Times : " << GameResult.ComputerWinTimes << endl;
    cout << "Draw Times : " << GameResult.DrawTimes << endl;
    cout << "Final Winner : " << GameResult.WinnerName << endl;

    cout << "--------------------------------------------------\n\n";
}

void StartGame()
{
    char PlayAgain;
    do
    {
        int PlayerWinTimes=0, ComputerWinTimes=0, DrawTimes=0;
        int NumberOfRounds = HowManyRouonds();
        stRoundInfo RoundInfo;
        stGameResult GameResult;

        for (int Round = 1; Round <= NumberOfRounds; Round++)
        {

            cout << "\nRound [" << Round << "] begins\n\n";
            RoundInfo = FillRoundInfo(Round);
            PrintRoundInfo(RoundInfo);

            if (RoundInfo.Winner == Player)
                PlayerWinTimes++;
            else if (RoundInfo.Winner == Computer)
                ComputerWinTimes++;
            else
                DrawTimes++;
        }

        GameResult = FillGameResults(NumberOfRounds, PlayerWinTimes, ComputerWinTimes, DrawTimes);
        PrintGameResults(GameResult);

        cout << "Do you want to play again? Y/N ? ";
        cin >> PlayAgain;

    } while (PlayAgain == 'Y' || PlayAgain == 'y');

}

int main()
{
    srand((unsigned)time(NULL));
    StartGame();
}
