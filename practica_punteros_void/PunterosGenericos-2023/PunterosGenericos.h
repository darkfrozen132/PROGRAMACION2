/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   PunterosGenericos.h
 * Author: leoncio
 *
 * Created on 23 de abril de 2024, 08:56 AM
 */

#ifndef PUNTEROSGENERICOS_H
#define PUNTEROSGENERICOS_H

void cargaproductos(void*&);
void cargaclientes(void*&);
void cargapedidos(void*&,void*&);


//funcionse adicionales
void*leer_linea_productos(ifstream&archProductos);
char*leer_cadena(ifstream&archProductos,char c);
void*leer_linea_pedidos(ifstream&archPedidos);
void* leer_linea_clientes(ifstream&archClientes);
int buscar_producto(void*reg,void*&productos);

#endif /* PUNTEROSGENERICOS_H */

