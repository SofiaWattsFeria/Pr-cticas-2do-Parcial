#include <vector>
#include "vehiculos.h"

int main() {
    // Coleccion de punteros a la clase base que mezcla Autos y Motocicletas
    std::vector<Vehiculo*> vehiculos;
    vehiculos.push_back(new Auto("Honda", "Civic", 200, 4));
    vehiculos.push_back(new Motocicleta("Kawasaki", "Ninja 400", 190, 399));
    vehiculos.push_back(new Auto("Nissan", "Versa", 180, 4));
    vehiculos.push_back(new Motocicleta("Italika", "FT150", 100, 150));

    // Cada objeto responde segun su tipo real
    for (Vehiculo* v : vehiculos) {
        v->mostrarInfo();
    }

    // Liberar memoria
    for (Vehiculo* v : vehiculos) {
        delete v;
    }

    return 0;
}
