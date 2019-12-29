#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <utility>
#include <stack>
#include "arbolbinario.h"

map<string, string> ariedades;
stack<ArbolBinario<string>> stackOfTrees;

using namespace std;

void rellenarMapAriedades(map<string, string> &ariedades){
  pair<string, string> aux;

  aux.first = "Cortar";
  aux.second = "1";
  ariedades.insert(aux);
  aux.first = "Mezclar";
  aux.second = "2";
  ariedades.insert(aux);
  aux.first = "Pelar";
  aux.second = "1";
  ariedades.insert(aux);
  aux.first = "Add";
  aux.second = "2";
  ariedades.insert(aux);
  aux.first = "Calentar";
  aux.second = "1";
  ariedades.insert(aux);
  aux.first = "Reservar";
  aux.second = "1";
  ariedades.insert(aux);
  aux.first = "Triturar";
  aux.second = "1";
  ariedades.insert(aux);
  aux.first = "Cocer";
  aux.second = "1";
  ariedades.insert(aux);
  aux.first = "Hornear";
  aux.second = "1";
  ariedades.insert(aux);
  aux.first = "Enharinar";
  aux.second = "1";
  ariedades.insert(aux);
  aux.first = "Freir";
  aux.second = "1";
  ariedades.insert(aux);
  aux.first = "Formar";
  aux.second = "1";
  ariedades.insert(aux);
  aux.first = "Emplatar";
  aux.second = "1";
  ariedades.insert(aux);
  aux.first = "Acompañar";
  aux.second = "2";
  ariedades.insert(aux);
}

void stoTree(string &linea){
  istringstream iss(linea);
  string nombreAccion;
  string ariedadAccion;
  string ingredienteAccion1;
  string ingredienteAccion2;

  while(!iss.eof()){
    getline(iss, nombreAccion, ' ');
    getline(iss, ingredienteAccion1, '\n');
    cout << "Ingrediente de accion es: " << ingredienteAccion1 << endl;
    ariedadAccion = ariedades.at(nombreAccion);
    cout << "la accion es " << nombreAccion << " con Ariedad " << ariedadAccion << endl;
    ArbolBinario<string> auxTree(nombreAccion);

    if(ariedadAccion=="1"){
      if(!ingredienteAccion1.empty()){
        auxTree.Insertar_Hi(auxTree.getRaiz(), ingredienteAccion1);
        stackOfTrees.push(auxTree);
      }

      else{
        if(!stackOfTrees.empty()){
          ArbolBinario<string> stackTree = stackOfTrees.top();
          stackOfTrees.pop();
          auxTree.Insertar_Hi(auxTree.getRaiz(), stackTree);
          stackOfTrees.push(auxTree);
        }
        else{
          cout << "Error en la pila. Terminar Programa!!!!";
          abort();
        }
      }
    }

    else if(ariedadAccion=="2"){
      if(!ingredienteAccion1.empty()){
        auxTree.Insertar_Hd(auxTree.getRaiz(), ingredienteAccion1);
        ArbolBinario<string> stackTree = stackOfTrees.top();
        stackOfTrees.pop();
        cout << "Tamaño de Pila ahora: " << stackOfTrees.size() << endl << endl;
        auxTree.Insertar_Hi(auxTree.getRaiz(), stackTree);
        stackOfTrees.push(auxTree);

      }
      else{
        if(!stackOfTrees.empty()){
          ArbolBinario<string> stackTree = stackOfTrees.top();
          stackOfTrees.pop();
          auxTree.Insertar_Hd(auxTree.getRaiz(), stackTree);
          stackTree = stackOfTrees.top();
          stackOfTrees.pop();
          auxTree.Insertar_Hi(auxTree.getRaiz(), stackTree);
          stackOfTrees.push(auxTree);
        }
        else{
          cout << "Error en la pila. Terminar Programa!!!!";
          abort();
        }
      }
    }
  }
}

int main(){
    cout << "Se va a crear un arbol binario con las instrucciones de uso de una receta\n";

    ArbolBinario<string> arbolCreado;
/*
    string linea1 = "Cortar Lechuga";
    string linea2 = "Cortar Tomate";
    string linea3 = "Mezclar";
    string linea4 = "Pelar Pepino";
    string linea5 = "Cortar";
    string linea6 = "Mezclar";
    string linea7 = "Pelar Cebolla";
    string linea8 = "Cortar";
    string linea9 = "Mezclar";
    string linea10 = "Add Aceite Oliva";
    string linea11 = "Add Vinagre De Vino";
    string linea12 = "Add Sal";
*/

    string linea1 = "Cortar Lechuga";
    string linea2 = "Cortar Tomate";
    string linea3 = "Mezclar";
    string linea4 = "Cortar Pepino";
    string linea5 = "Cortar Apio";
    string linea6 = "Mezclar";
    string linea7 = "Mezclar";
    rellenarMapAriedades(ariedades);
    stoTree(linea1);
    stoTree(linea2);
    stoTree(linea3);
    stoTree(linea4);
    stoTree(linea5);
    stoTree(linea6);
    stoTree(linea7);
  /*
    stoTree(linea8);
    stoTree(linea9);
    stoTree(linea10);
    stoTree(linea11);
    stoTree(linea12);
    */

    cout << "Esta la pila vacia??: " << stackOfTrees.empty() << endl;
    ArbolBinario<string> ResultadoFinal = stackOfTrees.top();
    cout << "El resultado del arbol final es: \n";
  //  cout << ResultadoFinal << endl << endl;
     ResultadoFinal.RecorridoPostOrden(cout);

}
