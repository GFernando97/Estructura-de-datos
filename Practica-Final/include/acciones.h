/**
 * @file instrucciones.h
 *
 * @brief Archivo cabecera de la clase @c instrucciones::instrucciones
 */

#ifndef _acciones_
#define _acciones_

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <utility>
#include <sstream>
#include <string>
#include <cstring>
using namespace std;

/**
 * @brief Clase que representa un objeto de tipo acciones
 * Esta clase representa un objeto del tipo acciones, con los siguientes datos:
 * -datos: Objeto de la clase map que almacenan las acciones junto con su Ariedad
 * La ariedad de una accion es la cantidad de ingredientes que puede tener una
 * accion para su interaccion
 */
class acciones{
private:

  /**
  * @brief map<string,string> que contiene como valor key el nombre de la accion
  * y en su segundo valor guarda un string con la ariedad de dicha accion.
  **/
  map<string, string> datos;

  /**
  * @brief Copia los valores de un objeto en el acutal
  * @param acc acciones cuyos valores van a ser copiados.
  **/
  void copiar(const acciones & acc);

  /**
  * @brief Elimina los elementos de acciones.
  * @post el resultado es un objeto acciones vacío.
  **/
  void clear();

  /**
  * @brief inserta una accion
  * @param rec: pair par de valores que almacenan nombre de accion y ariedad
  *
  **/
  void insert(const pair<string,  string> &aux);

public:

  /**
  * @brief consructor vacío, en este caso crea el objeto sin valores
  **/
  acciones(){}

  /**
  * @brief constructor de copia
  * @param acc: objeto original del cual se van a copiar los datos
  *
  **/
  acciones(const acciones & acc);

  /**
  * @brief Metodo get de key
  * @param key string que contiene la llave a buscar en  el map
  * @return cadena que contiene la clave encontrada en el map,
  * en este caso, el nombre de las acciones
  *
  **/
  string getKey(const string &key){return (*datos.find(key)).first;}

  /**
  * @brief Metodo get de ariedad
  * @param key string que contiene la clave a buscar en  el map
  * @return cadena que contiene el valor asociada a la clave encontrada en el map,
  * en este caso, la ariedad de la accion.
  *
  **/
  string getAriedad(const string & key){return (*datos.find(key)).second;}

  /**
  * @brief Metodo auxiliar creado para comprobar si el objeto está vacio
  * @return true si está vacío.
  * @return false  si no lo está;
  **/
  bool isEmpty()const;

  /**
  * @brief Método auxiliar creado para comprobar si el objeto contiene una accion .
  * @param nombreAccion string que contiene el nombre de la accion a buscar.
  * @return true si lo contiene(1).
  * @return false  si no existe la accion en el objeto(0);
  **/
  bool contains(const string &nombreAccion)const;

  /**
  * @brief sobrecarga del operador =
  * @param acc: acciones de las cuales se van a copiar los datos
  *
  **/
  acciones& operator=(const acciones &acc);

  /**
  * @brief Sobrecarga del operardor de salida de datos
  * @param o  flujo de salida de datos.
  * @param acc acciones que se van a introducir en la salida de datos.
  * @post Una vez sobrecargado el operador, se puede insertar en el flujo de salida
  * de datos unas acciones sin problemas.
  **/
  friend ostream &operator<<(ostream &o, const acciones &acc);

  /**
  * @brief Sobrecarga del operardor de entrada de datos
  * @param i  flujo de entrada de datos.
  * @param acc acciones que se van a inroducir en la entrada de datos.
  * @post Una vez sobrecargado el operador, se puede insertar en el flujo de entrada
  * de datos unas acciones sin problemas.
  **/
  friend istream &operator>>(istream &i, acciones &acc);




  class const_iterator;

  /**
   * @brief Clase iterator de acciones
   *
   * Esta clase ha sido implementada para poder utilizar iteradores en la clase
   * @c acciones. Se iterará sobre el map de valores de string y  string que almacenan
   * el código de la  y el objeto receta correspondiente con toda la información.
   *
   */
  class iterator{
  private:
    /**
    * @brief Iterador sobre el map que almacena las recetas.
    *
    **/
    map<string,  string>::iterator it;

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
    pair<const string,  string>& operator*(){return *it;}

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

    friend class acciones;
    friend class const_iterator;
  };


  /**
   * @brief Clase const_iterator de acciones
   *
   * Esta clase ha sido implementada para poder utilizar iteradores constantes en la clase
   * @c acciones. Se iterará sobre el map de valores de string y  string que almacenan
   * el código de la acciones y el objeto  correspondiente con toda la información.
   *
   */
  class const_iterator{
  private:

    /**
    * @brief Iterador constante sobre el map que almacena las acciones.
    *
    **/
    map<string, string>:: const_iterator cit;

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
    const pair<const string, string>& operator*()const{return *cit;}

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

    friend class acciones;
  };

  /**
  * @brief metodo begin para clase acciones
  * @return iterador apuntando al comienzo del map de la clase
  **/
  iterator begin(){
    iterator iter;
    iter.it = datos.begin();
    return iter;
  }

  /**
  * @brief metodo end para clase acciones
  * @return iterador apuntando al ultimo elemento del map de la clase
  **/
  iterator end(){
    iterator iter;
    iter.it = datos.end();
    return iter;
  }

  /**
  * @brief metodo constante begin para clase acciones
  * @return iterador constante apuntando al comienzo del map de la clase
  **/
  const_iterator cbegin()const{
    const_iterator citer;
    citer.cit = datos.cbegin();
    return citer;
  }

  /**
  * @brief metodo constante end para clase acciones
  * @return iterador constante apuntando al ultimo elemento del map de la clase
  **/
  const_iterator cend()const{
    const_iterator citer;
    citer.cit = datos.cend();
    return citer;
  }

};



#endif
