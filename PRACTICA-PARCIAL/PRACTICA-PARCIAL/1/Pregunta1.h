/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Pregunta1.h
 * Author: Leoncio
 *
 * Created on 6 de mayo de 2024, 12:20 PM
 */

#ifndef PREGUNTA1_H
#define PREGUNTA1_H
/*
 char**codigoDelProducto;
    int**fechaClienteCantidad;
 */
void cargarPedidos(int**&fechaClienteCantidad,char**&codigoDelProducto,char*nombre_archivo);
void pruebaDeCargaDePedidos(int**fechaClienteCantidad,char**codigoDelProducto,char*nombre_archivo);





//funciones adcionales
void incrementar_espacios(int**&fechaClienteCantidad,char**&codigoDelProducto,int&num,int&cap);
void asignar_espacios(int**&fechaClienteCantidad,char**&codigoDelProducto,int dni,int cantidad_sol,
        int fecha,char *cod,int num);
char*leer_cadena(ifstream&input,char c);
void ordenar(int**&fechaClienteCantidad,char**&codigoDelProducto,int,int);
void cambiar(int*&val1,int*&val2,char*&var1,char*&var2);

#endif /* PREGUNTA1_H */

