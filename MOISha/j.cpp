#include <iostream>
#include <algorithm>
#include <vector>

struct st { // структура, тайпдефы идут нафиг
    int a;
    char c;
};

bool operator<(st& l, st& r) { // переопределение оператора <.  & означает передачу по ссылке
    if (l.a == r.a) { // сортим по возрастанию цифры и убыванию буквы
        return l.c > r.c;
    }
    return l.a < r.a;
}

int main() {
    std::vector <st> v;
    for (int i = 0; i < 3; i++) {
        st tmp;
        std::cin >> tmp.a >> tmp.c;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end()); // переопределили оператор => 3 аргумент не нужен
    for (auto x : v) {
        std::cout << x.a << " " << x.c << "\n";
    }
}