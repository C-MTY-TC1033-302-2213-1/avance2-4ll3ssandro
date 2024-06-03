//Rodrigo Alessandro Vela Mayorga
//A00839934
//ITC
// 20/05/2024
//Esta actividad fue de ayuda para comprender el como se utiliza la herencia
//ademas de poder poner en practica esto, ya que me es mas facil aprenderlo
//al practicar, a diferencia de si me lo explican con pura teoria

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