/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Cliente.h
 * Author: Leoncio
 *
 * Created on 20 de mayo de 2024, 11:27 AM
 */

#ifndef CLIENTE_H
#define CLIENTE_H
#include <iostream>
#include<iomanip>
#include<fstream>
#include<cstring>
using namespace std;
#include "ProductoEntregado.h"
class Cliente{
    private:
        int dni;
        char*nombre;
        int telefono;
        class ProductoEntregado ProductosEntregados[100];
        int cantidad_productos_entregados;
        double monto_total;
    public:
        Cliente();
        int getDni();
        void setDni(int dni);
        
        void getNombre(char*nom);
        void setNombre(char*nom);
        
        int getTelefono();
        void setTelefono(int tele);
        
        int getCantidad_productos_entregados();
        void setCantidad_productos_entregados(int cant_prod_entre);
        
        double getMonto_total();
        void setMonto_total(double monto);
        
        bool operator>>(ifstream&arch,class Cliente&clien);

        
        
        
    
    
    
};

#endif /* CLIENTE_H */

