/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <iomanip>
#include <fstream>        
using namespace std; 
#include "Persona.h"

ifstream & operator >>(ifstream &arch,struct Persona &p){
    arch>>p.dni;
    if(arch.eof()) return arch;
    arch.get();
    arch.getline(p.nombre,50,',');
    arch>>p.suledo;
    return arch;
}