/*
Añade por favor en cada clase este comentario con toda tu información 
Nombre: Rodrigo Alessandro Vela Mayorga
Matricula: A00839934
Carrera: ITC
Fecha: 02/06/2024
Reflexión: En esta activida aprendi a poder utilizar el polimorfismo a traves de un ejemplo practico
viendo el resultado que tiene al utilizarlo en el metodo str.
*/

#ifndef Polimorfismo_h
#define Polimorfismo_h
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include "Video.h"
#include "Serie.h"
#include "Episodio.h"
#include "Pelicula.h"

const int MAX_VIDEOS = 100;
class Polimorfismo : public Video{
    private:
    Video* arrPtrVideos[MAX_VIDEOS];
    int cantidad;
    
    public:
    //Constructor default - vacio
    Polimorfismo();
    void leerArchivo(string _nombre);

    //Setters - Metodos modificadores
    void setPtrVideo(int index, Video *video);
    void setCantidad(int _cantidad);

    //Getters _ Metodos de acceso
    Video *getPtrVideo(int index);
    int getCantidad();

    //Otros metodos
    void reporteInventario();
    void reporteCalificacion(double _calificacion);
    void reporteGenero(string _genero);
    void reportePeliculas();
    void reporteSeries();

};

#endif /* Polimorfismo_h */