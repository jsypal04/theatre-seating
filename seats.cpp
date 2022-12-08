#include <iostream>
#include <iomanip>
using namespace std;

void printSeatChart(char seatChart[][30])
{
    cout <<setw(26) <<"Seats" <<endl;
    cout <<setw(40) <<right <<"123456789012345678901234567890" <<endl;
    for(int row = 0; row < 15; row ++)
    {
        cout <<"Row " << row + 1;
        if(row < 9)
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

int getNumSeatsinRow(int row, char seatChart[][30])
{
    
    //int numAvailSeats;
    int count = 0;
    //int total = 0;
    for (int i = 0; i < 30; i++) {
        if (seatChart[row][i] == '#') {
            count++;
        }
    }
    // for( int i = 0; i < row; i++)
    // {
    //     for(int j = 0; j < 15; j++)
    //     {
    //         if(seatchart[i][j] == "#")
    //         {
    //             count++;  
    //             cout << seatchart[i][j] << " is available ";
    //         } 
    //         else
    //         {
    //             cout << seatchart[i][j] << " is taken ";
    //         }    
    //     }       
        
    //     total += count;
    //     numAvailSeats[i] = count;
    
    //     count = 0;        
    // }
    return count;              
}   

int purchaseTickets(int &seatsSold, double &revenue, char seatChart[][30], double prices[]) {
	double runningTotal;
	double numTickets = 0;

	while (numTickets <= 450) {
		int choice;
		cout << "Select an Option (type '-1' to exit):\n";
		cout << "1. Buy a ticket\n2. See Running Total\n";
		cin >> choice;

		if (choice == -1) {
			return 0;
		}

		switch (choice) {
			case 1: {
				printSeatChart(seatChart);
				int row;
				int seat;
				do {
					cout << "Enter a row and seat number separated by a space: ";
					cin >> row >> seat;
                    if (seatChart[row - 1][seat - 1] == '*') {
                        cout << "That seat is taken. Choose another one." << endl;
                        continue;
                    }
				} while (row > 15 || seat > 30);

				seatsSold++;
				revenue += prices[row - 1];
				runningTotal += prices[row - 1];
				seatChart[row - 1][seat - 1] = '*';
				numTickets++;
				break;
			}
			case 2: {
				cout << "Your current total is $" << fixed << setprecision(2) << runningTotal << "\n";
				break;
			}
 		}
	}
	return 0;
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
    double revenue = 0.0;
    int seatsSold = 0;
    const int TOTAL_SEATS = 450;
    double prices[15];

    char seatChart[15][30];
    for(int row = 0; row < 15; row++)
    {
        for(int seat = 0; seat < 30; seat++)
        {
            seatChart[row][seat] = '#';
        }
    }

    getPrices(prices);
    printSeatChart(seatChart);

    int choice;
    do {
        cout << "Select an option (enter -1 to exit):";
        cout << "\n1. Purchase Tickets\n2. View Total Ticket Sales\n3. View Total Seats Sold\n4. View Available Seats in A Row\n5. View Available Seats in Auditorium\n";
        cin >> choice;

        switch (choice) {
            case 1: {
                purchaseTickets(seatsSold, revenue, seatChart, prices);
                break;
            }
            case 2: {
                cout << "$" << fixed << setprecision(2) << revenue << " worth of tickets sold." << endl;
                break;
            }
            case 3: {
                cout << seatsSold << " seats have been sold." << endl;
                break;
            }
            case 4: {
                int row;
                cout << "Which row would you like to view? ";
                cin >> row;

                cout << getNumSeatsinRow(row - 1, seatChart) << " seats are availible" << endl;
                break;
            }
            case 5: {
                cout << TOTAL_SEATS - seatsSold << " seats are available" << endl; 
            }
        }
    } while (choice != -1);


    return 0;
}