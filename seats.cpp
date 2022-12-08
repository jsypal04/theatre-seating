#include <iostream>
#include <iomanip>
using namespace std;

int getNumSeatsinRow(int row, char seatChart[][])
{
    
    int numAvailSeats[];
    int count = 0;
    int total = 0;
    for( int i = 0; int < row; i++)
    {
        for(int j = 0; j < 15; j++)
        {
            if(seatchart[i][j] = "#")
            {
                count++;  
                cout << seatchart[i][j] << " is available ";
            } 
            else
            {
                cout << seatchart[i][j] << " is taken ";
            }    
        }       
        
        total += count;
        numAvailSeats[i] = count;
    
        count = 0;        
    }
return total;              
}   

void printSeatChart(char seatChart[][30])
{
    cout <<setw(26) <<"Seats" <<endl;
    cout <<setw(40) <<right <<"123456789012345678901234567890" <<endl;
    for(int row = 0; row < 15; row ++)
    {
        cout <<"Row " <<row;
        if(row < 10)
            cout <<"     ";
        else
            cout <<"    ";
        
        for(int seat = 0; seat < 30; seat++)
        {
            cout <<seatChart[row][seat];
        }
        cout <<endl;
    }

}

void getPrices(double prices[15])
{
    for(int row = 0; row < 15; row++)
    {
        cout <<"Enter the price for row " <<(row + 1) <<": ";
        cin >> prices[row];
    }
}

int main() {
    char seatChart[15][30];
    for(int row = 0; row < 15; row++)
    {
        for(int seat = 0; seat < 30; seat++)
        {
            seatChart[row][seat] = '#';
        }
    }
    return 0;
}