#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "funciones.h"
void CargaDeClientes (int*&cli_DNI,char**& cli_Nombre,char*& cli_Categoria){
    
    ifstream archClientes("Clientes.csv",ios::in);
    int buff_cli_DNI[1000],cli,cant=0,tele;
    char *buff_cli_Nombre[1000],*nombre,aux;
    char buff_cli_Categoria[1000],categoria;
    while(1){
        archClientes>>cli;
        if(archClientes.eof()) break;
        archClientes>>aux;
        nombre=leer_cadena(archClientes,',');
        categoria=dar_categoria(nombre);
        archClientes>>tele;
        //pasar arreglo estaticos;
        buff_cli_DNI[cant]=cli;
        buff_cli_Nombre[cant]=nombre;
        buff_cli_Categoria[cant]=categoria;
        cant++;
        
    }
    //crear espacio para arreglo dinamicos;
    cli_DNI= new int[cant+1]{};
    cli_Nombre= new char*[cant+1]{};
    cli_Categoria= new char[cant+1]{};
    //pasar datos de estaticos a dinamicos
    for(int i=0;i<cant;i++){
        cli_DNI[i]=buff_cli_DNI[i];
        cli_Nombre[i]=buff_cli_Nombre[i];
        cli_Categoria[i]=buff_cli_Categoria[i];
    }
    
    
}
char* leer_cadena(ifstream&input,char c){
    char *nombre,buff[100];
    
    input.getline(buff,100,c);
    nombre=new char[strlen(buff)+1];
    strcpy(nombre,buff);
    return nombre;
    
}
char dar_categoria(char*&nombre){
    char cate;
    int tam_nombre=strlen(nombre);
    if(nombre[tam_nombre-2]==' '){
        cate=nombre[tam_nombre-1];
        nombre[tam_nombre-1]=' ';
       
    }
    else{
        cate='-';
        
    }
        return cate;
}
void ReporteDeClientes (int*cli_DNI,char** cli_Nombre,char* cli_Categoria){
    ofstream archReporteClientes("ReporteDeClientes.txt",ios::out);
    for(int i=0;cli_Nombre[i];i++){
        archReporteClientes<<left<<setw(10)<<cli_DNI[i]<<setw(60)<<cli_Nombre[i]
                <<setw(8)<<cli_Categoria[i]<<endl;
    }
}
void CargaDePedidosYProductos(int*&cli_DNI,int*& pro_Codigo,char**& pro_Descripcion,
    double*&pro_Descuento,double*& pro_Precio,int**& cli_CodigoProFechaPedido, 
        double**&cli_CantidadPedido){
    ifstream archPedidos("Pedidos.csv",ios::in);
    int *buff_pro_Codigo{},*buff_cli_CodigoProFechaPedido[1000]{};
    char *buff_pro_Descripcion[1000]{};
    double buff_pro_Descuento[1000]{},buff_pro_Precio[1000]{},*buff_cli_CantidadPedido[1000];
    int cantidad[500]{};
    int cant,pos;
    int cod,dni,fecha;
    char *descripcion;
    double precio,descuento;
    for(int i=0;cli_DNI[i];i++){
        buff_cli_CodigoProFechaPedido[i]= new int[1000]{};
        buff_cli_CantidadPedido[i]= new double[1000]{};
       
    }
    buff_pro_Codigo= new int[1000];
    while(1){
        archPedidos>>cod;
        if(archPedidos.eof()) break;
        descripcion=leer_cadena(archPedidos,',');
        leer_valores_restantes(cant,dni,fecha,precio,descuento,archPedidos);
        pos=buscar_dni(cli_DNI,dni);
        colocar_valores(buff_cli_CodigoProFechaPedido[pos],buff_cli_CantidadPedido[pos],cod,fecha,
                cant,cantidad[pos]);
        //pos2=buscar_producto(buff_pro_Codigo,cod);
        colocar_producto(buff_pro_Codigo,cod,buff_pro_Descripcion,descripcion,buff_pro_Descuento,descuento,buff_pro_Precio,precio);
    }
    
           
}
void colocar_producto(int*&buff_pro_Codigo,int cod,char**&buff_pro_Descripcion,char*descripcion,
        double*&buff_pro_Descuento,double descuento,double*&buff_pro_Precio,double precio){
    /*
    for(int i=0;buff_pro_Codigo[i];i++){
        if(buff_pro_Codigo[i]==cod){
          
        }
        else{
            buff_pro_Codigo[i]=cod;
            buff_pro_Descripcion[i]=descripcion;
            buff_pro_Descuento[i]=descuento;
            buff_pro_Precio[i]=precio;
        }
    }
     * */
}

void colocar_valores(int*&pro_Codigo_Fecha,double*&cli_cantidad_pedido,int cod,int fecha,
            int cant,int&cantidad){
    pro_Codigo_Fecha[2*cantidad]=cod;
    pro_Codigo_Fecha[2*cantidad+1]=fecha;
    cli_cantidad_pedido[cantidad]=cant;
    cantidad++;
    

}
void leer_valores_restantes(int &cant,int&dni,int&fecha,double&precio,
        double&descuento,ifstream&archPedidos){
    char aux;
    int dd,mm,aa;
    archPedidos>>cant;
    if(archPedidos.fail()){
        archPedidos.clear();
        archPedidos>>descuento>>aux>>cant;
    }
    else{
        descuento=0;
    }
    archPedidos>>aux>>precio>>aux>>dni>>aux>>dd>>aux>>mm>>aux>>aa;
    fecha=dd+mm*100+aa*10000;
}
int buscar_dni(int*cli_DNI,int dni){
    for(int i=0;cli_DNI[i];i++){
        if(dni==cli_DNI[i]) return i;
    }
    return -1;
}

