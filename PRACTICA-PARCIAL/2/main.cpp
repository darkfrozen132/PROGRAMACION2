/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: Leoncio
 *
 * Created on 6 de mayo de 2024, 04:59 PM
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include<fstream>


using namespace std;
#include "Pregunta2.h"

int main(int argc, char** argv) {
    void*productos;
    cargarProductos(productos,"Productos.csv");
    pruebaDeCargaDeProductos(productos);
    
    return 0;
}

