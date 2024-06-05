#include <iostream>
#include <string>

using namespace std;

void brute_force_attack(const string& target_password) {
    string characters = "abcdefghijklmnopqrstuvwxyz";
    int max_length = 2;  // Limiting to four characters

    for (int length = 1; length <= max_length; ++length) {
        string attempt(length, 'a');
        while (true) {
            cout << "Trying password: " << attempt << endl;
            if (attempt == target_password) {
                cout << "Password found: " << attempt << endl;
                return;
            }

            // Increment the attempt string
            int pos = length - 1;
            while (pos >= 0 && attempt[pos] == 'z') {
                attempt[pos] = 'a';
                --pos;
            }
            if (pos < 0) {
                break;
            }
            attempt[pos]++;
        }
    }

    cout << "Password not found within the specified length limit." << endl;
}

int main() {
    string target_password = "te";
    brute_force_attack(target_password);
    return 0;
}

