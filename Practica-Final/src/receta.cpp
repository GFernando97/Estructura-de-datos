/**
 * @file receta.cpp
 * @brief Implementación de la clase receta::receta.
 */
#include "receta.h"


void receta::copiar(const receta &rec){
  setCode(rec.getCode());
  setPlato(rec.getPlato());
  setNombre(rec.getNombre());
  setIngs(rec.getIngs());
  setInstrucciones(rec.getInstrucciones());
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
  imprimeInstrucciones();
  cout << endl << endl;
}

void receta::insertarInstrucciones(istream &i, const acciones &acc){
  instrucciones aux;
  aux.setAcciones(acc);
  i >> aux;

  this->setInstrucciones(aux);
}

string receta::BuscadorInstrucciones(const string &ruta){
  string fullNameFile = "/"+this->getCode()+"m.txt";
  string fullRoute = ruta+fullNameFile;

  ifstream fAux(fullRoute);
  if(!fAux){
    fAux.close();
    cout << "Fstream cerrado \n";
    return "Undefined";
  }
  else{
    fAux.close();
  return fullRoute;
  }
}

bool receta::contains(const string &nombreIngrediente)const{
  receta::const_iterator cit;

  for(cit=this->cbegin(); cit!=this->cend(); ++cit){
    if((*cit).first == nombreIngrediente){
      return true;
    }
  }
  return false;
}

void receta::imprimeInstrucciones()const{
  ArbolBinario<string> auxTree(this->getInstrucciones().getDatos());
  ArbolBinario<string>::postorden_iterador pit;
  string ingr1;
  string ingr2;
  string singleAcc;
  bool ingr1lleno = false;
  bool ingr2lleno = false;
  bool accionEncontrada = false;

  for(pit = auxTree.beginpostorden(); pit != auxTree.endpostorden(); ++pit){
    if(this->contains((*pit))){
      if(!ingr1lleno){
        ingr1 = (*pit);
        ingr1lleno = true;
      }
      else if(!ingr2lleno && ((*pit) != ingr1)){
        ingr2 = (*pit);
        ingr2lleno = true;
      }
    }
    else{
      if(this->getInstrucciones().contains((*pit))){
        singleAcc = (*pit);
        accionEncontrada = true;

      }
      if(accionEncontrada){
        if(ingr1lleno && ingr2lleno){
          cout << "\t"<< singleAcc << "  " << ingr1 << " " << ingr2 << endl;
          accionEncontrada = false;
        }
        else if(ingr1lleno && !ingr2lleno){
          cout << "\t"<< singleAcc << "  " << ingr1 << endl;
          accionEncontrada = false;
        }
        else if(!ingr1lleno && !ingr2lleno){
          cout << "\t"<< singleAcc << endl;
          accionEncontrada = false;
        }
        ingr2lleno = false;
        ingr1lleno = false;
        ingr1.clear();
        ingr2.clear();
        singleAcc.clear();
      }
    }
  }
}
