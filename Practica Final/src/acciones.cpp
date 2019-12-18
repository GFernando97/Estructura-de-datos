#include "acciones.h"

void acciones::copiar(const acciones & acc){
  this.datos = acc.datos;
}

void acciones::clear(){
  datos.clear();
}

acciones::acciones(const acciones &acc){
  this.clear();
  copiar(acc);
}

acciones& acciones::opeator=(const acciones &acc){
  if(this!=&acc){
    copiar(acc);
  }

  return *this;
}

ostream &operator<<(ostream &o, const acciones &acc){
  o << acc.first
}
