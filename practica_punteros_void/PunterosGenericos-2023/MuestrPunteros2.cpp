#include <iostream>
#include <iomanip>
#include <fstream>        
using namespace std; 

enum RegProd{CODIGO,DESCRIPCION,PRECIO,TIPO};
enum RegCli{DNI,NOMBRE,PEDIDOS,LINEACREDITO};
enum RegPedido{CODIGOPRODUCTO,CANTIDADPRODUCTO,TOTALPEDIDO};

void imprimeproductos(void *prod){
    ofstream archRepProd("ReporteDeProductos.txt",ios::out);
    if(not archRepProd.is_open()){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO ReporteDeProductos.txt"<<endl;
        exit(1);
    }
    archRepProd<<setprecision(2)<<fixed;
    void**productos=(void**)prod;
    void**producto;
    for(int i=0;productos[i];i++){
        producto=(void**)productos[i];
        archRepProd<<(char*)producto[CODIGO]<<','<<(char*)producto[DESCRIPCION]<<','<<
                *((double*)producto[PRECIO])<<','<<*((char*)producto[TIPO])<<endl;
    }
}

void imprimeClientes(void *cli){
    ofstream archRepCli("ReporteDeClientes.txt",ios::out);
    if(not archRepCli.is_open()){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO ReporteDeClientes.txt"<<endl;
        exit(1);
    }
    archRepCli<<setprecision(2)<<fixed;
    void**clientes=(void**)cli;
    void**cliente;
    for(int i=0;clientes[i];i++){
        cliente=(void**)clientes[i];
        archRepCli<<*((int*)cliente[DNI])<<','<<(char*)cliente[NOMBRE]<<','<<*((int*)cliente[LINEACREDITO])<<endl;
    }
}