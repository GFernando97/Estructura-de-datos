//#ifndef _INGREDIENTES_
#define _INGREDIENTES_

#include <iostream>
#include <fstream>
#include <utility>
#include <list>
#include "VD.h"
#include "ingrediente.h"


using namespace std;

/*
int tam = datos.size();
int inicio = 0;
int fin = tam;
pair<bool,int> econtradoEnPos;

while(inicio < fin){
  int mitad = (inicio + fin)/2;
  if(datos[mitad] == ing){
    encontradoEnPos.first = true;
    encontradoEnPos.second = mitad;
  //  return encontradoEnPos;
  }

  else{
    if(strcmp(ing.getNombre(), datos[mitad]).getNombre() > 0)
      inicio = mitad+1;

    else fin = mitad;
  }

  encontradoEnPos.first = false;
  encontradoEnPos.second = inicio;

}
return encontradoEnPos;
*/

class Ingredientes{
private:
  VD<Ingrediente> datos;
  VD<int> indice;

  //IMPLEMENTADO -- REVISAR POR SI ACASO
  pair<bool, int> estaEnIndice(int posEnDatos);
  //IMPLEMENTADO
  pair<bool, int> estaEnDatos(Ingrediente &ing);
  //IMPLEMENTADO
  void Copiar(const Ingredientes & ing);//
  //IMPLEMENTADO
  void Clear();
  //IMPLEMENTADO -- REVISAR SI NO FUNCIONA
  void ordenarPorNombre();

public:

  //IMPLEMENTADO
  Ingredientes(){};
  //IMPLEMENTADO
  Ingredientes(const Ingredientes &ing);

  //IMPLEMENTADO
  Ingredientes getIngredienteTipo(string tipo);
  //IMPLEMENTADO
  void addIngrediente(const Ingrediente &ing);
  //IMPLEMENTADO
  void deleteIngrediente(const Ingrediente &ing);
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
  Ingrediente get(int indice);

  //IMPLEMENTADO
  Ingredientes &operator=(const Ingredientes &lista);
  //IMPLEMENTADO
  Ingrediente &operator[](int i)const{return datos[i]};
  //IMPLEMENTADO --POR SI ACASO, INCLUIR LA PARTE DE NOMBRE - CALORIAS ... AL PRINCIPIO
  friend ostream &operator<<(ostream &o, const Ingredientes &lista);
  //IMPLEMENTADO
  friend istream &operator>>(istream &i, Ingredientes &lista);

  void ImprimirPorTipo( ostream &out);

//  void calcularEstadisticas(const Ingredientes &listaTipo);

};
