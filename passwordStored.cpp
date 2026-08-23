#include <iostream>
#include <string>
#include <random>
#include <functional>

using namespace std;

// Generate random salt
string generateSalt(int length = 16) {
    const string characters =
        "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    random_device rd;
    mt19937 generator(rd());
    uniform_int_distribution<int> distribution(0, characters.length() - 1);

    string salt;

    for (int i = 0; i < length; i++) {
        salt += characters[distribution(generator)];
    }

    return salt;
}

// Hash password + salt
size_t hashPassword(const string& password, const string& salt) {
    hash<string> hasher;
    return hasher(salt + password);
}

int main() {

    string password;

    cout << "Enter Password: ";
    cin >> password;

    // Generate salt
    string salt = generateSalt();

    // Hash password with salt
    size_t hashedPassword = hashPassword(password, salt);

    cout << "\n--- Stored Password Information ---\n";
    cout << "Salt: " << salt << endl;
    cout << "Password Hash: " << hashedPassword << endl;

    // Login verification
    string loginPassword;

    cout << "\nEnter Password for Login: ";
    cin >> loginPassword;

    size_t loginHash = hashPassword(loginPassword, salt);

    if (loginHash == hashedPassword) {
        cout << "Login Successful!" << endl;
    }
    else {
        cout << "Invalid Password!" << endl;
    }

    return 0;
}