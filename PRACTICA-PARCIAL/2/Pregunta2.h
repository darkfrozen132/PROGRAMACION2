/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Pregunta2.h
 * Author: Leoncio
 *
 * Created on 6 de mayo de 2024, 04:59 PM
 */

#ifndef PREGUNTA2_H
#define PREGUNTA2_H

void cargarProductos(void*&productos,char*nombre_archivo);
void pruebaDeCargaDeProductos(void*produtos);

//funciones adicionales
void*leer_registro(ifstream&input);
char*leer_cadena(ifstream&input,char c);
void incrementarEspacios(void**&pro,int&num,int&cap);
int compCodProducto(const void*var1,const void*var2);
#endif /* PREGUNTA2_H */

