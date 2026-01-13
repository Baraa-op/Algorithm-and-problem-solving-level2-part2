
//Advanced-40- 2
#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
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

bool Is_Odd_Number(int Number)
{
    return Number % 2 != 0 ;
}




int Random_Number(int From , int To)
{
    int Random = rand() % (To - From + 1) + From ;
    return Random ;
}



void Random_Array(int Arr[100], int &ArrLength)
{

    cout << "Plese enter length of array : " ;
    cin >> ArrLength;


    for(int i = 0 ; i<ArrLength ; i++)
    {
        Arr[i] = Random_Number(1 , 100) ;
    }
    cout <<"\n" ;

}

void Print_Array(int Arr[100], int ArrLength)
{
    for(int i = 0 ; i<ArrLength ; i++)
    {
        cout << Arr[i] << " " ;
    }
}



void Add_Array_Elements(int Number , int arr[100], int& Arr2Length)
{
    arr[Arr2Length] = Number;
    Arr2Length++ ;
}

bool Distinct_Number(int Number , int arr[100] , int &ArrLength)
{
    for(int i = 1 ; i < ArrLength; i++)
    {
        if(Number != arr[i])
            return true;
    }
    
    return false ;
}

void Copy_distinct_Number_From_Array(int arr[100] , int ArrLength , int arr2[100] , int& Arr2Length)
{
    Add_Array_Elements(arr[0] , arr2 , Arr2Length);
    
    for(int i = 1 ; i < ArrLength; i++)
    {
        if(Distinct_Number(arr2[i] , arr , ArrLength ))
        {
            Add_Array_Elements(arr[i] , arr2 , Arr2Length);
        }
    }
}



int main()
{

    srand((unsigned)time(NULL));
    
	
    int ArrLength ;
    int Arr2Length = 0 ;
    int arr[100] ;
    int arr2[100] ;
    cout << "\n" ;
    
    
    Random_Array(arr, ArrLength) ;
    cout << "\n" ;
    
    
    cout << "array Elements : " ;
    Print_Array(arr, ArrLength);
    cout << "\n" ;
    cout << "dist number in array : " ;
    Copy_distinct_Number_From_Array(arr , ArrLength , arr2 , Arr2Length);
    Print_Array(arr2,  Arr2Length);
    cout << "\n" ;
    return 0 ;
    
}
