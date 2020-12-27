#include <iostream>

int main() {
    // for (начальные условия; условие выполнения; операции при переходе на след
    // итерацию)
    for (int i = 0, j = 10; i * j <= 100; i++, j++) { 
        std::cout << i * j << '\n';
    }
    int a = 0;
    while (a < 100) {
        std::cout << a;
        a += 10; // a = a + 10
    }
    /* do {

    } while ();
    */
}


/* a = a + 10           a += 10
    a = a + 1           a++ / ++a
*/