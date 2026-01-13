//Advanced-37- 2
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



void Copy_Array_Using_Add_Array_Elements(int arr[100] , int arr2[100],int ArrLength, int& Arr2Length)
{
    for(int i = 0 ; i < ArrLength ; i++)
    {
        Add_Array_Elements(arr[i] , arr2 , Arr2Length);
    }
}


int main()
{

    srand((unsigned)time(NULL));
    
	
    int ArrLength ;
    int Arr2Length = 0 ;
    int Arr[100] ;
    int Arr2[100] ;
    cout << "\n" ;
    
    
    Random_Array(Arr, ArrLength) ;
    cout << "\n" ;
    Copy_Array_Using_Add_Array_Elements(Arr , Arr2 , ArrLength , Arr2Length);
    
    cout << "array Elements : " ;
    Print_Array(Arr, ArrLength);
    cout << "\n" ;
    cout << "copy of array Elements : " ;
    Print_Array(Arr2, Arr2Length);
    cout << "\n" ;
    return 0 ;
}   
