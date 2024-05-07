/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   FlotaGenerica.h
 * Author: Leoncio
 *
 * Created on 2 de mayo de 2024, 08:20 PM
 */

#ifndef FLOTAGENERICA_H
#define FLOTAGENERICA_H

#include <fstream>

using namespace std;
void cargacamiones(void*&flota,int numcamiones,double pesomaximo,void* (*lee)(ifstream&),
        double(*calculanumero)(void*),char*filename);


double calcula_peso_camion(void*aux_flota);
void crear_lista(void*&lista);
void agregar_dato(void*dato,void*aux_flota);
void actualizar_pedido(double peso,void*flota);
#endif /* FLOTAGENERICA_H */

