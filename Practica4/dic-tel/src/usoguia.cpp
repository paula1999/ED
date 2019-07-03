/**
 * @file usoguia.cpp
 * @author Paula Villanueva Nuñez
*/

#include "guiatlf.h"
#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char * argv[]){
  Guia_Tlf g, otraguia, un, dif, inter, caract;
  string n, tlf, telef, nombre, respuesta;
  char caracter;

  if (argc != 3){
    cout << "Argumentos inválidos\n";
    return -1;
  }

  ifstream f(argv[1]);

  if (!f){
     cout << "Error al abrir el archivo " << argv[1] << endl;
     return -1;
  }

  cout << "Introduce una guia" << endl;
  f >> g;
  cout << "La guia insertada:\n" << g << endl;
  cin.clear();


  // Cambiar número de teléfono
  cout << "¿Quieres cambiar algún número de teléfono? (s/n)\n";
  cin >> respuesta;

  if (respuesta == "s"){
    cout << "Dime el nombre de quien quieres cambiar su teléfono:\n";
    cin.ignore(); // Para esperar a que se introduzca el nombre
    getline(cin,nombre);
    cin.clear();
    cout << "Dime el nuevo telefono: \n";
    cin >> telef;

    if (g.cambiar_num(nombre, telef))
      cout << "Se ha cambiado con éxito, la nueva guía es: \n" << g << endl;
    else{
      cout << "No se ha podido cambiar\n";
    }
  }

  // Mostrar los nombres y sus teléfonos que empiecen por un caracter dado
  cout << "Introduce un caracter para mostrar todas las personas cuyo nombre empieza por dicho caracter:\n";
  cin >> caracter;

  caract = g.buscar_caracter(caracter);

  cout << "La guía que contienen los nombres que empiezan por " << caracter << " es: \n" << caract << endl;

  // Obtener el número de teléfono
  cout << "Dime un nombre sobre el que quieres obtener el telefono" << endl;
  cin.ignore();

  while (getline(cin,n)){
	   cout << "\nBuscando " << n << "...." << endl;

     tlf = g.gettelefono(n);

     if (tlf == "")
		     cout << "No existe ese nombre en la guia" << endl;
	   else
	       cout << "El telefono es " << tlf << endl;

     cout << "Pulse Ctrl+D si no quieres obtener ningún teléfono más\n";
     cout << "Dime un nombre sobre el que quieres obtener el telefono" << endl;
   }

   // Borrar nombre
   cin.clear();
   cout << "Dime el nombre que quieres borrar" << endl;

   while (getline(cin,n)){
	   g.borrar(n);

     cout << "\nAhora la guia es:" << endl;
	   cout << g << endl;
     cout << "Pulse Ctrl+D si no quieres borrar ninguno más\n";
	   cout << "Dime el nombre que quieres borrar" << endl;
   }

   cin.clear();

   // Introducimos la segunda guía
   ifstream h(argv[2]);

   cout << "\nIntroduciendo la segunda guía..." << endl;
   h >> otraguia;
   cin.clear();

   // Unión de las dos guías
   un = g+otraguia;

   cout << "\nLa union de las dos guías: " << endl << un << endl;

   // Diferencia de las dos guías
   dif = g-otraguia;

   cout << "\nLa diferencia de las dos guías:" << endl << dif << endl;

   // Intersección de las dos guías
   inter = g.interseccion(otraguia);
   cout << "\n\nLa intersección de las dos guías:\n\n" << inter << endl;
}
