/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   AsignacionDinamicaMemoriaExacta.h
 * Author: leoncio
 *
 * Created on 16 de abril de 2024, 12:54 PM
 */

#ifndef ASIGNACIONDINAMICAMEMORIAEXACTA_H
#define ASIGNACIONDINAMICAMEMORIAEXACTA_H
#include <fstream>
void lecturaDeProductos (char*,char***&productos,int*& stock,double*& precios);

void pruebaDeLecturaDeProductos (char*,char***&productos,int*& stock,double*& precios);




//funcione extras
void incremento_memoria(char***&productos,int*&stock,double*&precios,int &num_dat,int& cap);
char* leer_cadena(ifstream&arch,char c);
/*
 
   char ***productos,***codigoPedidos;
    int *stock, *fechaPedidos, ***dniCantPedidos;
    double *precios;
 
 
 
 
 
 */

#endif /* ASIGNACIONDINAMICAMEMORIAEXACTA_H */

