#include <iostream> // для ввода и вывода данных
#include <iomanip> // форматирование вывода

int main() {
    int i = 100;
    long long ll;
    char c;
    bool b;
    double d;
    std::cout.precision(9); // точность десятичных чисел
    std::cout << "Hi!";
    /* if (условие) {
        команды;
    }
    */
    if (i == 100) {
        std::cout << "Good";
    }
}
//Запуск g++ ./begin.cpp
