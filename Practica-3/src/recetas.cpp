#include "recetas.h"

void recetas::copiar(const recetas &rec){

}

void recetas::insert(const receta &rec){
  map<string, receta>::iterator it;
  pair<string, receta> recetaux;
  recetaux.first = rec.getCode();
  recetaux.second = rec;
  it = datos.find(rec.getCode());

  if(it == datos.end()){
    datos.insert(recetaux);
  }

  else cout << "El código ya ha sido insertado" << endl;
}

void recetas::borrar(string &codigo){
  map<string,receta>::iterator it;
  it = datos.find(codigo);

  if(it != datos.end()){
    datos.erase(it);
  }
}

recetas::recetas(const recetas &rec){
  copiar(rec);
}

recetas& recetas::operator=(const recetas &rec){
  if(this != &rec){
    copiar(rec);
  }

  return *this;
}

ostream &operator <<(ostream &o, recetas &rec){
  for(recetas::const_iterator cit = rec.cbegin(); cit != rec.cend(); ++cit){
    o << (*cit).first <<";" << (*cit).second << endl;
//  o << (*cit).second;
  }
  return o;
}

istream &operator >>(istream &i, recetas &rec){
  string linea;
  receta recetaAux;

  while(!i.eof()){
    getline(i, linea, '\n');
    if(linea != ""){
      istringstream iss(linea);
      iss >> recetaAux;
      rec.insert(recetaAux);
    }
  }
  return i;
}

ostream &operator <<(ostream & os,const pair<const string, const receta> & d){
  os<< d.first << ";" << d.second;
  return os;
}
/*
list<receta> recetas::recetasAdecuadas(const float &caloriasMax){
    float caloriasActuales = 0;

    while(caloriasActuales < caloriasMax){

    }
}
*/
