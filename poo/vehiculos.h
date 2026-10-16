#ifndef VEHICULOS_H
#define VEHICULOS_H

#include <iostream>
#include <string>

// Clase base: datos comunes a cualquier vehiculo
class Vehiculo {
protected:
    std::string marca;
    std::string modelo;
    int velocidadMax; // km/h

public:
    Vehiculo(const std::string& marca, const std::string& modelo, int velocidadMax)
        : marca(marca), modelo(modelo), velocidadMax(velocidadMax) {}

    // Destructor virtual: necesario para borrar objetos derivados desde un puntero base
    virtual ~Vehiculo() = default;

    // Metodo virtual: las clases derivadas lo sobrescriben
    virtual void mostrarInfo() const {
        std::cout << "Vehiculo: " << marca << " " << modelo
                  << " | Velocidad maxima: " << velocidadMax << " km/h" << std::endl;
    }
};

// Clase derivada: Auto
class Auto : public Vehiculo {
private:
    int numPuertas;

public:
    Auto(const std::string& marca, const std::string& modelo, int velocidadMax, int numPuertas)
        : Vehiculo(marca, modelo, velocidadMax), numPuertas(numPuertas) {}

    void mostrarInfo() const override {
        std::cout << "Auto: " << marca << " " << modelo
                  << " | Velocidad maxima: " << velocidadMax << " km/h"
                  << " | Puertas: " << numPuertas << std::endl;
    }
};

// Clase derivada: Motocicleta
class Motocicleta : public Vehiculo {
private:
    int cilindrada; // cc

public:
    Motocicleta(const std::string& marca, const std::string& modelo, int velocidadMax, int cilindrada)
        : Vehiculo(marca, modelo, velocidadMax), cilindrada(cilindrada) {}

    void mostrarInfo() const override {
        std::cout << "Motocicleta: " << marca << " " << modelo
                  << " | Velocidad maxima: " << velocidadMax << " km/h"
                  << " | Cilindrada: " << cilindrada << " cc" << std::endl;
    }
};

#endif
