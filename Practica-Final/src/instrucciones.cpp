/**
 * @file instrucciones.cpp
 * @brief Implementación de la clase instrucciones::instrucciones
 */
#include "instrucciones.h"


void instrucciones::copiar(const instrucciones &inst){
  this->datos = inst.datos;
}

void instrucciones::clear(){
  this->datos.clear();
}

instrucciones::instrucciones(const instrucciones &inst){
  this->clear();
  copiar(inst);
}

void instrucciones::setAcciones(const acciones &acc){
  this->acc=acc;
}

instrucciones& instrucciones::operator=(const instrucciones &inst){
  if(this!=&inst){
    copiar(inst);
  }

  return *this;
}

ostream &operator<<(ostream &o, const instrucciones &inst){
//  o << inst.datos;

  return o;

}

istream &operator>>(istream &i, instrucciones &inst){
/*  inst.clear();
  stack<ArbolBinario> auxStack;
  ArbolBinario aux;
  string nombreAccion;
  string auxIngr1;
  string auxIngr2;
  string linea;

  while(!i.eof()){
    getline(i, linea, '\n');
    istringstream iss(linea);
    getline(linea, nombreAccion,' ' );


    if(acc.getAriedad(nombreAccion)==1){
      getline(linea, auxIngr1, '\n');
      if(!aux.empty()){
        aux.
      }

    }

  }*/

  return i;
}
/*
string stringCleaner(string cadena_original,string cadena_a_eliminar){
	string linea(cadena_original);
  while(linea.find_first_of(cadena_a_eliminar) != std::string::npos){
		linea.erase(linea.find_first_of(cadena_a_eliminar),cadena_a_eliminar.length());
	}

	return linea;
}
*/
