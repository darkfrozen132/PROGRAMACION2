#include <iostream>
#include <fstream>
#include <iomanip>
#include<cstring>
using namespace std;

#include "PunterosGenericos.h"

enum reg_productos{CODIGO,DESCRIPCION,PRECIO,TIPO_PRODUCTO};
enum reg_clientes{DNI,NOMBRE_CLIENTE,LISTAPEDACEP,LINEACRED};
enum reg_pedidos{CODIGOPED,DNIPED,CANTPED};
void cargaproductos(void*&pr){
    ifstream archProductos("Productos2.csv",ios::in);
    void *productos[200]{};
    void **buff_productos;
    void *reg_pro;
    int cant=0;
    while(1){
        reg_pro=leer_linea_productos(archProductos);
        if(archProductos.eof()) break;
        productos[cant]=reg_pro;
        cant++;
    }
    buff_productos=new void*[cant+1]{};
    for(int i=0;i<cant;i++){
        buff_productos[i]=productos[i];
    }
    pr=buff_productos;
    
}
void*leer_linea_productos(ifstream&archProductos){
    void**registro= new void*[4];
    char*cod,*descripcion;
    double *prec=new double;
    char *tipo=new char;
   
    cod=leer_cadena(archProductos,',');
    if(archProductos.eof()) return nullptr;
    descripcion=leer_cadena(archProductos,',');
    archProductos>>*prec;
    archProductos.get();
    archProductos>>*tipo;
    archProductos.get();
    registro[CODIGO]=cod;
    registro[DESCRIPCION]=descripcion;
    registro[PRECIO]=prec;
    registro[TIPO_PRODUCTO]=tipo;
    
    return registro;
    
}
char*leer_cadena(ifstream&archProductos,char c){
    char*aux,buf[1000];
    archProductos.getline(buf,1000,c);
    aux=new char[strlen(buf)+1];
    strcpy(aux,buf);
    return aux;
}
void cargaclientes(void*&cli){
    ifstream archClientes("Clientes2.csv",ios::in);
    void*reg;
    void*auxclientes[1000];
    void**clientes;
    int cant=0;
    while(1){
        reg=leer_linea_clientes(archClientes);
        if(archClientes.eof()) break;
        auxclientes[cant]=reg;
        cant++;
    }
    clientes=new void*[cant+1]{};
    for(int i=0;i<cant;i++){
        clientes[i]=auxclientes[i];
    }
    cli=clientes;
        
        
        
    
        
}
void* leer_linea_clientes(ifstream&archClientes){
    void**reg=new void*[4];
    
    int*dni=new int;
    char*nomb_clien;
    int*lin_cred=new int;
    int*tele=new int;
    archClientes>>*dni;
    if(archClientes.eof()) return nullptr;
    archClientes.get();
    nomb_clien=leer_cadena(archClientes,',');
    archClientes>>*tele;
    archClientes.get();
    archClientes>>*lin_cred;
    reg[DNI]=dni;
    reg[NOMBRE_CLIENTE]=nomb_clien;
    reg[LISTAPEDACEP]=nullptr;
    reg[LINEACRED]=lin_cred;
    return reg;
    
}
void cargapedidos(void*&productos,void*&clientes){
    ifstream archPedidos("Pedidos2.csv",ios::in);
    void*reg;
    void**producto;
    int pos_producto;
    while(1){
        reg=leer_linea_pedidos(archPedidos);
        if(archPedidos.eof()) break;
        pos_producto=buscar_producto(reg,productos);
        cout<<pos_producto<<endl;
    }   
}
int buscar_producto(void*reg,void*&productos){
    void**regis=(void**)reg;
    void**produc=(void**)productos;
    void**pro;
    for(int i=0;produc[i];i++){
        pro=(void**)produc[i];
        if(strcmp((char*)regis[0],(char*)pro[0])==0) return i;
    }
    return -1;
    
}
void*leer_linea_pedidos(ifstream&archPedidos){
    void**reg=new void*[3];
    int*dni=new int;
    int*cant=new int;
    char*codigo;
    codigo=leer_cadena(archPedidos,',');
    if(archPedidos.eof()) return nullptr;
    archPedidos>>*dni;
    archPedidos.get();
    archPedidos>>*cant;
    archPedidos.get();
    reg[CODIGOPED]=codigo;
    reg[DNIPED]=dni;
    reg[CANTPED]=cant;
    return reg;
            
            
}

