#include <iostream>
#include <fstream>
#include <iomanip>
#include "AperturaDeArchivos.h"
#include "Estructuras.h"
using namespace std;
bool  operator >> (ifstream& in,struct Cliente& cliente){
    char aux;
    in>>cliente.dni;
    if(in.eof()) return false;
    in>>aux;
    in.getline(cliente.nombre,50,',');
    in>>aux>>cliente.telefono;
    return true;
}
bool  operator >> (ifstream& in,struct Producto& producto){
    char aux;
    in.getline(producto.codigo,10,',');
    if(in.eof()) return false;
    in>>aux;
    in.getline(producto.descripcion,50,',');
    in>>aux>>producto.precio>>aux>>producto.stock;
    return true;
    
}
bool  operator >> (ifstream& in,struct Pedido& pedido){
    char aux;
    in.getline(pedido.CodigoProducto,10,',');
    if(in.eof()) return false;
    in>>aux>>pedido.dniCliente;
}