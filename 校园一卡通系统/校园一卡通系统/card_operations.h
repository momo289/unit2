#ifndef CARD_OPERATIONS_H
#define CARD_OPERATIONS_H

#include <iostream>
#include <string>

using namespace std;

// Module 1: Constants and Struct
const double FEE_RATE = 0.02;
const double WARNING_BALANCE = 10.0;

struct Card {
    int id;
    string name;
    double balance;
    int transactions;
};

// Module 2: Namespace and Formatting
namespace card {
    void printLine(char c = '-', int len = 60);
    void title(const string& s);

    // Module 3: Memory Management
    Card* createCards(int n);
    void destroyCards(Card* p);
    void inputCards(Card* arr, int n);

    // Module 4: Account Operations
    void deposit(Card& c, double amount, double fee = FEE_RATE);
    bool spend(Card& c, double cost);
    bool spend(Card& c, double cost, const string& item);
    void showBalance(const Card& c);
    void viewStudentID(const Card* p);

    // Module 5: Type Conversion
    int toCent(double amount);

    // Module 6: Report
    void printReport(const Card* arr, int n);
}

#endif