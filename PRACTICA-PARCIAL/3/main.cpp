/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Leoncio
 *
 * Created on 6 de mayo de 2024, 05:42 PM
 */


#include <iostream>
#include <iomanip>
#include <cstring>
#include<fstream>


using namespace std;
#include "Pregunta1.h"
#include "Pregunta2.h"

#include "ColaConEnteros.h"
//#include "ColaConProductos.h"
#include "ColaGenerica.h"
int main(int argc, char** argv) {
    char**codigoDelProducto;
    int**fechaClienteCantidad;
    
    cargarPedidos(fechaClienteCantidad,codigoDelProducto,"Pedidos.csv");
    pruebaDeCargaDePedidos(fechaClienteCantidad,codigoDelProducto,"PruebaPedidos.txt");
    void*productos;
    cargarProductos(productos,"Productos.csv");
    pruebaDeCargaDeProductos(productos);
    void*cola;
    
    cargaEnteros(cola,leenumero,"numeros.txt");
    
    
    mostrarEnteros(cola,imprimenumero,"reporte.txt");

    return 0;
}

