
#include "ingrediente.h"
using namespace std;

void Ingrediente::Copiar(const Ingrediente &ing){
  *this = ing;
}

Ingrediente::Ingrediente(const Ingrediente &original){
  Copiar(original);
}

Ingrediente::Ingrediente(string nombre, int calorias, int hidratos, int proteinas, int grasas, int fibra, string tipo){
  setNombre(nombre);
  setTipo(tipo);
  setGrasas(grasas);
  setCalorias(calorias);
  setHc(hidratos);
  setProteinas(proteinas);
  setFibra(fibra);
}


Ingrediente& Ingrediente:: operator=(const Ingrediente &ing){
  if(this != &ing)
    Copiar(ing);

    return *this;
}

bool Ingrediente::operator ==(const Ingrediente &ing){
  if(this->getNombre() == ing.getNombre() && this->getTipo() == ing.getTipo()
  && this->getCalorias() == ing.getCalorias() && this->getHc()== ing.getHc()
  && this->getProteinas() == ing.getProteinas() && this->getGrasas() == ing.getGrasas()
  && this->getFibra() == ing.getFibra())
    return true;

  else return false;
}


ostream &operator <<(ostream &o, const Ingrediente &ing){

   o << ing.getNombre() << ";"
     << ing.getCalorias() << ";"
     << ing.getHc() << ";"
     << ing.getProteinas() << ";"
     << ing.getGrasas() << ";"
     << ing.getFibra() << ";"
     << ing.getTipo() << endl;

     return o;
}

istream &operator >>(istream &i, Ingrediente &ing){
  string nombre, tipo, calorias, hc, proteinas, grasa, fibra;

  getline(i, nombre,';');
  getline(i,calorias,';');
  getline(i,hc,';');
  getline(i,proteinas,';');
  getline(i,grasa,';');
  getline(i,fibra,';');
  getline(i,tipo);

  ing.setNombre(nombre);
  ing.setCalorias(stoi(calorias, nullptr, 10));
  ing.setHc(stoi(hc, nullptr, 10));
  ing.setProteinas(stoi(proteinas, nullptr, 10));
  ing.setGrasas(stoi(grasa, nullptr, 10));
  ing.setFibra(stoi(fibra, nullptr,10));
  ing.setTipo(tipo);

  return i;
}
