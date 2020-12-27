#include <iostream>

class MyClass {
    public: // публичные методы и переменные - доступны для всех
    void set(int n) {
        a = n;
    }
    int get() {
        return a;
    }
    MyClass(int n) { // конструктор, запускается при объявлении объекта
        std::cout << n;
    }
    int b = 100;
    private: // приватные - доступны только для других методов класса
    int a = 1001;
    protected: // хз что такое

};

int main() {
    MyClass c(10);
    std::cout << c.b;
    c.set(0);
    std::cout << c.get();
}