#ifndef _INGREDIENTES_
#define _INGREDIENTES_

#include <iostream>
#include <fstream>
#include <utility>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include "VD.h"
#include "ingrediente.h"


using namespace std;

class Ingredientes{
private:
  VD<Ingrediente> datos;
  VD<int> indice;

  //IMPLEMENTADO -- REVISAR POR SI ACASO
  pair<bool, int> estaEnIndice(int posEnDatos) const;
  //IMPLEMENTADO
  pair<bool, int> estaEnDatos(string nombreIng) const;
  //IMPLEMENTADO
  void Copiar(const Ingredientes & ing);//
  //IMPLEMENTADO
  void Clear();
  //IMPLEMENTADO -- REVISAR SI NO FUNCIONA
  void ordenarPorNombre();

public:

  //IMPLEMENTADO
  Ingredientes(){}
  //IMPLEMENTADO
  Ingredientes(const Ingredientes &ing);

  //IMPLEMENTADO
  Ingredientes getIngredienteTipo(string tipo) const;
  //IMPLEMENTADO
  void addIngrediente(const Ingrediente & ing);
  //IMPLEMENTADO
  void deleteIngrediente(Ingrediente &ing);
  //IMPLEMENTADO
  int size()const{return datos.size();}//

/*
  void setNombreIngrediente(int indice, string nuevoNombre);
  void setTipoIngrediente(int indice, string nuevoTipo);
  void setCaloriasIngrediente(int indice, string nuevoValor);
  void setHcIngrediente(int indice, int nuevoValor);
  void setProteinasIngrediente(int indice, int nuevoValor);
  void setGrasasIngrediente(int indice, int nuevoValor);
  void setFibraIngrediente(int indice, int nuevoValor);*/

  //IMPLEMENTADO
  Ingrediente get(string nombreIng);

  void borrar(string nombreIng);

  //IMPLEMENTADO
  Ingredientes& operator=(const Ingredientes &lista);
  //IMPLEMENTADO
  Ingrediente &operator[](int i){return datos[i];}
  //IMPLEMENTADO --POR SI ACASO, INCLUIR LA PARTE DE NOMBRE - CALORIAS ... AL PRINCIPIO
  friend ostream & operator<<(ostream &o, const Ingredientes &lista);
  //IMPLEMENTADO
  friend istream & operator>>(istream &i, Ingredientes &lista);

  void ImprimirPorTipo( ostream &out);


};

#endif
