/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   AsignacionDinamicaMemoriaExacta.h
 * Author: leoncio
 *
 * Created on 10 de abril de 2024, 01:35 PM
 */

#ifndef ASIGNACIONDINAMICAMEMORIAEXACTA_H
#define ASIGNACIONDINAMICAMEMORIAEXACTA_H
#include <fstream>
void lecturaDeProductos(char*,char***&, int*&, double*&);
void pruebaDeLecturaDeProductos(char*,char***&, int*&, double*&);
void lecturaDePedidos (char*,int*& fechaPedidos,char***&codigoPedidos,int***& dniCantPedidos);
void pruebaDeLecturaDePedidos (char*,int* fechaPedidos,char***codigoPedidos,int*** dniCantPedidos);








char** dar_codigo_nombre(char*cod,char*nombre);
char* leer_cadena(ifstream&input,char caracter);
char** colocar_codigo(char**&buff_codigoPedidos,int&cant,char*codigo);
int**colocar_codigo(int**buffDniCantPedidos,
                    int&cant,int dni,int cantidad);



int buscar_fecha(int*arr_fecha,int fecha);

/*
 
 
 
 
   char ***productos,***codigoPedidos;
    int *stock, *fechaPedidos, ***dniCantPedidos;
    double *precios;
    
 
 
 
 */
#endif /* ASIGNACIONDINAMICAMEMORIAEXACTA_H */

