/**
 * @file ingredientes.cpp
 * @brief Implementación de la clase @c ingredientes::ingredientes.
 */
#include "ingredientes.h"
#include "ingrediente.h"

using namespace std;

  pair<bool, int>ingredientes::estaEnIndice(int posEnDatos) const{
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

  pair <bool, int> ingredientes::estaEnDatos(string nombreIng) const{
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

  void ingredientes::Copiar(const ingredientes &ing){
    Clear();

    datos = ing.datos;
    indice = ing.indice;

  }

  void ingredientes::Clear(){
  /*  delete this->datos);
    delete this->indice);*/
  }

//De momento, vamos a descartar esta función, puesto que no se usa para nada
/*
  void ingredientes::ordenarPorNombre(){
    ingrediente aux;

      for(int i = 0; i < datos.size()-1; i++){
        for(int j= 0; j < datos.size()-i-1; j++){
          if(datos[j].getNombre().compare(datos[j+1].getNombre()) > 0){
            aux = datos[j+1];
            datos.erase(j+1);
            datos.insert(datos[j], j+1);
            datos.erase(j);
            datos.insert(aux, j);
          }
        }
      }
  }
*/

  ingredientes::ingredientes(const ingredientes &ing){
    Clear();
    Copiar(ing);
  }

  ingredientes ingredientes::getIngredienteTipo(string tipo) const{
    ingredientes ingredientesTipo;

    for(unsigned int i = 0; i < datos.size(); i++){
      if(datos[i].getTipo() == tipo)
        ingredientesTipo.addingrediente(datos[i]);
    }

    return ingredientesTipo;
  }

  void ingredientes::addingrediente(const ingrediente & ing){
    pair<bool, int> posDatos = estaEnDatos(ing.getNombre());
    pair<bool, int> posIndice;

    if(posDatos.first == false){
      datos.insert(datos.begin()+posDatos.second, ing);

      actualizarPosDatosInsert(posDatos.second);
      posIndice = estaEnIndice(posDatos.second);
      indice.insert(indice.begin()+posIndice.second ,posDatos.second);
    }

    else if(posIndice.first == true ){

      if(datos[posDatos.second].getTipo() != ing.getTipo()){
        datos.insert( datos.begin()+posDatos.second ,ing);
        indice.insert(indice.begin()+posIndice.second, posDatos.second);
      }
    }


  }

  void ingredientes::deleteingrediente(ingrediente &ing){
    pair <bool, int> estaEnPos = estaEnDatos(ing.getNombre());
    int pos;

    if(estaEnPos.first == true){
      pos = estaEnPos.second;
      datos.erase(datos.begin()+pos);

      if(estaEnIndice(pos).first == true){
        pos = estaEnIndice(pos).second;
        indice.erase(indice.begin()+pos);
      }
    }
  }

  void ingredientes::actualizarPosDatosInsert(int desde){
    for(unsigned int i =0; i< indice.size(); i++ ){
      if(indice[i]>=desde){
        this->indice[i]++;
      }
    }
  }

  void ingredientes::actualizarPosDatosBorrar(int desde){
    for(unsigned int i = 0; i< indice.size(); i++){
      if(indice[i]>=desde){
        this->indice[i]--;
      }
    }
  }
//-------------------------------------------------------------------
//                GETTERS Y SETTERS SE IMPLEMENTARÁN AQUÍ
  void ingredientes::setNombreingrediente(int indice, string nuevoNombre){
    datos[indice].setNombre(nuevoNombre);
  }

  void ingredientes::setTipoingrediente(int indice, string nuevoTipo){
    datos[indice].setTipo(nuevoTipo);
  }

  void ingredientes::setCaloriasingrediente(int indice, int nuevoValor){
    datos[indice].setCalorias(nuevoValor);
  }

  void ingredientes::setHcingrediente(int indice, int nuevoValor){
    datos[indice].setHc(nuevoValor);
  }

  void ingredientes::setProteinasingrediente(int indice, int nuevoValor){
    datos[indice].setProteinas(nuevoValor);
  }

  void ingredientes::setGrasasingrediente(int indice, int nuevoValor){
    datos[indice].setGrasas(nuevoValor);
  }

  void ingredientes::setFibraingrediente(int indice, int nuevoValor){
    datos[indice].setFibra(nuevoValor);
  }

  vector<string> ingredientes::getTipos(){
    vector<string> aux;
    int indiceEnDatos;
    string Saux;

    vector<string>::iterator auxIt;
    vector<int>::const_iterator indIt;

    for(indIt = indice.cbegin(); indIt != indice.cend(); ++indIt){
      bool contains = false;
      indiceEnDatos = *indIt;
      Saux = datos[indiceEnDatos].getTipo();
      for(auxIt = aux.begin(); auxIt != aux.end() && !contains; ++auxIt){
        if(Saux == *auxIt){
          contains = true;
        }
      }

      if(!contains) aux.push_back(Saux);
    }
    return aux;
  }

  bool ingredientes::contains(const string &nombreIng){
     const_iterator it;
     bool contains = false;
     for(it = this->cbegin(); it!=this->cend(); ++it){
       if((*it).getNombre()==nombreIng){
        contains = true;
        return contains;
      }
    }

     return contains;
   }
//-------------------------------------------------------------------

  ingrediente ingredientes:: get(const string nombreIng)const{
    string nombreVacio = "";
    ingrediente vacio(nombreVacio, 0, 0, 0, 0, 0, nombreVacio);
    ingredientes::const_iterator it;

    for(it = this->cbegin(); it != this->cend(); ++it){
      if((*it).getNombre()==nombreIng){
        vacio = *it;
      }
    }
    return vacio;
  }

  void ingredientes::borrar(string nombreIng){
    pair <bool, int> estaEnPos = estaEnDatos(nombreIng);
    int pos = estaEnPos.second;
    pair <bool,int> estaEnPosIndice = estaEnIndice(pos);

    if(estaEnPos.first == true){
      datos.erase(datos.begin()+estaEnPos.second);
      indice.erase(indice.begin()+estaEnPosIndice.second);
      actualizarPosDatosBorrar(pos);
      }
  }

  ingredientes& ingredientes::operator=(const ingredientes &lista){
    if(this != &lista){
      Clear();
      Copiar(lista);
    }
    return *this;
  }

  ostream &operator <<(ostream &o, const ingredientes &lista){
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

  istream &operator>>(istream&i, ingredientes &lista){
    string linea;
    ingrediente ingAux;
    getline(i, linea, '\n');
    while(!i.eof()){
        i >> ingAux;
        lista.addingrediente(ingAux);
    }
    return i;
  }

  void ingredientes::ImprimirPorTipo(ostream &out){
      for (unsigned int i = 0; i < indice.size(); i++){
        out << datos[indice[i]]  << endl;
      }

    }

  //---------------------------------------------------------------------------------
  //---------------------------------------------------------------------------------
  //METODOS NECESARIOS PARA CALCULAR LA ESTADISTICA
  //DE UN TIPO DE ingrediente
  //---------------------------------------------------------------------------------
  //---------------------------------------------------------------------------------
  void ingredientes::getEstadistica(const string tipo){
    ingredientes ingredientes_tipo = getIngredienteTipo(tipo);
    float proCal, proHc, proProt, proGra, proFi,
          desCal, desHc, desProt, desGra, desFi= 0;
    vector<ingrediente> maximos;
    vector<ingrediente> minimos;
    vector<int> datosCalorias;
    vector<int> datosHc;
    vector<int> datosProteinas;
    vector<int> datosGrasas;
    vector<int> datosFibra;

    for(int i = 0; i < ingredientes_tipo.size(); i++){
      datosCalorias.insert(datosCalorias.begin()+i, ingredientes_tipo[i].getCalorias());
      datosHc.insert(datosHc.begin()+i, ingredientes_tipo[i].getHc());
      datosProteinas.insert(datosProteinas.begin()+i, ingredientes_tipo[i].getProteinas());
      datosGrasas.insert(datosGrasas.begin()+i, ingredientes_tipo[i].getGrasas());
      datosFibra.insert(datosFibra.begin()+i, ingredientes_tipo[i].getFibra());
    }

    desFi = getDesviacion(datosFibra);
    proCal = getPromedio(datosCalorias);
    proHc = getPromedio(datosHc);
    proProt = getPromedio(datosProteinas);
    proGra = getPromedio(datosGrasas);
    proFi = getPromedio(datosFibra);

    desCal = getDesviacion(datosCalorias);
    desHc = getDesviacion(datosHc);
    desProt = getDesviacion(datosProteinas);
    desGra = getDesviacion(datosGrasas);
    desFi = getDesviacion(datosFibra);

    maximos = getMaximos(ingredientes_tipo);
    minimos = getMinimos(ingredientes_tipo);


    cout << "Estadística____________________________" << endl;
    cout << "Tipo de alimento " << tipo << endl;
    cout << "Promedio +-Desviación" << endl;
    cout << "Calorías" << "\tHidratos de Carb." << "\tProteínas" << "\tGrasas" << "\tFibra" << endl;
    cout << proCal << "+-" << desCal << "\t"
         << proHc << "+-" << desHc << "\t"
         << proProt << "+-" << desProt << "\t"
         << proGra << "+-" << desGra << "\t"
         << proFi << "+-" << desFi << endl;

    cout << endl << "Maximos Valores" << endl;
    cout << "Calorías (Alimento)\tHidratos de Carb (Alimento)\tProteínas (Alimento)\tGrasas (Alimento)\tFibra (Alimento)" << endl;
    cout << maximos[0].getCalorias() << " " << maximos[0].getNombre() << "\t"
         << maximos[1].getHc() << " " << maximos[1].getNombre() << "\t"
         << maximos[2].getProteinas() << " " << maximos[2].getNombre() << "\t"
         << maximos[3].getGrasas() << " " << maximos[3].getNombre() << "\t"
         << maximos[4].getFibra() << " " << maximos[4].getNombre() << endl;

    cout << endl << "Mínimos Valores" << endl;
    cout << "Calorías (Alimento)\tHidratos de Carb (Alimento)\tProteínas (Alimento)\tGrasas (Alimento)\tFibra (Alimento)" << endl;
    cout << minimos[0].getCalorias() << " " << minimos[0].getNombre() << "\t"
         << minimos[1].getHc() << " " << minimos[1].getNombre() << "\t"
         << minimos[2].getProteinas() << " " << minimos[2].getNombre() << "\t"
         << minimos[3].getGrasas() << " " << minimos[3].getNombre() << "\t"
         << minimos[4].getFibra() << " " << minimos[4].getNombre() << endl;


  }

  float ingredientes::getPromedio(const vector<int> &datosIng){
    float promedioMacro = 0;
    for(unsigned int i = 0; i < datosIng.size(); i++)
      promedioMacro += datosIng[i];

    if(datosIng.size()!=0)
      promedioMacro = promedioMacro/datosIng.size();

    return promedioMacro;
  }

  float ingredientes::getDesviacion(const vector<int> &datosIng){
    float promedioDatos = getPromedio(datosIng);
    vector<int> aux = datosIng;

    for(unsigned int i = 0; i < aux.size(); i++)
      aux[i] = (aux[i]-promedioDatos)*(aux[i]-promedioDatos);

    float resultado = getPromedio(aux);

    return sqrt(resultado);
  }

  vector<ingrediente> ingredientes::getMaximos(const ingredientes & ing){
    int iCalorias = 0, iHc = 0, iProteinas = 0, iGrasas = 0, iFibra = 0;
    int maxCalorias = ing[0].getCalorias();
    int maxHc = ing[0].getHc();
    int maxProteinas = ing[0].getProteinas();
    int maxGrasas = ing[0].getGrasas();
    int maxFibra = ing[0].getFibra();

    for(int i = 1; i < ing.size(); i++){
      if(ing[i].getCalorias() > maxCalorias){
        maxCalorias = ing[i].getCalorias();
        iCalorias = i;
      }
      if(ing[i].getHc() > maxHc){
        maxHc = ing[i].getHc();
        iHc = i;
      }
      if(ing[i].getProteinas() > maxProteinas){
        maxProteinas = ing[i].getProteinas();
        iProteinas = i;
      }
      if(ing[i].getGrasas() > maxGrasas){
        maxGrasas = ing[i].getGrasas();
        iGrasas = i;
      }
      if(ing[i].getFibra() > maxFibra){
        maxFibra = ing[i].getFibra();
        iFibra = i;
      }
    }
    vector<ingrediente> aux;
    aux.insert(aux.begin(), ing[iCalorias]);
    aux.insert(aux.begin()+1, ing[iHc]);
    aux.insert(aux.begin()+2, ing[iProteinas]);
    aux.insert(aux.begin()+3, ing[iGrasas]);
    aux.insert(aux.begin()+4, ing[iFibra]);
    return aux;
  }

  vector<ingrediente> ingredientes::getMinimos(const ingredientes &ing){
    int iCalorias = 0, iHc = 0, iProteinas = 0, iGrasas = 0, iFibra = 0;
    int minCalorias = ing[0].getCalorias();
    int minHc = ing[0].getHc();
    int minProteinas = ing[0].getProteinas();
    int minGrasas = ing[0].getGrasas();
    int minFibra = ing[0].getFibra();

    for(int i = 1; i < ing.size(); i++){
      if(ing[i].getCalorias() < minCalorias){
        minCalorias = ing[i].getCalorias();
        iCalorias = i;
      }
      if(ing[i].getHc() < minHc){
        minHc = ing[i].getHc();
        iHc = i;
      }
      if(ing[i].getProteinas() < minProteinas){
        minProteinas = ing[i].getProteinas();
        iProteinas = i;
      }
      if(ing[i].getGrasas() < minGrasas){
        minGrasas = ing[i].getGrasas();
        iGrasas = i;
      }
      if(ing[i].getFibra() < minFibra){
        minFibra = ing[i].getFibra();
        iFibra = i;
      }
    }


    vector<ingrediente> aux2;
    aux2.insert(aux2.begin(), ing[iCalorias]);
    aux2.insert(aux2.begin()+1, ing[iHc]);
    aux2.insert(aux2.begin()+2, ing[iProteinas]);
    aux2.insert(aux2.begin()+3, ing[iGrasas]);
    aux2.insert(aux2.begin()+4, ing[iFibra]);

    return aux2;
}
