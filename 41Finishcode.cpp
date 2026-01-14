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

bool Is_Palindrome_Array(int arr[100] , int ArrLength)
{
    for(int i = 0 ; i < ArrLength; i++)
    {
        if(arr[i] != arr[ArrLength - 1 - i ])
            return false ;
    }
    
    return true ;
}



int main()
{
    int arr[100] , ArrLength;
    
    Fill_Array(arr , ArrLength);
    cout << "array Elements:\n" ; 
    Print_Array_Element(arr , ArrLength);
    
    if(Is_Palindrome_Array(arr , ArrLength))
    {
        cout <<"\nPalindrome array \n" ;
    }
    else
        cout <<"\nNot Palindrome array \n" ;
}    
