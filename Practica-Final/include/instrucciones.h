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

class instrucciones{
private:
  ArbolBinario<string> datos;
  acciones acc;

  void copiar(const instrucciones &inst);
  void clear();

public:
  instrucciones(){}
  instrucciones(const acciones &acc){ this->setAcciones(acc);}
  instrucciones(const instrucciones &inst);

  void setAcciones(const acciones &acc);
  void setDatos(const ArbolBinario<string> &inst);
  acciones getAcciones()const{return this->acc;}
  ArbolBinario<string> getDatos()const{return this->datos;}
  ArbolBinario<string>& getDatos(){return this->datos;}
  instrucciones& operator=(const instrucciones &inst);
  friend ostream &operator<<(ostream &o, const instrucciones &inst);
  friend istream &operator>>(istream &i, instrucciones &inst);
};

#endif
