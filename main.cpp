//
//  main.cpp
//  Avance2 31/05/24
//
//  Created by Ma. Guadalupe Roque Díaz de León on 31/05/24.
//

// Clases Base - Video - con método virtual str() para Poliformismo
// Clases Derivadas - Pelicula, Serie
// Clase usada para composición - Episodio
// Clase Polimorfismo -  para aplicar el polimorfismo con el método virtual y las clases derivadas
// Arreglo de apuntadores


/*
Añade por favor en cada clase este comentario con toda tu información 
Nombre: Rodrigo Alessandro Vela Mayorga
Matricula: A00839934
Carrera: ITC
Fecha: 02/06/2024
Reflexión: 
- ¿Qué aprendí en el desarrollo de esta clase?
*/

#include <iostream>
#include "Video.h"
#include "Episodio.h"
#include "Pelicula.h"
#include "Serie.h"
#include "Polimorfismo.h"
#include "Inventario1.csv"
#include "Inventario2.csv"

#include <string>
using namespace std;

void polimorfismo(Polimorfismo inventario){
  // Declaración de variables locales
 int opcion, oscares, cantidadEpisodios;
 double calificacion;
 string genero;

 cin >> opcion;

 switch (opcion) {
     case 1:
         cin >> calificacion;
         inventario.reporteCalificacion(calificacion);
         break;

     case 2:
         cin >> genero;
         inventario.reporteGenero(genero);
         break;

     case 3:
         inventario.reporteInventario();
         break;

     case 4:
         inventario.reportePeliculas();
         break;

     case 5:
         inventario.reporteSeries();
         break;

    default:
         cout << "Error\n";
         break;
    }
}

int main() {
    // Declaracion de objetos
    Polimorfismo netflix;
    int opcion;

    // leer la opcion
    cin >> opcion;

    switch (opcion){
        case 1:
           netflix.leerArchivo("Inventario1.csv");
           polimorfismo(netflix);
           break;

        case 2:
          netflix.leerArchivo("Inventario2.csv");
          polimorfismo(netflix);
          break;

    default:
          cout << "incorrecta" ;
    }

    return 0;
}