//Advanced-48-2
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

float GetFractionPart(float Number)
{
    return Number - int(Number) ;
}



int MyFloor(float Number)
{
    int IntPart ;
    IntPart = int(Number) ;
    
    float FractionPart  ;
    FractionPart = GetFractionPart(Number) ;
    if(Is_Negative_Number(Number) && FractionPart != 0)
        return --IntPart ;
    else
        return IntPart ; 
}


int main()
{
    float Number = Read_Number("plese enter Number : " ) ;
    cout << "\nmy floor : " << MyFloor(Number) ;
    cout << "\nC++ floor : " << floor(Number);


}


