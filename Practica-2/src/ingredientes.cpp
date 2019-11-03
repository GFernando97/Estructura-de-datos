/**
 * @file ingredientes.cpp
 * @brief Implementación de la clase @c ingredientes::ingredientes.
 */
#include "ingredientes.h"
#include "ingrediente.h"
#include "VD.h"

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

  void ingredientes::ordenarPorNombre(){
    ingrediente aux;

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

  ingredientes::ingredientes(const ingredientes &ing){
    Clear();
    Copiar(ing);
  }

  ingredientes ingredientes::getingredienteTipo(string tipo) const{
    ingredientes ingredientesTipo;

    for(int i = 0; i < datos.size(); i++){
      if(datos[i].getTipo() == tipo)
        ingredientesTipo.addingrediente(datos[i]);
    }

    return ingredientesTipo;
  }

  void ingredientes::addingrediente(const ingrediente & ing){
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

  void ingredientes::deleteingrediente(ingrediente &ing){
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

  void ingredientes::actualizarPosDatosInsertar(int desde){

    for(int i =0; i< indice.size(); i++ ){
      if(indice[i]>=desde){
        this->indice[i]++;
      }
    }
  }

  void ingredientes::actualizarPosDatosBorrar(int desde){
    for(int i = 0; i< indice.size(); i++){
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

  VD<string> ingredientes::getTipos(){
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

  ingrediente ingredientes:: get(string nombreIng){
    ingrediente vacio;
    for(int i = 0; i < datos.size(); i++){
      if(datos[i].getNombre()== nombreIng){
        vacio = datos[i];
      }
    }

    return vacio;
  }

  void ingredientes::borrar(string nombreIng){
    pair <bool, int> estaEnPos = estaEnDatos(nombreIng);
    int pos = estaEnPos.second;
    pair <bool,int> estaEnPosIndice = estaEnIndice(pos);

    if(estaEnPos.first == true){
      datos.Borrar(estaEnPos.second);
      indice.Borrar(estaEnPosIndice.second);
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
      for (int i = 0; i < indice.size(); i++){
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
    ingredientes ingredientes_tipo = getingredienteTipo(tipo);
    float proCal, proHc, proProt, proGra, proFi,
          desCal, desHc, desProt, desGra, desFi= 0;
    VD<ingrediente> maximos;
    VD<ingrediente> minimos;
    VD<int> datosCalorias;
    VD<int> datosHc;
    VD<int> datosProteinas;
    VD<int> datosGrasas;
    VD<int> datosFibra;

    for(int i = 0; i < ingredientes_tipo.size(); i++){
      datosCalorias.Insertar(ingredientes_tipo[i].getCalorias(),i);
      datosHc.Insertar(ingredientes_tipo[i].getHc(),i);
      datosProteinas.Insertar(ingredientes_tipo[i].getProteinas(),i);
      datosGrasas.Insertar(ingredientes_tipo[i].getGrasas(),i);
      datosFibra.Insertar(ingredientes_tipo[i].getFibra(),i);
    }

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

  float ingredientes::getPromedio(const VD<int> &datosIng){
    float promedioMacro = 0;
    for(int i = 0; i < datosIng.size(); i++)
      promedioMacro += datosIng[i];

    if(datosIng.size()!=0)
      promedioMacro = promedioMacro/datosIng.size();

    return promedioMacro;
  }

  float ingredientes::getDesviacion(const VD<int> &datosIng){
    float promedioDatos = getPromedio(datosIng);
    VD<int> aux = datosIng;

    for(int i = 0; i < aux.size(); i++)
      aux[i] = (aux[i]-promedioDatos)*(aux[i]-promedioDatos);

    float resultado = getPromedio(aux);

    return sqrt(resultado);
  }

  VD<ingrediente> ingredientes::getMaximos(const ingredientes & ing){
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
    VD<ingrediente> aux;
    aux.Insertar(ing[iCalorias],0);
    aux.Insertar(ing[iHc],1);
    aux.Insertar(ing[iProteinas],2);
    aux.Insertar(ing[iGrasas],3);
    aux.Insertar(ing[iFibra],4);
    return aux;
  }

  VD<ingrediente> ingredientes::getMinimos(const ingredientes &ing){
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


    VD<ingrediente> aux2;
    aux2.Insertar(ing[iCalorias],0);
    aux2.Insertar(ing[iHc],1);
    aux2.Insertar(ing[iProteinas],2);
    aux2.Insertar(ing[iGrasas],3);
    aux2.Insertar(ing[iFibra],4);

    return aux2;
}
