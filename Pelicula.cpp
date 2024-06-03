//Rodrigo Alessandro Vela Mayorga
//A00839934
//ITC
// 20/05/2024
//En esta actividad me ayudo a conocer la funcion de la herencia al ponerla en practica para resolver el
//ejercicio, dando como resultado un codigo mas limpio debido a su utilizacion

#include "Pelicula.h"

Pelicula::Pelicula():Video(){
    oscares = 100;
}
Pelicula::Pelicula (string _iD, string _titulo, int _duracion, string _genero, double _calificacion, 
int _oscares):Video(_iD, _titulo, _duracion, _genero, _calificacion){
    oscares = _oscares;
}

//Metodos modificadores -setters
void Pelicula::setOscares(int _oscares){
    oscares = _oscares;
}
    
//Metodos de acceso - getters
int Pelicula::getOscares(){
    return oscares;
}

//Otros metodos
string Pelicula::str(){
    //Tenemos acceso directo a los atribustos de la clase padre porque son protected
    return iD + ' ' + titulo + ' ' + to_string(duracion) + ' ' +
    genero + ' ' + to_string(calificacion) + ' ' + to_string(oscares);
}