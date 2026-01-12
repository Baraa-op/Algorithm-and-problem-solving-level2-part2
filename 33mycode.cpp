//Advanced-33- 2
#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std  ;

int Read_Positive_Numbers(string Message)
{

    int Number = 0   ;
    do
    {
        cout << Message ;
        cin >> Number;
        cout << "\n" ;

    } while(Number <= 0 );

    return Number;


}

int Random_Number(int From , int To)
{
    int Random = rand() % (To - From + 1) + From ;
    return Random ;
}





enum enCharType {SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4};



char Get_Random_Charactor(enCharType CharType)
{
    switch(CharType)
    {
    case SmallLetter :
        return char(Random_Number(97, 122)) ;
    case CapitalLetter :
        return char(Random_Number(65, 90)) ;
    case SpecialCharacter :
        return char(Random_Number(33, 47 )) ;
    case Digit :
        return char(Random_Number(48, 57)) ;

    }
    return '\0' ;

}



/**

void Random_Array(string arr[100], int &ArrLength)
{

    cout << "Plese enter length of array : " ;
    cin >> ArrLength;


    for(int i = 0 ; i<ArrLength ; i++)
    {
        arr[i] = Random_Number(1 , 100) ;
    }
    cout <<"\n" ;

}
**/

void Print_Array(string Arr[100], int ArrLength)
{
    for(int i = 0 ; i<ArrLength ; i++)
    {
        cout << Arr[i] << " " ;
    }
}

string Generate_Block()
{

    string Text = "";
    
    for(int j = 1 ; j <= 4 ; j++)
    {
        Text = Text + Get_Random_Charactor(enCharType::CapitalLetter) ;
    }
    
    return Text ;
}


string Kay_Generate()
{
    string Text = Generate_Block()  ;
    for(int i = 2 ; i<=4 ; i++)
    {
        Text = Text + "-" + Generate_Block()  ;
    }
    return Text ;
}

void Keys_Number(string arr[100] , int ArrLength)
{
    for(int i = 0 ; i<ArrLength; i++)
    {
        arr[i] = Kay_Generate() ;
        cout << "Key [" << i + 1<< "] : " << arr[i] << "\n" ;
    }
}



int main()
{
    srand((unsigned)time(NULL));

    int ArrLength ;
    cout << "Plese enter length of array : " ;
    cin >> ArrLength;
    
    string arr[100] ;
    
    
    //Random_Array(arr , ArrLength);
    Keys_Number(arr , ArrLength);


}


