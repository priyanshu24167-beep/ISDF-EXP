#include <iostream>
#include <string>
#include <random>
#include <algorithm>
#include <cctype>

using namespace std;

string generateCaptcha(int length = 8) {
    string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string lowercase = "abcdefghijklmnopqrstuvwxyz";
    string digits = "0123456789";
    string special = "@#$%&*";

    string all = uppercase + lowercase + digits + special;
    string captcha;

    random_device rd;
    mt19937 gen(rd());

    // Ensure at least one character from each category
    uniform_int_distribution<int> upperDist(0, uppercase.size() - 1);
    uniform_int_distribution<int> lowerDist(0, lowercase.size() - 1);
    uniform_int_distribution<int> digitDist(0, digits.size() - 1);
    uniform_int_distribution<int> specialDist(0, special.size() - 1);

    captcha += uppercase[upperDist(gen)];
    captcha += lowercase[lowerDist(gen)];
    captcha += digits[digitDist(gen)];
    captcha += special[specialDist(gen)];

    // Fill remaining characters
    uniform_int_distribution<int> allDist(0, all.size() - 1);

    while (captcha.length() < length) {
        captcha += all[allDist(gen)];
    }

    // Shuffle CAPTCHA
    shuffle(captcha.begin(), captcha.end(), gen);

    return captcha;
}

int main() {

    string captcha;
    string userInput;

    captcha = generateCaptcha(8);

    cout << "============================\n";
    cout << "       CAPTCHA VERIFICATION\n";
    cout << "============================\n";

    cout << "CAPTCHA: " << captcha << endl;

    cout << "\nEnter CAPTCHA: ";
    cin >> userInput;

    if (userInput == captcha) {
        cout << "\nVerification Successful!" << endl;
    }
    else {
        cout << "\nVerification Failed!" << endl;
        cout << "Correct CAPTCHA was: " << captcha << endl;
    }

    return 0;
}