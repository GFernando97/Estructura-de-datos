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

list<receta> recetas::recetasAdecuadas(const float &caloriasMax){
  const int NRecetas = this->size()+1;
  std::vector<std::vector<float> >matrix(NRecetas);
  std::vector<receta> recetasAux;
  std::vector<float> CaloriasRec;
  std::vector<float> RazonRec;

  //Creamos la matriz que va a guardar los valores de Razon acumulados
  for(int i = 0; i < NRecetas; i++)
    matrix[i].resize(caloriasMax+1);
  //Inicializamos la primera fila y la primera columna a valores 0
  for(int i = 0; i < caloriasMax+1; i++)
    matrix[0][i] = 0.0;
  for(int i= 1; i < NRecetas; i++)
    matrix[i][0] = 0.0;

  //Ahora vamos a inicializar los vectores de calorias y razones
  //con sus respectivos Valores
  receta vacia;
  recetasAux.push_back(vacia);
  CaloriasRec.push_back(0);
  RazonRec.push_back(0);
  for(recetas::const_iterator cit = cbegin(); cit != cend(); ++cit){
    recetasAux.push_back((*cit).second);
    CaloriasRec.push_back((*cit).second.getCalorias());
    RazonRec.push_back((*cit).second.getRazon());
  }
  for(int i= 1; i < NRecetas; i++ ){
    for(int j = 1; j < caloriasMax+1; j++){
      if(CaloriasRec[i] <= j){
        if((RazonRec[i]+matrix[i-1][j-CaloriasRec[i]]) > matrix[i-1][j])
          matrix[i][j]= RazonRec[i]+matrix[i-1][j-CaloriasRec[i]];
        else
            matrix[i][j] = matrix[i-1][j];
      }
      else matrix[i][j] = matrix[i-1][j];
    }
  }

  vector<int> resultados;
  int i =  NRecetas-1;
  int j = caloriasMax-1;

  while(i > 0 and j >0){
    if(matrix[i][j] != matrix[i-1][j]){
      resultados.push_back(i);
      j = j - CaloriasRec[i];

      i--;
    }
    else i--;
  }

  list<receta> recetasSeleccionadas;

  for(unsigned int i = 0; i < resultados.size(); i++){
    bool encontrado = false;
    for(unsigned int j = 0; j < recetasAux.size() and !encontrado; j++){
      if(resultados[i] == j){
        recetasSeleccionadas.push_front(recetasAux[j]);
        encontrado = true;
      }
    }
  }

  return recetasSeleccionadas;
}
