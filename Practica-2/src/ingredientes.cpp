#include <iostream>
#include <fstream>
#include <utility>
#include <cmath>
#include <list>
#include <cstring>
#include "ingredientes.h"

using namespace std;

  pair<bool, int>Ingredientes::estaEnIndice(int posEnDatos){
    int tam = indice.size();
    int inicio = 0;
    int fin = tam;
    pair<bool,int> encontradoEnPos;

    while(inicio < fin){
      int mitad = (inicio + fin)/2;

      if(indice[mitad] == posEnDatos){
        encontradoEnPos.first = true;
        encontradoEnPos.second = mitad;
      }

      else{
        if(strcmp(datos[mitad].getTipo(), datos[posEnDatos].getTipo() >= 0))
          inicio = mitad+1;

        else fin = mitad;
      }

      econtradoEnPos.first = false;
      encontradoEnPos.second = inicio;
    }

    return encontradoEnPos;
  }

  pair <bool, int> Ingredientes::estaEnDatos(Ingrediente &ing){
    int tam = datos.size();
    int inicio = 0;
    int fin = tam;
    pair<bool,int> econtradoEnPos;

    while(inicio < fin){
      int mitad = (inicio + fin)/2;
      if(datos[mitad] == ing){
        encontradoEnPos.first = true;
        encontradoEnPos.second = mitad;
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

  }


  void Ingredientes::Copiar(const Ingredientes &ing){
    Clear();

    datos = ing.datos;
    indice = ing.indice;

  }

  void Ingredientes::Clear(){
    datos.liberar();
    indice.liberar();
  }

  void Ingredientes::ordenarPorNombre(){
    Ingrediente aux;

      for(int i = 0; i < datos.size()-1; i++){
        for(int j= 0; j < datos.size()-i-1; j++){
          if(strcmp(datos[j], datos[j+1]) > 0){
            aux = datos[j+1];
            datos.borrar(j+1);
            datos.insert(datos[j], j+1);
            datos.borrar(j);
            datos.insert(aux, j);
          }
        }
      }
  }

  Ingredientes Ingredientes::Ingredientes(const Ingredientes &ing){
    Clear();
    Copiar(&ing);
  }

  Ingredientes Ingredientes::getIngredienteTipo(string tipo){
    Ingrediente ingredientesTipo;

    ingredientesTipo.clear();
    for(int i = 0; i < datos.size(); i++){
      if(datos[i].getTipo() == tipo){}
        ingredientesTipo.addIngrediente(datos[i]);
    }

    return ingredientesTipo;
  }


  void Ingredientes::addIngrediente(const Ingrediente &ing){
    pair<bool, int> posDatos = estaEnDatos(ing);
    pair<bool, int> posIndice = estaEnIndice(posDatos.second);

    if(posDatos.first == false){
      datos.insert(ing, posDatos.second);
      indice.insert(posDatos.second, posIndice.second);
    }

    else if(pos.first == true ){
      if(datos[pos.second].getTipo() != ing.getTipo())
        datos.insert(ing, pos.second + 1);
    }
  }

  void deleteIngrediente(const Ingrediente &ing){
    pair <bool, int> estaEnPos = estaEnDatos(ing);
    int pos;

    if(estaEnPos.first = true){
      pos = estaEnPos.second;
      datos.Borrar(pos);

      if(estaEnIndice(pos).first == true){
        pos = estaEnIndice(pos).second;
        indice.Borrar(pos);
      }
    }
  }
//-------------------------------------------------------------------
//                GETTERS Y SETTERS SE IMPLEMENTARÁN AQUÍ
//
//
//
//
//
//
//
//-------------------------------------------------------------------

  Ingrediente Ingredientes:: get(int indice){
    if(indice <= datos.size() && indice >= 0)
      return datos[indice];
  }

  Ingredientes Ingredientes::&operator=(const Ingredientes &lista){
    if(this != &lista){
      clear();
      copiar(lista);
    }
    return *this;
  }

  ostream &operator <<(ostream &o, const Ingredientes &lista){
    int n = lista.size();

    for(int i = 0; i < n; i++){
      os << lista.datos[i].getNombre() << ";"
         << lista.datos[i].getCalorias() << ";"
         << lista.datos[i].getHc() << ";"
         << lista.datos[i].getProteinas() << ";"
         << lista.datos[i].getGrasas() << ";"
         << lista.datos[i].getFibra() << ";"
         << lista.datos[i].getTipo() << endl;
    }

    return os;
  }

  istream &operator>>(istream&i, Ingredientes &lista){
    string aux;
    Ingrediente ingAux;
    string nombre, tipo, calorias, hc, proteinas, grasa, fibra;
    int nveces =0;

    while(!i.eof()){
      getline(i,aux,'\n');
      if(nveces == 0){
        nveces++;
      }
      else{
        getline(aux, nombre,';');
        getline(aux,calorias,';');
        getline(aux,hc,';');
        getline(aux,proteinas,';');
        getline(aux,grasa,';');
        getline(aux,fibra,';');
        getline(aux,tipo);

        ingAux.setNombre(nombre);
        ingAux.setCalorias(stoi(calorias, nullptr, 10));
        ingAux.setHc(stoi(hc, nullptr, 10));
        ingAux.setProteinas(stoi(proteinas, nullptr, 10));
        ingAux.setGrasas(stoi(grasa, nullptr, 10));
        ingAux.setFibra(stoi(fibra, nullptr,10));
        ingAux.setTipo(tipo);

        lista.addIngrediente(ingAux);
        nveces++;
      }
    }

    return i;
  }

    void Ingredientes::ImprimirPorTipo(ostream &out){

      for (int i = o; i < indice.size(); i++){
        out << datos[indice[i]] << endl;
      }

      return out;
    }
