#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

enum enGameChoice { Stone = 1, Paper = 2, Scissor = 3 };
enum enWinner { Player = 1, Computer = 2, Draw = 3 };


struct stRoundInfo
{
	int RoundNumber = 0;
	enGameChoice PlayerChoise;
	enGameChoice ComputerChoice;
	enWinner Winner;
	string WinnerName;
};

struct stGameResults
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

int HowManyRounds()
{
	int Number;

	do
	{
		cout << "How Many Rounds do you want? [1 to 10] ";
		cin >> Number;

	} while (Number < 1 || Number > 10);

		return Number;
}


enGameChoice ReadPlayerChoice()
{
	int Choice;

	do
	{
		cout << "Your Choice: [1]:Stone , [2]:Paper , [3]:Scissor. : ";
		cin >> Choice;
	} while (Choice < 1 || Choice > 3);

	return (enGameChoice)Choice;
}

enGameChoice ReadComputerChoice()
{
	return (enGameChoice)RandomNumber(1, 3);
}

enWinner WhoWonTheRound(enGameChoice PlayerChoice, enGameChoice ComputerChoice)
{
	if (PlayerChoice == ComputerChoice)
		return enWinner::Draw;

	if ((PlayerChoice == Stone && ComputerChoice == Scissor) ||
		(PlayerChoice == Paper && ComputerChoice == Stone) ||
		(PlayerChoice == Scissor && ComputerChoice == Paper))
		return enWinner::Player;

	return enWinner::Computer;
}

enWinner WhoWonTheGame(int PlayerWonTimes, int ComputerWonTimes)
{
	if (PlayerWonTimes > ComputerWonTimes)
		return enWinner::Player;
	else if (PlayerWonTimes < ComputerWonTimes)
		return enWinner::Computer;
	else
		return enWinner::Draw;
}

string StringWinnerName(enWinner Winner)
{
	string arrWinnerName[3] = { "Player" , "Computer" , "Draw" };
	return arrWinnerName[Winner - 1];
}

string StringChoiceName(enGameChoice Choice)
{
	string arrChoiceName[3] = { "Stone" , "Paper" , "Scissor" };
	return arrChoiceName[Choice - 1];
}



stRoundInfo FillRoundInfo(int NumberOfRound)
{
	stRoundInfo RoundInfo;

	RoundInfo.RoundNumber = NumberOfRound;
	RoundInfo.PlayerChoise = ReadPlayerChoice();
	RoundInfo.ComputerChoice = ReadComputerChoice();
	RoundInfo.Winner = WhoWonTheRound(RoundInfo.PlayerChoise, RoundInfo.ComputerChoice);
	RoundInfo.WinnerName = StringWinnerName(RoundInfo.Winner);

	return RoundInfo;

}

stGameResults FillGameResults(int NumberOfRounds, int PlayerWinTimes, int ComputerWinTimes, int DrawTimes)
{
	stGameResults GameResult;

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
	cout << "\n------ Round [" << RoundInfo.RoundNumber << "] ------\n\n";
	cout << "PlayerChoice    : " << StringChoiceName(RoundInfo.PlayerChoise) << endl;
	cout << "Computer Choice : " << StringChoiceName(RoundInfo.ComputerChoice) << endl;
	cout << "Round Winner    : " << RoundInfo.WinnerName;
	cout << "\n\n------------------------------------ \n\n";
}

void PrintGameResults(stGameResults GameResult)
{
	cout << "\t\t --------------------------------------\n\n";
	cout << "\t\t\t +++ [Game Over] +++ \n\n";
	cout << "\t\t --------------------------------------\n\n";

	cout << "------------------- [Game Results] -------------------\n\n";

	cout << "GameRounds         : " << GameResult.NumberOfRounds << endl;
	cout << "Player Won Times   : " << GameResult.PlayerWinTimes << endl;
	cout << "Computer Won Times : " << GameResult.ComputerWinTimes << endl;
	cout << "Draw Times         : " << GameResult.DrawTimes << endl;
	cout << "Final Winner       : " << GameResult.WinnerName << endl;

	cout << "------------------------------------------------------\n\n";

}

void StartGame()
{
	char PlayAgain;

	do
	{
		int PlayerWinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;
		int NumberOfRounds = HowManyRounds();
		stRoundInfo RoundInfo;
		stGameResults GameResult;

		for (int Round = 1; Round <= NumberOfRounds; Round++)
		{
			cout << "\nRound [" << Round << "] begins : \n\n";
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

		cout << "Do you want to play again? [Y/N] ";
		cin >> PlayAgain;
	} while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main()
{
	srand((unsigned)time(NULL));
	StartGame();
	return 0;
}
