#include <iostream>

int main() {
    int num;
    char ch;
    std::cin >> num >> ch;
    std::cout << num << " " << ch;
    if (num == 5 || ch == 'a') { // && <=> и, || <=> или
        std::cout << "Glek";
    }
    
}