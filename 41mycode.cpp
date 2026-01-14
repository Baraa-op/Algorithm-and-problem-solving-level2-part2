//Advanced-41⁹- 2
#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std  ;


void Fill_Array(int arr[100] , int &ArrLength)
{
    ArrLength = 7 ;
    arr[0] = 1 ;
    arr[1] = 2 ;
    arr[2] = 3 ;
    arr[3] = 4 ;
    arr[4] = 3 ;
    arr[5] = 2 ;
    arr[6] = 1 ;
}


void Print_Array_Element(int arr[100] , int &ArrLength)
{
    for(int i = 0 ; i < ArrLength; i++)
    {
        cout << "array [ " << i+1 << " ] : " << arr[i] << "\n" ;
    }
}


void Check_Palindrome_In_Array(int arr[100] , int &ArrLength)
{
    int Counter = 0 ;
    for(int i = 0 ; i < ArrLength ; i++)
    {
        if(arr[i] == arr[ArrLength - 1 - i ])
            Counter++ ;
        
    }
    if(Counter == ArrLength)
        cout << "Palindrome array " ;
    else 
        cout << "not Palindrome array " ;    
        
    
}




int main()
{
    int arr[100] , ArrLength;
    
    Fill_Array(arr , ArrLength);
    cout << "array Elements:\n" ; 
    Print_Array_Element(arr , ArrLength);
    Check_Palindrome_In_Array(arr , ArrLength);
}    
