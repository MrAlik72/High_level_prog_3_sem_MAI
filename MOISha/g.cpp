#include <iostream>
#include <string> // для использования строк
#include <cctype> // определить тип символа

int main() {
    std::string s;
    std::cin >> s;
    std::cout << s.size() << " " << s << std::endl; // размер строки
    s[2] = 'b'; // строку можно изменять
    std::cout << s << "\n";
    std::string s1 = s.substr(2, 100); // подстрока - название.substr(откуда, сколько)
    std::cout << s1;
    int a = stoi(s1); // строку в инт
    std::string s2 = std::to_string(a); // число в строку
}