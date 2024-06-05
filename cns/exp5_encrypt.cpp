#include <iostream>
#include <string>

using namespace std;

string caesar_encrypt(const string& message, int shift) {
    string encrypted_message = "";
    for (char c : message) {
        if (islower(c)) {
            encrypted_message += (c - 'a' + shift) % 26 + 'a';
        } else if (isupper(c)) {
            encrypted_message += (c - 'A' + shift) % 26 + 'A';
        } else {
            encrypted_message += c;
        }
    }
    return encrypted_message;
}

int main() {
    string message;
    int shift;
    
    cout << "Enter the message to encrypt: ";
    getline(cin, message);
    
    cout << "Enter the shift value: ";
    cin >> shift;

    string encrypted_message = caesar_encrypt(message, shift);
    cout << "Encrypted message: " << encrypted_message << endl;
    
    return 0;
}