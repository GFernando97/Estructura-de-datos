/**
 * @file receta.cpp
 * @brief Implementación de la clase receta::receta.
 */
#include "receta.h"
#include "ingredientes.h"
#include "color.h"
#include <string>

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

  while(!iss.eof() ){
    getline(iss, subcadena, ';');
    unsigned int cantidad;
    string nombre;
    istringstream issSplitter(subcadena);
      while(!issSplitter.eof()){
        getline(issSplitter, palabraSuelta, ' ');
        if(!palabraSuelta.empty())
          palabrasAlmacenadas.push_back(palabraSuelta);
      }

      unsigned int lastIter =  palabrasAlmacenadas.size()-2;
      for(unsigned int i = 0; i < palabrasAlmacenadas.size()-1; i++){
          if(i ==lastIter ){
            nombre += palabrasAlmacenadas[i];
          }
          else nombre +=  palabrasAlmacenadas[i]+" " ;
        }

        if(palabrasAlmacenadas[palabrasAlmacenadas.size()-1] != "")
          cantidad = stoul(palabrasAlmacenadas[palabrasAlmacenadas.size()-1], nullptr, 10);

        else
          cantidad = stoul(palabrasAlmacenadas[palabrasAlmacenadas.size()-2], nullptr, 10);


      tempPair.first =  nombre;
      tempPair.second = cantidad;


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


void receta::calcularNutrientes(const ingredientes &all){
  string nombreAux;
  float cantidad;
  const float valorDefecto = 100.0;
  float resultadoCal = 0;
  float resultadoHc = 0;
  float resultadoGra = 0;
  float resultadoPr = 0;
  float resultadoFib = 0;

  for(receta::const_iterator cit = cbegin(); cit != cend(); ++cit){
    nombreAux = (*cit).first;
    cantidad = (*cit).second;
    ingrediente ing=all.get(nombreAux);

    resultadoCal = resultadoCal + ((ing.getCalorias()*cantidad)/valorDefecto);
    resultadoHc = resultadoHc + ((ing.getHc()*cantidad)/valorDefecto);
    resultadoGra = resultadoGra + ((ing.getGrasas()*cantidad)/valorDefecto);
    resultadoPr = resultadoPr + ((ing.getProteinas()*cantidad)/valorDefecto);
    resultadoFib = resultadoFib + ((ing.getFibra()*cantidad)/valorDefecto);
  }

   this->setCalorias(resultadoCal);
   this->setHc(resultadoHc);
   this->setGrasas(resultadoGra);
   this->setProteinas(resultadoPr);
   this->setFibra(resultadoFib);
   calcularRazon();
}

void receta::imprimeValNutricionales()const{
  cout << "Valores nutricionales de la receta " << *this << " son: " << endl;
  cout << "Calorias " << getCalorias() << "\tHidratos de cab.\t" << getHc()
       << "\tProteinas\t" << getProteinas() << "\tGrasas\t" << getGrasas()
       << "\tFibra\t" << getFibra() << endl << endl;
}

void receta::calcularRazon(){
  float nuevoValor = this->getProteinas()/this->getHc();
  this->setRazon(nuevoValor);
}

void receta::imprimeInfoReceta()const{
  cout <<FBLU("CODE:")<<getCode()<<"  "
       <<FBLU("NOMBRE:")<<getNombre()<<"  "
       <<FBLU("PLATO:")<<getPlato()<<endl<<endl;

  cout <<UNDL(BOLD("Ingredientes:"))<<endl<<endl;
  receta::const_iterator cit;
  for(cit=cbegin(); cit!=cend(); ++cit){
    cout <<"\t"<<(*cit).first <<" "<<(*cit).second<<endl;
  }
  cout <<endl;
  cout <<UNDL(BOLD("Informacion Nutricional:"))<<endl<<endl;
  cout <<"\tCalorias:"<<getCalorias()<<endl;
  cout <<"\tHidratos de Carbono:"<<getHc()<<endl;
  cout <<"\tGrasas:"<<getGrasas()<<endl;
  cout <<"\tProteina:"<<getProteinas()<<endl;
  cout <<"\tFibra:"<<getFibra()<<endl<<endl;

  cout <<UNDL(BOLD("Pasos a seguir:"))<<endl<<endl;
  cout <<"PASOS A SEGUIR TODAVIA SIN IMPLEMENTAR\n";
}
