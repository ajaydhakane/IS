#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

std::string string_to_hex(const std::string& input) {
    std::stringstream ss;
    ss << std::hex << std::setfill('0');
    for (unsigned char c : input) {
        ss << std::setw(2) << static_cast<int>(c);
    }
    return ss.str();
}

int main() {
    std::string input = "Hello, World!";
    std::string hex_output = string_to_hex(input);
    std::cout << "Input string: " << input << std::endl;
    std::cout << "Hexadecimal representation: " << hex_output << std::endl;
    return 0;
}