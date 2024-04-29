#include <iostream>
#include <fstream>
#include <iomanip>
#include<cstring>
using namespace std;
#include "MuestraPunteros.h"
#include "PunterosGenericos.h"

enum reg_productos{CODIGO,DESCRIPCION,PRECIO,TIPO_PRODUCTO};
enum reg_clientes{DNI,NOMBRE_CLIENTE,LISTAPEDACEP,LINEACRED};
enum reg_pedido{CODIGOPED,DNIPED,CANTPED};
enum reg_pedidos{CODIGOPRODUCTO, CANTIDADPRODUCTO, TOTALPEDIDO};
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
    int pos_producto,pos_cliente;
    int *cantidad_ClientesxPedido;
    //asignar memoria de 50 espacios temporales
    
    cantidad_ClientesxPedido=asignar_memoria(clientes);
    
    while(1){
        reg=leer_linea_pedidos(archPedidos);
        if(archPedidos.eof()) break;
        pos_producto=buscar_producto(reg,productos);
        pos_cliente=buscar_cliente(reg,clientes);
        cout<<pos_cliente<<endl;
        colocar_pedidos(productos,clientes,pos_producto,pos_cliente,reg,cantidad_ClientesxPedido);
    }
    for(int i=0;i<200;i++){
        cout<<cantidad_ClientesxPedido[i]<<"    "<<i<<endl;
    }
       

}
void colocar_pedidos(void*&productos,void*&clientes,int pos_producto,int pos_cliente,void*reg,int*&cantidad_ClientesxPedido){
    void**regis=(void**)reg;
    void**aux_productos=(void**)productos;  
    void**aux_producto=(void**)aux_productos[pos_producto];
    void**aux_clientes=(void**)clientes;
    void**aux_cliente=(void**)aux_clientes[pos_cliente];
    void**aux_lista_pedidos=(void**)aux_cliente[LISTAPEDACEP];
    int precio=*(int*)aux_producto[PRECIO];
    int cant=*(int*)regis[CANTPED];
    int nuevo_cred=*(int*)aux_cliente[LINEACRED]-precio*cant;
    int *cred=new int;
    *cred=nuevo_cred;  
    
    void** reg_pedidos=new void*[3];
    reg_pedidos[CODIGOPRODUCTO]=(char*)regis[CODIGOPED];
    reg_pedidos[CANTIDADPRODUCTO]=(char*)regis[CANTIDADPRODUCTO];
    reg_pedidos[TOTALPEDIDO]=cred;
    int indiceInsertado=cantidad_ClientesxPedido[pos_cliente];
//    enum reg_productos{CODIGO,DESCRIPCION,PRECIO,TIPO_PRODUCTO};
//    enum reg_clientes{DNI,NOMBRE_CLIENTE,LISTAPEDACEP,LINEACRED};
//    enum reg_pedidos{CODIGOPED,DNIPED,CANTPED};
//      enum reg_pedidos{CODIGOPRODUCTO, CANTIDADPRODUCTO, TOTALPEDIDO};
    cout<<indiceInsertado<<endl;;
    cout<<*(char*)aux_producto[TIPO_PRODUCTO]<<endl;
    cout<<*(int*)aux_cliente[LINEACRED]<<endl;
    cout<<endl;
    if(*(char*)aux_producto[TIPO_PRODUCTO]=='N'){
        aux_lista_pedidos[indiceInsertado]=reg_pedidos;
        aux_cliente[LISTAPEDACEP]=aux_lista_pedidos;
    }
    else{
        if(*(int*)aux_cliente[LINEACRED]>precio*cant){          
            aux_lista_pedidos[indiceInsertado]=reg_pedidos;
            aux_cliente[LISTAPEDACEP]=aux_lista_pedidos;
        }
        else{
            return;
        }
        
    }
    aux_clientes[pos_cliente]=aux_cliente;
    clientes=aux_clientes;
    cantidad_ClientesxPedido[pos_cliente]++;
    
    
    
}
int* asignar_memoria(void*&clientes){
    int *nPedidosXCliente;
    int cant_cliente_pedido=0;
    void**auxClientes=(void**)clientes;
    void**auxCliente;
    for(cant_cliente_pedido;auxClientes[cant_cliente_pedido];cant_cliente_pedido++){
        auxCliente=(void**)auxClientes[cant_cliente_pedido];
        auxCliente[LISTAPEDACEP]=new void*[50]{};
        auxClientes[cant_cliente_pedido]=auxCliente;
    
    
    }
    clientes=auxClientes;
    nPedidosXCliente=new int[cant_cliente_pedido+1]{0};
    return nPedidosXCliente;
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
int buscar_cliente(void*reg,void*&clientes){
    void**regis=(void**)reg;
    void**cliente=(void**)clientes;
    void**clien;
    for(int i=0;cliente[i];i++){
        clien=(void**)cliente[i];
        if(*(int*)regis[DNIPED]==*(int*)clien[DNI]) return i;
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
void imprimeReporte(void *&clientes){
    void **clientesPedidos,**arrClientes=(void **)clientes,**clienteActual,**pedidoActual;
    char *codigo;
    int *dni;
    for(int i=0;arrClientes[i];i++){
        clienteActual=(void **)arrClientes[i];
        clientesPedidos=(void **)clienteActual[2];
        dni=(int *)clienteActual[0];
        cout<<left<<setw(10)<<*dni<<": "<<i;
        for(int j=0;clientesPedidos[j];j++){
            if(clientesPedidos!=nullptr){
                pedidoActual=(void **)clientesPedidos[j];
                codigo=(char *)pedidoActual[0];
                cout<<left<<setw(10)<<(char *)codigo;                
            }   
        }
        cout<<endl;
    }
};
void imprimeLinea(ofstream& arch, char caracter, int repeticiones){
    for(int i=0; i<repeticiones; i++)
        arch << caracter;
    arch << endl;
}

void imprimeCliente(ofstream& archReporte, void* cliente){
    void** auxCliente, **auxRegistro, **auxPedidos, **auxPedido;
    auxCliente = (void**) cliente;
    auxRegistro = (void**) auxCliente;
    archReporte << left << setw(20) << *((int*) auxRegistro[DNI]) << 
            setw(50) << (char*) auxRegistro[NOMBRE_CLIENTE] << fixed <<
            *((double*) auxRegistro[LINEACRED]) << endl;
    imprimeLinea(archReporte, '-', 100);
    archReporte << "Pedidos atendidos:" << endl;
    imprimeLinea(archReporte, '-', 100);
    archReporte << left << setw(10) << "Código" << setw(10) << "Cantidad" <<
            "Total" << endl;
    auxPedidos = (void**) auxRegistro[LISTAPEDACEP];
    if(auxPedidos != nullptr)
        for(int i=0; auxPedidos[i]; i++){
            auxPedido = (void**) auxPedidos[i];
            archReporte << left << setw(10) << ((char*) auxPedido[CODIGO]) <<
                    setw(10) << *((int*) auxPedido[DNIPED]) <<
                    *((double*) auxPedido[CANTPED]) << endl;
        }
    archReporte << endl;
}
//enum reg_productos{CODIGO,DESCRIPCION,PRECIO,TIPO_PRODUCTO};
//enum reg_clientes{DNI,NOMBRE_CLIENTE,LISTAPEDACEP,LINEACRED};
//enum reg_pedidos{CODIGOPED,DNIPED,CANTPED};
