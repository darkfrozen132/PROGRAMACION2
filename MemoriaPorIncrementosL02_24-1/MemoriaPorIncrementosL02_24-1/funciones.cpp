/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "funciones.hpp"

void lecturaDeLibros(const char* nombre, char***& libros, int**& stock) {

    int cant = 0, capacidad = 0;
    char** datosLibro;
    int* infStock;
    libros = nullptr;
    stock = nullptr;
    double d;

    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, nombre);

    while (1) {
        arch >> ws;
        if (arch.eof()) break;
        datosLibro = leerStrings(arch);
        infStock = leerInt(arch);
        arch >> d;
        if (cant == capacidad)incrementoMemoria(libros, stock, capacidad, cant);
        libros[cant - 1] = datosLibro;
        stock[cant - 1] = infStock;
        cant++;
    }
}

char** leerStrings(ifstream& arch) {

    char codigo[60]{};
    char nombre[150]{};
    char autor[100]{};
    arch.getline(codigo, 60, ',');
    arch.getline(nombre, 150, ',');
    arch.getline(autor, 100, ',');
    char** resultado = new char*[3];
    resultado[0] = new char[strlen(codigo) + 1] {
    };
    resultado[1] = new char[strlen(nombre) + 1] {
    };
    resultado[2] = new char[strlen(autor) + 1] {
    };
    strcpy(resultado[0], codigo);
    strcpy(resultado[1], nombre);
    strcpy(resultado[2], autor);

    return resultado;
}

int* leerInt(ifstream& arch) {
    int* resultado = new int[2] {
    };
    arch >> resultado[0];
    arch.get();
    return resultado;
}

void incrementoMemoria(char***& libros, int**& stock, int& capacidad, int& cant) {

    capacidad += AUMENTO;

    if (libros == nullptr) {

        libros = new char**[capacidad] {
        };
        stock = new int*[capacidad] {
        };
        cant = 1;

    } else {

        char*** auxLibros = new char**[capacidad] {
        };
        int** auxStock = new int*[capacidad] {
        };

        for (int n = 0; libros[n]; n++) auxLibros[n] = libros[n];
        for (int n = 0; stock[n]; n++) auxStock[n] = stock[n];

        delete libros;
        delete stock;

        libros = auxLibros;
        stock = auxStock;

    }

}

void pruebaDeLecturaDeLibros(const char* nombre, char*** libros, int** stock) {

    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch, nombre);

    for (int n = 0; libros[n]; n++) {
        char** auxLib = libros[n];
        int* auxSt = stock[n];
        arch << left << setw(10) << auxLib[0] << setw(80) << auxLib[1] << setw(30) << auxLib[2] << setw(5) << auxSt[0] << setw(5) << auxSt[1] << endl;
    }

}

void atencionDePedidos(const char* nombre, char*** libros, int** stock, int**& pedidosClientes, char***& pedidosLibros, bool**& pedidosAtendidos) {

    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch, nombre);

    int capClientes = 0, cantClientes = 0;
    int cantOrden = 0, maxOrden = 0;

    pedidosClientes = nullptr;
    pedidosLibros = nullptr;
    pedidosAtendidos = nullptr;

    //000059,34460612   CRY6839    VYG3594
    while (1) {
        arch >> ws;
        if (arch.eof()) break;
        int orden, dni;
        arch >> orden;
        arch.get();
        arch >> dni;
        agregaDatos(orden, dni, pedidosClientes, cantClientes, capClientes);
        while (1) {
            char codigo[20]{}, c;
            arch >> codigo;
            c = arch.get();
            agregaPedido(orden, codigo, pedidosLibros, pedidosAtendidos, libros, stock, cantOrden, maxOrden);
            if (c == '\n' || c == '\r') break;
        }

    }
   

}

void agregaDatos(int orden, int dni, int**& pedidosClientes, int& cantClientes, int& capClientes) {
   
    bool nuevo;
    int n = buscaIndice(pedidosClientes, dni, nuevo);
    if (nuevo) {

        if (cantClientes == capClientes)reservaMemoria(pedidosClientes, cantClientes, capClientes);

        int* registro = new int[3] {};
        registro[0] = dni;
        registro[1] = 1;
        registro[2] = orden;

        pedidosClientes[n] = registro;
        cantClientes++;
    } else {
        int* aux = pedidosClientes[n];
        int longitud = aux[1] + 2;
        aux[1]++;
        int* registro = new int[longitud + 1];
        for (int j = 0; j < longitud; j++) {
            registro[j] = aux[j];
        }
        delete pedidosClientes[n];
        registro[longitud] = orden;
        pedidosClientes[n] = registro;
        

    }


}

void reservaMemoria(int**& pedidosClientes, int& cantClientes, int& capClientes) {

    capClientes += AUMENTO;

    if (pedidosClientes == nullptr) {
        pedidosClientes = new int*[capClientes] {};
        cantClientes = 1;
    } else {
        int** auxPedidos = new int*[capClientes] {};
        for (int n = 0; pedidosClientes[n]; n++) auxPedidos[n] = pedidosClientes[n];
        delete pedidosClientes;
        pedidosClientes = auxPedidos;
        
    }

}

int buscaIndice(int** pedidosClientes, int dni, bool& nuevo) {

    int n=0;
    nuevo = true;
    if(pedidosClientes == nullptr) return 0;
    for (n = 0; pedidosClientes[n]; n++) {
        int* aux = pedidosClientes[n];
        if (aux[0] == dni) {
            nuevo = false;
            return n;
        }
    }
    
    return n;

}

void agregaPedido(int orden, char codigo[20], char***& pedidosLibros, bool**& pedidosAtendidos, char*** libros, int** stock, int& cantOrden, int& maxOrden) {

    int indiceLibro = buscaIndice(libros, codigo);
    int* auxSt = stock[indiceLibro];
    
    if(orden > maxOrden){
        reserveMemoria(pedidosLibros, pedidosAtendidos, orden,maxOrden);
        maxOrden = orden;
    }

    if (pedidosLibros[orden-1] == nullptr) {
        pedidosLibros[orden-1] = new char*[2] {};
        char** auxLib = pedidosLibros[orden-1];
        auxLib[0] = new char[9]{};
        char* auxCodigo = auxLib[0];
        for(int n = 0; codigo[n]; n++) auxCodigo[n] = codigo[n];
        //auxLib[0] = codigo;
        pedidosAtendidos[orden-1] = new bool [2] {};
        bool* auxAt = pedidosAtendidos[orden-1];
        if (auxSt[0] > 0) {
            auxAt[0] = true;
            auxSt[0]--;
        } else {
            auxAt[0] = false;
            auxSt[1]++;
        }
    } else {
        int indice;
        reservaMemoria2(orden-1,pedidosLibros,pedidosAtendidos,indice);
        char** auxLib = pedidosLibros[orden-1];
        bool* auxAt = pedidosAtendidos[orden-1];
        auxLib[indice] = new char[9]{};
        char* auxCodigo = auxLib[indice];
        for(int n = 0; codigo[n]; n++) auxCodigo[n] = codigo[n];
        //strcpy(auxLib[indice],codigo);
        if(auxSt[0] > 0){
            auxAt[indice] = true;
            auxSt[0]--;
        }else{
            auxAt[indice] = false;
            auxSt[1]++;
        }

    }

}

int buscaIndice(char*** libros, char codigo[20]) {

    for (int n = 0; libros[n]; n++) {
        char** aux = libros[n];
        if (strcmp(aux[0], codigo) == 0) return n;
    }

}

void reserveMemoria(char***& pedidosLibros, bool**& pedidosAtendidos, int orden,int maxOrden) {

    if (pedidosAtendidos == nullptr) {
        pedidosAtendidos = new bool*[orden + 1] {}; //+1 por el termino de parada
        pedidosLibros = new char**[orden + 1] {}; // el termino de parada sera *pedidosLibros[n]
    } else {
        char*** auxLibros = new char**[orden + 1] {};
        bool** auxAtendidos = new bool*[orden + 1] {};

        for (int n = 0; n < maxOrden+1; n++) auxLibros[n] = pedidosLibros[n];
        for (int n = 0; n < maxOrden+1; n++) auxAtendidos[n] = pedidosAtendidos[n];

        delete pedidosLibros;
        delete pedidosAtendidos;

        pedidosLibros = auxLibros;
        pedidosAtendidos = auxAtendidos;
    }

}

void reservaMemoria2(int orden, char***& pedidosLibros, bool**& pedidosAtendidos,int& n) {
    char** auxLib = pedidosLibros[orden];
    bool* auxSt = pedidosAtendidos[orden];
    for (n = 0; auxLib[n]; n++);
    char** auxLib2 = new char*[n + 2] {};
    bool* auxAt2 = new bool[n + 2] {};
    for (int m = 0; auxLib[m]; m++){
        auxLib2[m] = auxLib[m];
    }
    for (int m = 0; auxLib[m]; m++) auxAt2[m] = auxSt[m];
    delete pedidosLibros[orden];
    delete pedidosAtendidos[orden];
    pedidosLibros[orden] = auxLib2;
    pedidosAtendidos[orden] = auxAt2;
}

void reporteDeEntregaDePedidos(const char* nombre,int** pedidosClientes,char*** pedidosLibros,bool** pedidosAtendidos){
    
    ofstream arch;
    AperturaDeUnArchivoDeTextosParaEscribir(arch,nombre);
    
    arch << setw(60) << "REPORTE DE ATENCION DE PEDIDOS" << endl;
    int n = 0;
    int* auxCli = pedidosClientes[n];
    //for(n = 0; auxCli[0]!=0;n++){
    while(1){
        if(!pedidosClientes[n]) break;
        auxCli = pedidosClientes[n];
        if(auxCli[0]==0) break;
        linea(arch,'=');
        arch << "CLIENTE:" << setw(11) << auxCli[0] << endl;
        linea(arch,'=');
        
        for(int m = 0; m < auxCli[1];m++){
            arch << setw(12) << " " << setw(30) << "Pedidos No." << setw(30) << "Codigos del libro" << setw(30) << "Observacion" << endl;
            linea(arch,'-');
            char** auxLib = pedidosLibros[auxCli[m+2]-1];
            bool* auxAt = pedidosAtendidos[auxCli[m+2]-1];
            arch << setw(31) << " " << setw(6) << setfill('0') << auxCli[m+2] << setfill(' ');
            for(int j = 0; !(auxLib[j]==nullptr);j++){
                if(j != 0 ) arch << setw(37) << " ";
                arch << setw(20) << auxLib[j];
                if(auxAt[j]) arch << setw(40) << "ATENDIDO" << endl;
                else arch << setw(40) << "NO ATENDIDO" << endl;
            }
            linea(arch,'-');
        }
        n++;
    }
    
}

void linea(ofstream& arch,char c){
    for(int n = 0; n < 150;n++){
        arch << c;
    }
    arch << endl;
}