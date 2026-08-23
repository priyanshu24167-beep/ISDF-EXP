#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string password;
    int score = 0;

    cout << "Enter your password: ";
    cin >> password;

    bool upper = false, lower = false;
    bool digit = false, special = false;

    for (char ch : password) {
        if (isupper(ch))
            upper = true;
        else if (islower(ch))
            lower = true;
        else if (isdigit(ch))
            digit = true;
        else
            special = true;
    }

    // Check password length
    if (password.length() >= 8)
        score++;

    // Check character types
    if (upper)
        score++;

    if (lower)
        score++;

    if (digit)
        score++;

    if (special)
        score++;

    cout << "\n--- Password Analysis ---\n";
    cout << "Length >= 8      : " << (password.length() >= 8 ? "Yes" : "No") << endl;
    cout << "Uppercase letter : " << (upper ? "Yes" : "No") << endl;
    cout << "Lowercase letter : " << (lower ? "Yes" : "No") << endl;
    cout << "Digit            : " << (digit ? "Yes" : "No") << endl;
    cout << "Special character: " << (special ? "Yes" : "No") << endl;

    cout << "\nPassword Strength: ";

    if (score <= 2)
        cout << "Weak";
    else if (score == 3 || score == 4)
        cout << "Medium";
    else
        cout << "Strong";

    cout << endl;

    return 0;
}