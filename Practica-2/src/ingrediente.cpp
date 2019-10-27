#include <iostream>
#include <string>
#include "ingrediente.h"
using namespace std;

Ingrediente::Copiar(const Ingrediente &ing){
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

Ingrediente::Ingrediente &operator= (const Ingrediente &ing){
  if(this != &ing)
    Copiar(ing);

    return *this;
}
