/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   ProductoEntregado.h
 * Author: Leoncio
 *
 * Created on 20 de mayo de 2024, 11:27 AM
 */

#ifndef PRODUCTOENTREGADO_H
#define PRODUCTOENTREGADO_H

class ProductoEntregado{
    private:
        char*codigo;
        double precio;
    public:
        ProductoEntregado();
        char* getCodigo();        
        void setCodigo(char*);
        
        double getPrecio();
        void setPrecio(double);
        
        
      
    
    
};

#endif /* PRODUCTOENTREGADO_H */

