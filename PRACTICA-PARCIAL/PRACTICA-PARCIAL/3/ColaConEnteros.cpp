#include <iostream>
#include <iomanip>
#include <cstring>
#include<fstream>


using namespace std;
#include "Pregunta1.h"
#include "Pregunta2.h"

#include "ColaConEnteros.h"
//#include "ColaConProductos.h"
#include "ColaGenerica.h"

void cargaEnteros(void*&cola,void*(*lee)(ifstream&),char*nombre_archivo){
    ifstream arch(nombre_archivo,ios::in);
    void* reg;
    generacola(cola);
    
    while(1){
        reg=lee(arch);
        if(reg==nullptr) break;
        encola(cola,reg);
        
    }
    
}
void* leenumero(ifstream&input){
    int*num=new int;
    input>>*num;
    if(input.eof()) return nullptr;
    return num;
    
    
}
void mostrarEnteros(void*cola,void(*imprimenumero)(ofstream&,void*),char*nombre_archivo){
    ofstream archReporte(nombre_archivo,ios::out);
    void* reg;
    while(!colavacia(cola)){
        reg=desencola(cola);
        imprimenumero(archReporte,reg);
        void**col=(void**)cola;
        archReporte<<*(int*)col[2]<<endl;
    }
    
}
void imprimenumero(ofstream&output,void*reg){
    void**registro=(void**)reg;
    output<<*(int*)registro[0]<<" ";
}
