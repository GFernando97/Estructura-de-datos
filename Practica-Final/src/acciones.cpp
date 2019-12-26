/**
 * @file acciones.cpp
 * @brief Implementación de la clase acciones::acciones
 */
#include "acciones.h"

void acciones::copiar(const acciones & acc){
  this->datos = acc.datos;
}

void acciones::clear(){
  datos.clear();
}

void acciones::insert(const pair<string,  string> &aux){
  map<string,  string>::iterator it;
  it = datos.find(aux.first);

  if(it == datos.end()){
    datos.insert(aux);
  }

  else cout << "La accion ya ha sido insertada...\n";
}

acciones::acciones(const acciones &acc){
  this->clear();
  copiar(acc);
}

bool acciones::isEmpty()const{
  return datos.empty();
}

acciones& acciones::operator=(const acciones &acc){
  if(this!=&acc){
    copiar(acc);
  }

  return *this;
}

ostream &operator<<(ostream &o, const acciones &acc){
  acciones::const_iterator cit;

  for(cit = acc.cbegin(); cit != acc.cend(); ++cit){
    o << (*cit).first << " " << (*cit).second << endl;
  }

  return o;
}

istream &operator>>(istream &i, acciones &acc){
  string linea;
  string nombreAccion;
  string ariedad;
  pair<string,  string> pairAux;

  while(!i.eof()){
    getline(i, linea, '\n');
    if(linea != ""){
      istringstream iss(linea);
      getline(iss, nombreAccion, ' ');
      getline(iss,ariedad, '\n');

      pairAux.first = nombreAccion;
      pairAux.second = ariedad;
      acc.insert(pairAux);
    }

  }
  return i;
}
