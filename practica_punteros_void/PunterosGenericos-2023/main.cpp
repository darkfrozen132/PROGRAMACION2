/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: leoncio
 *
 * Created on 23 de abril de 2024, 08:54 AM
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include<cstring>
using namespace std;

#include "PunterosGenericos.h"
#include "MuestraPunteros2.h"

int main(int argc, char** argv) {
    void *productos,*clientes;
    cargaproductos(productos);
    
    imprimeproductos(productos);
    
    cargaclientes(clientes);
    
    imprimeClientes(clientes);
   
    cargapedidos(productos,clientes);
     /*
    imprimereporte(clientes);
     * */
return 0;
}

