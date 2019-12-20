#include "instrucciones.h"

void instrucciones::copiar(const instrucciones &inst){
  this->datos = inst.datos;
  this->acc = inst.acc;
}

void instrucciones::clear(){
  this->datos.clear();
}
/*
void instrucciones::createBinaryTree(istream &i){

}*/

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
  /*inst.clear();
  stack<ArbolBinario> auxStack;
  ArbolBinario aux;
  string nombreAccion;
  list<string> auxIng;
  string linea;

  while(!i.eof()){
    getline(i, linea, '\n');
    linea = linea.stringCleaner(linea, "\r");
    istringstream iss(linea);
    getline(linea, nombreAccion,' ' );


    if(acc.getAriedad(nombreAccion)==1){
      string aux;
      getline(linea, aux, ' ');
      if(!aux.empty()){

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
