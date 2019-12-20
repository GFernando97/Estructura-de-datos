#include "recetas.h"
#include "color.h"
#include <iomanip>



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

//---------------------------modificar metodo de salida de recetas----------
/*
ostream &operator <<(ostream &o, recetas &rec){
  for(recetas::const_iterator cit = rec.cbegin(); cit != rec.cend(); ++cit){
    o << (*cit).first <<";" << (*cit).second << endl;
//  o << (*cit).second;
  }
  return o;
}


Por ejemplo para escribir con subrayado y en negrita podemos hacerlo
cout<<UNDL(BOLD("Información Nutricional:"))<<endl<<endl;
*/
ostream &operator <<(ostream &o, recetas &rec){
  for(recetas::const_iterator cit = rec.cbegin(); cit != rec.cend(); ++cit){
    o << std::left
      <<FBLU("CODE:")
      << std::setw(5)
      <<(*cit).first
      <<FBLU("NOMBRE:")
      << std::setw(5)
      <<((*cit).second).getNombre()
      <<FBLU("PLATO:")
      <<((*cit).second).getPlato()
      << std::right
      << std::setw(10)<<endl;
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

receta recetas::fusionaRecetas(const receta &firstRecipe, const receta &secondRecipe){
  receta newRecipe;
  string aEliminar = "\r";
  string code = "F_"+firstRecipe.getCode()+"_"+secondRecipe.getCode();
  string nombre = "Fusion "+firstRecipe.getNombre()+" Y "+secondRecipe.getNombre();
  unsigned int nPlato = firstRecipe.getPlato();
  list<pair<string,unsigned int>> newIngList;

  receta::const_iterator cit;
  list<pair<string, unsigned int>>::iterator iter;

  for(cit=firstRecipe.cbegin(); cit!=firstRecipe.cend(); ++cit){
    newIngList.push_back(*cit);
  }

  for(cit=secondRecipe.cbegin(); cit!=secondRecipe.cend(); ++cit){
  bool encontrado=false;
    for(iter=newIngList.begin(); iter!=newIngList.end()&&!encontrado; ++iter){
      if((*cit).first==(*iter).first){
        (*iter).second = (*iter).second + (*cit).second;
        encontrado=true;
      }
    }

    if(!encontrado){
      newIngList.push_back(*cit);
    }
  }

  newRecipe.setCode(code);
  newRecipe.setNombre(nombre);
  newRecipe.setPlato(nPlato);
  newRecipe.setIngs(newIngList);

  return newRecipe;
}
