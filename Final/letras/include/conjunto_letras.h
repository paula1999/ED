/**
 * @file include/conjunto_letras.h
 * @author Paula Villanueva Núñez
 */

#ifndef _CONJUNTO_LETRAS_H
#define _CONJUNTO_LETRAS_H
#include <set>
#include "letra.h"
#include "diccionario.h"
#include <iostream>
using namespace std;

class Conjunto_Letras{
  private:
    set<Letra> conjunto;
    friend class Bolsa_letras;

  public:
    /**
      * @brief Construye un conjunto de letras vacío
      */
    Conjunto_Letras(){}

    /**
      * @brief Destructor
      */
    ~Conjunto_Letras ();

    /**
      * @brief Libera la memoria del conjunto de letras
      */
    void liberarMemoria();

    /**
      * @brief Devuelve el tamaño del conjunto de letras
      * @return Devuelve el tamaño del conjunto de letras
      */
    int getSize () const;

    /**
      * @brief Devuelve el conjunto de letras
      * @return Devuelve el conjunto de letras
      */
    set<Letra> getConjunto () const;

    /**
     	* @brief Operador de asignación
     	* @param otro El conjunto de letras que se va a asignar
  		*/
    Conjunto_Letras & operator= (const Conjunto_Letras & otro);

    /**
      * @brief Copia un conjunto de letras
      * @param otro Conjunto de letras copiado
      */
    void copiar (const Conjunto_Letras & otro);

    /**
      * @brief Añade una letra al conjunto de letras
      * @param otro Letra que se añade al conjunto de letras
      */
    void addLetra (const Letra & otro);

    /**
      * @brief Devuelve la frecuencia del carácter
      * @param caracter Carácter del que se calcula su frecuencia
      * @return Devuelve la frecuencia del carácter
      */
    int getFrecuencia (const char caracter) const;

    /**
      * @brief Devuelve la frecuencia total de todas las letras
      * @return Devuelve la frecuencia total del conjunto de letras
      */
    int getFrecuenciaTotal () const;

    /**
      * @brief Disminuye la frecuencia
      * @param otro Carácter del que se quiere disminuir la frecuencia
      * @param frec Frecuencia que se quiere disminuir
      */
    void quitarFrecuencia (const char otro, const int frec);

    /**
      * @brief Comprueba si una letra está en el conjunto
      * @param otro Letra que se busca
      * @param it Iterador que devuelve la posición donde se encuentra la letra. Es MODIFICADO
      * @return Devuelve true si está, si no, false
      */
    bool esta_letra (const Letra & otro, set<Letra>::const_iterator & it) const;

    /**
      * @brief Comprueba si una palabra se puede formar con las letras del conjunto de letras
      * @param sol Palabra que se quiere comprobar
      * @return Devuelve true si es válida, si no, false
      */
    bool comprobar_solucion (const string sol) const;

    /**
      * @brief Calcula la puntuación de una palabra
      * @param sol Palabra de la que se calcula la puntuación
      * @return Devuelve la puntuación de la palabra
      */
    int calcular_puntuacion (const string sol) const;

    /**
      * @brief Imprime las posibles soluciones y calcula la palabra con mayor longitud
      * @param posibles_soluciones Vector de las palabras evaluadas
      */
    void mejor_solucion_l (const vector<string> & posibles_soluciones) const;

    /**
      * @brief Imprime las posibles soluciones y calcula palabra con mayor puntuación
      * @param posibles_soluciones Vector de las palabras evaluadas
      * @return Devuelve la palabra con mayor puntuación
      */
    void mejor_solucion_p (const vector<string> & posibles_soluciones) const;

    /**
      * @brief Escritura del conjunto de letras
      * @param os Flujo de salida. Es MODIFICADO
      * @param otro Conjunto de letras que se escribe
      * @return El flujo de salida
      */
    friend ostream & operator<< (ostream &os, const Conjunto_Letras & otro);

    /**
      * @brief Lectura del conjunto de letras
      * @param is Flujo de entrada. ES MODIFICADO
      * @param otro Conjunto de letras. ES MODIFICADO
      * @return El flujo de entrada
     */
    friend istream & operator>> (istream & is, Conjunto_Letras & otro);
};

#endif
