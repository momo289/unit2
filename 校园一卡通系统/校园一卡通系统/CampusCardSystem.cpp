#include <iostream>
#include "card_operations.h"

using namespace std;

int main() {
    card::title("Campus Card System");

    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Card* myCards = createCards(n);
    inputCards(myCards, n);
    card::printLine();

    cout << "Operating on the first account" << endl;
    deposit(myCards[0], 100.0);
    try {
        spend(myCards[0], 8.5, "Lunch");
    }
    catch (const exception& e) {
        cout << "Transaction Exception: " << e.what() << endl;
    }

    showBalance(myCards[0]);
    viewStudentID(&myCards[0]);
    cout << "Balance in cents: " << toCent(myCards[0].balance) << endl;

    cout << "\nAll Accounts Report" << endl;
    printReport(myCards, n);

    destroyCards(myCards);
    myCards = nullptr;

    return 0;
}