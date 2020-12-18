/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   P3Examen2_DanielAlvarado.cpp
 * Author: dalva
 *
 * Created on December 18, 2020, 12:56 PM
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include "Tupla.h"
#include "Relacion.h"
#include "ManejadorRelaciones.h"

int menu();
void printRelacion(Relacion*&);
void freeVector(vector<Relacion*>&);

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    vector<Relacion*> listaRelaciones;
    ManejadorRelaciones manager;
    listaRelaciones = manager.leerArchivos();

    int opcion = 0;

    while (opcion != 4) {

        switch ((opcion = menu())) {

            case 1:
            {
                cout << "Crear Relacion" << endl << endl;

                string nombre = "";
                vector<string> encabezados;

                cout << "Ingrese el nombre de la relacion a crear: ";
                cin >> nombre;
                cout << endl << endl;

                int flag = 1;

                while (flag == 1) {

                    string encabezado = "";

                    cout << "Escriba el encabezado: ";
                    cin >> encabezado;
                    cout << endl << endl;

                    encabezados.push_back(encabezado);

                    cout << "Desea ingresar mas encabezados [1 = si| 2 = no]: ";
                    cin >> flag;
                    cout << endl << endl;

                    while (flag < 1 || flag > 2) {
                        cout << "Desea ingresar mas encabezados [1 = si| 2 = no]: ";
                        cin >> flag;
                        cout << endl << endl;
                    }
                }
                
                Relacion* datos = new Relacion(nombre);
                datos->setHeaders(encabezados);
                
                //el manejador lee todos los archivos agrega 
                listaRelaciones.clear();
                listaRelaciones = manager.leerArchivos();
                listaRelaciones.push_back(datos);
                manager.guardarRelaciones(listaRelaciones);   
                
                cout << "La Relacion se ha creado con exito" << endl << endl;

                break;

            }
            case 2:
            {
                cout << "Ver relaciones" << endl << endl;
                
                listaRelaciones = manager.leerArchivos();
                
                if(listaRelaciones.empty()){
                    cout << "La lista de relaciones esta vacia!" << endl << endl;
                
                }else{
                    
                    cout << "Esta es la lista: " << endl;
                    for(int i = 0; i < listaRelaciones.size(); i++){
                        cout << i+1 << " " <<listaRelaciones[i]->getNombre()
                                << endl;
                    }
                    
                    cout << endl << endl;
                    
                    int index = -1;
                    
                    cout << "Ingrese el indice de la relacion a mostrar: ";
                    cin >> index;
                    cout << endl << endl;
                    
                    while(index < 0){
                        cout << "Ingrese un indice mayor a 0: ";
                        cin >> index; 
                        cout << endl << endl;
                    }
                    
                    
                    printRelacion(listaRelaciones[index-1]);
                    
                    
                }
                
                break;

            }
            case 3:
            {

                break;

            }
            case 4:
            {
                //freeVector(listaRelaciones);
                cout << "Ha salido del programa..." << endl << endl;
                break;
            }
        }
    }

    return 0;
}

int menu() {

    int opcion = 0;

    do {

        cout << "------MENU------" << endl
                << "1. Crear Relacion" << endl
                << "2. Ver relaciones" << endl
                << "3. Insertar Tupla" << endl
                << "4. Salir" << endl
                << "Elija una opcion: ";

        cin >> opcion;
        cout << endl << endl;

    } while (opcion > 4 || opcion < 1);

    return opcion;
}

//imprime en consola la informacion de una relacion
void printRelacion(Relacion* &relacion){
    
    cout << "Estado de la Relacion: " << relacion->getNombre() << endl;
    
    //imprime los headers
    for(int i = 0; i < relacion->getHeaders().size(); i++){
        
        if(i==0){
            cout << "ID " << "  \t" << relacion->getHeaders().at(i) << "  \t";
           
        }else{
            cout << relacion->getHeaders().at(i) << "  \t"; 
        }
    }
    
    cout << endl;
    
    
    //imprime todas las tuplas
    for(int i = 0; i < relacion->getDatos().size(); i++){
        
        Tupla* temporal = relacion->getDatos().at(i);
        
        cout << temporal->getId() << "  \t";
        
        for(int j = 0; j < temporal->getDatos().size(); i++){
            
            cout << temporal->getDatos().at(j) << "  \t";
        }
        
        cout << endl;
    }
    
    
}

void freeVector(vector<Relacion*> &listaRelaciones){
    
    if(!listaRelaciones.empty()){
        
        for(int i = 0; listaRelaciones.size(); i++){
            
            if(listaRelaciones[i] != NULL){
                delete listaRelaciones[i];
            }
        }
        
        
        listaRelaciones.clear();
    }
}