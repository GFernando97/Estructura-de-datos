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


class acciones{
private:
  map<string, string> datos;
  void copiar(const acciones & acc);
  void clear();
  void insert(const pair<string,  string> &aux);

public:
  acciones(){}
  acciones(const acciones & acc);

  string getKey(const string &key){return (*datos.find(key)).first;}
  string getAriedad(const string & key){return (*datos.find(key)).second;}
  bool isEmpty()const;

  acciones& operator=(const acciones &acc);
  friend ostream &operator<<(ostream &o, const acciones &acc);
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
