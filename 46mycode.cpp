//Advanced-46 2
#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std  ;


int Read_Number(string Message)
{
    int Number;
    cout << Message;
    cin >> Number ;

    return Number ;
}

bool Is_Negative_Number(int Number)
{
    return Number < 0;
}


int MyAbs(int Number)
{
    if(Is_Negative_Number(Number))
    {
        return Number * -1 ;
    }

    return Number ;
}


int main()
{
    int Number = Read_Number("plese enter Number : " ) ;
    cout << "\nmy abs : " << MyAbs(Number) ;
    cout << "\nC++ abs : " << abs(Number);

}
