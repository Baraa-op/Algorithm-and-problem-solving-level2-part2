// PROJECT 1


#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std  ;
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


enum enType {Paper = 1, Stone = 2, Scissor = 3};


int Random_Number(int From, int To)
{
    int Random = rand() % (To - From + 1) + From ;
    return Random ;
}

enType Computer_Choose()
{
    return enType(Random_Number(1,3));
}

enType Player_Choose()
{
    return enType(Read_Number_From_To("your choose (1 = Paper / 2 = stone / 3 = Scissor) : ", 1, 3)) ;
}

int Round_Winner(enType PlayerChoose,enType ComputerChoose )
{

    // 0 = no winner , 1 = player winner , -1 = Computer win
    if(PlayerChoose == ComputerChoose)
        return 0 ;
    else if(PlayerChoose == Paper && ComputerChoose == Stone)
        return 1 ;
    else if(PlayerChoose == Stone && ComputerChoose == Scissor )
        return 1 ;
    else if(PlayerChoose == Scissor && ComputerChoose == Paper)
        return 1 ;
    else if(PlayerChoose == Paper && ComputerChoose == Scissor)
        return -1 ;
    else if(PlayerChoose == Scissor && ComputerChoose == Stone )
        return -1 ;
    else if(PlayerChoose == Stone && ComputerChoose == Paper)
        return -1 ;
}

string Print_Round_Winner(int RoundWinner)
{
    switch(RoundWinner)
    {
    case 1 :
    {
        system("color 20") ;
        return "player won " ;
    }

    case 0 :
    {
        system("color 60") ;
        return "No Winner" ;
    }

    case -1 :
    {
        system("color 40") ;
        return "Computer Won " ;

    }
    }
}

string EnumToString(enType type)
{
    switch (type)
    {
    case Stone:
        return "stone" ;
    case Paper:
        return "Paper";
    case Scissor:
        return "Scissors";
    default:
        return "Unknown";
    }
}


void Round_Numbers(int RoundNumber, int& PlayerWins, int& ComputerWins, int& Draw )
{

    for(int i = 1 ; i <= RoundNumber ; i++)
    {
        cout << "\n" ;
        cout << "Round [ " << i << " ] begins : \n\n" ;
        enType PlayerChoose = Player_Choose();
        enType ComputerChoose = Computer_Choose() ;
        cout << "\n\n" ;
        cout << "______________________Round [ " << i << " ] ______________________" ;
        cout << "\n\n" ;
        cout << "player choice : " << EnumToString(PlayerChoose) ;
        cout << "\n" ;
        cout << "Computer choice : " << EnumToString(ComputerChoose) ;
        cout << "\n" ;
        int RoundWinner = Round_Winner(PlayerChoose, ComputerChoose);
        cout << "round Winner : " << Print_Round_Winner(RoundWinner) ;
        cout << "\n" ;
        cout << "_________________________________________________________\n\n" ;
        if(RoundWinner == 1)
            PlayerWins++ ;
        else if(RoundWinner == -1)
        {
            ComputerWins++;
        }
        else
            Draw++;
    }
}

void Print_Result(int Rounds, int PlayerWins, int ComputerWins, int Draw)
{
    cout << "\n\n\n" ;
    cout << "\t\t__________________________________________________________________________________________________________________\n" ;
    cout << "\t\t+++ G a m e O v e r +++\t\t\n" ;
    cout << "\t\t_________________________________________________________ [ Game Results ] ________________________________________\n" ;
    cout << "\t\tgame Rounds : " << Rounds << endl ;
    cout << "\t\tplayer won times : " << PlayerWins << "\n" ;
    cout << "\t\tComputer won times : " << ComputerWins << "\n" ;
    cout << "\t\tDraw times : " << Draw << "\n" ;
    if(PlayerWins == ComputerWins)
        cout << "\t\tfinal winner : Draw [No Winner] " ;
    else if(PlayerWins > ComputerWins)
        cout << "\t\tfinal winner : player won " ;
    else
        cout << "\t\tComputer won " ;
}





int main()
{
    srand((unsigned)time(NULL)) ;


    bool Play_Again ;

    do
    {
        int RoundNumber =  Read_Number_From_To("how many rounds (1-10)? : ", 1, 10);
        int PlayerWins = 0;
        int ComputerWins = 0;
        int Draw = 0 ;
        Round_Numbers(RoundNumber, PlayerWins, ComputerWins, Draw );
        Print_Result(RoundNumber, PlayerWins, ComputerWins, Draw);
        cout << "\n\n\n\n" ;
        string Play = "" ;
        cout << "\t\tDo want to play again (Y/N) ? " ;
        cin >> Play ;
        if(Play == "Y" || Play == "y")
        {
            Play_Again = true ;
        }
        else
            Play_Again = false ;

        system("clear") ;
        system("color 70") ;
    } while(Play_Again);


}

