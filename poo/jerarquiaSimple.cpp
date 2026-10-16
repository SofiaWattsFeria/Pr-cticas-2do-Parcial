#include "vehiculos.h"

int main() {
    Auto miAuto("Toyota", "Corolla", 190, 4);
    Motocicleta miMoto("Yamaha", "MT-07", 210, 689);

    miAuto.mostrarInfo();
    miMoto.mostrarInfo();

    return 0;
}
