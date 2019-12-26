#ifndef _instrucciones_
#define _instrucciones_

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stack>
#include "acciones.h"
#include "arbolbinario.tpp"

using namespace std;

class instrucciones{
private:
  ArbolBinario<string> datos;
  acciones acc;

  void copiar(const instrucciones &inst);
  void clear();

public:
  instrucciones(){}
  instrucciones(const instrucciones &inst);

  void setAcciones(const acciones &acc);

  instrucciones& operator=(const instrucciones &inst);
  friend ostream &operator<<(ostream &o, const instrucciones &inst);
  friend istream &operator>>(istream &i, instrucciones &inst);
};

#endif
