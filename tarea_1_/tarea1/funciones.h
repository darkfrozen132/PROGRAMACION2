/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funciones.h
 * Author: leoncio
 *
 * Created on 23 de marzo de 2024, 04:35 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

ifstream & operator >>(ifstream&,struct Persona&);
ofstream & operator <<(ofstream&,const struct Persona&);
void menu(ofstream&);


#endif /* FUNCIONES_H */

