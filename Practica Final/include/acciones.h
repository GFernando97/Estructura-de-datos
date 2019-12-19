#ifndef _acciones_
#define _acciones_

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <utility>

using namespace std;


class acciones{
private:
  map<string, unsigned char> datos;
  void copiar(const acciones & acc);
  void clear();
  void insert(const pair<string, unsigned char> &aux);

public:
  acciones(){}
  acciones(const acciones & acc);

  unsigned char getAriedad(const string & key){return datos[key];}

  acciones& operator=(const acciones &acc);
  friend ostream &operator<<(ostream &o, const acciones &acc);
  friend istream &operator>>(istream &i, acciones &acc);




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
    map<string, unsigned char>::iterator it;

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
    map<string, unsigned char>:: const_iterator cit;

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
