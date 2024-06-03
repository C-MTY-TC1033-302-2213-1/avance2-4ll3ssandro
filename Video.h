//Rodrigo Alessandro Vela Mayorga
//A00839934
//ITC
// 20/05/2024
//Esta actividad me ayudo a recordar lo aprendido en relacion a POO 
//del semestre pasado

#ifndef Video_h
#define Video_h

#include <stdio.h>
#include <string>
using namespace std;
class Video{
    protected:
    string iD;
    string titulo;
    int duracion;
    string genero;
    double calificacion;

    public:
    Video();
    Video(string _iD, string _titulo, int _duracion, string _genero, double _calificacion);

    //Metodo modificadores
    void setiD(string _iD);
    void setTitulo(string _titulo);
    void setDuracion(int _duracion);
    void setGenero(string _genero);
    void setCalificacion(double _calificacion);

    //Metodos de acceso
    string getiD();
    string getTitulo();
    int getDuracion();
    string getGenero();
    double getCalificacion();

    //Otros metodos
    virtual string str();
};

#endif /* Video_h */