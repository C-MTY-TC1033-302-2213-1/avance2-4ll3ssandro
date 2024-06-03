//Rodrigo Alessandro Vela Mayorga
//A00839934
//ITC
// 20/05/2024

#include "Serie.h"
using namespace std;


Serie::Serie(string _iD, string _titulo, int _duracion, string _genero, double _calificacion):Video(_iD, _titulo, _duracion, _genero, _calificacion) {
    cantidad = 0;
}

//Metodos mofificadores
void Serie::setEpisodio(int posicion, Episodio episodio){
    //primero validar que exista ese episodio
    if (posicion >= 0  && posicion < cantidad){
        episodios[posicion] = episodio;
    }
}

//Cambiar el valor del atributo con el valor recibido con cantidad 
void Serie::setCantidad(int _cantidad){
    cantidad = _cantidad;
}

//Metodos de acceso
Episodio Serie::getEpisodio(int posicion){
    //Crea un objeto del tipo episodio y lo inicializa con el constructor default
    Episodio epi;
    //Validar que exista el episodio solicitado (posicion)
    if (posicion >= 0 && posicion < cantidad){
        return episodios[posicion];
    }
    //Si no existe se retorna un Episodio default
    return epi;
}

//Retorna el valor de un atributo en cantidad
int Serie::getCantidad(){
    return cantidad;
}

//Otros metodos
double Serie::calculaPromedio(){
    double acum = 0;

    for (int index = 0; index < cantidad; index++){
        acum = acum + episodios[index].getCalificacion();
    }

    if (cantidad > 0 ){
        return acum / cantidad;
    }
    else{
        return 0;
    }

}

//Overriding del metodo str() de la clase base
string Serie::str(){
    string resultado = Video::str() + ' ' + to_string(cantidad) + '\n';
    if (cantidad > 0){
        for (int index = 0; index < cantidad; index ++){
            resultado += episodios[index].Episodio::str() + '\n';
        }
    }
    return resultado;
}

//agrega un episodio solo si existe espacio
void Serie::agregaEpisodio(Episodio episodio){
    if(cantidad < 5){
        episodios[cantidad++] = episodio;
    }
}

void Serie::calculaDuracion(){
    int Temporada;

    Temporada = 0;
    for(int index = 0; index < cantidad; index++){
        Temporada += episodios[index].getTemporada();
    }
    duracion = Temporada;
}