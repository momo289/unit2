#include <iostream>
#include <string>

using namespace std;

// 1. Define the function as required
int countVowels(const char* p) {
    int count = 0;

    // Traverse the string using the pointer until the null terminator
    while (*p != '\0') {
        // Check if the current character is a vowel (lowercase or uppercase)
        if (*p == 'a' || *p == 'e' || *p == 'i' || *p == 'o' || *p == 'u' ||
            *p == 'A' || *p == 'E' || *p == 'I' || *p == 'O' || *p == 'U') {
            count++;
        }
        p++; // Move pointer to the next character
    }

    return count;
}

int main() {
    string input;

    

    // Use getline to read the whole line including spaces
    getline(cin, input);

    // 2. Call the function, passing the string as a const char*
    int result = countVowels(input.c_str());

    cout << "Number of vowels: " << result << endl;

    return 0;
}