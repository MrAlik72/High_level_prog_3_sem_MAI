#include <iostream>

int main() {
    int a = 10;
    int* p = &a;

    int* p1 = new int; // новое интовое число
    *p1 = 100;
    std::cout << *p1 << "\n";
    delete p1; // освобождение памяти
    std::cout << *p1 << "\n";
}