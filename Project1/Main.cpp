#include <iostream>
#include <string>
#include <vector>
#include <iomanip> // For formatting output (setw, setprecision, etc.)

using namespace std;

// Define Student struct
struct Student {
    string name;    // Name
    double chinese; // Chinese score
    double math;    // Math score
    double english; // English score
    double average; // Average score
};

int main() {
    int n;
    cout << "Enter the number of students: ";
    if (!(cin >> n)) return 0; // Handle invalid input

    vector<Student> students(n);

    // 1. Input student info and calculate average
    cout << "Enter info for " << n << " students (Format: Name Chinese Math English):" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> students[i].name >> students[i].chinese >> students[i].math >> students[i].english;
        students[i].average = (students[i].chinese + students[i].math + students[i].english) / 3.0;
    }

    

  
    cout << left << setw(15) << "Name"
        << right << setw(10) << "Chinese"
        << setw(10) << "Math"
        << setw(10) << "English"
        << setw(12) << "Average"
        << "    Remark" << endl;


 
    for (int i = 0; i < n; ++i) {
    
        cout << left << setw(15) << students[i].name
            << right << fixed << setprecision(1) << setw(10) << students[i].chinese
            << setw(10) << students[i].math
            << setw(10) << students[i].english
           
            << fixed << setprecision(2) << setw(12) << students[i].average;

      
        if (students[i].average >= 90) {
            cout << "    Excellent";
        }
        cout << endl;
    }
 

    return 0;
}