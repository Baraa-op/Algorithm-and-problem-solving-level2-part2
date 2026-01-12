//Advanced-35- 2
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

    } while(Number < 0 );

    return Number;


}





void Add_Array_Elements(int Number , int arr[100], int& ArrLength)
{
    arr[ArrLength] = Number;
    ArrLength++ ;
}





void Print_Array(int arr[100], int ArrLength)
{
    for(int i = 0 ; i<ArrLength ; i++)
    {
        cout << arr[i] << " " ;
    }
}







int main()
{
    int arr[100];
    int ArrLength;
    bool AddMore = true ;
    
    do
    {
        int Number = Read_Positive_Numbers("plese enter Number");
        Add_Array_Elements(Number , arr , ArrLength) ;
        cout << "do you need to add number ? (1 = yes , 0 = no) : ";
        cin >> AddMore;
    }while(AddMore);
    
    Print_Array(arr , ArrLength);
}


    
