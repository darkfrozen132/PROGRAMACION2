
#include <iostream>
#include <iomanip>
#include <cstring>
#include<fstream>


using namespace std;
#include "Pregunta1.h"

int main(int argc, char** argv) {
    char**codigoDelProducto;
    int**fechaClienteCantidad;
    
    cargarPedidos(fechaClienteCantidad,codigoDelProducto,"Pedidos.csv");
    pruebaDeCargaDePedidos(fechaClienteCantidad,codigoDelProducto,"PruebaPedidos.txt");

    return 0;
}

