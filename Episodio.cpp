//Rodrigo Alessandro Vela Mayorga
//A00839934
//ITC
// 20/05/2024
//Esta actividad me ayudo a recordar lo aprendido en relacion a POO 
//del semestre pasado

#include "Episodio.h"
using namespace std;


Episodio::Episodio(){
    titulo = "Zoro vs King";
    temporada = 11;
    calificacion = 10;
}
Episodio::Episodio(string _titulo, int _temporada, int _calificacion){
    titulo = _titulo;
    temporada = _temporada;
    calificacion = _calificacion;
}

//Metodos modificacores - sirven para cambiar el valor del atrbuto . setters
void Episodio::setTitulo(string _titulo){
    titulo = _titulo;
}
void Episodio::setTemporada(int _temporada){
    temporada = _temporada;
}
void Episodio::setCalificacion(int _calificacion){
    calificacion = _calificacion;
}

//Metodos de acceso - retorna el valor del atributo - setters
string Episodio::getTitulo(){
    return titulo;
}
int Episodio::getTemporada(){
    return temporada;
}
int Episodio::getCalificacion(){
    return calificacion;
}

//Otros metodos
string Episodio::str(){
    return titulo + ' ' + to_string(temporada) + ' ' + to_string(calificacion);
}