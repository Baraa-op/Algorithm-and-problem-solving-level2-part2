//Advanced-47 2
#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std  ;


float Read_Number(string Message)
{
    float Number;
    cout << Message;
    cin >> Number ;

    return Number ;
}

bool Is_Negative_Number(int Number)
{
    return Number < 0;
}


int MyRound(float Number)
{
    int First_Digits = int(Number * 10 ) % 10  ;
    if(Is_Negative_Number(Number))
    {
         if(First_Digits <= 4)
        {
            return int(Number-1) ;
        }
        else if(First_Digits >= 4)
        {
            return int(Number)  ;
        }
    }
    else if(!Is_Negative_Number(Number))
    {
        if(First_Digits <= 4)
            return int(Number) ;
    
        else if(First_Digits >= 4)
            return int(Number+1)  ;
    }
    
}


int main()
{
    float Number = Read_Number("plese enter Number : " ) ;
    cout << "\nmy round : " << MyRound(Number) ;
    cout << "\nC++ round : " << round(Number);


}

