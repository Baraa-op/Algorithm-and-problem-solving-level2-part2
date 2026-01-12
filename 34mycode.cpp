//Advanced-34- 2
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







void Random_Array(int arr[100], int &ArrLength)
{

    cout << "Plese enter length of array : " ;
    cin >> ArrLength;


    for(int i = 0 ; i<ArrLength ; i++)
    {
        arr[i] = Random_Number(1 , 100) ;
    }
    cout <<"\n" ;

}


void Print_Array(int arr[100], int ArrLength)
{
    for(int i = 0 ; i<ArrLength ; i++)
    {
        cout << arr[i] << " " ;
    }
}


bool Check_Number(int Number, int arr[100], int ArrLength)
{
    for(int i = 0 ; i<ArrLength ; i++)
    {
        if(Number == arr[i])
        {
            return true ;
        }
    }
    
    return false;
}

void Index_Array(int NumberForSearch , int arr[100] , int ArrLength)
{
    
    cout << "Number you looking for: " << NumberForSearch ;
    cout << "\n" ;
    
    if(Check_Number(NumberForSearch, arr , ArrLength))
    {
        for(int i = 0 ; i<ArrLength ; i++)
        {
            if(NumberForSearch == arr[i])
            {
                cout << "the number found as position : " << i+1 << "\n" ;
                cout << "the Number found its order : " << i ;
                break;
            }
        }
    }
    else
    {
        cout << "the Number is not found:( " ;
    }
}



int main()
{
    srand((unsigned)time(NULL));

    int ArrLength ;
    int arr[100] ;
    Random_Array(arr , ArrLength);
    cout << "arrays one elements\n" ;
    Print_Array(arr , ArrLength);
    cout << "\n\n" ;
    int NumberForSearch = Read_Positive_Numbers("plese enter Number to search for : ");
    
    Index_Array(NumberForSearch , arr, ArrLength);
    


}


