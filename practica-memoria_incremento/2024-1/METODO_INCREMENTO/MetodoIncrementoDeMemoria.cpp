#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

#include "MetodoIncrementoDeMemoria.h"
#define INCREMENTO 5
void lecturaDeLibros (char*nombre_archivo,char***&libros, int**&stock){
    ifstream archLibros(nombre_archivo,ios::in);
    int numDat=0,cap=0;
    char *cod,*nom,*aut;
    char**aux_lib;
    int stoc;
    int *aux_stock;    
    double prec;
    while(1){
        cod=leer_cadena(archLibros,',');
        if(archLibros.eof()) break;
        nom=leer_cadena(archLibros,',');
        aut=leer_cadena(archLibros,',');
        archLibros>>stoc;
        archLibros.get();
        archLibros>>prec;
        archLibros.get();
        
        aux_lib=new char*[3];
        aux_lib[0]=cod; aux_lib[1]=nom; aux_lib[2]=aut;
        
        aux_stock=new int[2];
        aux_stock[0]=stoc; aux_stock[1]=0;
        
        if(numDat==cap) incrementa_memoria(libros,stock,numDat,cap);
        libros[numDat-1]=aux_lib;
        stock[numDat-1]=aux_stock;
        
        numDat++;
      
    }
    
}
void pruebaDeLecturaDeLibros (char*nombre_archivo,char***&libros, int**&stock){
    ofstream archReporteLibros(nombre_archivo,ios::out);
    char **aux_libros;
    int *aux_stock;
    
    for(int i=0;libros[i];i++){
        aux_libros=libros[i];
        aux_stock=stock[i];
        archReporteLibros<<left<<setw(10)<<aux_libros[0]<<setw(60)<<aux_libros[1]
                <<setw(50)<<aux_libros[2];
        archReporteLibros<<right<<setw(10)<<aux_stock[0]<<setw(10)<<aux_stock[1]<<endl;
    }
}
void incrementa_memoria(char***&libros, int**&stock,int &numDat,int&cap){
    char ***aux_libros;
    int **aux_stock;
    cap+=INCREMENTO;
    if(numDat==0){
        libros= new char**[cap];
        stock=new int*[cap];
        numDat=1;
    }
    else{
        aux_stock=new int*[cap]{};
        aux_libros=new char**[cap]{};
        for(int i=0;i<numDat;i++){
            aux_libros[i]=libros[i];
            aux_stock[i]=stock[i];
            
        }
        delete libros,stock;
        libros=aux_libros;
        stock=aux_stock;
    }
}
char *leer_cadena(ifstream&input,char c){
    char*aux,buf[1000];
    input.getline(buf,1000,c);
    aux=new char[strlen(buf)+1];
    strcpy(aux,buf);
    return aux;
}
void atencionDePedidos (char*nombre_archivo, char***&libros, int**&stock, 
        int**&pedidosClientes, char***&pedidosLibros,bool**& pedidosAtendidos){
    ifstream archPedidos(nombre_archivo,ios::in);
    int cod,numDat=0,cap=0;
    int dni;
    char *cod_lib;
    int pos;
    int *num_ped;
    int *cap_lib;
    
    while(1){
        archPedidos>>cod;
        if(archPedidos.eof()) break;
        archPedidos.get();
        archPedidos>>dni;
        
        if(numDat==cap) incrementar_memoria(pedidosClientes,numDat,cap,cap_lib);
        
        
        
      
        colocarPedidos(cod,dni,pedidosClientes,numDat,cap_lib);
        
        
        while(archPedidos.get()!='\n');
    }
    
}
int buscar(int**pedidosClientes,int numDat,int dni){
    int *aux_pedidos;
    if(numDat==1){
        return -1;
    }
    for(int i=0;i<numDat;i++){
        aux_pedidos=pedidosClientes[i];
        if(aux_pedidos[i]==dni) return i;
    }
    return -1;
    
}
void incrementar_memoria(int**&pedidosClientes,int&numDat,int&cap,int*&cap_lib){
    int **aux_pedidosClientes;
    int *aux_cap_lib;
    cap+=INCREMENTO;
    if(numDat==0){
        pedidosClientes = new int*[cap]{};
        
        cap_lib=new int[cap]{};
        numDat=1;
    }
    else{
         aux_pedidosClientes = new int*[cap]{};
         aux_cap_lib=new int[cap]{};
         for(int i=0;i<numDat;i++){
             aux_pedidosClientes[i]=pedidosClientes[i];
             aux_cap_lib[i]=cap_lib[i];
         }
         delete pedidosClientes,cap_lib;
         pedidosClientes=aux_pedidosClientes;
         cap_lib=aux_cap_lib;
         
    }
}
void colocarPedidos(int cod,int dni, int**&pedidosClientes,int&numDat,int*&cap_lib){
    int *aux_lib;
    int pos;
    aux_lib= new int[2]{};
    aux_lib[0]=cod;
    aux_lib[1]=0;
    pos=buscar(pedidosClientes,numDat,dni);
    if(pos==-1){
        
        if(cap_lib[numDat-1]==0){
            incrementar_memoria_pedido_cliente(pedidosClientes[numDat],cap_lib[numDat]);
        }
    
        pedidosClientes[numDat-1]=aux_lib;
        numDat++;
    }
   
     
    
    
    
    
}
void incrementar_memoria_pedido_cliente(int*pedidosClientes,int &cap_lib){
    int *aux_p_clien;
    
    cap_lib+=INCREMENTO;
    if(pedidosClientes==nullptr){
        pedidosClientes= new int[cap_lib];
        
    }
    else{
        aux_p_clien=new int[cap_lib]{};
        for(int i=0;i<pedidosClientes[1];i++){
            aux_p_clien[i]=pedidosClientes[i];
        }
        delete pedidosClientes;
        pedidosClientes=aux_p_clien;
    }
}
