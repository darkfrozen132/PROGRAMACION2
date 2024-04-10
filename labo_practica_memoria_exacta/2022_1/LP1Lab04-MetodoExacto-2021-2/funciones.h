/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funciones.h
 * Author: leoncio
 *
 * Created on 9 de abril de 2024, 01:33 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <fstream>

void CargaDeClientes (int*&cli_DNI,char**& cli_Nombre,char*& cli_Categoria);
void ReporteDeClientes (int*cli_DNI,char**cli_Nombre,char*cli_Categoria);
void CargaDePedidosYProductos(int*&cli_DNI,int*& pro_Codigo,char**& pro_Descripcion,
    double*&pro_Descuento,double*& pro_Precio,int**& cli_CodigoProFechaPedido, 
        double**&cli_CantidadPedido);
void colocar_producto(int*& buff_pro_Codigo,int cod,char**&buff_pro_Descripcion,char*descripcion,
        double*&buff_pro_Descuento,double descuento,double*&buff_pro_Precio,double precio);







void colocar_valores(int*&pro_Codigo,double*&cli_cantidad_pedido,int cod,int fecha,
                int cant,int&cantidad);
void leer_valores_restantes(int &cant,int&dni,int&fecha,double&precio,
        double&descuento,ifstream&archPedidos);
int buscar_dni(int*cli_DNI,int dni);
char* leer_cadena(ifstream&input,char c);
char dar_categoria(char*&nombre);
#endif /* FUNCIONES_H */

