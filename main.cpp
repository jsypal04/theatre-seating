#include <iostream>
using namespace std;

int main() {
 
}    

int getNumSeatsinRow(int row, char seatChart[][])
{
    
    int numAvailSeats[];
    int count = 0;
    int total = 0;
    for( int i = 0; int < row; i++)
    {
        for(int j = 0; j < 15; j++)
        {
            if(seatchart[i][j] = "#')
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
