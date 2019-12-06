/**
 * @file recetas.h
 *
 * @brief Archivo cabecera de la clase @c recetas::recetas
 */

 #ifndef _recetas_
 #define _recetas_

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <list>
#include <string>
#include "receta.h"


using namespace std;

/**
* @brief Sobrecarga del operardor de salida de datos
* @param o  flujo de salida de datos.
* @param d par de valores de string y recetas que se va a introducir en la salida de datos.
* @post Una vez sobrecargado el operador, se puede insertar en el flujo de salida
* de datos un par de valores del tipo <string, receta>
**/
ostream &operator <<(ostream & os,const pair<const string, const receta> &d);


/**
 * @brief Clase que representa un objeto recetas.
 *
 * Esta clase ha sido implementada para poder representar a un conjunto de recetas.
 * Para pode llevar a cabo dicha Implementación, se ha utilizado el tipo de datos map
 * El map implementado tendrá los valores string y receta, teniendo el primero como
 * llave.
 */
class recetas{
private:
  /**
  * @brief Map de código de receta y receta.
  **/
  map<string, receta> datos;

  /**
  * @brief copia un conjunto de recetas
  * @param rec: recetas cuyos valores se van a copiar
  *
  **/
  void copiar(const recetas &rec);

  /**
  * @brief inserta una receta
  * @param rec: receta cuyos valores se van a insertar
  *
  **/
  void insert(const receta &rec);
public:
  /**
  * @brief consructor vacío, en este caso crea un conjunto de recetas sin valores
  **/
  recetas(){}

  /**
  * @brief constructor de copia
  * @param rec: receta original del cual se van a copiar los datos
  *
  **/
  recetas(const recetas &rec);

  /**
  * @brief Metodo para obtener el tamaño del objeto
  * @return numero de elementos utilizados en el map del objeto.
  **/
  unsigned int size(){return datos.size();}

  /**
  * @brief borrar una receta segun su código
  * @param codigo código de la receta que se va a intentar borrar.
  * @post borra la receta indicada
  *
  **/
  void borrar(string &codigo);

  /**
  * @brief sobrecarga del operador =
  * @param rec: conjunto de recetas del cual se van a copiar los datos
  *
  **/
  recetas &operator=(const recetas &rec);

  /**
  * @brief sobrecarga del operador de acceso []
  * @param codigo: valor del código de la receta a la que se intenta acceder.
  * @return Devuelve la receta que tenga el código como key del map asociado.
  **/
  receta &operator[](string codigo){return datos[codigo];}

  /**
  * @brief Sobrecarga del operardor de salida de datos
  * @param o  flujo de salida de datos.
  * @param rec recetas que se van a inroducir en la salida de datos.
  * @post Una vez sobrecargado el operador, se puede insertar en el flujo de salida
  * de datos un conjunto de recetas sin problemas.
  **/
  friend ostream & operator <<(ostream &o, recetas &rec);

  /**
  * @brief Sobrecarga del operardor de entrada de datos
  * @param i  flujo de entrada de datos.
  * @param rec objeto de la clase recetas que se va a inroducir en la entrada de datos.
  * @post Una vez sobrecargado el operador, se puede insertar en el flujo de entrada
  * de datos un conjunto de recetas sin problemas.
  **/
  friend istream & operator >>(istream &i, recetas &rec);

  /**
  * @brief Metodo para el cálculo del conjunto de mejores recetas dado un lim de Calorías
  * @param caloriasMax: Valor de calorias máx.
  * @return Devuelve una lista que contiene las recetas más adecuadas dado un máx. de calorias
  * y en base a una razón proteinas-hidratos.
  **/
  //list<receta> recetasAdecuadas(const float &caloriasMax);


class const_iterator;

/**
 * @brief Clase iterator de recetas
 *
 * Esta clase ha sido implementada para poder utilizar iteradores en la clase
 * @c recetas. Se iterará sobre el map de valores de string y receta que almacenan
 * el código de la receta y el objeto receta correspondiente con toda la información.
 *
 */
class iterator{
private:
  /**
  * @brief Iterador sobre el map que almacena las recetas.
  *
  **/
  map<string, receta>::iterator it;

public:

  /**
  * @brief Constructor vacio de la clase
  *
  **/
  iterator(){}

  /**
  * @brief Sobrecarga del operador ==
  * @param Objeto iterator con el cual se va a realizar la comparacion
  * @return true si ambos objetos son iguales
  * @return false si los objetos no son iguales
  **/
  bool operator== (const iterator &i) const{return i.it == it;}

  /**
  * @brief Sobrecarga del operador !=
  * @param Objeto iterator con el cual se va a realizar la comparacion
  * @return false si ambos objetos son iguales
  * @return true si los objetos no son iguales
  **/
  bool operator!= (const iterator &i) const{return i.it != it;}

  /**
  * @brief Sobrecarga del operador * de consulta
  * @return Nos devuelve un puntero al objeto actual de la iteración
  **/
  pair<const string, receta>& operator*(){return *it;}

  /**
  * @brief Sobrecarga del operador ++
  * @return devuelve el valor del iterador incrementado una vez
  **/
  iterator& operator++(){++it; return *this;}

  /**
  * @brief Sobrecarga del operador --
  * @return devuelve el valor del iterador decrementado una vez
  **/
  iterator& operator--(){--it; return *this;}

  friend class recetas;
  friend class const_iterator;
};


/**
 * @brief Clase const_iterator de recetas
 *
 * Esta clase ha sido implementada para poder utilizar iteradores constantes en la clase
 * @c recetas. Se iterará sobre el map de valores de string y receta que almacenan
 * el código de la receta y el objeto receta correspondiente con toda la información.
 *
 */
class const_iterator{
private:

  /**
  * @brief Iterador constante sobre el map que almacena las recetas.
  *
  **/
  map<string, receta>:: const_iterator cit;

public:
  /**
  * @brief Constructor vacio de la clase
  *
  **/
  const_iterator(){}

  /**
  * @brief Sobrecarga del operador ==
  * @param Objeto iterator con el cual se va a realizar la comparacion
  * @return true si ambos objetos son iguales
  * @return false si los objetos no son iguales
  **/
  bool operator== (const const_iterator &i) const{return i.cit == cit;}

  /**
  * @brief Sobrecarga del operador !=
  * @param Objeto iterator con el cual se va a realizar la comparacion
  * @return false si ambos objetos son iguales
  * @return true si los objetos no son iguales
  **/
  bool operator!= (const const_iterator &i) const{return i.cit != cit;}

  /**
  * @brief Sobrecarga del operador * de consulta
  * @return Nos devuelve un puntero al objeto actual de la iteración
  **/
  const pair<const string, receta>& operator*()const{return *cit;}

  /**
  * @brief Sobrecarga del operador ++
  * @return devuelve el valor del iterador incrementado una vez
  **/
  const_iterator & operator++(){++cit; return *this;}

  /**
  * @brief Sobrecarga del operador --
  * @return devuelve el valor del iterador decrementado una vez
  **/
  const_iterator & operator--(){--cit; return *this;}

  friend class recetas;
};

/**
* @brief metodo begin para clase recetas
* @return iterador apuntando al comienzo del map de la clase
**/
iterator begin(){
  iterator iter;
  iter.it = datos.begin();
  return iter;
}

/**
* @brief metodo end para clase recetas
* @return iterador apuntando al ultimo elemento del map de la clase
**/
iterator end(){
  iterator iter;
  iter.it = datos.end();
  return iter;
}

/**
* @brief metodo constante begin para clase recetas
* @return iterador constante apuntando al comienzo del map de la clase
**/
const_iterator cbegin()const{
  const_iterator citer;
  citer.cit = datos.cbegin();
  return citer;
}

/**
* @brief metodo constante end para clase recetas
* @return iterador constante apuntando al ultimo elemento del map de la clase
**/
const_iterator cend()const{
  const_iterator citer;
  citer.cit = datos.cend();
  return citer;
}

};


#endif
