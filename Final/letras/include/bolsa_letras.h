/**
 * @file include/bolsa_letras.h
 * @author Paula Villanueva Núñez
 */

#ifndef _BOLSA_LETRAS_H
#define _BOLSA_LETRAS_H
#include "letra.h"
#include "conjunto_letras.h"
#include <set>
#include <iostream>
using namespace std;

class Bolsa_letras{
  private:
    Conjunto_Letras bolsa;

  public:
    /**
      * @brief Construye una volsa de letras vacía
      */
    Bolsa_letras (){}

    /**
      * @brief Constructor de copia
      * @param otro Bolsa de letras de la que se hará la copia
      */
    Bolsa_letras (const Bolsa_letras & otro);

    /**
      * @brief Libera la memoria de la bolsa de letras
      */
    void liberarMemoria ();

    /**
      * @brief Destructor
      */
    ~Bolsa_letras ();

    /**
      * @brief Añade un conjunto de letras a la bolsa
      * @param otro Conjunto de letras que se añade a la bolsa de letras
      */
    void aniadir_conjunto (const Conjunto_Letras & otro);

    /**
      * @brief Devuelve la frecuencia del carácter
      * @param caracter Carácter del que se calcula su frecuencia
      * @return Devuelve la frecuencia del carácter
      */
    int getFrecuencia (const char caracter) const;

    /**
      * @brief Calcula las letras aleatorias
      * @param tamanio Número de letras aleatorias que calcula
      * @return Devuelve las letras aleatorias
      */
    multiset<char> sacar_letra (const int tamanio);

    /**
     	* @brief Operador de asignación
     	* @param otro La bolsa de letras que se va a asignar
  		*/
    Bolsa_letras & operator= (const Bolsa_letras & otro);

    /**
      * @brief Escritura de la bolsa de letras
      * @param os Flujo de salida. Es MODIFICADO
      * @param otro Bolsa de letras que se escribe
      * @return El flujo de salida
      */
    friend ostream & operator<< (ostream &os, const Bolsa_letras & otro);
};

#endif
