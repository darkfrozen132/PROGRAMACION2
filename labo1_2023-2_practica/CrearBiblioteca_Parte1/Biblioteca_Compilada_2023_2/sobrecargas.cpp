#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "AperturaDeArchivos.h"
#include "Estructuras.h"
using namespace std;
bool  operator >> (ifstream& in,struct Cliente& cliente){
    char aux;
    in>>cliente.dni;
    if(in.eof()){
        cliente.dni=0;
        return false;
    }
    
    in>>aux;
    in.getline(cliente.nombre,50,',');
    in>>cliente.telefono;
    
    for(int i=0;i<20;i++){
        cliente.productosEntregados[i]=ProductoEntregado();
    }
    cliente.montoTotal=0;
    cliente.cantidadProductosEntrgados=0;
    
    
    
    return true;
}
bool  operator >> (ifstream& in,struct Producto& producto){
    char aux;
    in.getline(producto.codigo,10,',');
    if(in.eof()){
        strcpy(producto.codigo,"XXXXXXX");
        return false;
    }
    
    
    in.getline(producto.descripcion,60,',');
    in>>producto.precio>>aux>>producto.stock;
    in>>ws;
    for(int i=0;i<20;i++){
        producto.clientesServidos[i]=0;
    }
    for(int i=0;i<20;i++){
        producto.clientesNoServidos[i]=0;
    }
    producto.cantidadClientesNoServidos=0;
    producto.cantidadClientesServidos=0;
    return true;
    
}
bool  operator >> (ifstream& in,struct Pedido& pedido){
    char aux;
    in.getline(pedido.CodigoProducto,10,',');
    
    if(in.eof()){
        strcpy(pedido.CodigoProducto,"XXXXXXX");
        pedido.dniCliente=0;
        return false;
    }
    in>>pedido.dniCliente;
    in>>ws;
    pedido.precioProducto=0;
    return true;
    
}
void operator +=(struct Cliente* cliente,struct Pedido& pedido){
    struct ProductoEntregado productoE;
    int i=0;    
    
        
        while(1){
            if(pedido.dniCliente==cliente[i].dni){
               
                cliente[i].montoTotal=cliente[i].montoTotal+pedido.precioProducto;
                strcpy(productoE.codigo,pedido.CodigoProducto);
                productoE.precio=pedido.precioProducto;
                cliente[i].productosEntregados[cliente[i].cantidadProductosEntrgados]=productoE;
                cliente[i].cantidadProductosEntrgados++;
                 
                
            }
            if(cliente[i].dni==0) break;
            
            
            i++;
        }
    
    
}
bool operator +=(struct Producto*productos,struct Pedido&pedido){
    int i=0;
    while(1){
        if(strcmp(productos[i].codigo,pedido.CodigoProducto)==0 ){
            if(productos[i].stock>0){
                productos[i].clientesServidos[productos[i].cantidadClientesServidos]=pedido.dniCliente;
                
                productos[i].precio=pedido.precioProducto;
                productos[i].stock--;
                return true;
                }
                else{        
                productos[i].clientesNoServidos[productos[i].cantidadClientesNoServidos]=pedido.dniCliente;
                productos[i].cantidadClientesNoServidos++;    productos[i].precio=pedido.precioProducto;
                return false;

                }
        }
        
        if(strcmp(productos[i].codigo,"XXXXXXX")==0) break;
        i++;
    }
    return false;
    
    
}
ofstream& operator <<(ofstream& out,const struct Cliente &cliente){
    int i=0;
    out<<setprecision(2);
    out<<fixed;
    out<<left<<setw(10)<<cliente.dni<<setw(60)<<cliente.nombre<<right<<setw(15)<<cliente.telefono<<
            setw(15)<<cliente.montoTotal<<setw(20)<<" Productos entregados: ";
    if(cliente.cantidadProductosEntrgados==0){
            out<<"No se le entregaron productos";
            
    }
    else{
        for(int i=0;i<cliente.cantidadProductosEntrgados;i++){


                out<<left<<setw(7)<<cliente.productosEntregados[i].codigo<<" ";



        }
    }
    out<<endl;
    
}
ofstream& operator<<(ofstream& out,const struct Producto&producto){
    out<<setprecision(2);
    out<<fixed;
    out<<left<<setw(8)<<producto.codigo<<setw(50)<<producto.descripcion<<right
            <<setw(6)<<producto.precio<<setw(15)<<producto.stock<<endl;
    out<<"Clientes atendidos: ";
    if(producto.cantidadClientesServidos==0){
        out<<"NO SE ATENDIERON PEDIDOS"<<endl;
    }
    else{
        for(int i=0;i<producto.cantidadClientesServidos;i++){
            out<<right<<setw(10)<<producto.clientesServidos[i];
        }
    }
    out<<endl;
    out<<"Clientes no atendidos: ";
    if(producto.cantidadClientesNoServidos==0){
        out<<"NO HAY CLIENTES SIN ATENDER"<<endl;
    }
    else{
        for(int i=0;i<producto.cantidadClientesNoServidos;i++){
            out<<right<<setw(10)<<producto.clientesNoServidos[i];
        }
    }
    out<<endl;
    
}