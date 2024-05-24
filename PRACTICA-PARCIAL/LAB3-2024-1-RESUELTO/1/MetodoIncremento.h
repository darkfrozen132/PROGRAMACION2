/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   MetodoIncremento.h
 * Author: Leoncio
 *
 * Created on 9 de mayo de 2024, 10:08 PM
 */

#ifndef METODOINCREMENTO_H
#define METODOINCREMENTO_H

/*
  char***libros,***pedidosLibros;
    int **stock,**pedidosClientes;
    bool**pedidosAtendidos;
    lecturaDeLibros("Libros.csv",libros,stock);
 */

void lecturaDeLibros(char*filename,char***&libros,int**&stock);
void pruebaDeLecturaLibros(char*filename,char***libros,int**stock);
void atencionDePedidos(char*filename,char***&libros,int**&stock,int**&pedidosClientes,
        char***&pedidosLibros,bool**&pedidosAtendidos);
void reporteDeEntregaDePedidos(char*filename,int**pedidosClientes,char***pedidosLibros,bool**pedidosAtendidos);
//funciones adicinales
void pasar_datos(char*cod,char*nombre,char*autor,char***libros,int**stock,int stck,int& num);
void incrementar_espacios(char***&libros,int**&stock,int&num,int&cap);
char* leer_cadena(ifstream&input,char c);


void incrementar_espacios(int**&pedidosClientes,int&num,int&cap);
int buscar_dni(int**pedidosClientes,int dni,int num);
void agregar_datos_dni(int*&pedidoCliente,int dni,int&num_2,int&cap_2,int ped,int pos);
void incrementar_espacios_nivel_2(int*&pedidoClientes,int&num,int&cap);
void incrementar_espacios_nivel_2(char**&pedidosLibros,bool*&pedidoAtendido,int&cap_lib,int&num_lib);
void incrementar_espacios_2(char***&pedidosLibros,bool**&pedidosAtendidos,int&cap_lib,int&num_lib);
void colocar_cod(char*cod,char**&pedidosLibros,bool*&pedidoAtendido,int&num_lib_2,int&cap_lib_2,int**stock,char***libros);
int buscar_libro(char*cod,char***libros);
void ordenarPedidosClientes(int**&pedidosClientes);
void qsort(int**&arr,int izq,int der);
void cambiar(int*&arr1,int*&arr2);
#endif /* METODOINCREMENTO_H */

