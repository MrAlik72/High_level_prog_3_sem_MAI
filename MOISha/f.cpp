#include <iostream>
#include <vector>

int main() {
    std::vector<int> v;
    int a;
    while (std::cin >> a) {
        v.push_back(a); // добавить в конец вектора. размер меняется автоматом
    }
    for (int x : v) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    v.pop_back(); // удалить последний элемент
    v.clear(); // очистить весь вектор
}