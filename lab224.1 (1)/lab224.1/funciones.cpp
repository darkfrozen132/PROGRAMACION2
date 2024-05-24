/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <string.h>
/* 
 * File:   funciones.cpp
 * Author: Administrador
 * 
 * Created on 18 de abril de 2024, 13:51
 */

#include "funciones.h"
#define INCREMENTO 5
using namespace std;
char *obtenerCadena(ifstream &arch,char delimitador){
    char cad[100],*cadena;
    arch.getline(cad,100,delimitador);
    if(arch.eof())return nullptr;
    cadena= new char [strlen(cad)+1];
    strcpy(cadena,cad);
    return cadena;
}

void incrementarLibros(char ***&libros,int **&stock,int &numeroLibros,int &capacidadLibros){
    capacidadLibros+=INCREMENTO;
    char ***librosAux;
    int **stockAux;
    if(numeroLibros==0){
        libros= new char **[capacidadLibros]{};
        stock= new int  *[capacidadLibros]{};
        numeroLibros++;    
    }else{
        librosAux= new char **[capacidadLibros]{};
        stockAux= new int  *[capacidadLibros]{};        
        for(int i=0;i<numeroLibros;i++){
            librosAux[i]=libros[i]; 
            stockAux[i]=stock[i];    
        }
        delete libros;
        delete stock;
        libros=librosAux;
        stock=stockAux;
    }

}
void agregarLibro(char *codigo,char *nombre,char *autor,char **&libroActual,int *&stockActual,int stock){
    libroActual= new char *[3];
    libroActual[0]=codigo;
    libroActual[1]=nombre;
    libroActual[2]=autor;
    stockActual= new int [2];
    stockActual[0]=stock;
    stockActual[1]=0;
    
}

void lecturaDeLibros(char *nombreArch,char ***&libros,int **&stock){
    ifstream arch (nombreArch,ios::in);
    if(!arch){
        cout<<"ERROR EN LA APERTURA DEL ARCHIVO"<<nombreArch;
        exit(1);
    }
    char *codigo,*nombre,*autor;
    int stockProducto,numeroLibros=0,capacidadLibros=0;
    double precio;
    while(1){
        codigo=obtenerCadena(arch,',');
        if(arch.eof())break;
        nombre=obtenerCadena(arch,',');
        autor=obtenerCadena(arch,',');
        arch>>stockProducto;
        arch.get();
        arch>>precio;
        arch.get();
        if(numeroLibros==capacidadLibros)incrementarLibros(libros,stock,numeroLibros,capacidadLibros);
        agregarLibro(codigo,nombre,autor,libros[numeroLibros-1],stock[numeroLibros-1],stockProducto);
        numeroLibros++;
    }
}
void pruebaDeLecturaDeLibros(char *nombreArch,char ***libros,int **stock){
    ofstream arch (nombreArch,ios::out);
    if(!arch){
        cout<<"ERROR EN LA APERTURA DEL ARCHIVO"<<nombreArch;
        exit(1);
    }
    char **libroActual;
    int *stockActual;
    arch<<"Los libros son los Siguientes"<<endl;

    for(int i=0;libros[i];i++){
        libroActual=libros[i];
        stockActual=stock[i];
        arch<<left<<setw(20)<<libroActual[0]<<setw(60)<<libroActual[1]<<setw(30)<<libroActual[2]<<stockActual[0]<<endl;
        
    }
}
char *obtenerCodigo(ifstream &arch){
    char cad[20],*cadena;
    arch>>cad;
    cadena=new char [strlen(cad)+1];
    strcpy (cadena,cad);
    return cadena;
}
int buscarCliente(int **pedidosClientes,int dni){
    int *clienteActual;
    for(int i=0;pedidosClientes[i];i++){
        clienteActual=pedidosClientes[i];
        if(clienteActual[0]==dni)return i;
    }
    return -1;
}
void aumentarEspaciosPedidosClientes(int **&pedidosClientes,int &numeroDePedidos,int &capacidadDePedidos){
       capacidadDePedidos+=INCREMENTO;
    int **pedidosClientesAux;
    if(numeroDePedidos==0){
        pedidosClientes= new int  *[capacidadDePedidos]{};
        numeroDePedidos++;    
    }else{
        pedidosClientesAux= new int  *[capacidadDePedidos]{};        
        for(int i=0;i<numeroDePedidos;i++){
            pedidosClientesAux[i]=pedidosClientes[i];   
        }
        delete pedidosClientes;
        pedidosClientes=pedidosClientesAux;
    }
}
void incrementarPedidosClientes(int *&pedidoCliente,int &numeroPedidosClientes,int &capacidad){
    capacidad+=INCREMENTO;
    int *pedidoClienteAux;
    if(numeroPedidosClientes==0){
        pedidoCliente=new int [capacidad]{};
        numeroPedidosClientes++;
    }else{
        pedidoClienteAux= new int[capacidad]{};
        for(int i=0;i<numeroPedidosClientes;i++){
            pedidoClienteAux[i]=pedidoCliente[i];
        }
        delete pedidoCliente;
        pedidoCliente=pedidoClienteAux;
    }
}
void ingresarClienteNuevo(int *&pedidoCliente,int dni,int numeroPedido,int &numeroPedidosClientes,int &capacidadPedidosClientes){
    pedidoCliente=nullptr;
    incrementarPedidosClientes(pedidoCliente,numeroPedidosClientes,capacidadPedidosClientes);
    pedidoCliente[0]=dni;
    pedidoCliente[1]=1;
    pedidoCliente[2]=numeroPedido;
    numeroPedidosClientes=3;
}
void ingresarPedidoCliente(int numeroPedido,int *&pedidosClientes,int &numeroPedidosClientes,int &capacidadPedidosClientes){
    if(numeroPedidosClientes==capacidadPedidosClientes)incrementarPedidosClientes(pedidosClientes,numeroPedidosClientes,capacidadPedidosClientes);
    pedidosClientes[1]++;
    pedidosClientes[numeroPedidosClientes]=numeroPedido;
    numeroPedidosClientes++;
}

void aumentarPedidos(char ***&pedidosLibros,bool **&pedidosAtendidos,int &cantidadPedidos,int &capacidadDePedidos){
    capacidadDePedidos+=INCREMENTO;
    char ***pedidosLibrosAux;
    bool **pedidosAtendidosAux;
    
    if(cantidadPedidos==1){
        pedidosLibros= new char **[capacidadDePedidos]{};
        pedidosAtendidos= new bool *[capacidadDePedidos]{};
    }else{
        pedidosLibrosAux= new char **[capacidadDePedidos]{};
        pedidosAtendidosAux= new bool *[capacidadDePedidos]{};       
        for(int i=0;i<cantidadPedidos;i++){
            pedidosLibrosAux[i]=pedidosLibros[i];
            pedidosAtendidosAux[i]=pedidosAtendidos[i];
        }
        delete pedidosLibros;
        delete pedidosAtendidos;
        pedidosLibros=pedidosLibrosAux;
        pedidosAtendidos=pedidosAtendidosAux;
    }
    
}
void incrementarCodigosPedidos(char **&pedidosLibros,bool *&pedidosAtendidos,int &numeroLibros,int &capacidadLibros){
    char **pedidosLibrosAux;
    bool *pedidosAtendidosAux;
    capacidadLibros+=INCREMENTO;
    if(numeroLibros==0){
        pedidosLibros= new char *[capacidadLibros]{};
        pedidosAtendidos= new bool [capacidadLibros]{};
        numeroLibros++;        
        
    }else{
        pedidosLibrosAux= new char *[capacidadLibros]{};
        pedidosAtendidosAux= new bool [capacidadLibros]{};
        for(int i=0;i<numeroLibros;i++){
            pedidosLibrosAux[i]=pedidosLibros[i];
            pedidosAtendidosAux[i]=pedidosAtendidosAux[i];
        }
        delete pedidosAtendidos;
        delete pedidosLibros;
        pedidosLibros=pedidosLibrosAux;
        pedidosAtendidos=pedidosAtendidosAux;
    }
}
int buscarPosicion(char ***libro,char *codigo){
    char **libroActual;
    for(int i=0;libro[i];i++){
        libroActual=libro[i];
        if(strcmp(libroActual[0],codigo)==0)return i;
    }
    return -1;
}
void agregarCodigoPedido(char *codigo,char **&pedidosLibros,bool *&pedidosAtendidos,int **&stock,char ***libros,int &numeroLibros,int &capacidadLibros){
    if(numeroLibros==capacidadLibros)incrementarCodigosPedidos(pedidosLibros,pedidosAtendidos,numeroLibros,capacidadLibros);
    int posicionLibro=buscarPosicion(libros,codigo);
    cout<<numeroLibros;
    pedidosLibros[numeroLibros-1]=codigo;
    int *stockActual;
    stockActual=stock[posicionLibro];
    cout<<codigo<<endl;
    numeroLibros++;
}
void atencionDePedidos(char *nombreArch,char ***libros,int **&stock,int **&pedidosClientes,char ***&pedidosLibros,bool **&pedidosAtendidos){
    ifstream arch (nombreArch,ios::in);
    if(!arch){
        cout<<"ERROR EN LA APERTURA DEL ARCHIVO"<<nombreArch;
        exit(1);
    }
    pedidosClientes=nullptr;
    pedidosLibros=nullptr;
    pedidosAtendidos=nullptr;
    int numeroPedido=0,dni,nroActual,cantidadPedidosActual,numeroDePedidos=0,capacidadDePedidos=0,numeroClientes=0,capacidadClientes=0;
    int numeroPedidosClientes[200]{},capacidadPedidosClientes[200]{};
    int numeroLibrosPedidos[200]{},capacidadlibrosPedidos[200]{},posicionCliente;
    int cantidadPedidos=0;
    char *codigo=nullptr,c;
    while(1){
        arch>>numeroPedido;
        if(arch.eof())break;
        if(arch.fail()){
            arch.clear();
            codigo=obtenerCodigo(arch);
            if(cantidadPedidos==1||cantidadPedidos==capacidadDePedidos)aumentarPedidos(pedidosLibros,pedidosAtendidos,cantidadPedidos,capacidadDePedidos);            

            agregarCodigoPedido(codigo,pedidosLibros[cantidadPedidos-1],pedidosAtendidos[cantidadPedidos-1],stock,libros,numeroLibrosPedidos[cantidadPedidos-1],capacidadlibrosPedidos[cantidadPedidos-1]);
        }else{
            arch>>c>>dni;
            if(numeroClientes==capacidadClientes)aumentarEspaciosPedidosClientes(pedidosClientes,numeroClientes,capacidadClientes);
            posicionCliente=buscarCliente(pedidosClientes,dni);
            if(posicionCliente==-1){
                ingresarClienteNuevo(pedidosClientes[numeroClientes-1],dni,numeroPedido,numeroPedidosClientes[numeroClientes-1],capacidadPedidosClientes[numeroClientes-1]);
                numeroClientes++;
                cantidadPedidos++;            

            }else{
                ingresarPedidoCliente(numeroPedido,pedidosClientes[posicionCliente],numeroPedidosClientes[posicionCliente],capacidadPedidosClientes[posicionCliente]);
                cantidadPedidos++;            

            }
          
        }
    }
    int *clienteActual;
    for(int i=0;pedidosClientes[i];i++){
        clienteActual=pedidosClientes[i];
        cout<<left<<setw(10)<<clienteActual[0]<<setw(10)<<clienteActual[1];
//        for(int j=2;clienteActual[j];j++){
//            cout<<setw(10)<<clienteActual[j];
//        }
        for(int j=2;j<numeroPedidosClientes[j];j++){
            cout<<setw(10)<<clienteActual[j];
        }
        cout<<endl;
    }
}


