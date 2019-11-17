/**
 * @file receta.cpp
 * @brief Implementación de la clase receta::receta.
 */
#include "receta.h"
using namespace std;


void receta::copiar(const receta &receta){
  setCode(receta.getCode());
  setPlato(receta.getPlato());
  setIngs(receta.getIngs());
}

receta::receta(const receta &original){
  copiar(original);
}

receta& receta::operator=(const receta &rec){
  if(this != &rec){
    copiar(rec);
  }
  return *this;
}
/*bool receta::operator==(const receta &rec){
  if(this->getTipo)
}*/

ostream& operator << (ostream &o,  const receta &rec){
  o << rec.getCode() << ";"
    << rec.getPlato() << ";"
    << rec.getNombre() << ";"
    << rec.getIngs() << endl;
}

istream& operator >> (istream &i, receta &rec){
  string code, plato, nombre, ings;

  getline(i, code,';');
  getline(i, plato,';');
  getline(i, nombre,';');
  getline(i,ings,'\n');

  rec.setCode(code);
  rec.setPlato(stoul(plato, nullptr, 10);
  rec.setNombre(nombre);
  rec.setIngs(extraerIngredientes(ings));


}

list<pair <string, unsigned int>> extraerIngredientes(const string &cadena){
istringstream iss(cadena);
string subcadena;
string palabraSuelta;

vector<string> palabrasAlmacenadas;
list<pair<string, unsigned int>> tempList;
pair<string,unsigned int> tempPair;

cout << cadena << endl;

while(!iss.eof()){
  getline(iss, subcadena, ';');
  unsigned int cantidad;
  string nombre;
  istringstream issSplitter(subcadena);

    while(!issSplitter.eof()){
      getline(issSplitter, palabraSuelta, ' ');
      palabrasAlmacenadas.push_back(palabraSuelta);
    }

    int lastIter =  palabrasAlmacenadas.size()-2;
    for(int i = 0; i < palabrasAlmacenadas.size()-1; i++){
        if(i ==lastIter ){
          nombre += palabrasAlmacenadas[i];
        }
        else nombre +=  palabrasAlmacenadas[i]+" " ;
      }

    cantidad = stoul(palabrasAlmacenadas[palabrasAlmacenadas.size()-1], nullptr, 10);

    tempPair.first =  nombre;
    tempPair.second = cantidad;
    cout << cantidad << " " << nombre << endl;


    tempList.push_back(tempPair);
    palabrasAlmacenadas.clear();
    nombre.clear();
  }

  return tempList;

}


}
