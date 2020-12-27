#include <cctype>
#include <iostream>

int main() {
    char c = 'r';
    std::cout << islower(c) << isupper(c) << isalpha(c) << isalnum(c);
    // маленькая буква, большая буква, буква, буква или число
}