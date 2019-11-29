/**
 * @file receta.cpp
 * @brief Implementación de la clase receta::receta.
 */
#include "receta.h"
using namespace std;


void receta::copiar(const receta &rec){
  setCode(rec.getCode());
  setPlato(rec.getPlato());
  setNombre(rec.getNombre());
  setIngs(rec.getIngs());
}


list<pair <string,unsigned int>> receta::extraerIngredientes(const string &cadena){
  istringstream iss(cadena);
  string subcadena;
  string palabraSuelta;

  vector<string> palabrasAlmacenadas;
  list<pair<string, unsigned int>> tempList;
  pair<string,unsigned int> tempPair;

  while(!iss.eof()){
    getline(iss, subcadena, ';');
    unsigned int cantidad;
    string nombre;
    istringstream issSplitter(subcadena);

      while(!issSplitter.eof()){
        getline(issSplitter, palabraSuelta, ' ');
        palabrasAlmacenadas.push_back(palabraSuelta);
      }

      unsigned int lastIter =  palabrasAlmacenadas.size()-2;
      for(unsigned int i = 0; i < palabrasAlmacenadas.size()-1; i++){
          if(i ==lastIter ){
            nombre += palabrasAlmacenadas[i];
          }
          else nombre +=  palabrasAlmacenadas[i]+" " ;
        }
    //    cout << "la palabra que almaceno es: " <<
      //  palabrasAlmacenadas[palabrasAlmacenadas.size()-2] << endl;

        if(palabrasAlmacenadas[palabrasAlmacenadas.size()-1] != "")
          cantidad = stoul(palabrasAlmacenadas[palabrasAlmacenadas.size()-1], nullptr, 10);

        else
          cantidad = stoul(palabrasAlmacenadas[palabrasAlmacenadas.size()-2], nullptr, 10);


    //  cout << "Cantidades añadidas: " << cantidad << endl;
      tempPair.first =  nombre;
      tempPair.second = cantidad;
  //    cout << cantidad << " " << nombre << endl;


      tempList.push_back(tempPair);
      palabrasAlmacenadas.clear();
      nombre.clear();
    }

    return tempList;
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


ostream &operator <<(ostream &o,  const receta &rec){
  o << rec.getCode() << ";"
    << rec.getPlato() << ";"
    << rec.getNombre() << ";";

    for(receta::const_iterator cit = rec.cbegin(); cit != rec.cend(); ++cit)
    if(cit == --rec.cend()){
      o << (*cit).first << " " <<(*cit).second;

    }
    else{
      o << (*cit).first << " " <<(*cit).second << ";";
    }

  return o;
}

istream &operator >>(istream &i, receta &rec){
  string code, plato, nombre, ings;

  getline(i, code,';');
  getline(i, plato,';');
  getline(i, nombre,';');
  getline(i,ings,'\n');

  list<pair <string, unsigned int>> listAux = rec.extraerIngredientes(ings);
  rec.setCode(code);
  rec.setPlato(stoul(plato, nullptr, 10));
  rec.setNombre(nombre);
  rec.setIngs(listAux);

return i;
}


float receta::calcularCalorias(ingredientes &allIngre){
  string ingrBusq;
  unsigned int cantidad;
  ingrediente ingAux;
  float resultado = 0;
    for(receta::const_iterator cit = cbegin(); cit != cend(); ++cit ){
      ingrBusq = (*cit).first;
      cantidad = (*cit).second;

      ingAux = allIngre.get(ingrBusq);
      resultado = resultado + ((ingAux.getCalorias()*cantidad)/100);
    }

    return resultado;
}

float receta::calcularHc(ingredientes &allIngre){
  string ingrBusq;
  unsigned int cantidad;
  ingrediente ingAux;
  float resultado = 0;
    for(receta::const_iterator cit = cbegin(); cit != cend(); ++cit ){
      ingrBusq = (*cit).first;
      cantidad = (*cit).second;

      ingAux = allIngre.get(ingrBusq);
      resultado = resultado + ((ingAux.getHc()*cantidad)/100);
    }

    return resultado;
}


float receta::calcularGrasas(ingredientes &allIngre){
  string ingrBusq;
  unsigned int cantidad;
  ingrediente ingAux;
  float resultado = 0;
    for(receta::const_iterator cit = cbegin(); cit != cend(); ++cit ){
      ingrBusq = (*cit).first;
      cantidad = (*cit).second;

      ingAux = allIngre.get(ingrBusq);
      resultado = resultado + ((ingAux.getGrasas()*cantidad)/100);
    }

    return resultado;
}

float receta::calcularProteinas(ingredientes &allIngre){
  string ingrBusq;
  unsigned int cantidad;
  float resultado = 0;
    for(receta::const_iterator cit = cbegin(); cit != cend(); ++cit ){
      ingrBusq = (*cit).first;
      cantidad = (*cit).second;

      ingrediente ingAux = allIngre.get(ingrBusq);
      resultado = resultado + ((ingAux.getProteinas()*cantidad)/100);
    }

    return resultado;
}

float receta::calcularFibra(ingredientes &allIngre){
  string ingrBusq;
  unsigned int cantidad;
  ingrediente ingAux;
  float resultado = 0;
    for(receta::const_iterator cit = cbegin(); cit != cend(); ++cit ){
      ingrBusq = (*cit).first;
      cantidad = (*cit).second;

      ingAux = allIngre.get(ingrBusq);
      resultado = resultado + ((ingAux.getFibra()*cantidad)/100);
    }

    return resultado;
}

void receta::calcularNutrientes(const ingredientes &allIngre){
  string ingrBusq;
  unsigned int cantidad;
  ingrediente ingAux;
  float resultadoCal, resultadoHc, resultadoGra, resultadoPr, resultadoFib = 0;

  for(receta::const_iterator cit = cbegin(); cit != cend(); ++cit){
    ingrBusq = (*cit).first;
    cantidad = (*cit).second;
    ingAux(allIngre.get(ingrBusq));
    resultadoCal = resultadoCal + ((ingAux.getCalorias()*cantidad)/100);
    resultadoHc = resultadoHc + ((ingAux.getHc()*cantidad)/100);
    resultadoGra = resultadoGra + ((ingAux.getGrasas()*cantidad)/100);
    resultadoPr = resultadoPr + ((ingAux.getProteinas()*cantidad)/100);
    resultadoFib = resultadoFib + ((ingAux.getFibra()*cantidad)/100);
   }

   this.setCalorias(resultadoCal);
   this.setHc(resultadoHc);
   this.setGrasas(resultadoGra);
   this.setProteinas(resultadoPr);
   this.setFibra(resultadoFib);
}
