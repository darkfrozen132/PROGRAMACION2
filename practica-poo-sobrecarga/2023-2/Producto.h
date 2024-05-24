/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Producto.h
 * Author: Leoncio
 *
 * Created on 20 de mayo de 2024, 11:27 AM
 */

#ifndef PRODUCTO_H
#define PRODUCTO_H

class Producto{
    private:
        char*codigo;
        char*descripcion;
        double precio;
        int stock;
        int clientes_servidos[100];
        int clientes_no_servidos[100];
        int cantidad_clientes_servidos;
        int cantidad_cientes_no_servidos;
        
};

#endif /* PRODUCTO_H */

