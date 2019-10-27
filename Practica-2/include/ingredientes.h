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

  pair<bool, int> estaEnIndice(Ingrediente &ing);
  pair<bool, int> estaEnDatos(Ingrediente &ing);
//
  void Copiar(const Ingredientes & ing);//
//
  void Clear();
  //
  void ordenarPorNombre();

public:
  Ingredientes(){};
  Ingredientes(const Ingredientes &ing);//


  list<Ingrediente> getIngredienteTipo(string tipo);//
  void addIngrediente(const Ingrediente &ing);
  void deleteIngrediente(const string &nombreIng);

  int size()const{return datos.size();}//

/*
  void setNombreIngrediente(int indice, string nuevoNombre);
  void setTipoIngrediente(int indice, string nuevoTipo);
  void setCaloriasIngrediente(int indice, string nuevoValor);
  void setHcIngrediente(int indice, int nuevoValor);
  void setProteinasIngrediente(int indice, int nuevoValor);
  void setGrasasIngrediente(int indice, int nuevoValor);
  void setFibraIngrediente(int indice, int nuevoValor);*/

  Ingrediente get(int indice);
  Ingredientes &operator=(const Ingredientes &lista);
  Ingrediente &operator[](int i)const;

  friend ostream &operator<<(ostream &o, const Ingredientes &lista);
  friend istream &operator>>(istream &i, Ingredientes & lista);

  void ImprimirPorTipo( ostream& out);

};
