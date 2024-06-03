//Rodrigo Alessandro Vela Mayorga
//A00839934
//ITC
// 20/05/2024
//En esta actividad me ayudo a conocer la funcion de la herencia al ponerla en practica para resolver el
//ejercicio, dando como resultado un codigo mas limpio debido a su utilizacion

#ifndef Pelicula_h
#define Pelicula_h


#include <iostream>
#include "Video.h"
#include <stdio.h>
#include <string>
using namespace std;

//Clase pelicula es derivada calse video
class Pelicula: public Video{
    private:
    int oscares;

    public:
    Pelicula ();
    Pelicula (string _iD, string _titulo, int duracion, string _genero, double _calificacion, int _oscares);

    //Metodos modificadores -setters
    void setOscares(int _oscares);
    
    //Metodos de acceso - getters
    int getOscares();
    
    //Otros metodos
    string str();
};

#endif /* Pelicula_h */