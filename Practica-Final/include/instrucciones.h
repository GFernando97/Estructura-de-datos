/**
 * @file instrucciones.h
 *
 * @brief Archivo cabecera de la clase @c instrucciones::instrucciones
 */

#ifndef _instrucciones_
#define _instrucciones_

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stack>
#include "acciones.h"
#include "arbolbinario.h"

using namespace std;

/**
 * @brief Clase que representa un objeto de tipo instrucciones
 * Esta clase representa un objeto del tipo instrucciones, con los siguientes datos:
 * -datos: Objeto de la clase ArbolBinario que almacena el orden de las instrucciones.
 * -acciones: Objeto de la clase acciones que contiene las acciones existentes.
 */
class instrucciones{
private:

  /**
  * @brief ArbolBinario de tipo string.
  * Este arbol almacena el orden en el que se dan las instrucciones
  **/
  ArbolBinario<string> datos;

  /**
  * @brief Objeto de tipo acciones.
  * En este objeto de almacenan las acciones existentes.
  **/
  acciones acc;

  /**
  * @brief Copia los valores de un objeto en el acutal
  * @param inst instrucciones cuyos valores van a ser copiados.
  **/
  void copiar(const instrucciones &inst);

  /**
  * @brief Elimina los elementos de instrucciones.
  * @post el resultado es un objeto instrucciones vacío.
  **/
  void clear();

public:

  /**
  * @brief constructor vacío de la Clase
  * @post crea un objeto instrucciones completamente vacío.
  **/
  instrucciones(){}

  /**
  * @brief constructor con argumentos de la Clase
  * @param acciones con las cuales se va a crear las instrucciones
  * @post Ahora en el Objeto instruccionees actual, se encuentran
  * los valores de las acciones pasadas por parametro.
  **/
  instrucciones(const acciones &acc){ this->setAcciones(acc);}

  /**
  * @brief constructor de copia de la Clase
  * @param objeto que va a ser copiado.
  * @post Ahora en el Objeto instruccionees actual, se encuentran
  * los valores del objeto copiado.
  **/
  instrucciones(const instrucciones &inst);

  /**
  * @brief Metodo set de acciones
  * @param acc acciones de las instrucciones
  * @post  ahora las instrucciones tienen las acciones pasadas como argumento
  * en el metodo.
  *
  **/
  void setAcciones(const acciones &acc);

  /**
  * @brief Metodo set de datos
  * @param inst ArbolBinario con los datos de las instrucciones
  * @post  ahora las instrucciones tienen el ArbolBinario pasado como argumento
  * en el metodo como datos.
  *
  **/
  void setDatos(const ArbolBinario<string> &inst);

  /**
   * @brief metodo get de acciones de las instrucciones
   * @return devuelve las acciones pertenecientes al objeto acciones de la clase.
  **/
  acciones getAcciones()const{return this->acc;}

  /**
   * @brief metodo constate get de datos de las instrucciones
   * @return devuelve los datos almacenados dentro de la clase.
  **/
  ArbolBinario<string> getDatos()const{return this->datos;}

  /**
   * @brief metodo get de datos de las instrucciones
   * @return devuelve los datos almacenados dentro de la clase.
  **/
  ArbolBinario<string>& getDatos(){return this->datos;}

  /**
  * @brief Método auxiliar creado para comprobar si una receta contiene un ingrediente.
  * @param nombreIngrediente string que contiene el nombre del ingrediente.
  * @return true si lo contiene(1).
  * @return false  si no existe el ingrediente en la receta(0);
  **/
  bool contains(const string &accion)const{return acc.contains(accion);}

  /**
  * @brief sobrecarga del operador =
  * @param rec: instrucciones del cual se van a copiar los datos
  *
  **/
  instrucciones& operator=(const instrucciones &inst);

  /**
  * @brief Sobrecarga del operardor de salida de datos
  * @param o  flujo de salida de datos.
  * @param inst instrucciones que se van a introducir en la salida de datos.
  * @post Una vez sobrecargado el operador, se puede insertar en el flujo de salida
  * de datos unas instrucciones sin problemas.
  **/
  friend ostream &operator<<(ostream &o, const instrucciones &inst);

  /**
  * @brief Sobrecarga del operardor de entrada de datos
  * @param i  flujo de entrada de datos.
  * @param inst instrucciones que se van a inroducir en la entrada de datos.
  * @post Una vez sobrecargado el operador, se puede insertar en el flujo de entrada
  * de datos unas instrucciones sin problemas.
  **/
  friend istream &operator>>(istream &i, instrucciones &inst);
};

#endif
