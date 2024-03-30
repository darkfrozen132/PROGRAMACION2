/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: leoncio
 *
 * Created on 30 de marzo de 2024, 04:14 PM
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "AperturaDeArchivos.h"
#include "Estructuras.h"
#include "sobrecargas.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    ifstream archClientes;    
    ifstream archProductos;
    ifstream archPedidos;
    AperturaDeUnArchivoDeTextosParaLeer(archClientes,"Clientes.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archPedidos,"Pedidos.csv");
    AperturaDeUnArchivoDeTextosParaLeer(archProductos,"Productos.csv");
    ofstream archClienteEscritura;
    ofstream archProductoEscritura;
    AperturaDeUnArchivoDeTextosParaEscribir(archClienteEscritura,"ResumenClientes.txt");
    AperturaDeUnArchivoDeTextosParaEscribir(archProductoEscritura,"ResumenProductos.txt");
    struct Cliente cliente[1000];
    struct Producto producto[1000];
    struct Pedido pedido[1000];
    int i=0;
    while(archClientes>>cliente[i]){
        i++;
    }
        
        
    i=0;
    
    while(archProductos>>producto[i]){
        
        i++;
    }
    
    i=0;
    while(archPedidos>>pedido[i]){
        
        i++;
    }
     
    i=0;
    int j=0;
    while(1){
        while(1){
            if(strcmp(pedido[i].CodigoProducto,producto[j].codigo)==0){
              pedido[i].precioProducto=producto[j].precio;
              
              
              break;
            }
           
            if(strcmp(producto[j].codigo,"XXXXXXX")==0) break;
            
            
            j++;
        }
        j=0;
        if(pedido[i].dniCliente==0) break;
        i++;
    }
     
    i=0,j=0;
  
    
   
    while(1){
        cliente+=pedido[i];
        if(pedido[i].dniCliente==0) break;
        i++;
        
                
    }
    i=0,j=0;
    while(1){
        producto+=pedido[i];
        if(pedido[i].dniCliente==0) break;
        
        i++;
        
         
        
        
    }
    
    i=0;
    archClienteEscritura<<right<<setw(80)<<"Reporte de Clientes"<<endl;
    archClienteEscritura<<left<<setw(10)<<"DNI"<<setw(60)<<"Nombre"<<setw(15)<<right<<"Telefono"
            <<setw(15)<<"Monto Total"<<" "<<left<<setw(60)<<"Lista de Productos Entregados"<<endl;
    while(1){
        archClienteEscritura<<cliente[i];
        if(cliente[i].dni==0) break;
        i++;
                
    }
    i=0;
    archProductoEscritura<<right<<setw(80)<<"Reporte de Productos"<<endl;
    archProductoEscritura<<left<<setw(8)<<"Codigo"<<setw(50)<<"Descripcion"<<right<<setw(6)
            <<"Precio"<<right<<setw(15)<<"Stock Final"<<endl;
    while(1){
        archProductoEscritura<<producto[i];
        if(strcmp(producto[i].codigo,"XXXXXXX")==0) break;
        i++;
    }
    return 0;
}

