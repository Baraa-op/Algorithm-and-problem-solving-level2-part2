#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int Read_Number_From_To(string Message, int From, int To)
{

    int Number = 0   ;
    do
    {
        cout << Message ;
        cin >> Number;
        cout << "\n" ;

    } while(Number < From || Number > To );

    return Number;


}


enum enDifficulty {Easy = 1, Mid = 2, Hard = 3, Mix = 4};

enum enOperatorType {Add = 1, Sub = 2, Multi = 3, Div = 4, OpMix = 5};

struct stGameInfo
{
    int Number_Of_Question ;
    int Answer;
    int Right_Answer_Number ;
    int Wrong_Answer_Number ;

};

enDifficulty Read_Difficulty()
{
    return enDifficulty(Read_Number_From_To("plese enter Difficulty {easy = 1 , Mid = 2 , Hard = 3 , Mix = 4} : ", 1, 4)) ;
}

enOperatorType Read_OperatorType()
{
    return enOperatorType(Read_Number_From_To("plese enter operator type {Add = 1 , Sub = 2 , Multi = 3 , Div = 4 , Mix = 5}  :  ", 1, 5)) ;
}


bool Is_Right_Number(int Num1, int Num2, enOperatorType OpType)
{
    switch(OpType)
    {
    case Add:
        return Num1 + Num2;
    case Sub:
        return Num1 - Num2;
    case Multi:
        return Num1 * Num2;
    case Div:
        if(Num2 == 0) return false;
        return Num1 / Num2;
    default:
        return false;
    }
}

int Check_Answer(int Num1, int Num2, enOperatorType OpType)
{
    switch(OpType)
    {
    case Add:
        return Num1 + Num2;
    case Sub:
        return Num1 - Num2;
    case Multi:
        return Num1 * Num2;
    case Div:
        if(Num2 == 0) return false;
        return Num1 / Num2;
    default:
        return false;
    }
}


int Random_Number(int From, int To)
{
    int Random = rand() % (To - From + 1) + From ;
    return Random ;
}

int Difficulty(enDifficulty& Difficulty)
{

    switch(Difficulty)
    {
    case Easy :
        return Random_Number(1, 9) ;
    case Mid :
        return Random_Number(10, 99) ;
    case Hard :
        return Random_Number(100, 999) ;
    case Mix :
        return Random_Number(1, 999) ;
    default:
        return -1 ;

    }
}

string EnumToString(enOperatorType OpType)
{
    switch (OpType)
    {
    case Add :
        return " + " ;
    case Sub:
        return " - ";
    case Multi:
        return " × ";
    case Div :
        return " ÷ " ;
    default:
        return "Unknown";
    }
}


void Random_Question(stGameInfo &GameInfo,enDifficulty DifficultyLevel, enOperatorType OpType)
{
    for(int i = 1 ; i <= GameInfo.Number_Of_Question ; i++)
    {

        if(OpType == OpMix)
        {
            OpType = enOperatorType(Random_Number(1,4));
            int Num1 = Difficulty(DifficultyLevel) ;
            int Num2 = Difficulty(DifficultyLevel) ;
            cout << "Question  [" << i << "/" << GameInfo.Number_Of_Question << " ] "  ;
            cout << "\n\n" ;
            cout << Num1 ;
            cout << "\n" ;
            cout << Num2 ;
            cout << EnumToString(OpType) ;
            cout << "\n___________________\n" ;
            cin >> GameInfo.Answer ;
            if(Check_Answer(Num1,Num2, OpType ) == GameInfo.Answer )
            {
                cout << "\nRight answer (: " ;
                GameInfo.Right_Answer_Number++ ;
            }
            else
            {
                cout << "\nWrong answer :( " ;
                GameInfo.Wrong_Answer_Number++ ;
                cout << "right answer is : " << Check_Answer(Num1,Num2, OpType ) ;


            }
            cout << "\n\n" ;
        }

        else
        {
            int Num1 = Difficulty(DifficultyLevel) ;
            int Num2 = Difficulty(DifficultyLevel) ;
            cout << "Question  [" << i << "/ " << GameInfo.Number_Of_Question << " ] "  ;
            cout << "\n\n" ;
            cout << Num1 ;
            cout << "\n" ;
            cout << Num2 ;
            cout << EnumToString(OpType) ;
            cout << "\n___________________\n" ;
            cin >> GameInfo.Answer ;
            if(Check_Answer(Num1,Num2, OpType ) == GameInfo.Answer )
            {
                cout << "\nRight answer (: " ;
                GameInfo.Right_Answer_Number++ ;
            }
            else
            {
                cout << "\nWrong answer :( " ;
                GameInfo.Wrong_Answer_Number++ ;
                cout << "right answer is : " << Check_Answer(Num1,Num2, OpType ) ;


            }
            cout << "\n\n" ;

        }
    }
}




void Print_Result(stGameInfo &GameInfo,enDifficulty DifficultyLevel, enOperatorType OpType)
{
    cout << "\n\n_______________________________________\n\n " ;
    if(GameInfo.Right_Answer_Number >= GameInfo.Wrong_Answer_Number)
    {
        cout << "Final result is pass (: " ;
    }
    else
        cout << "Final result is fail ): " ;
        
    cout << "\n\n_______________________________________\n\n " ;
    cout << "Number of question : " << GameInfo.Number_Of_Question ;
    cout << "\n" ;
    cout << "question Level : " <<  DifficultyLevel;
    cout << "\n" ;
    cout << "OpType : " << EnumToString(OpType) ;
    cout << "\n" ;
    cout << "Number of right answer : " << GameInfo.Right_Answer_Number ;
    cout << "\n" ; 
    cout << "Number of wrong answer : " << GameInfo.Wrong_Answer_Number ;
    cout << "\n" ; 
}

void Start_Game()
{
    char Again = 'Y';

    do
    {
        
        
        stGameInfo GameInfo ;
        GameInfo.Right_Answer_Number = 0 ;
        GameInfo.Wrong_Answer_Number = 0 ;
        GameInfo.Number_Of_Question = Read_Number_From_To("plese enter how many questions you need (1-10) : ", 1, 10);
        enDifficulty DifficultyLevel = Read_Difficulty();
        enOperatorType OpType = Read_OperatorType() ;
        Random_Question(GameInfo, DifficultyLevel, OpType);
        Print_Result(GameInfo, DifficultyLevel, OpType);
        cout << "\n\n\ndo want to play again ? Y/N : " ;
        cin >>  Again;
    } while(Again == 'Y'|| Again == 'y');

}




int main()
{
    srand((unsigned)time(NULL));
    Start_Game();
}
