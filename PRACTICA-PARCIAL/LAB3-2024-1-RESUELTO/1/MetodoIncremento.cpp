#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;
#include "MetodoIncremento.h"
#include "AperturaDeArchivos.h"
void lecturaDeLibros(char*filename,char***&libros,int**&stock){
    ifstream archLibros;
    AperturaDeUnArchivoDeTextosParaLeer(archLibros,filename);
    int num=0,cap=0;
    char*cod,*nombre,*autor,c;
    int stck;
    double prec;
    while(1){
        cod=leer_cadena(archLibros,',');
        if(cod==nullptr) break;
        nombre=leer_cadena(archLibros,',');
        autor=leer_cadena(archLibros,',');
        archLibros>>stck>>c>>prec;
        archLibros.get();
        if(num==cap) incrementar_espacios(libros,stock,num,cap);
        pasar_datos(cod,nombre,autor,libros,stock,stck,num);
    }
    
    
}
void pruebaDeLecturaLibros(char*filename,char***libros,int**stock){
    char**aux_libros;
    int*aux_stock;
    ofstream archReporteLibros;
    AperturaDeUnArchivoDeTextosParaEscribir(archReporteLibros,filename);
    //encabezado;
    
    archReporteLibros<<left<<setw(10)<<"CODIGO"<<setw(60)<<"NOMBRE"<<setw(40)<<"AUTOR"
            <<setw(20)<<"Stock Inicial"<<setw(30)<<"Pedidos No atendidos"<<endl;
    for(int i=0;libros[i];i++){
        aux_libros=libros[i];
        aux_stock=stock[i];
        archReporteLibros<<left<<setw(10)<<aux_libros[0]<<setw(60)<<aux_libros[1]<<setw(40)
                <<aux_libros[2];
        archReporteLibros<<right<<setw(10)<<aux_stock[0]<<setw(20)<<aux_stock[1]<<endl;
    }
}
void pasar_datos(char*cod,char*nombre,char*autor,char***libros,int**stock,int stck,int& num){
    char**aux_lib=new char*[3];
    aux_lib[0]=cod;
    aux_lib[1]=nombre;
    aux_lib[2]=autor;
    
    libros[num-1]=aux_lib;
    
    int*aux_stck=new int[2];
    aux_stck[0]=stck;
    aux_stck[1]=0;
    
    
    
    stock[num-1]=aux_stck;
    
    num++;
    
}
void incrementar_espacios(char***&libros,int**&stock,int&num,int&cap){
    char***aux_lib;
    int**aux_stock;
    cap=cap+5;
    if(num==0){
        libros=new char**[cap]{};
        stock=new int*[cap]{};
        num=1;
    }
    else{
        aux_lib=new char**[cap]{};
        aux_stock=new int*[cap]{};
        for(int i=0;i<num;i++){
            aux_lib[i]=libros[i];
            aux_stock[i]=stock[i];
        }
        delete libros,stock;
        libros=aux_lib;
        stock=aux_stock;
                
    
    }
        
}
char* leer_cadena(ifstream&input,char c){
    char*buf,cad[100];
    input.getline(cad,100,c);
    if(input.eof()) return nullptr;
    buf=new char[strlen(cad)+1];
    strcpy(buf,cad);
   
    
    return buf;
}
void atencionDePedidos(char*filename,char***&libros,int**&stock,int**&pedidosClientes,
        char***&pedidosLibros,bool**&pedidosAtendidos){
    ifstream archPedidos;
    AperturaDeUnArchivoDeTextosParaLeer(archPedidos,filename);
    int num=0,cap=0;
    int num_2[1000]{}, cap_2[1000]{};
    
    int num_lib=0,cap_lib=0;
    int num_lib_2[1000]{},cap_lib_2[1000]{};
    pedidosLibros=nullptr;
    int ped,dni;
    int pos;
    char c;
    char cod[8];
    while(1){
        archPedidos>>ped;
        if(archPedidos.eof())break;
        archPedidos>>c>>dni;        
        pos=buscar_dni(pedidosClientes,dni,num);        
        if(pos==-1){
            if(num==cap)incrementar_espacios(pedidosClientes,num,cap);
            agregar_datos_dni(pedidosClientes[num-1],dni,num_2[num-1],cap_2[num-1],ped,pos);
            num++;
        }
        else{
        agregar_datos_dni(pedidosClientes[pos],dni,num_2[pos],cap_2[pos],ped,pos);    
        } 
        
        while(1){
            c=archPedidos.get();
            if(c=='\n') break;
            archPedidos>>cod;
              
            
            cout<<cap_lib<<" "<<ped<<endl;
            if(cap_lib<ped){
                while(1){
                    if(cap_lib<ped){
                    cap_lib=cap_lib+5;
                    }
                    else{
                        incrementar_espacios_2(pedidosLibros,pedidosAtendidos,cap_lib,num_lib);
                        num_lib=ped;
                        break;
                    }

                }
            }
            colocar_cod(cod,pedidosLibros[ped],pedidosAtendidos[ped],num_lib_2[ped],cap_lib_2[ped],stock,libros);
            c=archPedidos.get();
            if(c=='\n') break;
        }
        
        
        
      //  while(archPedidos.get()!='\n');
        
    }
    cout<<pedidosLibros[1][0]<<endl;
    
    for(int i=0;i<50;i++){
        cout<<pedidosLibros[i]<<endl;
           
//            for(int j=0;auxas[j];j++){
//                cout<<auxas[j]<<endl;
//            }
        }
   
        
 
    
}
void colocar_cod(char*cod,char**&pedidosLibros,bool*&pedidoAtendido,int&num_lib_2,int&cap_lib_2,int**stock,char***libros){
    if(num_lib_2==cap_lib_2) incrementar_espacios_nivel_2(pedidosLibros,pedidoAtendido,num_lib_2,cap_lib_2);
    
    char*codigo=cod;
    //strcpy(pedidosLibros[num_lib_2],cod);
    pedidosLibros[num_lib_2-1]=codigo;
    
    int pos;
    pos=buscar_libro(cod,libros);
    if(pos!=-1){
        int *aux=stock[pos];
  
        if(aux[0]>0){
            pedidoAtendido[num_lib_2-1]=true;
            aux[0]--;
            
        }
        else{
            aux[1]++;
        }
    
    stock[pos]=aux;
    num_lib_2++;
    }
}
int buscar_libro(char*cod,char***libros){
    char**aux;
    
    for(int i=0;libros[i];i++){
        aux=libros[i];
        if(strcmp( cod,aux[0]   )==0) return i;
    }
    return -1;
}

void incrementar_espacios_nivel_2(char**&pedidosLibros,bool*&pedidoAtendido,int&num_lib,int&cap_lib){
    char**aux_pedidos_libros;
    bool*aux_pedidoAtendidos;
    cap_lib=cap_lib+5;
    if(num_lib==0){
        pedidosLibros=new char*[cap_lib]{};
        pedidoAtendido=new bool[cap_lib]{};
        num_lib=1;
    }
    else{
       aux_pedidos_libros=new char*[cap_lib]{};
       aux_pedidoAtendidos=new bool[cap_lib]{};
       for(int i=0;i<num_lib;i++){
           aux_pedidos_libros[i]=pedidosLibros[i];
           aux_pedidoAtendidos[i]=pedidoAtendido[i];
       }
       delete pedidosLibros,pedidoAtendido;
       pedidosLibros=aux_pedidos_libros;
       pedidoAtendido=aux_pedidoAtendidos;
    }
}
void incrementar_espacios_2(char***&pedidosLibros,bool**&pedidosAtendidos,int&cap_lib,int&num_lib){
    char***aux_pedidos_libros;
    bool**aux_pedidosAtendidos;
    cout<<cap_lib<<endl;
    if(pedidosLibros==nullptr){
        pedidosLibros=new char**[cap_lib]{};
        pedidosAtendidos=new bool*[cap_lib]{};
        num_lib=1;
    }
    else{
       aux_pedidos_libros=new char**[cap_lib]{};
       aux_pedidosAtendidos=new bool*[cap_lib]{};
       for(int i=0;num_lib;i++){
           aux_pedidos_libros[i]=pedidosLibros[i];
           aux_pedidosAtendidos[i]=pedidosAtendidos[i];
       }
       delete pedidosLibros,pedidosAtendidos;
       pedidosLibros=aux_pedidos_libros;
       pedidosAtendidos=aux_pedidosAtendidos;
    }
}

void agregar_datos_dni(int*&pedidoCliente,int dni,int&num_2,int&cap_2,int ped,int pos){
    
    if(num_2==cap_2) incrementar_espacios_nivel_2(pedidoCliente,num_2,cap_2);
    
    if(pos==-1){
        pedidoCliente[0]=dni;
        pedidoCliente[1]=1;       
        pedidoCliente[2]=ped;
        num_2=3;
    }
    else{
        pedidoCliente[num_2-1]=ped;
        pedidoCliente[1]++;

        
    }
    num_2++;
        
    
    
}
void incrementar_espacios_nivel_2(int*&pedidoClientes,int&num,int&cap){
    int* aux_pedidosClientes;
    cap=cap+5;
    if(num==0){
        pedidoClientes=new int[cap]{};
        num=1;
        
    }
    else{
        aux_pedidosClientes=new int[cap]{};
        for(int i=0;i<num;i++){
            aux_pedidosClientes[i]=pedidoClientes[i];
            
        }
        delete pedidoClientes;
        pedidoClientes=aux_pedidosClientes;
    }
}
void incrementar_espacios(int**&pedidosClientes,int&num,int&cap){
    int** aux_pedidosClientes;
    cap=cap+5;
    if(num==0){
        pedidosClientes=new int*[cap]{};
        num=1;
        
    }
    else{
        aux_pedidosClientes=new int*[cap]{};
        for(int i=0;i<num;i++){
            aux_pedidosClientes[i]=pedidosClientes[i];
            
        }
        delete pedidosClientes;
        pedidosClientes=aux_pedidosClientes;
    }
}
int buscar_dni(int**pedidosClientes,int dni,int num){
    if(num==0) return -1;//caso de que no haya ningun dni registrado
    
    int*aux;
    
    for(int i=0;i<num-1;i++){
        aux=pedidosClientes[i];
        if(aux[0]==dni) return i;
    }
    return -1;
    
}
void ordenarPedidosClientes(int**&pedidosClientes){
    int i;
    
    for(i=0;pedidosClientes[i];i++ );
        
    
    qsort(pedidosClientes,0,i-1);
}
void qsort(int**&arr,int izq,int der){
    int pos,limite;
    int*aux,*aux2;
    if(izq>=der) return;
    pos=(izq+der)/2;
    cambiar(arr[izq],arr[pos]);
    limite=izq;
    for(int i=izq+1;i<=der;i++){
        aux=arr[i];
        aux2=arr[izq];
        if(aux[1]>aux2[1]){
            limite++;
            cambiar(arr[i],arr[limite]);
        }
    }
    cambiar(arr[izq],arr[limite]);
    qsort(arr,izq,limite-1);
    qsort(arr,limite+1,der);
}
void cambiar(int*&arr1,int*&arr2){
    int*aux=arr1;
    arr1=arr2;
    arr2=aux;
}
void reporteDeEntregaDePedidos(char*filename,int**pedidosClientes,char***pedidosLibros,bool**pedidosAtendidos){
    ofstream archEntregaPedidos;
    AperturaDeUnArchivoDeTextosParaEscribir(archEntregaPedidos,filename);
    int *aux;
    int pos;
    for(int i=0;pedidosClientes[i];i++){
        aux=pedidosClientes[i];
        archEntregaPedidos<<aux[0]<<" "<<aux[1]<<endl;
          for(int j=0;j<aux[1];j++){
              archEntregaPedidos<<aux[j+2]<<endl;
              char**auxlib=pedidosLibros[aux[j+2]];
             //archEntregaPedidos<<auxlib[0]<<endl;
//              for(int k=0;auxlib[k];k++){
//                  archEntregaPedidos<<auxlib[k]<<endl;
//              }
              
          }    
    }
}
