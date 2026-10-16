#include <memory>
#include <vector>
#include "vehiculos.h"

int main() {
    // Coleccion iterable; unique_ptr libera la memoria automaticamente
    std::vector<std::unique_ptr<Vehiculo>> vehiculos;
    vehiculos.push_back(std::make_unique<Vehiculo>("Generico", "Base", 120));
    vehiculos.push_back(std::make_unique<Auto>("Mazda", "3", 195, 4));
    vehiculos.push_back(std::make_unique<Motocicleta>("Suzuki", "GSX-R600", 260, 599));
    vehiculos.push_back(std::make_unique<Auto>("Ford", "Mustang", 250, 2));

    // Recorrido con un iterador del lenguaje
    for (auto it = vehiculos.begin(); it != vehiculos.end(); ++it) {
        (*it)->mostrarInfo();
    }

    return 0;
}
