//Advanced-45 2
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
    }while(Number <= 0);
    
    return Number ;
}

bool Is_Negative_Number(int Number)
{
    return Number < 0;
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
        arr[i] = Random_Number(-100,100) ;
    }
}


void Print_Array_Element(int arr[100] , int &ArrLength)
{
    for(int i = 0 ; i < ArrLength; i++)
    {
        cout << "array [ " << i+1 << " ] : " << arr[i] << "\n" ;
    }
}

int Negative_Number_In_Array(int arr[100] , int &ArrLength)
{
    int Number_Of_Negative= 0 ;
    for(int i = 0 ; i < ArrLength; i++)
    {
        if(Is_Negative_Number(arr[i]))
        {
            Number_Of_Negative++ ;
        }
    }
    
    return Number_Of_Negative;
}



int main()
{
    srand((unsigned)time(NULL));
    
    int arr[100] , ArrLength = 0;
    
    Fill_Array_With_Random_Number(arr , ArrLength);
    cout << "array Elements:\n" ; 
    Print_Array_Element(arr , ArrLength);
    cout << "\n" ;
    
    cout << "Negative Number in array is : " ;
    cout << Negative_Number_In_Array(arr , ArrLength) ;
}    
