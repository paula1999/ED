/**
 * @file usodiccionario.cpp
 * @author Paula Villanueva Nuñez
*/

#include <iostream>
#include <fstream>
#include "diccionario.h"
using namespace std;

/*Recorre la lista de información asociada a una clave y la imprime*/
void EscribeSigni (const list<string>&l){
	  list<string>::const_iterator it_s;

	  for (it_s=l.begin(); it_s!=l.end(); ++it_s){
		    cout << *it_s << endl;
	  }
}

/*Lee un diccioario e imprime datos asociados a una clave.
Hay un fichero ejemplo de prueba: data.txt.Para lanzar el programa con ese fichero se escribe:
                  ./usodiccionario < data.txt
*/
int main(int argc, char * argv[]){
	Diccionario<string,string> D, D_letra, Dmax;
	string a, palabra, letra;
	list<string> l;

	if (argc != 2){
		cout << "Argumentos inválidos\n";
		cout << "Introduce: ./bin/usodiccionario datos/data.txt\n";
		return -1;
	}

	ifstream f(argv[1]);

	if (!f){
     cout << "Error al abrir el archivo " << argv[1] << endl;
     return -1;
  }

	cout << "Introduce diccionario:\n";
	f >> D;
	cout << "\nImprimiendo diccionario:\n";
	cout << D;
	cout << "\nIntroduce una palabra de la que quieres buscar información:" << endl;
	cin >> a;

	l = D.getInfo_Asoc(a);

	if (l.size() > 0)
	  EscribeSigni(l);

	// Buscamos la palabra introducida y la borramos
	cout << "\n¿Qué palabra quieres borrar?\n";
	cin >> palabra;

	D.borrar_Palabra(palabra);

	cout << "El diccionario resultante es:\n" << D;

	// Buscamos las palabras que empiezan por la letra introducida
	cout << "\nIntroduce una letra para buscar todas las palabras que empiezan por ella:\n";
	cin >> letra;

	D_letra = D.buscar_Letra(letra);

	cout << "Las palabras que empiezan por la letra " << letra << " son:\n" << D_letra;

	// Buscamos las palabras que tienen el mayor número de significados
	Dmax = D.max_significado();

	cout << "\nLas palabras con el mayor número de significados son:\n" << Dmax;
}
