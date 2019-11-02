#include "ingredientes.h"
#include "ingrediente.h"
#include "VD.h"

using namespace std;

  pair<bool, int>Ingredientes::estaEnIndice(int posEnDatos) const{
    int tam = indice.size();
    int inicio = 0;
    int fin = tam;
    int mitad;
    pair<bool,int> encontradoEnPos;
    while(inicio < fin){
      mitad = (inicio + fin) / 2;

      if(indice[mitad] == posEnDatos){
        encontradoEnPos.first = true;
        encontradoEnPos.second = mitad;
        return encontradoEnPos;
      }

      else{

        cout << datos[posEnDatos].getTipo() << " > " << datos[mitad].getTipo() << "?\n";
        if(datos[posEnDatos].getTipo().compare(datos[indice[mitad]].getTipo()) >= 0){
          inicio = mitad+1;

        }


        else fin = mitad;
      }

    }
    encontradoEnPos.first = false;
    encontradoEnPos.second = inicio;

    return encontradoEnPos;
  }

  pair <bool, int> Ingredientes::estaEnDatos(string nombreIng) const{
    int tam = datos.size();
    int inicio = 0;
    int fin = tam;
    int mitad;
    pair<bool,int> encontradoEnPos;

    while(inicio < fin){
      mitad =(inicio + fin) / 2;

      if(datos[mitad].getNombre() == nombreIng){
        encontradoEnPos.first = true;
        encontradoEnPos.second = mitad;
        return encontradoEnPos;
      }

      else{
        if(nombreIng.compare(datos[mitad].getNombre()) >= 0)
          inicio = mitad+1;

        else  fin = mitad;

      }

    }
    encontradoEnPos.first = false;
    encontradoEnPos.second = inicio;
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

  Ingredientes Ingredientes::getIngredienteTipo(string tipo) const{
    Ingredientes ingredientesTipo;

    for(int i = 0; i < datos.size(); i++){
      if(datos[i].getTipo() == tipo)
        ingredientesTipo.addIngrediente(datos[i]);
    }

    return ingredientesTipo;
  }

  void Ingredientes::addIngrediente(const Ingrediente & ing){
    pair<bool, int> posDatos = estaEnDatos(ing.getNombre());
    pair<bool, int> posIndice;


    //////////////////////////////////////////////////////////////
    //cout << "esta en datos(tue-false)--" << posDatos.first << endl;

    //cout << "esta en datos--" << posDatos.second <<  endl;
    cout << "Insertar " << ing.getNombre() << " en el indice " << posDatos.second << endl;
    ////////////////////////////////////////////////////////////
    if(posDatos.first == false){
      datos.Insertar(ing, posDatos.second);
      actualizarPosDatos(posDatos.second);
      posIndice = estaEnIndice(posDatos.second);

      cout << "el tipo es: " << datos[posDatos.second].getTipo();
      //cout << "Esta en indice(true-false)--" << posIndice.first << endl;
      //cout << "Esta en indice--" << posIndice.second << endl;
      cout << " insertar el valor " << posDatos.second
           << " en pos " << posIndice.second << endl;
      cout << "--------------------------------------------------\n";
      //////////////////////////////////////////////////////////////////////

      indice.Insertar(posDatos.second, posIndice.second);
      for (int i = 0; i < indice.size(); i++){
        cout << datos[indice[i]]  << endl;
      }
      cout << "--------------------------------------------------\n\n";


    }

    else if(posIndice.first == true ){

      /*//////////////////////////////////////////////////////////////////////////
      cout << "Intentando insertar en datos...." << endl;
      ///////////////////////////////////////////////////////////////////*/
      if(datos[posDatos.second].getTipo() != ing.getTipo()){
        datos.Insertar(ing, posDatos.second);
        indice.Insertar(posDatos.second, posIndice.second);
      }
    }

    //cout << "Maria no es realidad " << datos.size() << "\n";
    //cout << "--------------------------------------------------\n";

  }

  void Ingredientes::deleteIngrediente(Ingrediente &ing){
    pair <bool, int> estaEnPos = estaEnDatos(ing.getNombre());
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

  void Ingredientes::actualizarPosDatos(int desde){

    cout <<"los datos de indice son ahora\n" ;
    for(int i =0; i< indice.size(); i++ ){
      if(indice[i]>=desde){
        this->indice[i]++;
      }
      cout << " para i:" << i << " el valor es: " <<indice[i] << endl;
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
    Ingrediente vacio;
    for(int i = 0; i < datos.size(); i++){
      if(datos[i].getNombre()== nombreIng){
        vacio = datos[i];
      }
    }

    return vacio;
  }

  void Ingredientes::borrar(string nombreIng){
    pair <bool, int> estaEnPos = estaEnDatos(nombreIng);
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
         << lista.datos[i].getTipo()  << endl;
    }

    return o;
  }

  istream &operator>>(istream&i, Ingredientes &lista){
    string linea;
    Ingrediente ingAux;

    getline(i, linea, '\n');
    while(!i.eof()){
        i >> ingAux;
        lista.addIngrediente(ingAux);

    }

    //lista.ordenarPorNombre();

    return i;
  }

    void Ingredientes::ImprimirPorTipo(ostream &out){
      for (int i = 0; i < indice.size(); i++){
        out << datos[indice[i]]  << endl;
      }

    }
