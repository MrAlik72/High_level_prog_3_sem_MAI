#include <iostream>
#include <vector> // vector - динамический массив 

int main() {
    int n;
    std::cin >> n;
    std::vector <int> v(n, 100); // std::vector <тип> название(размер, чем заполнен)
    for (int a: v) { // для всех a из (вектора) v
        std::cout << a << " ";
    }
    std::cout << std::endl;
    v.resize(2 * n, 1010); // изменить размер вектора
    for (int a : v) {
        std::cout << a << " ";
    }
    std::cout << v.size() << " " << v.empty() << std::endl; // размер вектора, проверка на пустоту
    
}