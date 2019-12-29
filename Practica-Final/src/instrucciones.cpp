/**
 * @file instrucciones.cpp
 * @brief Implementación de la clase instrucciones::instrucciones
 */
#include "instrucciones.h"



void instrucciones::copiar(const instrucciones &inst){
  this->datos = inst.datos;
  this->acc = inst.acc;
}

void instrucciones::clear(){
  this->datos.clear();
}

instrucciones::instrucciones(const instrucciones &inst){
  this->clear();
  copiar(inst);
}

void instrucciones::setAcciones(const acciones &acc){
  this->acc=acc;
}

void instrucciones::setDatos(const ArbolBinario<string> &inst){
  this->datos=inst;
}

instrucciones& instrucciones::operator=(const instrucciones &inst){
  if(this!=&inst){
    copiar(inst);
  }

  return *this;
}

ostream &operator<<(ostream &o, const instrucciones &inst){
  o << inst.datos;
  return o;
}

istream &operator>>(istream &i, instrucciones &inst){
  stack<ArbolBinario<string>> stackOfTrees;
  string nombreAccion;
  string ariedadAccion;
  string ingredienteAccion1;
  string ingredienteAccion2;

  while(!i.eof()){
    string linea;
    getline(i, linea,'\n');
    istringstream iss(linea);
    while(!iss.eof()){
      //cout << "Nueva linea\n\n";
      getline(iss, nombreAccion, ' ');
      getline(iss, ingredienteAccion1, '\n');
      //cout << "Nombre de la accion: " << nombreAccion << endl;
    //  cout << "Nombre del ingrediente: " << ingredienteAccion1 << endl;
      if(nombreAccion != ""){
        ariedadAccion = inst.acc.getAriedad(nombreAccion);
        ArbolBinario<string> auxTree(nombreAccion);

        if(ariedadAccion=="1"){
          if(!ingredienteAccion1.empty()){
            auxTree.Insertar_Hi(auxTree.getRaiz(), ingredienteAccion1);
            stackOfTrees.push(auxTree);
            //cout << "Tamaño de Pila ahora: " << stackOfTrees.size() << endl;

          }

          else{
            if(!stackOfTrees.empty()){
            //  cout << "Voy a usar arboles de la pila por falta de ing...\n";
              ArbolBinario<string> treeStack = stackOfTrees.top();
              stackOfTrees.pop();
              auxTree.Insertar_Hi(auxTree.getRaiz(), treeStack);
              stackOfTrees.push(auxTree);
            //  cout << "Tamaño de Pila ahora: " << stackOfTrees.size() << endl;

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
            ArbolBinario<string> treeStack = stackOfTrees.top();
            stackOfTrees.pop();
          //  cout << "Tamaño de Pila ahora: " << stackOfTrees.size()<< endl;
            auxTree.Insertar_Hi(auxTree.getRaiz(), treeStack);
            stackOfTrees.push(auxTree);
          //  cout << "Tamaño de Pila ahora: " << stackOfTrees.size() << endl;


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
            //  cout << "Tamaño de Pila ahora: " << stackOfTrees.size() << endl;

            }
            else{
              cout << "Error en la pila. Terminar Programa!!!!";
              abort();
            }
          }
        }
      }
      nombreAccion.clear();
      ingredienteAccion1.clear();
      ingredienteAccion2.clear();
    }
    iss.clear();
  }
//  cout << "\n\nTamaño de la pila despues de terminar: " << stackOfTrees.size() << endl;
  inst.datos = stackOfTrees.top();
  stackOfTrees.pop();

  return i;
}


/*
string stringCleaner(string cadena_original,string cadena_a_eliminar){
	string linea(cadena_original);
  while(linea.find_first_of(cadena_a_eliminar) != std::string::npos){
		linea.erase(linea.find_first_of(cadena_a_eliminar),cadena_a_eliminar.length());
	}

	return linea;
}
*/
