/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: chumbi
 *
 * Created on 16 de abril de 2024, 21:33
 */

#include "funciones.hpp"

int main(int argc, char** argv) {
    
    char ***libros, ***pedidosLibros;
    int **stock, **pedidosClientes;
    bool **pedidosAtendidos;
    
//    char** test = new char*[5]{"HOla","hola","hola","hola"};
//    test[4] = nullptr;
//    int n;
//    for(n = 0; test[n];n++){
//        cout << n;
//    }
//    
//    cout << n;
    
    lecturaDeLibros("Libros.csv",libros,stock);
    pruebaDeLecturaDeLibros("ReporteDeLibrosInicial.txt",libros,stock);
    
    atencionDePedidos("Pedidos.txt",libros,stock,pedidosClientes,pedidosLibros,pedidosAtendidos);
    pruebaDeLecturaDeLibros("ReporteDeLibrosFinal.txt",libros,stock);
//    
    reporteDeEntregaDePedidos("ReporteDeEntregaDePedisos.txt",pedidosClientes,pedidosLibros,pedidosAtendidos);
    //cout << "Fin"<<endl;
    
    return 0;
}

