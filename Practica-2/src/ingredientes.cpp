#include "ingredientes.h"


using namespace std;

  pair<bool, int>Ingredientes::estaEnIndice(int posEnDatos){
    int tam = indice.size();
    int inicio = 0;
    int fin = tam;
    pair<bool,int> encontradoEnPos;

    while(inicio < fin){
      int mitad = (inicio + fin)/2;

      if(indice[mitad] == posEnDatos){
        encontradoEnPos.first = true;
        encontradoEnPos.second = mitad;
      }

      else{
        if(datos[mitad].getTipo().compare(datos[posEnDatos].getTipo())>= 0)
          inicio = mitad+1;

        else fin = mitad;
      }

      encontradoEnPos.first = false;
      encontradoEnPos.second = inicio;
    }

    return encontradoEnPos;
  }

  pair <bool, int> Ingredientes::estaEnDatos(Ingrediente &ing){
    int tam = datos.size();
    int inicio = 0;
    int fin = tam;
    pair<bool,int> encontradoEnPos;

    while(inicio < fin){
      int mitad = (inicio + fin)/2;
      if(datos[mitad] == ing){
        encontradoEnPos.first = true;
        encontradoEnPos.second = mitad;
      }

      else{
        if(ing.getNombre().compare(datos[mitad].getNombre()) > 0)
          inicio = mitad+1;

        else fin = mitad;
      }

      encontradoEnPos.first = false;
      encontradoEnPos.second = inicio;

    }
    return encontradoEnPos;

  }


  void Ingredientes::Copiar(const Ingredientes &ing){
    Clear();

    datos = ing.datos;
    indice = ing.indice;

  }

  void Ingredientes::Clear(){
  /*  delete this->datos);
    delete this->indice);*/
  }

  void Ingredientes::ordenarPorNombre(){
    Ingrediente aux;

      for(int i = 0; i < datos.size()-1; i++){
        for(int j= 0; j < datos.size()-i-1; j++){
          if(datos[j].getNombre().compare(datos[j+1].getNombre()) > 0){
            aux = datos[j+1];
            datos.Borrar(j+1);
            datos.Insertar(datos[j], j+1);
            datos.Borrar(j);
            datos.Insertar(aux, j);
          }
        }
      }
  }

  Ingredientes::Ingredientes(const Ingredientes &ing){
    Clear();
    Copiar(ing);
  }

  Ingredientes Ingredientes::getIngredienteTipo(string tipo){
    Ingredientes ingredientesTipo;

    ingredientesTipo.Clear();
    for(int i = 0; i < datos.size(); i++){
      if(datos[i].getTipo() == tipo){}
        ingredientesTipo.addIngrediente(datos[i]);
    }

    return ingredientesTipo;
  }


  void Ingredientes::addIngrediente(Ingrediente &ing){
    pair<bool, int> posDatos = estaEnDatos(ing);
    pair<bool, int> posIndice = estaEnIndice(posDatos.second);

    if(posDatos.first == false){
      datos.Insertar(ing, posDatos.second);
      indice.Insertar(posDatos.second, posIndice.second);
    }

    else if(posIndice.first == true ){
      if(datos[posIndice.second].getTipo() != ing.getTipo())
        datos.Insertar(ing, posIndice.second + 1);
    }
  }

  void Ingredientes::deleteIngrediente(Ingrediente &ing){
    pair <bool, int> estaEnPos = estaEnDatos(ing);
    int pos;

    if(estaEnPos.first = true){
      pos = estaEnPos.second;
      datos.Borrar(pos);

      if(estaEnIndice(pos).first == true){
        pos = estaEnIndice(pos).second;
        indice.Borrar(pos);
      }
    }
  }
//-------------------------------------------------------------------
//                GETTERS Y SETTERS SE IMPLEMENTARÁN AQUÍ
//
//
//
//
//
//
//
//-------------------------------------------------------------------

  Ingrediente Ingredientes:: get(string nombreIng){
    for(int i = 0; i < datos.size(); i++)
      if(datos[i].getNombre()== nombreIng)
        return datos[i];
  }

  void Ingredientes::borrar(string nombreIng){
    Ingrediente ing = get(nombreIng);
    pair <bool, int> estaEnPos = estaEnDatos(ing);
    int pos;

    if(estaEnPos.first == true){
      pos = estaEnPos.second;
      datos.Borrar(pos);

      if(estaEnIndice(pos).first == true){
        pos = estaEnIndice(pos).second;
        indice.Borrar(pos);
      }
    }
  }

  Ingredientes& Ingredientes::operator=(const Ingredientes &lista){
    if(this != &lista){
      Clear();
      Copiar(lista);
    }
    return *this;
  }

  ostream &operator <<(ostream &o, const Ingredientes &lista){
    int n = lista.size();

    for(int i = 0; i < n; i++){
      o << lista.datos[i].getNombre() << ";"
         << lista.datos[i].getCalorias() << ";"
         << lista.datos[i].getHc() << ";"
         << lista.datos[i].getProteinas() << ";"
         << lista.datos[i].getGrasas() << ";"
         << lista.datos[i].getFibra() << ";"
         << lista.datos[i].getTipo() << endl;
    }

    return o;
  }

  istream &operator>>(istream&i, Ingredientes &lista){
    string linea;
    Ingrediente ingAux;
    string nombre, tipo, calorias, hc, proteinas, grasa, fibra;

    getline(i, linea, '\n');
    while(!i.eof()){
      getline(i,linea,'\n');

        stringstream aux(linea);
        getline(aux, nombre,';');
        getline(aux,calorias,';');
        getline(aux,hc,';');
        getline(aux,proteinas,';');
        getline(aux,grasa,';');
        getline(aux,fibra,';');
        getline(aux,tipo);

        ingAux.setNombre(nombre);
        ingAux.setCalorias(stoi(calorias, nullptr, 10));
        ingAux.setHc(stoi(hc, nullptr, 10));
        ingAux.setProteinas(stoi(proteinas, nullptr, 10));
        ingAux.setGrasas(stoi(grasa, nullptr, 10));
        ingAux.setFibra(stoi(fibra, nullptr,10));
        ingAux.setTipo(tipo);

        lista.addIngrediente(ingAux);
    }

    return i;
  }

    void Ingredientes::ImprimirPorTipo(ostream &out){

      for (int i = 0; i < indice.size(); i++){
        cout << datos[indice[i]] << endl;
      }

    }
