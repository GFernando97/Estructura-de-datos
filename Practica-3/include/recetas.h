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
#include <string>
#include "receta.h"


using namespace std;

ostream &operator <<(ostream & os,const pair<const string, const receta> &d);


class recetas{
private:
  map<string, receta> datos;

  void copiar(const recetas &rec);
  void insert(const receta &rec);
public:

recetas(){}
recetas(const recetas &rec);
unsigned int size(){return datos.size();}
void borrar(string &codigo);
//list<receta> recetasAdecuadas(const int &caloriasMax); 


recetas &operator=(const recetas &rec);
receta &operator[](string codigo){return datos[codigo];}



//Sobrecarga de Operadores
friend ostream & operator <<(ostream &o, recetas &rec);
friend istream & operator >>(istream &i, recetas &rec);


class const_iterator;

class iterator{
private:
  map<string, receta>::iterator it;

public:
  iterator(){}
  bool operator== (const iterator &i) const{return i.it == it;}
  bool operator!= (const iterator &i) const{return i.it != it;}

  pair<const string, receta>& operator*(){return *it;}

  iterator& operator++(){++it; return *this;}
  iterator& operator--(){--it; return *this;}

  friend class recetas;
  friend class const_iterator;
};

class const_iterator{
private:
  map<string, receta>:: const_iterator cit;

public:
  const_iterator(){}
  bool operator== (const const_iterator &i) const{return i.cit == cit;}
  bool operator!= (const const_iterator &i) const{return i.cit != cit;}

  const pair<const string, receta>& operator*()const{return *cit;}
  const_iterator & operator++(){++cit; return *this;}
  const_iterator & operator--(){--cit; return *this;}

  friend class recetas;
};

iterator begin(){
  iterator iter;
  iter.it = datos.begin();
  return iter;
}

iterator end(){
  iterator iter;
  iter.it = datos.end();
  return iter;
}

const_iterator cbegin()const{
  const_iterator citer;
  citer.cit = datos.cbegin();
  return citer;
}

const_iterator cend()const{
  const_iterator citer;
  citer.cit = datos.cend();
  return citer;
}

};


#endif
