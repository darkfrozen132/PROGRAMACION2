/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: leoncio
 *
 * Created on 26 de marzo de 2024, 01:15 PM
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include "AperturaDeArchivos.h"
#include "Estructuras.h"
#include "sobrecargas.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    ifstream archClientes;
    ifstream archPedidos;
    ifstream archProductos;
    AperturaDeUnArchivoDeTextosParaLeer(archClientes,"Clientes.csv");
    struct Cliente cliente;
    archClientes>>cliente;
    

    return 0;
}

