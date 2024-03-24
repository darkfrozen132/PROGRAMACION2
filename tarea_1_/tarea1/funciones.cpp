#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include "funciones.h"
#include "persona.h"



ifstream & operator >>(ifstream& in,struct Persona& persona){
    char aux;
    in>>persona.dni;
    if(!in.eof()){
    in>>aux;
    in>>persona.nombre;
    in>>persona.peso;
    in>>persona.talla;
    }
    else{
        persona.dni=0;
    }
    
    
    return in;
    
}
void menu(ofstream& out){
    out<<setw(10)<<left<<"DNI"<<setw(10)
    <<setw(10)<<left<<"Nombre"
    <<setw(10)<<left<<"Peso"
    <<setw(10)<<left<<"Talla";
    
}
ofstream & operator <<(ofstream&,const struct Persona){
    
}
