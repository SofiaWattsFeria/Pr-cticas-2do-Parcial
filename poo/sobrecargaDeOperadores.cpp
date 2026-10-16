#include <cstdlib>
#include <iostream>
#include <stdexcept>

class Fraccion {
private:
    int numerador;
    int denominador;

    static int mcd(int a, int b) {
        a = std::abs(a);
        b = std::abs(b);

        while (b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }

        return a;
    }

    void simplificar() {
        if (denominador < 0) {          // el signo siempre en el numerador
            numerador = -numerador;
            denominador = -denominador;
        }
        int divisor = mcd(numerador, denominador);
        if (divisor != 0) {
            numerador /= divisor;
            denominador /= divisor;
        }
    }

public:
    Fraccion(int numerador = 0, int denominador = 1)
        : numerador(numerador), denominador(denominador) {
        if (denominador == 0) {
            throw std::invalid_argument("El denominador no puede ser cero");
        }
        simplificar();
    }

    // Suma: a/b + c/d = (a*d + c*b) / (b*d)
    Fraccion operator+(const Fraccion& otra) const {
        return Fraccion(numerador * otra.denominador + otra.numerador * denominador,
                        denominador * otra.denominador);
    }

    // Igualdad: a/b == c/d si a*d == c*b (equivalencia)
    bool operator==(const Fraccion& otra) const {
        return numerador * otra.denominador == otra.numerador * denominador;
    }

    friend std::ostream& operator<<(std::ostream& os, const Fraccion& f) {
        os << f.numerador << "/" << f.denominador;
        return os;
    }
};

int main() {
    Fraccion a(1, 2);
    Fraccion b(1, 3);
    Fraccion c(2, 4);

    std::cout << a << " + " << b << " = " << (a + b) << std::endl;

    std::cout << a << " == " << c << " ? "
              << (a == c ? "Si, son equivalentes" : "No son equivalentes") << std::endl;
    std::cout << a << " == " << b << " ? "
              << (a == b ? "Si, son equivalentes" : "No son equivalentes") << std::endl;

    return 0;
}
