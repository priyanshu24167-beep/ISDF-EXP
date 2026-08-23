#include <iostream>
#include <string>
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;

string generateCaptcha(int length, mt19937& gen) {
    string characters =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789"
        "@#$%&*";

    uniform_int_distribution<int> dist(0, characters.length() - 1);
    string captcha;

    for (int i = 0; i < length; i++) {
        captcha += characters[dist(gen)];
    }

    bool hasUpper = false;
    bool hasLower = false;
    bool hasDigit = false;
    bool hasSpecial = false;

    for (char c : captcha) {
        if (c >= 'A' && c <= 'Z')
            hasUpper = true;
        else if (c >= 'a' && c <= 'z')
            hasLower = true;
        else if (c >= '0' && c <= '9')
            hasDigit = true;
        else
            hasSpecial = true;
    }

    if (!hasUpper || !hasLower || !hasDigit || !hasSpecial)
        return generateCaptcha(length, gen);

    return captcha;
}

int main() {
    unsigned seed = chrono::high_resolution_clock::now()
        .time_since_epoch()
        .count();

    mt19937 gen(seed);

    string captcha = generateCaptcha(8, gen);
    string input;

    cout << "============================\n";
    cout << "      CAPTCHA VERIFICATION\n";
    cout << "============================\n";

    cout << "CAPTCHA: " << captcha << endl;

    cout << "\nEnter CAPTCHA: ";
    cin >> input;

    if (input == captcha)
        cout << "\nVerification Successful!" << endl;
    else
        cout << "\nVerification Failed!" << endl;

    return 0;
}