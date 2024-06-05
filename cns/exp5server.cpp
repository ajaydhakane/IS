#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <mutex>

using namespace std;

vector<string> participants;
mutex participants_mutex;

string caesar_encrypt(const string &message, int shift) {
    string encrypted_message;
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

string caesar_decrypt(const string &ciphertext, int shift) {
    string decrypted_message;
    for (char c : ciphertext) {
        if (islower(c)) {
            decrypted_message += (c - 'a' - shift + 26) % 26 + 'a';
        } else if (isupper(c)) {
            decrypted_message += (c - 'A' - shift + 26) % 26 + 'A';
        } else {
            decrypted_message += c;
        }
    }
    return decrypted_message;
}

void broadcast_message(const string &username, const string &message) {
    string encrypted_message = caesar_encrypt(message, 3);
    participants_mutex.lock();
    for (const auto &participant : participants) {
        if (participant != username) {
            cout << participant << " received: " << encrypted_message << endl;
        }
    }
    participants_mutex.unlock();
}

void join_chat(const string &username) {
    participants_mutex.lock();
    participants.push_back(username);
    participants_mutex.unlock();
    cout << username << " has joined the chat." << endl;
}

void leave_chat(const string &username) {
    lock_guard<mutex> lock(participants_mutex);
    auto it = find(participants.begin(), participants.end(), username);
    if (it != participants.end()) {
        participants.erase(it);
    }
    cout << username << " has left the chat." << endl;
}

int main() {
    string username;
    cout << "Enter your username: ";
    getline(cin, username);

    join_chat(username);

    while (true) {
        string message;
        cout << "Enter message (or 'exit' to leave): ";
        getline(cin, message);

        if (message == "exit") {
            leave_chat(username);
            break;
        }

        broadcast_message(username, message);
    }

    return 0;
}