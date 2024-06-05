#include <iostream>
#include <string>

using namespace std;

string decrypt_message(string encrypted_message, string key) {
    string decrypted_message = "";
    int key_length = key.length();
    int message_length = encrypted_message.length();

    for (int i = 0; i < message_length; i++) {
        if (isalpha(encrypted_message[i])) {
            char base = isupper(encrypted_message[i]) ? 'A' : 'a';
            decrypted_message += (encrypted_message[i] - base - key[i % key_length] + 26) % 26 + base;
        } else {
            decrypted_message += encrypted_message[i];
        }
    }

    return decrypted_message;
}

int main() {
    string encrypted_message, key;

    cout << "Enter the encrypted message: ";
    getline(cin, encrypted_message);

    cout << "Enter the decryption key: ";
    getline(cin, key);

    string decrypted_message = decrypt_message(encrypted_message, key);

    cout << "Decrypted message: " << decrypted_message << endl;

    return 0;
}