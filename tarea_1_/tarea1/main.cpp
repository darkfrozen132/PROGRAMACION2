/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: leoncio
 *
 * Created on 23 de marzo de 2024, 04:34 PM
 */

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
#include "persona.h"
#include "funciones.h"
int main(int argc, char** argv) {
    Persona personas[100];
    int i=0;
    ifstream arch("personas.txt",ios::in);
    ofstream res("resultado.txt",ios::out);
    while(1){
        arch>>personas[i];
        if(arch.eof()) break;
        i++;
    }
    menu(res);
    i=0;
    while(1){
        res<<personas[i];
        i++;
        if(personas[i].dni==0){
            break;
        }
        
        
    }
    return 0;
}

