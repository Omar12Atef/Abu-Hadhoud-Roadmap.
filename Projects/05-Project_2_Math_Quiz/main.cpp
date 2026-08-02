#include <iostream> 
using namespace std;

enum enQuestionLevel {Easy = 1 , medium = 2 , Hard = 3 , Mix = 4} ;
enum enOperationType {Add = 1 , Subtract = 2 , Multiply = 3 , Divide = 4 , MixOp = 5} ;

struct stQuestionInfo
{
    short Number1 = 0 ;
    short Number2 = 0 ;
    enOperationType OpType ;
    short PlayerAnswer = 0 ;
    short CorrectAnswer = 0 ;
    bool IsCorrect = false ;
} ;

struct stQuizInfo
{
    short NumberOfQuestions = 0 ;
    enOperationType OpType ;
    enQuestionLevel QuestionLevel ;
    short NumberOfRightAnswers = 0 ;
    short NumberOfWrongAnswers = 0 ;
    bool IsPass = false ;
} ;

/* ---------------------------------------------------------------------------------------------- */
/* ---------------------------------------------------------------------------------------------- */
/* ---------------------------------------------------------------------------------------------- */

int randomnumber (int From , int To)
{
    int random = rand() % (To - From + 1) + From ;

    return random ;
}


short PlayerAnswer()
{
	short Number ;
	cin >> Number ;
	return Number ;		
}

short ReadNumberOfQuestions()
{
    short NumberOfQuestions ;

    do
    {
        cout << "How many Questions do you want to answer ? " ;
        cin >> NumberOfQuestions ;
    } while (NumberOfQuestions < 1 || NumberOfQuestions > 10) ;

    return NumberOfQuestions ;
}


enQuestionLevel ReadQuizLevel()
{
    short Level ;
    do
    {
        cout << "Enter Question Level : [1]:Easy , [2]:medium , [3]:Hard , [4]:Mix ? " ;
        cin >> Level ; 
    } while (Level < 1 || Level > 4) ;

    return (enQuestionLevel) Level ;
}


enOperationType ReadOpType()
{
    short OpType ;

    do
    {
        cout << "Enter Operation Type : [1]:Add , [2]:Subtract , [3]:Multiply , [4]:Divide , [5]:Mix ? " ;
        cin >> OpType ;
    } while (OpType < 1 || OpType > 5) ;
    
    return (enOperationType) OpType ;
}


short GetRandomNumberByLevel(enQuestionLevel QuestionLevel)
{
    switch (QuestionLevel)
    {
        case enQuestionLevel::Easy :
            return randomnumber(1 , 10) ;

        case enQuestionLevel::medium :
            return randomnumber(10 , 50) ;

        case enQuestionLevel::Hard :
            return randomnumber(50 , 100) ;
        
        case enQuestionLevel::Mix :
            return randomnumber(1 , 100) ;
        default :
            return randomnumber(1 , 10) ;
    }   
}


int simpleCalculator(int Number1 , int Number2 , enOperationType OpType)
{
    switch(OpType)
    {
        case enOperationType::Add :
            return Number1 + Number2 ;
        case enOperationType::Subtract :
            return Number1 - Number2 ;
        case enOperationType::Multiply :
            return Number1 * Number2 ;
        case enOperationType::Divide :
            return Number1 / Number2 ;
        default :
            return Number1 + Number2 ;
    }
}


bool IsAnswerCorrect(stQuestionInfo QuestionInfo)
{
    return QuestionInfo.PlayerAnswer == QuestionInfo.CorrectAnswer ;
}


string GetOpTypeSymbol(enOperationType OpType)
{
    string arrOpSymbols[5] = {"+" , "-" , "*" , "/" , "Mix"} ;
    return arrOpSymbols[OpType - 1] ;
}


string GetQuizLevelName(enQuestionLevel Level)
{
    string arrGameLevel[4] = {"Easy" , "medium" , "Hard" , "Mix"} ;
    return arrGameLevel[Level - 1] ;
}


bool IsPass(short NumberOfRightAnswers , short NumberOfWrongAnswers)
{
    if (NumberOfRightAnswers > NumberOfWrongAnswers)
        return true ;
    else
        return false ;
}


stQuestionInfo FillQuestionInfo(enQuestionLevel QuestionLevel ,enOperationType OpType)
{
    stQuestionInfo QuestionInfo;

    QuestionInfo.Number1 = GetRandomNumberByLevel(QuestionLevel) ;
    QuestionInfo.Number2 = GetRandomNumberByLevel(QuestionLevel) ;

    if (OpType == MixOp)
        QuestionInfo.OpType = (enOperationType) randomnumber(1 , 4) ;
    else
        QuestionInfo.OpType = OpType ;

    QuestionInfo.CorrectAnswer = simpleCalculator(QuestionInfo.Number1 , QuestionInfo.Number2 , QuestionInfo.OpType) ;
    
    return QuestionInfo ;
}


stQuizInfo FillQuiz(short NumberOfQuestions , short NumberOfRightAnswers , short NumberOfWrongAnswers , enOperationType OpType , enQuestionLevel Level)
{
    stQuizInfo Quiz ;

    Quiz.NumberOfQuestions = NumberOfQuestions ;
    Quiz.OpType = OpType ;
    Quiz.QuestionLevel = Level ;
    Quiz.NumberOfRightAnswers = NumberOfRightAnswers ;
    Quiz.NumberOfWrongAnswers = NumberOfWrongAnswers ;
    Quiz.IsPass = IsPass(NumberOfRightAnswers , NumberOfWrongAnswers) ;

    return Quiz ;
}


void PrintQuestionInfo(stQuestionInfo QuestionInfo , short QuestionNumber , short NumberOfQuestions)
{
    cout << "\nQuestion [" << QuestionNumber << "/" << NumberOfQuestions << "]\n\n" ;
    cout << QuestionInfo.Number1 ;
    cout << " " << GetOpTypeSymbol(QuestionInfo.OpType) ;
    cout << " " << QuestionInfo.Number2 ;
    cout << " = ?\n" ;
    cout << "----------------------------------------\n" ;
    
}


void PrintQuiz(stQuizInfo Quiz)
{
    cout << "----------------------------------------\n\n" ;

    if (Quiz.IsPass)
        cout << "\t\tFinal Result is PASS.\n\n" ;
    else
        cout << "\t\tFinal Result is FAIL.\n\n" ;

    cout << "----------------------------------------\n\n" ;

    cout << "Number Of Questions       : " << Quiz.NumberOfQuestions ;
    cout << "\nQuestion Level          : " << GetQuizLevelName(Quiz.QuestionLevel) ;
    cout << "\nOperation Type          : " << GetOpTypeSymbol(Quiz.OpType) ;
    cout << "\nNumber of Right Answers : " << Quiz.NumberOfRightAnswers ;
    cout << "\nNumber of Wrong Answers : " << Quiz.NumberOfWrongAnswers ;

    cout << "\n\n----------------------------------------" ;
}


void PlayQuiz()
{
        short NumberOfQuestions = ReadNumberOfQuestions() ;
        enQuestionLevel Level = ReadQuizLevel() ; 
        enOperationType OpType = ReadOpType() ;
        short NumberOfRightAnswers = 0 , NumberOfWrongAnswers = 0 ;

        for (int QuestionNumber = 1 ; QuestionNumber <= NumberOfQuestions ; QuestionNumber ++)
        {
            stQuestionInfo QuestionInfo = FillQuestionInfo(Level , OpType) ;
            PrintQuestionInfo(QuestionInfo , QuestionNumber , NumberOfQuestions) ;

            QuestionInfo.PlayerAnswer = PlayerAnswer() ;
            QuestionInfo.IsCorrect = IsAnswerCorrect(QuestionInfo) ;

            if (QuestionInfo.IsCorrect)
            {
                cout << "Right Answer.\n\n" ;
                NumberOfRightAnswers++ ;
            }
            else
            {
                cout << "Wrong Answer.\n" ;
                cout << "Correct Answer is : " ;
                cout << QuestionInfo.CorrectAnswer << "\n\n" ;
                NumberOfWrongAnswers++ ;
            }
        }
        stQuizInfo Quiz = FillQuiz(NumberOfQuestions , NumberOfRightAnswers , NumberOfWrongAnswers , OpType , Level) ;
        PrintQuiz(Quiz) ;

}


void StartQuiz()
{
    char PlayAgain = 'y' ;

    do
    {
            PlayQuiz() ;

        cout << "\n\nDo you want to play again? Y/N ? " ;
        cin >> PlayAgain ;

    } while (PlayAgain == 'y' || PlayAgain == 'Y') ;
}


int main() 
{

    srand((unsigned)time(NULL)) ;

    StartQuiz() ;
    
    return 0;
}
