/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ManejadorRelaciones.cpp
 * Author: dalva
 * 
 * Created on December 18, 2020, 1:21 PM
 */

#include "ManejadorRelaciones.h"

ManejadorRelaciones::ManejadorRelaciones() {
}

ManejadorRelaciones::ManejadorRelaciones(const ManejadorRelaciones& orig) {
}

ManejadorRelaciones::~ManejadorRelaciones() {
}

void ManejadorRelaciones::guardarRelaciones(vector<Relacion*> &listaRelaciones) {

    ofstream encabezados;

    encabezados.open("EncabezadosArchivos.txt", ofstream::out | ofstream::trunc);

    if (encabezados.is_open()) {
        encabezados << listaRelaciones.size() << endl;
    }
    
    //pasa por las relaciones guardando encabezados en un archivo separado
    // y guarda sus tuplas en un txt aparte
    for (int i = 0; i < listaRelaciones.size(); i++) {


        string arch = ".txt";

        Relacion* relacion = listaRelaciones[i];

        //guarda encabezados
        if (encabezados.is_open()) {

            encabezados << relacion->nombre << endl;

            for (int i = 0; i < relacion->encabezados.size(); i++) {

                encabezados << relacion->encabezados[i] << ",";
            }

            encabezados << endl;

        }

        //guarda las tuplas en un txt
        string nombre = "";
        nombre = relacion->nombre;
        nombre += arch;
        ofstream archivo;

        archivo.open(nombre, ofstream::out | ofstream::trunc);

        if (archivo.is_open()) {


            archivo << relacion->listaDatos.size() << endl;

            for (int i = 0; i < relacion->listaDatos.size(); i++) {

                Tupla* fila = relacion->listaDatos[i];

                vector<string> textos = fila->getDatos();

                archivo << fila->identificacion << endl;

                for (int j = 0; j < textos.size(); j++) {

                    archivo << textos[j] << ",";
                }

                archivo << endl;

            }


            archivo.close();

        }



    }

    encabezados.close();
}

vector<Relacion*> ManejadorRelaciones::leerArchivos() {

    vector<Relacion*> listaDeRelaciones;

    ifstream encabezados;
    encabezados.open("EncabezadosArchivos.txt");

    if (encabezados.is_open()) {

        int size = 0;
        encabezados >> size;
        
        //recorre un ciclo for con la cantidad contada de Relaciones
        for (int k = 0; k < size; k++) {

            string nombreArch = "";
            string headers = "";

            encabezados >> nombreArch;

            encabezados >> headers;

            vector<string> listaHeaders;
            string buffer = "";

            //recorre el string para guardar los encabezados en el vector
            for (int i = 0; i < headers.length(); i++) {

                if (headers[i] == ',') {

                    listaHeaders.push_back(buffer);
                    buffer.clear();

                } else if (i == headers.length() - 1) {

                    listaHeaders.push_back(buffer);
                    buffer.clear();

                } else {
                    buffer += headers[i];
                }
            }

            //lectura del archivo que contiene los datos
            Relacion* rel = new Relacion(nombreArch);
            rel->setHeaders(listaHeaders);
            nombreArch += ".txt";
            ifstream relacion;
            relacion.open(nombreArch);

            if (relacion.is_open()) {

                int size = 0;

                relacion >> size;

                for (int k = 0; k < size; k++) {

                    Tupla* temporal = new Tupla();

                    int id = 0;

                    relacion >> id;
                    temporal->setIdentificacion(id);

                    string buffer = "";
                    string dato = "";

                    relacion >> buffer;
                    
                    //ciclo for que divide los datos y los almacena en el vector
                    for (int i = 0; i < buffer.size(); i++) {

                        if (buffer[i] == ',') {

                            temporal->addDato(dato);
                            dato.clear();

                        } else if (i == buffer.length() - 1) {

                            temporal->addDato(dato);
                            dato.clear();

                        } else {
                            dato += buffer[i];
                        }
                    }

                    rel->listaDatos.push_back(temporal);
                }

                listaDeRelaciones.push_back(rel);

            }
        }
    }

    return listaDeRelaciones;
}