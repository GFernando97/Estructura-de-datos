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
      mitad =(inicio + fin) / 2;
      if(indice[mitad] == posEnDatos){
        encontradoEnPos.first = true;
        encontradoEnPos.second = mitad;
        return encontradoEnPos;
      }

      else{
        if(datos[posEnDatos].getTipo().compare(datos[indice[mitad]].getTipo()) >= 0){
          if(datos[posEnDatos].getTipo().compare(datos[indice[mitad]].getTipo()) == 0){
            if(datos[posEnDatos].getNombre().compare(datos[indice[mitad]].getNombre()) <= 0){
              if(datos[posEnDatos].getTipo().compare(datos[indice[mitad-1]].getTipo()) == 0){
                if(datos[posEnDatos].getNombre().compare(datos[indice[mitad-1]].getNombre()) > 0){
                  encontradoEnPos.first = false;
                  encontradoEnPos.second = mitad;
                  return encontradoEnPos;
                }
                else fin = mitad;
              }
              else if(datos[posEnDatos].getTipo().compare(datos[indice[mitad-1]].getTipo()) > 0){
                encontradoEnPos.first = false;
                encontradoEnPos.second = mitad;
                return encontradoEnPos;
              }
              else inicio = mitad+1;
            }
            else inicio = mitad+1;
          }
          else inicio = mitad+1;
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

    if(posDatos.first == false){
      datos.Insertar(ing, posDatos.second);

      actualizarPosDatosInsertar(posDatos.second);
      posIndice = estaEnIndice(posDatos.second);
      indice.Insertar(posDatos.second, posIndice.second);
    }

    else if(posIndice.first == true ){

      if(datos[posDatos.second].getTipo() != ing.getTipo()){
        datos.Insertar(ing, posDatos.second);
        indice.Insertar(posDatos.second, posIndice.second);
      }
    }


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

  void Ingredientes::actualizarPosDatosInsertar(int desde){

    for(int i =0; i< indice.size(); i++ ){
      if(indice[i]>=desde){
        this->indice[i]++;
      }
    }
  }

  void Ingredientes::actualizarPosDatosBorrar(int desde){
    for(int i = 0; i< indice.size(); i++){
      if(indice[i]>=desde){
        this->indice[i]--;
      }
    }
  }
//-------------------------------------------------------------------
//                GETTERS Y SETTERS SE IMPLEMENTARÁN AQUÍ
  void Ingredientes::setNombreIngrediente(int indice, string nuevoNombre){
    datos[indice].setNombre(nuevoNombre);
  }

  void Ingredientes::setTipoIngrediente(int indice, string nuevoTipo){
    datos[indice].setTipo(nuevoTipo);
  }

  void Ingredientes::setCaloriasIngrediente(int indice, int nuevoValor){
    datos[indice].setCalorias(nuevoValor);
  }

  void Ingredientes::setHcIngrediente(int indice, int nuevoValor){
    datos[indice].setHc(nuevoValor);
  }

  void Ingredientes::setProteinasIngrediente(int indice, int nuevoValor){
    datos[indice].setProteinas(nuevoValor);
  }

  void Ingredientes::setGrasasIngrediente(int indice, int nuevoValor){
    datos[indice].setGrasas(nuevoValor);
  }

  void Ingredientes::setFibraIngrediente(int indice, int nuevoValor){
    datos[indice].setFibra(nuevoValor);
  }

  VD<string> Ingredientes::getTipos(){
    VD<string> aux;
    int contador = 0;
    string Saux;

    for(int i = 0; i < indice.size(); i++){
      Saux = datos[indice[i]].getTipo();
      if(aux.Esta(Saux) == false){
        aux.Insertar(Saux, contador);
        contador++;
      }
    }

    return aux;
  }
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
    int pos = estaEnPos.second;
    pair <bool,int> estaEnPosIndice = estaEnIndice(pos);

    if(estaEnPos.first == true){
      datos.Borrar(estaEnPos.second);
      indice.Borrar(estaEnPosIndice.second);
      actualizarPosDatosBorrar(pos);
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
    return i;
  }

  void Ingredientes::ImprimirPorTipo(ostream &out){
      for (int i = 0; i < indice.size(); i++){
        out << datos[indice[i]]  << endl;
      }

    }

  void Ingredientes::getEstadistica(const string tipo){
    Ingredientes ingredientes_tipo = getIngredienteTipo(tipo);
    float prom_cal, prom_hid, prom_pro, prom_gras, prom_fib = 0;

    for(int i=0; i<ingredientes_tipo.size(); i++){
        prom_cal += ingredientes_tipo.getCaloriasIngrediente(i);
        prom_hid += ingredientes_tipo.getHcIngrediente(i);
        prom_pro += ingredientes_tipo.getProteinasIngrediente(i);
        prom_gras += ingredientes_tipo.getGrasasIngrediente(i);
        prom_fib += ingredientes_tipo.getFibraIngrediente(i);
    }

    prom_cal = prom_cal/ingredientes_tipo.size();
    prom_hid = prom_hid/ingredientes_tipo.size();
    prom_pro = prom_pro/ingredientes_tipo.size();
    prom_gras = prom_gras/ingredientes_tipo.size();
    prom_fib = prom_fib/ingredientes_tipo.size();

    cout << "Estadística____________________________" << endl;
    cout << "Tipo de alimento " << tipo << endl;
    cout << "Promedio +-Desviación" << endl;
    cout << "Calorías" << "\tHidratos de Carb." << "\tProteínas" << "\tGrasas" << "\tFibra" << endl;
    cout << prom_cal << "\t\t" << prom_hid << "\t\t" << prom_pro << "\t\t" << prom_gras << "\t\t" << prom_fib << endl;


  }
