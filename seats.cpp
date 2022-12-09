#include <iostream>
#include <iomanip>
using namespace std;

// Function to print the seat chart
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

// gets the number of available seats in a given row
int getNumSeatsinRow(int row, char seatChart[][30])
{
    // initializes a variable to keep track of the available seats
    int count = 0;
    // iterates through every item in the array at the index of the row
    for (int i = 0; i < 30; i++) {
        // if the seat is not taken, add it to count
        if (seatChart[row][i] == '#') {
            count++;
        }
    }
    // returns count
    return count;              
}   

// the function to purchase tickets
int purchaseTickets(int &seatsSold, double &revenue, char seatChart[][30], double prices[]) {
	// variables to keep track of the total and the number of tickets
    double runningTotal;
	double numTickets = 0;

    // runs a loop so that the user can buy as many tickets as they like, terminating after they have bought 450 tickets (the number of seats in the auditorium)
	while (numTickets <= 450) {
		// collects the user's menu choice
        int choice;
		cout << "Select an Option:\n";
		cout << "1. Buy a ticket\n2. See Running Total\n3. Exit\n";
		cin >> choice;

		if (choice == 3) {
            printSeatChart(seatChart);
            cout <<setprecision(2) <<fixed << "Total price: $" << runningTotal <<endl;

			return 0;
		}

        // a switch statement to handle the menu
		switch (choice) {
            // the case of buying tickets
			case 1: {
                // print the seat chart
				printSeatChart(seatChart);

                // collect user input on what row and seat they want to buy
				int row;
				int seat;
                do
                {
                    cout << "Enter a row and seat number separated by a space: ";
				    cin >> row >> seat;
                    while (row > 15 || row < 1 || seat > 30 || seat < 1)
				    {
                        cout << "That seat does not exist. Choose another one." <<endl;
                        cout << "Enter a row and seat number separated by a space: ";
				        cin >> row >> seat;
				    }
                    if(seatChart[row - 1][seat - 1] == '*')
                    {
                        cout << "Seat is occupied. Choose another one. " <<endl;
                    }
                } while (seatChart[row - 1][seat - 1] == '*');
                

                // adds one to seatsSold, adds price to revenue and runningTotal, marks the seat as taken in the seat chart, adds one to numTickets
				seatsSold++;
				revenue += prices[row - 1];
				runningTotal += prices[row - 1];
				seatChart[row - 1][seat - 1] = '*';
				numTickets++;
				break;
			}
            // the case of viewing the running total
			case 2: {
				cout << "Your current total is $" << fixed << setprecision(2) << runningTotal << "\n";
				break;
			}
 		}
	}
    printSeatChart(seatChart);
    cout <<setprecision(2) <<fixed << "Total price: $" << runningTotal <<endl;
	return 0;
}

// the function to ask the user for the prices for each row
void getPrices(double prices[15])
{
    for(int row = 0; row < 15; row++)
    {
        cout <<"Enter the price for row " <<(row + 1) <<": ";
        cin >> prices[row];
    }
}

// the main function
int main() {
    // sets the global variables to keep track of everything
    double revenue = 0.0;
    int seatsSold = 0;
    const int TOTAL_SEATS = 450;
    double prices[15];

    // creates the seat chart
    char seatChart[15][30];
    for(int row = 0; row < 15; row++)
    {
        for(int seat = 0; seat < 30; seat++)
        {
            seatChart[row][seat] = '#';
        }
    }

    // gets the prices from the user and prints the seat chart
    getPrices(prices);
    printSeatChart(seatChart);

    // the main menu loop
    int choice;
    do {
        // collects the user's menu choice
        cout << "Select an option:";
        cout << "\n1. Purchase Tickets\n2. View Total Ticket Sales\n3. View Total Seats Sold\n4. View Available Seats in A Row\n5. View Available Seats in Auditorium\n6. Exit\n";
        cin >> choice;

        switch (choice) {
            // the purchase tickets case
            case 1: {
                purchaseTickets(seatsSold, revenue, seatChart, prices);
                break;
            }
            // view ticket calse case
            case 2: {
                cout << "$" << fixed << setprecision(2) << revenue << " worth of tickets sold." << endl;
                break;
            }
            // view available seats case
            case 3: {
                cout << seatsSold << " seats have been sold." << endl;
                break;
            }
            // view available seats in a row case 
            case 4: {
                // collects user input about which row they want
                int row;
                cout << "Which row would you like to view? ";
                cin >> row;

                // finds the number of avaiable seats in the row
                cout << getNumSeatsinRow(row - 1, seatChart) << " seats are available" << endl;
                break;
            }
            // view total avaiable seats case
            case 5: {
                cout << TOTAL_SEATS - seatsSold << " seats are available" << endl; 
            }
        }
    // breaks out of the loop if the user chooses exit
    } while (choice != 6);


    return 0;
}