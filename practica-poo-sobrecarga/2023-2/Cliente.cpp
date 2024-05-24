#include "Cliente.h"



 Cliente::Cliente(){
     
 }
 
int Cliente::getDni(){
    return dni;
}
void Cliente::setDni(int dni){
    this->dni=dni;
}        
void Cliente::getNombre(char*nom){
    if(nombre==nullptr) nom[0]=0;
        strcpy(nombre,nom);
}
void Cliente::setNombre(char*nom){
    if(nombre!=nullptr) delete nombre;
    nombre=new char[strlen(nom)+1];
    strcpy(nom,nombre);
}
        
        int getTelefono();
        void setTelefono(int tele);
        
        int getCantidad_productos_entregados();
        void setCantidad_productos_entregados(int cant_prod_entre);
        
        double getMonto_total();
        void setMonto_total(double monto);
        
        bool operator>>(ifstream&arch,class Cliente&clien);