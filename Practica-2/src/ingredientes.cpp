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

  //---------------------------------------------------------------------------------
  //---------------------------------------------------------------------------------
  //METODOS NECESARIOS PARA CALCULAR LA ESTADISTICA
  //DE UN TIPO DE INGREDIENTE
  //---------------------------------------------------------------------------------
  //---------------------------------------------------------------------------------
  void Ingredientes::getEstadistica(const string tipo){
    Ingredientes ingredientes_tipo = getIngredienteTipo(tipo);
    float proCal, proHc, proProt, proGra, proFi,
          desCal, desHc, desProt, desGra, desFi= 0;
    VD<Ingrediente> maximos;
    VD<Ingrediente> minimos;
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

  float Ingredientes::getPromedio(const VD<int> &datosIng){
    float promedioMacro = 0;
    for(int i = 0; i < datosIng.size(); i++)
      promedioMacro += datosIng[i];

    if(datosIng.size()!=0)
      promedioMacro = promedioMacro/datosIng.size();

    return promedioMacro;
  }

  float Ingredientes::getDesviacion(const VD<int> &datosIng){
    float promedioDatos = getPromedio(datosIng);
    VD<int> aux = datosIng;

    for(int i = 0; i < aux.size(); i++)
      aux[i] = (aux[i]-promedioDatos)*(aux[i]-promedioDatos);

    float resultado = getPromedio(aux);

    return sqrt(resultado);
  }

  VD<Ingrediente> Ingredientes::getMaximos(const Ingredientes & ing){
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
    VD<Ingrediente> aux;
    aux.Insertar(ing[iCalorias],0);
    aux.Insertar(ing[iHc],1);
    aux.Insertar(ing[iProteinas],2);
    aux.Insertar(ing[iGrasas],3);
    aux.Insertar(ing[iFibra],4);
    return aux;
  }

  VD<Ingrediente> Ingredientes::getMinimos(const Ingredientes &ing){
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


    VD<Ingrediente> aux2;
    aux2.Insertar(ing[iCalorias],0);
    aux2.Insertar(ing[iHc],1);
    aux2.Insertar(ing[iProteinas],2);
    aux2.Insertar(ing[iGrasas],3);
    aux2.Insertar(ing[iFibra],4);

    return aux2;
}
