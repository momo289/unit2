#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// 1. Define inline function for squaring
inline double square(double x) {
    return x * x;
}

// 2. Define function with default parameter
double power(double base, int exponent = 2) {
    double result = 1.0;
    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }
    return result;
}

// 3. Define overloaded functions for basic math
double calc(double a, double b, char op) {
    if (op == '/') {
        if (b == 0) return NAN; // Return Not-A-Number for divide by zero
        return a / b;
    }
    else if (op == '+') return a + b;
    else if (op == '-') return a - b;
    else if (op == '*') return a * b;
    return 0.0;
}

double calc(int a, int b, char op) {
    if (op == '/') {
        if (b == 0) return NAN;
        return static_cast<double>(a) / b;
    }
    else if (op == '+') return a + b;
    else if (op == '-') return a - b;
    else if (op == '*') return a * b;
    return 0.0;
}

int main() {
    double num1, num2;
    char op;

    // Read input
    cin >> num1 >> num2 >> op;

    // 1. Output for square()
    cout << "square(" << num1 << ") = "
        << fixed << setprecision(2) << square(num1) << endl;

    // 2. Output for power() - using exponent 3 as per example
    cout << "power(" << num1 << ",3) = "
        << fixed << setprecision(2) << power(num1, 3) << endl;

    // 3. Output for calc()
    double result;
    // Check if inputs are integers to call the int overload
    if (num1 == static_cast<int>(num1) && num2 == static_cast<int>(num2)) {
        result = calc(static_cast<int>(num1), static_cast<int>(num2), op);
    }
    else {
        result = calc(num1, num2, op);
    }

    // Handle divide by zero error
    if (isnan(result)) {
        cout << "Error: divide by zero" << endl;
    }
    else {
        cout << num1 << " " << op << " " << num2 << " = "
            << fixed << setprecision(2) << result << endl;
    }

    return 0;
}