#include <iostream>
#include <new> // for bad_alloc
#include "card_operations.h"

using namespace std;
using namespace card;

int main() {
    title("Campus Card System");

    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Card* cards = nullptr;

    // Module 9: Memory allocation exception handling
    try {
        cards = createCards(n);
    }
    catch (const bad_alloc& e) {
        cout << "Memory allocation failed! System exiting." << endl;
        return 1;
    }

    inputCards(cards, n);
    printLine();

    // Module 8: Operations on first account
    if (n > 0) {
        cout << "\n--- Operations on First Account ---" << endl;
        viewStudentID(&cards[0]); // Passing const pointer

        // 1. Deposit 100
        cout << "Depositing 100.00..." << endl;
        deposit(cards[0], 100.0);
        showBalance(cards[0]); // Passing const reference

        // 2. Spend 8.5
        try {
            if (spend(cards[0], 8.5, "Lunch")) {
                cout << "Purchase successful." << endl;
            }
            else {
                throw runtime_error("Insufficient balance for this purchase.");
            }
        }
        catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
        showBalance(cards[0]);

        // 3. Convert to cents
        int cents = toCent(cards[0].balance);
        cout << "Balance in cents: " << cents << " fen" << endl;
        printLine();
    }

    // Module 6: Print Report
    cout << "\n--- Account Report ---" << endl;
    printReport(cards, n);

    // Release memory
    destroyCards(cards);
    cout << "Memory released. System finished." << endl;

    return 0;
}