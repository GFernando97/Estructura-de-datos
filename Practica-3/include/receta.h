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
//#include "ingrediente.h"



using namespace std;

class receta{
private:
  string code;
  unsigned int plato;
  string nombre;
  list< pair<string,unsigned int> > ings;
  float calorias;
  float hc;
  float grasas;
  float proteinas;
  float fibra;
  float razon;

  void copiar(const receta &rec);
  list<pair <string,unsigned int>> extraerIngredientes(const string &cadena);


public:
  receta(){}
  receta(const receta &original);

  //Sobrecarga de operadores
  receta &operator=(const receta &rec);
//  bool operator==(const receta &rec);


  //getters
  string getCode()const{return this->code;}
  unsigned int getPlato()const{return this->plato;}
  list<pair<string, unsigned int>> getIngs()const{return this->ings;}

  string getNombre()const{return this->nombre;}

    /**
    * @brief Metodo get de calorias
    * @return numero de calorias del ingrediente
    *
    **/
    float getCalorias() const{return this->calorias;}

    /**
    * @brief Metodo get de Hidratos
    * @return numero de Hidratos del ingrediente
    *
    **/
    float getHc() const{return this->hc;}

    /**
    * @brief Metodo get de Proteinas
    * @return numero de Proteinas del ingrediente
    *
    **/
    float getProteinas() const{return this->proteinas;}

    /**
    * @brief Metodo get de Grasas
    * @return numero de Grasas del ingrediente
    *
    **/
    float getGrasas() const{return this->grasas;}

    /**
    * @brief Metodo get de Fibra
    * @return numero de fibra del ingrediente
    *
    **/
    float getFibra() const{return this->fibra;}

    /**
    * @brief Metodo set de Nombre
    * @param nombre del ingrediente
    * @post  ahora el ingrediente tiene el nombre pasado como argumento
    * en el metodo.
    *
    **/

    float getRazon() const{return this->razon;}

  //SETTERS
  void setCode(string code){ this->code = code;}
  void setPlato(unsigned int plato){this->plato = plato;}
  void setIngs( list<pair<string, unsigned int>> ings){this->ings = ings;}
  void setNombre(string nombre){this->nombre = nombre;}
  void setRazon(int valor){this->razon = valor;}
  int ningredientes()const{return ings.size();}

  /**
  * @brief Metodo set de Calorias
  * @param Calorias del ingrediente
  * @post  ahora el ingrediente tiene las calorias pasadas como argumento
  * en el metodo.
  *
  **/
  void setCalorias(float calorias){this->calorias = calorias;}

  /**
  * @brief Metodo set de Hidratos
  * @param Hidratos del ingrediente
  * @post  ahora el ingrediente tiene los hidratos pasados como argumento
  * en el metodo.
  *
  **/
  void setHc(float hidratos){this->hc = hidratos;}

  /**
  * @brief Metodo set de Proteinas
  * @param proteinas del ingrediente
  * @post  ahora el ingrediente tiene las proteinas pasadas como argumento
  * en el metodo.
  *
  **/
  void setProteinas(float proteinas){this->proteinas = proteinas;}

  /**
  * @brief Metodo set de Grasas
  * @param grasas del ingrediente
  * @post  ahora el ingrediente tiene las grasas pasadas como argumento
  * en el metodo.
  *
  **/
  void setGrasas(float grasas){this->grasas = grasas;}

  /**
  * @brief Metodo set de Fibra
  * @param fibra del ingrediente
  * @post  ahora el ingrediente tiene la fibra pasada como argumento
  * en el metodo.
  *
  **/
  void setFibra(float fibra){this->fibra = fibra;}

  //Sobrecarga de entrada y salida de datos
  friend ostream & operator <<(ostream &o, const receta &rec);
  friend istream & operator >>(istream &i, receta &rec);

  /////////////////////////////////////////////////////////////////////////////////
  //////////////////////Métodos para calculo de nutrientes//////////////////////////
  void calcularNutrientes(const ingredientes &all);
  void calcularRazon();
  void imprimeValNutricionales()const;




  ////////////////////////////////////////////////////////////////////////////////
  /////////////////////////////Nuevas clases//////////////////////////////////////

class const_iterator;

class iterator{
private:
   list<pair<string,unsigned int>>::iterator it;

public:
  iterator(){}
  bool operator== (const iterator &i) const{return i.it== it;}
  bool operator!= (const iterator &i) const{return i.it!= it;}

  pair<string,unsigned int>& operator*(){ return *it;}

  iterator& operator++(){++it; return *this;}
  iterator& operator--(){--it; return *this;}

friend class receta;
friend class const_iterator;

};

class const_iterator{
private:
   list<pair<string, unsigned int> >::const_iterator it;

public:
  const_iterator(){}

  bool operator== (const const_iterator & i) const{return i.it==it;}
  bool operator!= (const const_iterator & i) const{return i.it!=it;}

  const  pair<string, unsigned int>& operator*()const{return *it;}

  const_iterator & operator++(){++it; return *this;}
  const_iterator & operator--(){--it; return *this;}

  friend class receta;
};

iterator begin(){
  iterator iter;
  iter.it = ings.begin();
  return iter;
}

iterator end(){
  iterator iter;
  iter.it = ings.end();
  return iter;

}

const_iterator cbegin()const{
  const_iterator citer;
  citer.it = ings.cbegin();
  return citer;
}

const_iterator cend()const{
  const_iterator citer;
  citer.it = ings.cend();
  return citer;
}

/////////////////////////Fin de Implementacion/////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

};
#endif
