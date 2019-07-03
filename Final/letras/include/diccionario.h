/**
 * @file include/diccionario.h
 * @author Paula Villanueva Núñez
 */

#ifndef _DICCIONARIO_H
#define _DICCIONARIO_H
#include <set>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Diccionario{
  private:
    set<string> datos;

  public:
    /**
      * @brief Construye un diccionario vacío.
      */
    Diccionario (){}

    /**
      * @brief Devuelve el numero de palabras en el diccionario
      */
    int size () const;

    /**
      * @brief Obtiene todas las palabras en el diccionario de un longitud dada
      * @param longitud: la longitud de las palabras de salida
      * @return un vector con las palabras de longitud especifica en el parametro de entrada
      */
    vector<string> PalabrasLongitud (const int longitud) const;

    /**
      * @brief Indica si una palabra está en el diccionario o no
      * @param palabra: la palabra que se quiere buscar
      * @return true si la palabra esta en el diccionario. False en caso contrario
      */
    bool Esta (const string palabra) const;

    /**
      * @brief Inserta una palabra en el diccionario
      * @param palabra Palabra que se inserta en el diccionario
      */
    void insert (string palabra);

    /**
      * @brief Calcula cuántas veces aparece un carácter en el diccionario
      * @param l Carácter que se busca
      * @return Devuelve las veces que aparece el carácter en el diccionario
      */
    double contador_letra (const char & l) const;

    /**
      * @brief Escribe el diccionario en un fichero
      * @param fichero Fichero en el que se escribe
      * @return Devuelve true si ha tenido éxito, si no, false
      */
    bool pasar_a_fichero (const char *fichero) const;

    /**
      * @brief Calcula las palabras válidas que se pueden formar
      * @param letras Caracteres para formar las palabras. Es MODIFICADO
      * @return Devuelve un vector con todas las posibles palabras
      */
    vector<string> calcular_soluciones (multiset<char> & letras) const;

    /**
      * @brief Evalúa si hay una solución válida con unas letras aleatorias
      * @param letras Letras aleatorias
      * @return Devuelve true si no se puede formar una palabra válida, si sí, false
      */
    bool sin_solucion (multiset<char> & letras) const;

    /**
      * @brief Lee de un flujo de entrada un diccionario
      * @param is:flujo de entrada
      * @param D: el objeto donde se realiza la lectura.
      * @return el flujo de entrada
      */
    friend istream & operator>> (istream & is,Diccionario &D);

    /**
      * @brief Escribe en un flujo de salida un diccionario
      * @param os:flujo de salida
      * @param D: el objeto diccionario que se escribe
      * @return el flujo de salida
      */
    friend ostream & operator<< (ostream & os, const Diccionario & D);

    class iterator{
      private:
        set<string>::iterator it;

      public:
        iterator (){}
        const string & operator *();
        iterator & operator ++();
        iterator & operator --();
        bool operator== (const iterator &i);
        bool operator!= (const iterator &i);
        friend class Diccionario;
    };

    iterator begin();
    iterator end();
};

#endif
