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

int menu();

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    int opcion = 0; 
    
    while(opcion != 4){
        
        switch((opcion = menu())){
            
            case 1:{
                
                break;
            
            }case 2:{
                
                break;
            
            }case 3:{
                
                break;
            
            }case 4:{
                cout << "Ha salido del programa..." << endl << endl;
                break;
            }
        }
    }
    
    return 0;
}

int menu(){
    
    int opcion = 0;
    
    do{
        
        cout << "------MENU------" << endl
                << "1. Crear Relacion" << endl
                << "2. Ver relaciones" << endl
                << "3. Insertar Tupla" << endl
                << "4. Salir" << endl
                << "Elija una opcion: ";
        
        cin >> opcion; 
        cout << endl << endl;
        
    }while(opcion > 4 || opcion < 1);
    
    return opcion;
}