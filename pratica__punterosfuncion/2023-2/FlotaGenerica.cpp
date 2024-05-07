#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>

#include "ListaConEnteros.h"
#include "ListaConRegistros.h"
#include "FlotaGenerica.h"
using namespace std;

enum nodo{cab,sig};

void cargacamiones(void*&flota,int numcamiones,double pesomaximo,void* (*lee)(ifstream&),
        double(*calculanumero)(void*),char*filename){
    
    void*aux_flota[numcamiones];
    
    for(int i=0;i<numcamiones;i++){
       crear_lista(aux_flota[i]);
    }
    void*dato;
    ifstream archNumero(filename,ios::in);
    int num_cam=0;
    double acumulador=0;
    while(1){
        dato=lee(archNumero);
        if(dato==nullptr)break;
        
        double peso_dato=calculanumero(dato);
        
            double peso_camion=calcula_peso_camion(aux_flota[num_cam]);
        
        if(peso_dato+peso_camion>pesomaximo){
        
            
            num_cam++;
            if(num_cam>=numcamiones) break;
        
        }
        agregar_dato(dato,aux_flota[num_cam]);
        actualizar_pedido(peso_dato,aux_flota[num_cam]);
        
        
    }
    
    flota=aux_flota;
    
    for(int i=0;i<numcamiones;i++){
        cout<<aux_flota[i]<<endl;
    }
    
    
}
void actualizar_pedido(double peso,void*flota){
    void**flot=(void**)flota;
    double*ptr=new double;
    ptr=(double*)flot[cab];
    double pes=peso+*ptr;
    *ptr=pes;
}
double calcula_peso_camion(void*aux_flota){
    void**flota=(void**)aux_flota;
    double*pes=new double;
    pes=(double*)flota[cab];
   
    return *pes;
    
}
void agregar_dato(void*dato,void*aux_flota){
    void**nuevo_nodo=new void*[2];
    nuevo_nodo[cab]=dato;
    nuevo_nodo[sig]=nullptr;
    void**cabeza=(void**)aux_flota;
    nuevo_nodo[sig]=cabeza[sig];
    cabeza[sig]=nuevo_nodo;
    
    
    
}
void crear_lista(void*&lista){
    
    double* peso=new double;
    *peso=0.0;
    void**lis=new void*[2];
    lis[cab]=peso;
    lis[sig]=nullptr;
    lista=lis;
    
}
