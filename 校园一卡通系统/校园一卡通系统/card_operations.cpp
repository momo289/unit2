#include "card_operations.h"

namespace card {
    void printLine(char c, int len) {
        for (int i = 0; i < len; ++i) cout << c;
        cout << endl;
    }

    void title(const string& s) {
        printLine('=');
        cout << setw((60 + s.length()) / 2) << s << endl;
        printLine('=');
    }
}

Card* createCards(int n) {
    try {
        Card* arr = new Card[n];
        return arr;
    }
    catch (const bad_alloc& e) {
        cerr << "Memory allocation failed!" << endl;
        exit(1);
    }
}

void destroyCards(Card* p) {
    delete[] p;
}

void inputCards(Card* arr, int n) {
    for (int i = 0; i < n; ++i) {
        cout << "Enter ID, Name, Balance for student " << i + 1 << ": ";
        while (true) {
            try {
                cin >> arr[i].id >> arr[i].name >> arr[i].balance;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    throw runtime_error("Invalid input type!");
                }
                if (arr[i].balance < 0) {
                    throw invalid_argument("Balance cannot be negative!");
                }
                arr[i].transactions = 0;
                break;
            }
            catch (const exception& e) {
                cout << "Error: " << e.what() << " Try again." << endl;
            }
        }
    }
}

void deposit(Card& c, double amount, double fee) {
    if (amount > 0) {
        c.balance += amount * (1 - fee);
        c.transactions++;
    }
}

bool spend(Card& c, double cost) {
    if (cost < 0) throw runtime_error("Cost cannot be negative!");
    if (c.balance < cost) throw runtime_error("Insufficient balance!");
    c.balance -= cost;
    c.transactions++;
    return true;
}

bool spend(Card& c, double cost, const string& item) {
    cout << "Item: " << item << ", Cost: " << cost << " Yuan." << endl;
    return spend(c, cost);
}

void showBalance(const Card& c) {
    cout << "Balance: " << fixed << setprecision(2) << c.balance << " Yuan" << endl;
}

void viewStudentID(const Card* p) {
    cout << "ID: " << p->id << endl;
}

int toCent(double amount) {
    return static_cast<int>(amount * 100);
}

void printReport(const Card* arr, int n) {
    card::printLine();
    cout << left << setw(10) << "ID"
        << setw(15) << "Name"
        << setw(15) << "Balance"
        << setw(15) << "Transactions" << endl;
    card::printLine();
    for (int i = 0; i < n; ++i) {
        cout << left << setw(10) << arr[i].id
            << setw(15) << arr[i].name
            << fixed << setprecision(2) << setw(15) << arr[i].balance
            << setw(15) << arr[i].transactions << endl;
    }
    card::printLine();
}