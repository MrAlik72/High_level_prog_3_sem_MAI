#include <iostream>
#include <algorithm> // содержит сорт, бин поиск, мин, макс и кучу всего
#include <vector>

bool sravnit(int l, int r) { // компаратор. возвращает истину когда числа стоят правильно
    return std::abs(l) < std::abs(r);
}

int main() {
    std::cout << std::max("abc", "abC"); // строки сортируются лексикографически
    std::cout << std::endl;
    std::vector <int> v(5);
    for (int i = 0; i < 5; i++) {
        std::cin >> v[i];
    }
    sort(v.begin(), v.end(), sravnit); // sort(инератор на начало, на конец, компаратор)
    // по умолчанию сортится по возрастанию
    for (int i = 0; i < 5; i++) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
    std::cout << binary_search(v.begin(), v.end(), 10); // проверить, есть ли элемент в векторе
    // lower_bound - самая левая позиция, на которую можно поставить элемент, не нарушив порядок
    // upper_bound - самая правая позиция, на которую можно поставить элемент, не нарушив порядок
    // вычесть из итератора итератор на начало => получить индекс элемента, куда указ. итератор
    auto lower = lower_bound(v.begin(), v.end(), 10) - v.begin();
    auto upper = upper_bound(v.begin(), v.end(), 10);
    int up = *upper; // разыменовать => получить значение, на которое указывает итератор
}