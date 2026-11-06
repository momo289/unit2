#include "card_operations.h"
#include <iomanip>
#include <stdexcept>

namespace card {

    void printLine(char c, int len) {
        for (int i = 0; i < len; ++i) cout << c;
        cout << endl;
    }

    void title(const string& s) {
        printLine('=');
        cout << s << endl;
        printLine('=');
    }

    Card* createCards(int n) {
        return new Card[n]; // Throws bad_alloc if failed
    }

    void destroyCards(Card* p) {
        delete[] p;
    }

    void inputCards(Card* arr, int n) {
        for (int i = 0; i < n; ++i) {
            while (true) {
                try {
                    cout << "Enter ID, Name, Initial Balance for student " << i + 1 << ": ";
                    cin >> arr[i].id >> arr[i].name >> arr[i].balance;

                    if (cin.fail()) {
                        cin.clear(); // clear error flags
                        cin.ignore(10000, '\n'); // discard bad input
                        throw invalid_argument("Invalid input data type!");
                    }
                    if (arr[i].balance < 0) {
                        throw invalid_argument("Balance cannot be negative!");
                    }

                    arr[i].transactions = 0;
                    break; // break while loop if success
                }
                catch (const exception& e) {
                    cout << "Exception: " << e.what() << " Please re-enter." << endl;
                }
            }
        }
    }

    void deposit(Card& c, double amount, double fee) {
        if (amount <= 0) throw invalid_argument("Deposit amount must be positive.");
        double final_amount = amount * (1.0 - fee);
        c.balance += final_amount;
        c.transactions++;
    }

    bool spend(Card& c, double cost) {
        if (cost <= 0) throw invalid_argument("Cost must be positive.");
        if (c.balance < cost) return false; // Insufficient balance

        c.balance -= cost;
        c.transactions++;
        return true;
    }

    bool spend(Card& c, double cost, const string& item) {
        cout << "Purchasing item: " << item << endl;
        return spend(c, cost);
    }

    void showBalance(const Card& c) {
        cout << "Current Balance: " << fixed << setprecision(2) << c.balance << " CNY" << endl;
        if (c.balance < WARNING_BALANCE) {
            cout << "[Warning] Low balance!" << endl;
        }
    }

    void viewStudentID(const Card* p) {
        cout << "Student ID: " << p->id << endl;
    }

    int toCent(double amount) {
        return static_cast<int>(amount * 100);
    }

    void printReport(const Card* arr, int n) {
        printLine();
        cout << left << setw(10) << "ID"
            << setw(15) << "Name"
            << right << setw(12) << "Balance"
            << setw(15) << "Transactions" << endl;
        printLine();

        for (int i = 0; i < n; ++i) {
            cout << left << setw(10) << arr[i].id
                << setw(15) << arr[i].name
                << right << fixed << setprecision(2) << setw(12) << arr[i].balance
                << setw(15) << arr[i].transactions << endl;
        }
        printLine();
    }
}