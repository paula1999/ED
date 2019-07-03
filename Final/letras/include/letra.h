/**
 * @file include/letra.h
 * @author Paula Villanueva Núñez
 */

#ifndef _LETRA_H
#define _LETRA_H
#include <iostream>
using namespace std;

class Letra{
  private:
    char l;
    int frecuencia;
    int puntuacion;

  public:
    /**
      * @brief Construye una letra vacía
      */
    Letra();

    /**
      * @brief Constructor de copia
      * @param a Letra (carácter)
      * @param frec Frecuencia del carácter
      * @param puntos Puntuación del carácter
      */
    Letra (char a, int frec, int puntos);

    /**
      * @brief Constructor de copia
      * @param otro Letra de la que se hará la copia
      */
    Letra (const Letra & otro);

    /**
      * @brief Destructor
      */
    ~Letra();

    /**
      * @brief Libera la memoria de la letra
      */
    void liberarMemoria ();

    /**
     	* @brief Operador de asignación
     	* @param otro La letra que se va a asignar
  		*/
    Letra & operator= (const Letra & otro);

    /**
      * @brief Copia una letra
      * @param otro Letra copiada
      */
    void copiar (const Letra & otro);

    /**
      * @brief Devuelve el carácter de la letra
      * @return Devuelve el carácter de la letra
      */
    char getLetra () const;

    /**
      * @brief Devuelve la frecuencia de la letra
      * @return Devuelve la frecuencia de la letra
      */
    int getFrecuencia () const;

    /**
      * @brief Devuelve la puntuación de la letra
      * @return Devuelve la puntuación de la letra
      */
    int getPuntuacion () const;

    /**
      * @brief Escritura de la letra
      * @param os Flujo de salida. Es MODIFICADO
      * @param otro Letra que se escribe
      * @return El flujo de salida
      */
    friend ostream & operator<< (ostream &os, const Letra & otro);

    /**
      * @brief Lectura de la letra
      * @param is Flujo de entrada. ES MODIFICADO
      * @param otro Letra. ES MODIFICADO
      * @return El flujo de entrada
     */
    friend istream & operator>> (istream & is, Letra & otro);
};

#endif
