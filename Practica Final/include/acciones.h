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

public:
  acciones(){}
  acciones(const acciones & acc);

  unsigned char getAriedad(const string & key){return datos[key];}

  acciones& operator=(const acciones &acc);
  friend ostream &operator<<(ostream &o, const acciones &acc);
  friend istream &operator>>(istream &i, acciones &acc);


};



#endif
