#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "AsignacionDinamicaMemoriaExacta.h"
#define INCREMENTO 5
void lecturaDeProductos (char*nombre_archivo,char***&productos,int*& stock,double*& precios){
    ifstream archProductos(nombre_archivo,ios::in);
    int num_dat=0,cap=0;
    char *buf_productos_nombre;
    char *buf_productos_codigo;
    char **buf_produc;
   
    int buf_stock;
    double buf_precio;
    char c;
    while(1){
        buf_productos_codigo=leer_cadena(archProductos,',');
        if(archProductos.eof()) break;
        buf_productos_nombre=leer_cadena(archProductos,',');
        archProductos>>buf_precio;
        archProductos.get();
        archProductos>>buf_stock;
        
       archProductos.get();
        buf_produc=new char*[2];
        buf_produc[0]=buf_productos_codigo;
        buf_produc[1]=buf_productos_nombre;
        if(num_dat==cap){
            incremento_memoria(productos,stock,precios,num_dat,cap);
        }
        productos[num_dat-1]=buf_produc;
        stock[num_dat-1]=buf_stock;
        precios[num_dat-1]=buf_precio;
        num_dat++;
        
    }
}
void pruebaDeLecturaDeProductos (char*nombre_archivo,char***&productos,int*& stock,double*& precios){
    ofstream archReporteProductos(nombre_archivo,ios::out);
    
    char **aux_produc;
    for(int i=0;productos[i];i++){
        aux_produc=productos[i];
        archReporteProductos<<setw(7)<<left<<aux_produc[0]<<setw(30)<<aux_produc[1]<<
                setw(10)<<stock[i]<<setw(10)<<precios[i]<<endl;
    }
}
void incremento_memoria(char***&productos,int*&stock,double*&precios,int &num_dat,int& cap){
    int *b_stock;
    double *b_precio;
    char *** b_productos;
    cap+=5;
    if(productos==nullptr){
        productos=new char**[cap];
        stock=new int[cap];
        precios=new double[cap];
        num_dat=1;
    }
    else{
        b_stock= new int[cap]{};
        b_precio=new double[cap]{};
        b_productos=new char**[cap]{};
        for(int i=0;i<num_dat;i++){
            b_stock[i]=stock[i];
            b_precio[i]=precios[i];
            b_productos[i]=productos[i];
            
        }
        delete productos;
        delete stock;
        delete precios;
        stock=b_stock;
        precios=b_precio;
        productos=b_productos;
    }
    
    
}
char* leer_cadena(ifstream&arch,char c){
    char*aux;
    char buf[1000];
    arch.getline(buf,1000,c);
    aux=new char[strlen(buf)+1];
    strcpy(aux,buf);
    return aux;
}