    /*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Almacen.h
 * Author: Leoncio
 *
 * Created on 20 de mayo de 2024, 11:22 AM
 */

#ifndef ALMACEN_H
#define ALMACEN_H
#include <iostream>
#include<iomanip>
#include<fstream>
#include<cstring>
using namespace std;
#include "Cliente.h"
#include "Producto.h"

class Almacen{
    private:
        class Cliente arreglo_clientes[100];
        int cantidad_clientes;
        class Producto arreglo_productos[100];
        int cantidad_productos;
    public:
        
        
};

#endif /* ALMACEN_H */

