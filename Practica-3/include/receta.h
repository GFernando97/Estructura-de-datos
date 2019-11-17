/**
 * @file receta.h
 *
 * @brief Archivo cabecera de la clase @c receta::receta
 */
#ifndef _receta_
#define _receta_


#include <string>
#include <list>
#include <iostream>
#include <fstream>
#include <sstream>
#include <utility>


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

  void copiar(const receta &receta);

public:
  receta(){}
  receta(const receta &original);

  //Sobrecarga de operadores
  receta &operator=(const receta &rec);
//  bool operator==(const receta &rec);


  //getters
  string getCode(){return this.code;}
  unsigned int getPlato(){return this.plato;}
  list<pair<string, unsigned int>> getIngs(){return this.ings;}

    /**
    * @brief Metodo get de calorias
    * @return numero de calorias del ingrediente
    *
    **/
    int getCalorias() const{return this->calorias;}

    /**
    * @brief Metodo get de Hidratos
    * @return numero de Hidratos del ingrediente
    *
    **/
    int getHc() const{return this->hidratos;}

    /**
    * @brief Metodo get de Proteinas
    * @return numero de Proteinas del ingrediente
    *
    **/
    int getProteinas() const{return this->proteinas;}

    /**
    * @brief Metodo get de Grasas
    * @return numero de Grasas del ingrediente
    *
    **/
    int getGrasas() const{return this->grasas;}

    /**
    * @brief Metodo get de Fibra
    * @return numero de fibra del ingrediente
    *
    **/
    int getFibra() const{return this->fibra;}

    /**
    * @brief Metodo set de Nombre
    * @param nombre del ingrediente
    * @post  ahora el ingrediente tiene el nombre pasado como argumento
    * en el metodo.
    *
    **/

  //SETTERS
  void setCode(string code){ this.code = code;}
  void setPlato(unsigned int plato){this.plato = plato;}
  void setIngs( list<pair<string, unsigned int>> ings){this.ings = ings;}
  void setCalorias(float valor){this.calorias = valor;}
  /**
  * @brief Metodo set de Calorias
  * @param Calorias del ingrediente
  * @post  ahora el ingrediente tiene las calorias pasadas como argumento
  * en el metodo.
  *
  **/
  void setCalorias(int calorias){this->calorias = calorias;}

  /**
  * @brief Metodo set de Hidratos
  * @param Hidratos del ingrediente
  * @post  ahora el ingrediente tiene los hidratos pasados como argumento
  * en el metodo.
  *
  **/
  void setHc(int hidratos){this->hidratos = hidratos;}

  /**
  * @brief Metodo set de Proteinas
  * @param proteinas del ingrediente
  * @post  ahora el ingrediente tiene las proteinas pasadas como argumento
  * en el metodo.
  *
  **/
  void setProteinas(int proteinas){this->proteinas = proteinas;}

  /**
  * @brief Metodo set de Grasas
  * @param grasas del ingrediente
  * @post  ahora el ingrediente tiene las grasas pasadas como argumento
  * en el metodo.
  *
  **/
  void setGrasas(int grasas){this->grasas = grasas;}

  /**
  * @brief Metodo set de Fibra
  * @param fibra del ingrediente
  * @post  ahora el ingrediente tiene la fibra pasada como argumento
  * en el metodo.
  *
  **/
  void setFibra(int fibra){this->fibra = fibra;}

  //Sobrecarga de entrada y salida de datos
  friend ostream& operator << (ostream &o, const receta &rec);
  friend istream& operator >>(istream &i, receta &rec);

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
  list<pair<string, usigned int> >::const_iterator it;

public:
  const_iterator(){}

  bool operator== (const const_iterator &i) const{return i.it==it;}
  bool operator!= (const const_iterator &i) const{return i.it!=it;}

  const  pair<string, unsigned int>& operator*()const{return *it;}

  const_iterator & operator++(){++it; return *this;}
  const_iterator & operator--(){--it; return *this;}

  friend class receta;
};



};
#endif
