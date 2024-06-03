//Rodrigo Alessandro Vela Mayorga
//A00839934
//ITC
// 20/05/2024


#ifndef Episodio_h
#define Episodio_h

#include <stdio.h>
#include <string>
using namespace std;


class Episodio{
    protected:
        string titulo;
        int temporada;
        int calificacion;
    
    public:
    //Constructores
    Episodio();
    Episodio(string _titulo, int _temporada, int _calificacion);

    //Metodos modificacores - sirven para cambiar el valor del atrbuto . setters
    void setTitulo(string _titulo);
    void setTemporada(int _temporada);
    void setCalificacion(int _calificacion);
    
    //Metodos de acceso - retorna el valor del atributo - setters
    string getTitulo();
    int getTemporada();
    int getCalificacion();

    //Otros metodos
    string str();
};

#endif /* Episodio_h */