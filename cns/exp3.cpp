#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

string caesar_decrypt(const string& ciphertext, int shift) {
    string decrypted_text = "";
    for (char c : ciphertext) {
        if (islower(c)) {
            decrypted_text += (c - shift - 'a' + 26) % 26 + 'a';
        } else if (isupper(c)) {
            decrypted_text += (c - shift - 'A' + 26) % 26 + 'A';
        } else {
            decrypted_text += c;
        }
    }
    return decrypted_text;
}

char frequency_analysis(const string& ciphertext) {
    unordered_map<char, int> frequency;
    for (char c = 'a'; c <= 'z'; ++c) {
        frequency[c] = 0;
    }

    for (char c : ciphertext) {
        if (isalpha(c)) {
            frequency[tolower(c)]++;
        }
    }

    return max_element(frequency.begin(), frequency.end(),
                       [](const pair<char, int>& a, const pair<char, int>& b) {
                           return a.second < b.second;
                       })->first;
}

pair<string, int> cryptanalysis_attack(const string& ciphertext) {
    char most_common_in_english = 'e';
    char most_common_in_ciphertext = frequency_analysis(ciphertext);

    int shift = (most_common_in_ciphertext - most_common_in_english + 26) % 26;

    string decrypted_text = caesar_decrypt(ciphertext, shift);
    return make_pair(decrypted_text, shift);
}

int main() {
    string ciphertext = "this is pratik";
    auto result = cryptanalysis_attack(ciphertext);
    cout << "Decrypted Text: " << result.first << endl;
    cout << "Detected Shift: " << result.second << endl;
    return 0;
}
