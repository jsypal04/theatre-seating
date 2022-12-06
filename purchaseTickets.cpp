#include <iostream>
#include <iomanip>
using namespace std;

int purchaseTickets(int &seatsSold, double &revenue, char seatChart[][10], double prices[]) {
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
				// printSeatChart(seatChart);
				int row;
				int seat;
				cout << "Enter a row and seat number separated by a space: ";
				cin >> row >> seat;

				seatsSold++;
				revenue += prices[row - 1];
				runningTotal += prices[row - 1];
				seatChart[row - 1][seat - 1] = '#';
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

int main() {
	
	
	return 0;
}