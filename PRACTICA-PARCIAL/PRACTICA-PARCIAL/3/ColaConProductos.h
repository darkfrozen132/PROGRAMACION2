/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   ColaConProductos.h
 * Author: Leoncio
 *
 * Created on 6 de mayo de 2024, 10:58 PM
 */

#ifndef COLACONPRODUCTOS_H
#define COLACONPRODUCTOS_H

void procesarPedidos(int**&fechaClienteCantidad,char**&codigoDelProducto,void*&productos);
void reporteDePedidos(void*productos,char*nombre_archivo);


int buscar(char*codigo,void*prod);

#endif /* COLACONPRODUCTOS_H */

