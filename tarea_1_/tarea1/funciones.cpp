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
    out<<right<<setw(60)<<endl;
    out<<left<<setw(15)<<"DNI"<<setw(15)<<"Nombre"<<setw(15)
            <<"Peso"<<setw(15)<<"Talla"<<endl;
    
    
}

ofstream & operator <<(ofstream& out,const struct Persona& persona){
    out.precision(2);
    out<<fixed;
    out<<left<<setw(15)<<persona.dni<<left<<setw(15)<<persona.nombre<<left<<
            setw(15)<<persona.peso<<setw(15)<<persona.talla<<endl;
    return out;
    
}

 
