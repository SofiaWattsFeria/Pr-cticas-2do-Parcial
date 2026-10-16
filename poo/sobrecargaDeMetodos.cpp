#include <iostream>

class Calculadora {
public:
    // Version 1: dos enteros
    int sumar(int a, int b) {
        return a + b;
    }

    // Version 2: tres enteros
    int sumar(int a, int b, int c) {
        return a + b + c;
    }

    // Version 3: dos decimales
    double sumar(double a, double b) {
        return a + b;
    }
};

int main() {
    Calculadora calc;

    std::cout << "sumar(5, 3) = " << calc.sumar(5, 3) << std::endl;
    std::cout << "sumar(5, 3, 2) = " << calc.sumar(5, 3, 2) << std::endl;
    std::cout << "sumar(2.5, 3.7) = " << calc.sumar(2.5, 3.7) << std::endl;

    return 0;
}
