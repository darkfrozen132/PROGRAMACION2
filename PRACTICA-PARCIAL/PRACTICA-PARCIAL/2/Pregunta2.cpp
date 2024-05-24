#include <iostream>
#include <iomanip>
#include <cstring>
#include<fstream>

#include<cstdlib>
using namespace std;
#include "Pregunta2.h"
enum regProductos{CODIGO,DESCRIPCION,PRECIO,STOCK};
void cargarProductos(void*&pro,char*nombre_archivo){
    ifstream archProductos(nombre_archivo,ios::in);
    if(!archProductos.is_open()){
        cout<<"No se pudo abrir este archivo"<<endl;
        exit(1);
    }
    void**productos;
    int num=0,cap=0;
    
    void*reg;
    while(1){
        reg=leer_registro(archProductos);
        if(reg==nullptr) break;
        if(num==cap) incrementarEspacios(productos,num,cap);
        
        productos[num-1]=reg;
        num++;
    }
    
     pro=productos;
     cout<<pro<<endl;
   qsort(pro,num-2,sizeof(void*),compCodProducto);
  
    
}
int compCodProducto(const void*var1,const void*var2){
    
    void**reg1=(void**)var1;
    
    void**registro1=(void**)reg1[0];
    void**reg_producto1=(void**)registro1[0];
    
    
    
    void**reg2=(void**)var2;
    void**registro2=(void**)reg2[0];
    void**reg_producto2=(void**)registro2[0];
    
    char*au1,*au2;
    au1=(char*)reg_producto1[CODIGO];
    au2=(char*)reg_producto2[CODIGO];
    double *a1=new double;
    a1=(double*)reg_producto1[PRECIO];
   // cout<<*a1<<setw(10)<<au2<<endl;
        return strcmp(    au1 , au2     );
    
}
void incrementarEspacios(void**&pro,int&num,int&cap){
    void**auxpro;
    cap+=5;
    if(num==0){
        pro=new void*[cap];
        num=1;
    }
    else{
        auxpro=new void*[cap]{};
        
        for(int i=0;i<num;i++){
            auxpro[i]=pro[i];            
        }
        delete pro;
        pro=auxpro;
        
    }
}
void*leer_registro(ifstream&input){
    //enum regProductos{CODIGO,DESCRIPCION,PRECIO,STOCKFINAL};
    void**registros=new void*[2];
    void**registro=(void**)registros[0];
    
    registro=new void*[4];
    
    char*cod,*descrip;
    double*prec=new double;
    int*stockf=new int;
    
    cod=leer_cadena(input,',');
    if(input.eof())return nullptr;
    descrip=leer_cadena(input,',');
    input>>*prec;
    input.get();
    input>>*stockf;
    input.get();
    registro[CODIGO]=cod;
    registro[DESCRIPCION]=descrip;
    registro[PRECIO]=prec;
    registro[STOCK]=stockf;
    registros[0]=registro;
    registros[1]=nullptr;
    
    
    return registros;
    
    
}
char*leer_cadena(ifstream&input,char c){
    char *cad,buf[100];
    input.getline(buf,100,c);
    if(input.eof()) return nullptr;
    cad=new char[strlen(buf)+1];
    strcpy(cad,buf);   
    
    return cad;
}
void pruebaDeCargaDeProductos(void*productos){
    void**registros=(void**)productos;
    ofstream archReporteProductos("ReporteProductos.txt",ios::out);
    if(!archReporteProductos.is_open()){
        cout<<"No se pudo abrir el archivo"<<endl;
        exit(1);
    }
    //encabezado
    archReporteProductos<<left<<setw(10)<<"Codigo"<<setw(60)<<"Descripcion"
            <<setw(12)<<"Precio"<<setw(10)<<"Stock"<<endl;
    for(int i=0;registros[i];i++){
        
        
        void**registro=(void**)registros[i];
        void**reg=(void**)registro[0];
        archReporteProductos<<left<<setw(10)<<(char*)reg[CODIGO]<<setw(55)<<
                (char*)reg[DESCRIPCION];
        archReporteProductos<<right<<setw(10)<<*(double*)reg[PRECIO]<<
                setw(10)<<*(int*)reg[STOCK]<<endl;
    }
}
