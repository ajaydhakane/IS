#include <iostream>
#include <string>

using namespace std;

string encrypt_message(string message, string key) {
    string encrypted_message = "";
    int key_length = key.length();
    int message_length = message.length();

    for (int i = 0; i < message_length; i++) {
        if (isalpha(message[i])) {
            char base = isupper(message[i]) ? 'A' : 'a';
            encrypted_message += (message[i] - base + key[i % key_length]) % 26 + base;
        } else {
            encrypted_message += message[i];
        }
    }

    return encrypted_message;
}

int main() {
    string message, key;

    cout << "Enter the message to encrypt: ";
    getline(cin, message);

    cout << "Enter the encryption key: ";
    getline(cin, key);

    string encrypted_message = encrypt_message(message, key);

    cout << "Encrypted message: " << encrypted_message << endl;

    return 0;
}