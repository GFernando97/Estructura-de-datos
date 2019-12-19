#include "instrucciones.h"

void instrucciones::copiar(const instrucciones &inst){
  this.datos = inst.datos;
  this.acc = inst.acc;
}

void instrucciones::clear(){
  datos.clear();
  acc.clear();
}

instrucciones::instrucciones(const instrucciones &inst){
  this.clear();
  copiar(inst);
}

instrucciones& instrucciones::operator=(const instrucciones &inst){
  if(this!=&inst){
    copiar(inst);
  }

  return *this;
}

ostream &operator<<(ostream &o, const instrucciones &inst){
  o << inst.datos;

  return o;

}

istream &operator>>(istream &i, instrucciones &inst){

  return i;

}
