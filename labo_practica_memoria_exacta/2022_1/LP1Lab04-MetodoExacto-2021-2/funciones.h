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










char* leer_cadena(ifstream&input,char c);
char dar_categoria(char*&nombre);
#endif /* FUNCIONES_H */

