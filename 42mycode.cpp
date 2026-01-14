//Advanced-42 2
#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std  ;


int Read_Positive_Number(string Message)
{
    int Number;
    
    do
    {
        cout << Message;
        cin >> Number ;
    }while(Number < 0);
    
    return Number ;
}

bool Is_Odd_Number(int Number)
{
    return Number % 2 != 0 ;
}



int Random_Number(int From , int To)
{
    int Random = rand() % (To - From + 1) + From ;
    return Random;
}



void Fill_Array_With_Random_Number(int arr[100] , int &ArrLength)
{
    ArrLength = Read_Positive_Number("Plese enter length of array : " );
    for(int i = 0 ; i < ArrLength; i++)
    {
        arr[i] = Random_Number(1,100) ;
    }
}


void Print_Array_Element(int arr[100] , int &ArrLength)
{
    for(int i = 0 ; i < ArrLength; i++)
    {
        cout << "array [ " << i+1 << " ] : " << arr[i] << "\n" ;
    }
}

int Odd_Number_In_Array(int arr[100] , int &ArrLength)
{
    int Number_Of_Odd = 0 ;
    for(int i = 0 ; i < ArrLength; i++)
    {
        if(Is_Odd_Number(arr[i]))
        {
            Number_Of_Odd++ ;
        }
    }
    
    return Number_Of_Odd ;
}



int main()
{
    srand((unsigned)time(NULL));
    
    int arr[100] , ArrLength = 0;
    
    Fill_Array_With_Random_Number(arr , ArrLength);
    cout << "array Elements:\n" ; 
    Print_Array_Element(arr , ArrLength);
    cout << "\n" ;
    
    cout << "odd Number in array is : " ;
    cout << Odd_Number_In_Array(arr , ArrLength) ;
}    
