/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Axel Mestanza
 * Proyecto: main.cpp
 * Created on 18 de abril de 2024, 13:48
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>

#include "funciones.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    char ***libros,***pedidosLibros;
    int **stock,**pedidosClientes;
    bool**pedidosAtendidos;
    lecturaDeLibros("Libros.csv",libros,stock);
    pruebaDeLecturaDeLibros("ReporteLibros.txt",libros,stock);
    atencionDePedidos("Pedidos.txt",libros,stock,pedidosClientes,pedidosLibros,pedidosAtendidos);
    pruebaDeLecturaDeLibros("ReporteLibros.txt",libros,stock);
    return 0;
}

