/**
 * @file receta.h
 *
 * @brief Archivo cabecera de la clase @c receta::receta
 */
#ifndef _receta_
#define _receta_

#include <string>
#include <list>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>
#include "ingredientes.h"
#include "instrucciones.h"
#include "color.h"



using namespace std;


/**
 * @brief Clase que representa un objeto receta.
 *
 * Esta clase representa un objeto del tipo receta con los valores por defecto de:
 * -code: codigo que tiene la receta y por el cual se identificará.
 * -plato: indica el numero del plato dentro de un menú.
 * -nombre: indica el nombre que tiene la receta.
 * -lista de ingredientes que contiene la receta
 * -Valores de caloria, hidratos de carbono, grasas, proteinas y fibra que tiene la receta.
 * Además, se ha añadido una varable adicional que contiene la razón proteina-hidratos que guarda la receta.
 *
 */
class receta{
private:

  /**
  * @brief Codigo de la receta.
  **/
  string code;

  /**
  * @brief numero del plato al que pertenece la receta.
  **/
  unsigned int plato;

  /**
  * @brief Nombre de la receta.
  **/
  string nombre = "Undefined";

  /**
  * @brief Lista de ingredientes de la receta.
  **/
  list< pair<string,unsigned int> > ings;

  /**
  * @brief Calorias de la receta.
  **/
  float calorias;

  /**
  * @brief Hidratos de la receta.
  **/
  float hc;

  /**
  * @brief Grasas de la receta.
  **/
  float grasas;

  /**
  * @brief Proteínas de la receta.
  **/
  float proteinas;

  /**
  * @brief Fibra de la receta.
  **/
  float fibra;

  /**
  * @brief Razón proteina-hidratos de la receta.
  **/
  float razon;

  /**
  * @brief instReceta conjunto de instrucciones para formar la receta
  **/
  instrucciones instReceta;


  /**
  * @brief copia una receta
  * @param rec: receta cuyos valores se van a copiar
  *
  **/
  void copiar(const receta &rec);

  /**
  * @brief Método auxiliar creado para extraer los ingredientes de un string.
  * @param cadena de string que contiene los diferentes ingredientes y sus respectivas cantidades.
  * @return lista de ingredientes con sus respectivas cantidades.
  *
  **/
  list<pair <string,unsigned int>> extraerIngredientes(const string &cadena);


public:
  /**
  * @brief consructor vacío, en este caso crea una receta sin valores
  **/
  receta(){}

  /**
  * @brief constructor de copia
  * @param original: objeto original del cual se van a copiar los datos
  *
  **/
  receta(const receta &original);

  /**
  * @brief sobrecarga del operador =
  * @param rec: receta del cual se van a copiar los datos
  *
  **/
  receta &operator=(const receta &rec);


  /**
  * @brief Método get del código de la receta
  * @return código de la receta actual.
  *
  **/
  string getCode()const{return this->code;}

  /**
  * @brief Método get del Plato de la receta.
  * @return numero  del plato de la receta actual.
  *
  **/
  unsigned int getPlato()const{return this->plato;}

  /**
  * @brief Método get de los ingredientes de la receta.
  * @return Lista de ingredientes de la receta.
  *
  **/
  list<pair<string, unsigned int>> getIngs()const{return this->ings;}

  /**
  * @brief Método get del Nombre de la receta.
  * @return Nombre de la receta actual.
  *
  **/
  string getNombre()const{return this->nombre;}

  /**
  * @brief Metodo get de calorias
  * @return numero de calorias de la receta
  *
  **/
  float getCalorias() const{return this->calorias;}

  /**
  * @brief Metodo get de Hidratos
  * @return numero de Hidratos de la receta
  *
  **/
  float getHc() const{return this->hc;}

  /**
  * @brief Metodo get de Proteinas
  * @return numero de Proteinas de la receta
  *
  **/
  float getProteinas() const{return this->proteinas;}

  /**
  * @brief Metodo get de Grasas
  * @return numero de Grasas de la receta
  *
  **/
  float getGrasas() const{return this->grasas;}

  /**
  * @brief Metodo get de Fibra
  * @return numero de fibra de la receta
  *
  **/
  float getFibra() const{return this->fibra;}

  /**
  * @brief Metodo get de la razon de la receta
  * @return valor de la razon de la receta actual
  **/
  float getRazon() const{return this->razon;}

  /**
  * @brief Metodo get de las instrucciones de la receta
  * @return valor de las instrucciones de la receta actual
  **/
  instrucciones getInstrucciones() const{return this->instReceta;}

  /**
  * @brief Metodo personalizado de size de ingredientes
  * @return Tamaño de la lista de ingredientes
  *
  **/
  int ningredientes()const{return ings.size();}

  /**
  * @brief Metodo set de Código
  * @param nombre del codigo
  * @post  ahora la receta tiene el código pasado como argumento
  * en el metodo.
  *
  **/
  void setCode(string code){ this->code = code;}

  /**
  * @brief Metodo set de plato
  * @param Número del plato
  * @post  ahora la rectea tiene el valor del plato pasado como argumento
  * en el metodo.
  *
  **/
  void setPlato(unsigned int plato){this->plato = plato;}

  /**
  * @brief Metodo set de Ingredientes
  * @param Lista de ingredientes
  * @post  ahora La receta tiene Los ingredientes pasado como argumento
  * en el metodo.
  *
  **/
  void setIngs( list<pair<string, unsigned int>> ings){this->ings = ings;}

  /**
  * @brief Metodo set de Nombre
  * @param nombre de la receta
  * @post  ahora la receta tiene el nombre pasado como argumento
  * en el metodo.
  *
  **/
  void setNombre(string nombre){this->nombre = nombre;}

  /**
  * @brief Metodo set de Razon
  * @param Valor de la razón
  * @post  ahora ls receta tiene el valor de la razón pasado como argumento
  * en el metodo.
  *
  **/
  void setRazon(float valor){this->razon = valor;}

  /**
  * @brief Metodo set de Calorias
  * @param Calorias de la receta
  * @post  ahora la receta tiene las calorias pasadas como argumento
  * en el metodo.
  *
  **/
  void setCalorias(float calorias){this->calorias = calorias;}

  /**
  * @brief Metodo set de Hidratos
  * @param Hidratos de la receta
  * @post  ahora la receta tiene los hidratos pasados como argumento
  * en el metodo.
  *
  **/
  void setHc(float hidratos){this->hc = hidratos;}

  /**
  * @brief Metodo set de Proteinas
  * @param proteinas de la receta
  * @post  ahora la receta tiene las proteinas pasadas como argumento
  * en el metodo.
  *
  **/
  void setProteinas(float proteinas){this->proteinas = proteinas;}

  /**
  * @brief Metodo set de Grasas
  * @param grasas de la receta
  * @post  ahora la receta tiene las grasas pasadas como argumento
  * en el metodo.
  *
  **/
  void setGrasas(float grasas){this->grasas = grasas;}

  /**
  * @brief Metodo set de Fibra
  * @param fibra de la receta
  * @post  ahora la receta tiene la fibra pasada como argumento
  * en el metodo.
  *
  **/
  void setFibra(float fibra){this->fibra = fibra;}

  /**
  * @brief Metodo set de Instrucciones
  * @param Instrucciones de la receta
  * @post  ahora la receta tiene las instrucciones pasadas como argumento
  * en el metodo.
  *
  **/
  void setInstrucciones(instrucciones inst){this->instReceta = inst;}

  /**
  * @brief Sobrecarga del operardor de salida de datos
  * @param o  flujo de salida de datos.
  * @param rec receta que se va a inroducir en la salida de datos.
  * @post Una vez sobrecargado el operador, se puede insertar en el flujo de salida
  * de datos una receta sin problemas.
  **/
  friend ostream & operator <<(ostream &o, const receta &rec);

  /**
  * @brief Sobrecarga del operardor de entrada de datos
  * @param i  flujo de entrada de datos.
  * @param rec receta que se va a inroducir en la entrada de datos.
  * @post Una vez sobrecargado el operador, se puede insertar en el flujo de entrada
  * de datos una receta sin problemas.
  **/
  friend istream & operator >>(istream &i, receta &rec);

  /////////////////////////////////////////////////////////////////////////////////
  //////////////////////Métodos para calculo de nutrientes//////////////////////////


  /**
  * @brief Método para el cálculo de los nutrientes correspondientes a una receta
  * @param all: Diccionario de ingredientes en el cual buscar la información necesaria
  * para el cálculo de los nutrientes.
  * @post Una vez que se ha llevado a cabo este método, los valores de los nutrientes
  * correspondientes a la receta se guardan en el propio objeto.
  **/
  void calcularNutrientes(const ingredientes &all);

  /**
  * @brief Método para calcular la razón proteina-hidratos de una receta.
  * @pre Para poder llevar a cabo este metodo, todos los nutrientes deben haber sido previamente
  * calculados.
  * @post Se guarda el valor de la razón en el propio objeto.
  **/
  void calcularRazon();

  /**
  * @brief Método de impresión personalizada de los valores nutricionales.
  * @post Imprime por pantalla los valores almacenados en el objeto correspondientes
  * a los nutrientes que tiene la receta.
  **/
  void imprimeValNutricionales()const;

  /**
  * @brief Método de fusión para fusionar otra receta con la actual
  * @post
  * a los nutrientes que tiene la receta.
  **/
  receta fusionar(const receta &recFusion);

  void imprimeInfoReceta()const;





  ////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////Nuevas clases//////////////////////////////////////

class const_iterator;

/**
 * @brief Clase iterator de receta
 *
 * Esta clase ha sido implementada para poder utilizar iteradores en la clase
 * @c receta. Se iterará sobre la lista de pares de string y unsigned int
 * que almacena a los ingredientess contenidos en la receta.
 *
 */
class iterator{
private:
  /**
   * @brief Iterador sobre la lista que almacena los ingredientes.
   *
   **/
   list<pair<string,unsigned int>>::iterator it;

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
  bool operator== (const iterator &i) const{return i.it== it;}

  /**
  * @brief Sobrecarga del operador !=
  * @param Objeto iterator con el cual se va a realizar la comparacion
  * @return false si ambos objetos son iguales
  * @return true si los objetos no son iguales
  **/
  bool operator!= (const iterator &i) const{return i.it!= it;}

  /**
  * @brief Sobrecarga del operador * de consulta
  * @return Nos devuelve un puntero al objeto actual de la iteración
  **/
  pair<string,unsigned int>& operator*(){ return *it;}

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

friend class receta;
friend class const_iterator;

};

/**
 * @brief Clase const_iterator de receta
 *
 * Esta clase ha sido implementada para poder utilizar iteradores constantes en la clase
 * @c receta. Se iterará sobre la lista de pares de string y unsigned int
 * que almacena a los ingredientess contenidos en la receta.
 *
 */
class const_iterator{
private:

  /**
   * @brief Iterador constante sobre la lista que almacena los ingredientes.
   *
   **/
   list<pair<string, unsigned int> >::const_iterator it;

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
  bool operator== (const const_iterator & i) const{return i.it==it;}

  /**
  * @brief Sobrecarga del operador !=
  * @param Objeto iterator con el cual se va a realizar la comparacion
  * @return false si ambos objetos son iguales
  * @return true si los objetos no son iguales
  **/
  bool operator!= (const const_iterator & i) const{return i.it!=it;}

  /**
  * @brief Sobrecarga del operador * de consulta
  * @return Nos devuelve un puntero al objeto actual de la iteración
  **/
  const  pair<string, unsigned int>& operator*()const{return *it;}

  /**
  * @brief Sobrecarga del operador ++
  * @return devuelve el valor del iterador incrementado una vez
  **/
  const_iterator & operator++(){++it; return *this;}

  /**
  * @brief Sobrecarga del operador --
  * @return devuelve el valor del iterador decrementado una vez
  **/
  const_iterator & operator--(){--it; return *this;}
  friend class receta;
};


  /**
  * @brief metodo begin para clase receta
  * @return iterador apuntando al comienzo de la lista de la clase
  **/
  iterator begin(){
    iterator iter;
    iter.it = ings.begin();
    return iter;
  }

  /**
  * @brief metodo end para clase receta
  * @return iterador apuntando al ultimo elemento de la lista de la clase
  **/
  iterator end(){
  iterator iter;
  iter.it = ings.end();
  return iter;

}

  /**
  * @brief metodo constante de begin para clase receta
  * @return iterador constante apuntando al comienzo de la lista de la clase
  **/
  const_iterator cbegin()const{
  const_iterator citer;
  citer.it = ings.cbegin();
  return citer;
}

  /**
  * @brief metodo constante end para clase receta
  * @return iterador constante apuntando al ultimo elemento de la lista de la clase
  **/
  const_iterator cend()const{
  const_iterator citer;
  citer.it = ings.cend();
  return citer;
}

/////////////////////////Fin de Implementacion/////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

};
#endif
