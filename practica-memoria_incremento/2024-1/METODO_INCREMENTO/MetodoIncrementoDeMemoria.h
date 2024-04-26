/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   MetodoIncrementoDeMemoria.h
 * Author: leoncio
 *
 * Created on 17 de abril de 2024, 02:15 PM
 */

#ifndef METODOINCREMENTODEMEMORIA_H
#define METODOINCREMENTODEMEMORIA_H

void lecturaDeLibros (char*nombre_archivo,char***&libros, int**&stock);
void pruebaDeLecturaDeLibros (char*nombre_archivo,char***&libros, int**&stock);
void atencionDePedidos (char*, char***&, int**&, int**&, char***&,bool**& pedidosAtendidos);


// funciones adicionales
char *leer_cadena(ifstream&input,char c);
void incrementa_memoria(char***&libros, int**&stock,int &numDat,int&cap);
int buscar(int**pedidosClientes,int numDat,int dni);
void incrementar_memoria(int**&pedidosClientes,int&numDat,int&cap,int*&cap_lib);
void colocarPedidos(int cod,int dni, int**&pedidosClientes,int&numDat,int*&cap_lib);
void incrementar_memoria_pedido_cliente(int*pedidosClientes,int &cap_lib);
/*
 char ***libros,***pedidosLibros;
    int **stock, **pedidosClientes;
    bool **pedidosAtendidos;
 */
#endif /* METODOINCREMENTODEMEMORIA_H */

