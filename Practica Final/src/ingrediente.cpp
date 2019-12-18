/**
 * @file ingrediente.cpp
 * @brief Implementación de la clase ingrediente::ingrediente.
 */
#include "ingrediente.h"
using namespace std;

void ingrediente::Copiar(const ingrediente &ing){
  setNombre(ing.getNombre());
  setTipo(ing.getTipo());
  setCalorias(ing.getCalorias());
  setHc(ing.getHc());
  setProteinas(ing.getProteinas());
  setGrasas(ing.getGrasas());
  setFibra(ing.getFibra());
}

ingrediente::ingrediente(const ingrediente &original){
  Copiar(original);
}

ingrediente::ingrediente(string nombre, float calorias, float hidratos, float proteinas, float grasas, float fibra, string tipo){
  setNombre(nombre);
  setTipo(tipo);
  setGrasas(grasas);
  setCalorias(calorias);
  setHc(hidratos);
  setProteinas(proteinas);
  setFibra(fibra);
}


ingrediente& ingrediente:: operator=(const ingrediente &ing){
  if(this != &ing){
    Copiar(ing);
  }

    return *this;
}

bool ingrediente::operator ==(const ingrediente &ing){
  if(this->getNombre() == ing.getNombre() && this->getTipo() == ing.getTipo()
  && this->getCalorias() == ing.getCalorias() && this->getHc()== ing.getHc()
  && this->getProteinas() == ing.getProteinas() && this->getGrasas() == ing.getGrasas()
  && this->getFibra() == ing.getFibra())
    return true;

  else return false;
}


ostream& operator << (ostream &o, const ingrediente &ing){

   o << ing.getNombre() << ";"
     << ing.getCalorias() << ";"
     << ing.getHc() << ";"
     << ing.getProteinas() << ";"
     << ing.getGrasas() << ";"
     << ing.getFibra() << ";"
     << ing.getTipo();

     return o;
}

istream& operator >> (istream &i, ingrediente &ing){
  string nombre, tipo, calorias, hc, proteinas, grasa, fibra, aux;

  getline(i, nombre,';');
  getline(i,calorias,';');
  getline(i,hc,';');
  getline(i,proteinas,';');
  getline(i,grasa,';');
  getline(i,fibra,';');
  getline(i,tipo, '\r');
  getline(i, aux, '\n');

  if(nombre != ""){
    ing.setNombre(nombre);
    ing.setCalorias(stof(calorias));
    ing.setHc(stof(hc));
    ing.setProteinas(stof(proteinas));
    ing.setGrasas(stof(grasa));
    ing.setFibra(stof(fibra));
    ing.setTipo(tipo);
  }

  return i;
}
