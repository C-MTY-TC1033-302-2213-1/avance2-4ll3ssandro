//Rodrigo Alessandro Vela Mayorga
//A00839934
//ITC
// 26/05/2024

#ifndef Polimorfismo_h
#define Polimorfismo_h
#include <typeinfo>
#include <iostream>
#include <sstream>
#include <fstream>
#include "Pelicula.h"
#include "Serie.h"
#include "Episodio.h"

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