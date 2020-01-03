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

void instrucciones::setIngredientesIncluidos(const vector<string> &ing){
  this->ingrIncluidos = ing;
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
      cout << "\n\nNueva linea\n";
      getline(iss, nombreAccion, ' ');
      getline(iss, ingredienteAccion1, '\n');
      cout << "Nombre de la accion: " << nombreAccion << endl;
      cout << "Nombre del ingrediente: " << ingredienteAccion1 << endl;
      cout << "Tamaño de la pila antes de interaccion:" << stackOfTrees.size() << endl;
      cout << "Se ha realizado la accion:\n";
      if(nombreAccion != ""){
        ariedadAccion = inst.acc.getAriedad(nombreAccion);
        ArbolBinario<string> auxTree(nombreAccion);

        if(ariedadAccion=="1"){
          if(!ingredienteAccion1.empty()){
            auxTree.Insertar_Hi(auxTree.getRaiz(), ingredienteAccion1);
            stackOfTrees.push(auxTree);
            //cout << "Tamaño de Pila ahora: " << stackOfTrees.size() << endl;
            cout << "Crear arbol con ingrediente incluido - Ariedad 1\n";
          }
          else{
            if(!stackOfTrees.empty()){
              cout << "Voy a usar arboles de la pila por falta de ing...\n";
              ArbolBinario<string> treeStack = stackOfTrees.top();
              stackOfTrees.pop();
              auxTree.Insertar_Hi(auxTree.getRaiz(), treeStack);
              stackOfTrees.push(auxTree);
              //cout << "Tamaño de Pila ahora: " << stackOfTrees.size() << endl;
              cout << "Crear arbol con un elemento de la pila - Ariedad 1\n";
            }
            else{
              cout << "Error en la pila. Terminar Programa!!!!";
              abort();
            }
          }
        }

        else if(ariedadAccion=="2"){

          if(!ingredienteAccion1.empty()){
            cout << "Interpreto que el ingrediente no esta vacio\n";
            istringstream iss2(ingredienteAccion1);
            vector<string> elementosCadena;
            cout << "Se van a separar los elementos de la cadena de ingredientes.\n";
            while(!iss2.eof()){
              string aux1;
              getline(iss2, aux1, ' ');
              elementosCadena.push_back(aux1);
            }

            bool ingrediente1lleno = false;
            bool ingrediente2lleno = false;
            string ingrediente1;
            string ingrediente2;

            for(int i = 0; i<elementosCadena.size(); i++){
              if(!ingrediente1lleno){
                if(ingrediente1.empty()){
                  ingrediente1 = elementosCadena[i];
                }
                else{
                  ingrediente1 = ingrediente1 + " " + elementosCadena[i];
                  cout << "Ingrediente 1 valores: " << ingrediente1 << endl;
                  cout << "Contenido en ingredientes: " << inst.containsIngr(ingrediente1) << endl;
                }

                if(inst.containsIngr(ingrediente1)){
                    ingrediente1lleno = true;
                  //  cout << "Se ha declarado que el ingrediente1 esta lleno\n";
                  //  cout << "Su valor es:" <<ingrediente1<<endl;
                }
              }

              else {
                if(ingrediente1lleno and !ingrediente2lleno){
                  if(ingrediente2.empty()){
                    ingrediente2 = elementosCadena[i];
                  }
                  else{
                  ingrediente2 = ingrediente2 + " " +elementosCadena[i];
                  //cout << "Ingrediente 2 valores: " << ingrediente2 << endl;
                  //cout << "Contenido en ingredientes: " << inst.containsIngr(ingrediente2) << endl;
                  }

                  if(inst.containsIngr(ingrediente2)){
                    ingrediente2lleno = true;
                    //cout << "Se ha declarado que el ingrediente2 esta lleno\n";
                    //cout << "Su valor es:" <<ingrediente2<<endl;
                  }
                }
              }
            }

            if(ingrediente1lleno and ingrediente2lleno){
               cout << "Ambos ingredientes estan ocupados, por ende se rellenaran sus valores.\n";
               cout << "Sus valores son: " << ingrediente1 << " Y " << ingrediente2 << endl;
               auxTree.Insertar_Hi(auxTree.getRaiz(), ingrediente1);
               auxTree.Insertar_Hd(auxTree.getRaiz(), ingrediente2);
               stackOfTrees.push(auxTree);
               cout << "Se ha creado un arbol con 2 ingredientes dados en la inst - Ariedad 2\n";
            }

            else{
                auxTree.Insertar_Hd(auxTree.getRaiz(), ingredienteAccion1);
                ArbolBinario<string> treeStack = stackOfTrees.top();
                stackOfTrees.pop();
                //cout << "Tamaño de Pila ahora: " << stackOfTrees.size() << endl << endl;
                auxTree.Insertar_Hi(auxTree.getRaiz(), treeStack);
                stackOfTrees.push(auxTree);
                cout << "Se ha creado un arbol con un ingrediente y con un arbol de la pila - Ariedad 2\n";
            }
          }
          else{
            cout << "Interpreto que el archivo de instrucciones esta vacio\n";
            if(!stackOfTrees.empty()){
              ArbolBinario<string> treeStack = stackOfTrees.top();
              stackOfTrees.pop();

              auxTree.Insertar_Hd(auxTree.getRaiz(), treeStack);
              treeStack = stackOfTrees.top();
              stackOfTrees.pop();
              auxTree.Insertar_Hi(auxTree.getRaiz(), treeStack);
              stackOfTrees.push(auxTree);
              cout << "Se ha creado un arbol con dos arboles de la pila - Ariedad 2\n";

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
  //cout << "\n\nTamaño de la pila despues de terminar: " << stackOfTrees.size() << endl;
  inst.datos = stackOfTrees.top();
  stackOfTrees.pop();

  return i;
}

bool instrucciones::containsIngr(const string &ingr){
  for(int i =0; i < ingrIncluidos.size(); i++){
      if(ingrIncluidos[i] == ingr){
        return true;
      }
  }
  return false;
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
