/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: leoncio
 *
 * Created on 10 de abril de 2024, 01:34 PM
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

#include "AsignacionDinamicaMemoriaExacta.h"

int main(int argc, char** argv) {
    char ***productos,***codigoPedidos;
    int *stock, *fechaPedidos, ***dniCantPedidos;
    double *precios;
    
    lecturaDeProductos("Productos.csv",productos, stock, precios);
            
    pruebaDeLecturaDeProductos ("ReporteDeProductos.txt" ,productos, stock, precios);
   
    lecturaDePedidos ("Pedidos.csv", fechaPedidos, codigoPedidos, dniCantPedidos);
     
    pruebaDeLecturaDePedidos ("ReporteDePedidos.txt", fechaPedidos, codigoPedidos, dniCantPedidos);
    /*
    reporteDeEnvioDePedidos (“ReporteDeEntregaDePedisos.txt”, productos, stock, precios,
    fechaPedidos, codigoPedidos, dniCantPedidos);
    pruebaDeLecturaDeProductos (“ReporteDeProductosFinal.txt” ,productos, stock, precios);
     */
    return 0;
}

