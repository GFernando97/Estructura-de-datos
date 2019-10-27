/*• Insertar y Borrar un ingrediente. Estas operaciones tienen que preservar
 el orden tras
su ejecución. Recordar que el orden que tenemos en Ingredientes es doble 1)
Solamente por nombre 2) Por tipo y nombre.

• Obtener el ingrediente en la posición i según el orden del nombre.
• Obtener la información de un ingrediente dando su nombre
• Obtener todas los ingredientes de un tipo
• Sobrecargas el operator [] para realizar consultas
de la posición i
• Operadores de modificación: modificar el ingrediente
ingrediente
• Además se deberá sobrecargar los operadores de escritura y lectura en flujos.
por otro


pareja Conjunto :: Esta (int x) const {
//Al estar ordenado podemos hacer una busqueda binaria
int n = d.size();
int inicio = 0, fin = n;

while (inicio < fin) {
  int mitad = (inicio + fin)/2;
  if (d[mitad] == x) {
    pareja p = {mitad, true};
    return p;
  }

  else {
    if (x > d[mitad])
      inicio = mitad + 1;
    else
    fin = mitad;
  }

  pareja p = {inicio, false};
  return p;
}
}

*/



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

  }


  void Ingredientes::Copiar(const Ingredientes &ing){
    Clear();

    datos = ing.datos;
    indice = ing.indice;

  }

  void Ingredientes::Clear(){
  }


  Ingredientes Ingredientes::Ingredientes(const Ingredientes &ing){
    Clear();
    Copiar(&ing);
  }

  list<Ingrediente> Ingredientes::getIngredienteTipo(string tipo){
    list<Ingrediente> ingredientesTipo;


    ingredientesTipo.clear();
    for(int i = 0; i < datos.size(); i++){
      if(datos[i].getTipo() == tipo){}
        ingredientesTipo.insert(datos[i]);
    }

    return ingredientesTipo;
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

  void deleteIngrediente(const string &nombreIng){
    
  }
