#include "Polimorfismo.h"
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

//Constructor defaul-vacio
Polimorfismo::Polimorfismo(){
    for (int index = 0; index < MAX_VIDEOS; index++){
        arrPtrVideos[index] = nullptr;
    }
    cantidad = 0;
}

//Setters - Metodos modificadores
void Polimorfismo::setPtrVideo(int index, Video *video){
    //Validad index que este entre 0 >= %%  < cantidad
    if (index >= 0 && index < cantidad){
        //Modificar el apuntador
        arrPtrVideos[index] = video;
    }
}

//cambia el valor de atributo cantidad al nuevo valor recibido cómo parámetro de entrada,
//validar que _cantidad este entre 0 .. MAX_VIDEOS -1 , de lo contrario NO se modifica el valor del atributo

void Polimorfismo::setCantidad(int _cantidad){
    //Primero validar el valor de _cantidad
    if (_cantidad >= 0 && _cantidad < MAX_VIDEOS){
        cantidad = _cantidad;
    }
}

//Getters _ Metodos de acceso
// validar que _index exista en el arreglo, si no existe se retorna nullptr.
Video* Polimorfismo::getPtrVideo(int index){
    //Validar que exista index
    if (index >= 0 && index < cantidad){
        return arrPtrVideos[index];
    }
    //si no existe un return 
    return nullptr;
}
int Polimorfismo::getCantidad(){
    return cantidad;
}

//Otros metodos
void Polimorfismo::reporteInventario(){
            //Declarion de contadores
        int cantidadPeliculas, cantidadSeries;
        //inicializar
        cantidadPeliculas = 0;
        cantidadSeries = 0;

    //recorrer todo el arreglo de prt usando un for
    for (int index = 0; index < cantidad; index++){
        cout << arrPtrVideos[index]->str() << endl;

        if (typeid(*arrPtrVideos[index]) == typeid(Pelicula)){
            cantidadPeliculas++;
        }
        else if (typeid(*arrPtrVideos[index]) == typeid(Serie)){
            cantidadSeries++;
        }
    }

    //Fuera del for desplegamos los totales 
    cout << "Peliculas = " << cantidadPeliculas << endl;
    cout << "Series = " << cantidadSeries << endl;
}
void Polimorfismo::reporteCalificacion(double _calificacion){
    //contador total
    int total;
    //inicializar el contador
    total = 0;

    for (int index = 0; index < cantidad; index++){
        //verificar si la calificacion == _calificacion
        //si es una apuntador se usa la notacion flecha
        if (arrPtrVideos[index]->getCalificacion() == _calificacion){
            cout << arrPtrVideos[index]->str() << endl;
            total++;
        }
    }
    //desplegar el total fuera del for 
    cout << "Total = " << total << endl;
}
void Polimorfismo::reporteGenero(string _genero){
    int total = 0;
    for (int index = 0; index < cantidad; index++){
        if (arrPtrVideos[index]->getGenero() == _genero){
            cout << arrPtrVideos[index]->str() << endl;
            total++;
        }
    }
    cout << "Total = " << total << endl; 
}
void Polimorfismo::reportePeliculas(){
    int total = 0;
    for (int index = 0; index < cantidad; index++){
        if (typeid(*arrPtrVideos[index]) == typeid(Pelicula)){
            cout << arrPtrVideos[index]->str() << endl;
            total++;
        }
    }
    cout << "Total Peliculas = " << total << endl;
}
void Polimorfismo::reporteSeries(){
    int total = 0;
    for (int index = 0; index < cantidad; index++){
        if (typeid(*arrPtrVideos[index]) == typeid(Serie)){
            cout << arrPtrVideos[index]->str() << endl;
            total++;
        }
    }
    if (total == 0){
        cout << "No series" << endl;
    }
}

void Polimorfismo::leerArchivo(string _nombre){
    Serie *arrPtrSeries[50];
    Pelicula *arrPtrPeliculas[50];
    Episodio episodio;
    fstream entrada;
    string row[7];
    string line, word;
    int cantidadPeliculas = 0;
    int cantidadSeries = 0;
    int cantidad = 0;
    int iR = 0, index;
    double promedio;

    entrada.open(_nombre, ios::in);

    while (getline(entrada, line)){
        stringstream s(line);
        iR = 0;
        while (getline(s ,word,',')){
            row[iR++] = word;
        }

        if (row[0] == "P"){
            arrPtrPeliculas[cantidadPeliculas] = new Pelicula(row[1], row[2], stoi(row[3]), row[4], stod(row[5]), stoi(row[6]));
            cantidadPeliculas++;
        }
        else if (row[0] == "S"){
            arrPtrSeries[cantidadSeries] = new Serie(row[1], row[2], stoi(row[3]), row[4], stod(row[5]));
            cantidadSeries++;
        }
        else if (row[0] == "E"){
            index = stoi(row[1]) - 500;
            arrPtrSeries[index]->agregaEpisodio(*(new Episodio(row[2], stoi(row[3]), stod(row[4]))));
        }
    }


//Fuera del ciclo
//Ya termino de leer todo el archivo y ahora se guarda todo en los apuntadores de Pelicula y Series
//en el "arrPtrVideo"
//Se copian todos los apuntadores del arreglo de Series al arreglo de apuntadores de video calculando
//su calificacionPromedio ya que tiene todos los episodios

     for (int index = 0; index < cantidadSeries; index++){
        promedio = arrPtrSeries[index]->calculaPromedio();
        arrPtrSeries[index]->setCalificacion(promedio);
        arrPtrVideos[cantidad++] = arrPtrSeries[index];
    }

    for(int index = 0; index < cantidadPeliculas; index++){
        arrPtrVideos[cantidad++] = arrPtrPeliculas[index];
    }

    setCantidad(cantidad);
}