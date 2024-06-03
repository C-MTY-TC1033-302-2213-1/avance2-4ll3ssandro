//Rodrigo Alessandro Vela Mayorga
//A00839934
//ITC
// 20/05/2024
//Esta actividad fue de ayuda para comprender el como se utiliza la herencia
//ademas de poder poner en practica esto, ya que me es mas facil aprenderlo
//al practicar, a diferencia de si me lo explican con pura teoria.

#ifndef Serie_h
#define Serie_h
//Para herencia
#include "Video.h"
//Para composicion
#include "Episodio.h"
#include <iostream>
using namespace std;

class Serie : public Video{
    private:
    Episodio episodios[5];
    int cantidad;

    public:
    //Metodo constructor
    Serie();
    Serie(string _iD, string _titulo, int _duracion, string _genero, double _calificacion);
    

    //Metodos mofificadores
    void calculaDuracion();
    void setEpisodio(int posicion, Episodio episodio);

    void setCantidad(int _cantidad);

    //Metodos de acceso
    Episodio getEpisodio(int posicion);
    int getCantidad();

    //Otros metodos
    double calculaPromedio();
    string str();
    void agregaEpisodio(Episodio episodio);
};

#endif /* Serie_h */