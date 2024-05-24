/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Leoncio
 *
 * Created on 9 de mayo de 2024, 10:07 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;
#include "MetodoIncremento.h"
/*
 * 
 */
int main(int argc, char** argv) {
    char***libros,***pedidosLibros;
    int **stock,**pedidosClientes;
    bool**pedidosAtendidos;
    lecturaDeLibros("Libros.csv",libros,stock);
    pruebaDeLecturaLibros("ReporteDeLibrosInicial.txt",libros,stock);
    atencionDePedidos("Pedidos.txt",libros,stock,pedidosClientes,pedidosLibros,pedidosAtendidos);
    ordenarPedidosClientes(pedidosClientes);
    pruebaDeLecturaLibros("ReporteDeLibrosFinal.txt",libros,stock);
    reporteDeEntregaDePedidos("ReporteDeEntregaDePedidos.txt",pedidosClientes,pedidosLibros,pedidosAtendidos);
    return 0;
}

