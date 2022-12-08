#include <iostream>
#include <iomanip>
using namespace std;

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
				// printSeatChart(seatChart);
				int row;
				int seat;
				do {
					cout << "Enter a row and seat number separated by a space: ";
					cin >> row >> seat;
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

int main() {

	int seatsSold = 0;
	double revenue = 0.0;

	double prices[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

	char seatChart[15][30];

	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 30; j++) {
			seatChart[i][j] = '#';
		}
	}
	
	purchaseTickets(seatsSold, revenue, seatChart, prices);
	
	return 0;
}