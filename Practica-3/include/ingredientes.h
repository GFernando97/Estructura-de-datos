/**
 * @file ingredientes.h
 *
 * @brief Archivo cabecera de la clase @c ingredientes::ingredientes
 */
#ifndef _ingredientes_
#define _ingredientes_

#include <iostream>
#include <fstream>
#include <utility>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include "ingrediente.h"


using namespace std;
/**
 * @brief Clase que representa un conjunto de ingredientes.
 *
 * Esta clase representa un conjunto de ingredientes valiéndose de dos vectores de la stl @c vector.
 * Los ingredientes se mantienen ordenados por nombre
 * en el primer vector y por nombre y tipo en el segundo.
 *
 */
class ingredientes{
private:

 /**
  * @brief Vector que almacena los ingredientes.
  * Este vector almacena todos los objetos @a ingrediente que maneja la clase
  *
  * Los ingredientes que contiene se encuentran ordenados por orden alfabético de
  * nombre.
  **/
  vector<ingrediente> datos;

  /**
	* @brief Vector de índices.
	* Este vector contiene enteros que apuntan a posiciones de @a datos.
  * En este vector se mantienen los ingredientes ordenados por orden alfabético
  * pero por el tipo.
	**/
  vector<int> indice;

  /**
  * @brief Metodo que comprueba si una posicion del vector primario daots se
  * encuentra en el vector de indices.
  * @param posEnDatos posicion que se va a comprobar
  * @return si ha encontrado el valor, va a devolver un pair con el valor true y
  * el valor entero en el cual se encuentra la posicion deseada del vector primario.
  * @return si no ha encontrado el valor, va a devolver un pair con false y el valor
  * mas adecuado en el cual insertar dicha posicion de forma que se mantengan ambos órdenes.
  **/
  pair<bool, int> estaEnIndice(int posEnDatos) const;

  /**
  * @brief Metodo que comprueba si un ingrediente se encuentra insertado en el vector
  * principal datos.
  * @param nombreIng nombre del ingrediente a comprobar.
  * @return si ha encontrado el ingrediente, va a devolver un pair con el valor true y
  * el valor entero en el cual se encuentra el ingrediente.
  * @return si no ha encontrado el ingrediente, va a devolver un pair con el valor
  * false y el valor de la posidicon mas adecuada en la que insertar el
  * ingrediente para mantener el orden.
  *
  **/
  pair<bool, int> estaEnDatos(string nombreIng) const;

  /**
  * @brief Copia los valores de un objeto en el acutal
  * @param ing Ingrediente cuyos valores van a ser copiados.
  **/
  void Copiar(const ingredientes & ing);

  /**
  * @brief Elimina los elementos de ingredientes.
  * @post el resultado es un objeto Ingrediente vacío.
  **/
  void Clear();

  /**
  * @brief Ordena los valores de datos por nombre en orden alfabético.
  * Método implementado- pero no usado hasta el momento.
  * @post Un vector de datos ordenado alfabéticamente.

  void ordenarPorNombre();
  **/

public:

  /**
  * @brief constructor vacío de la Clase
  * @post crea un objeto ingrediente completamente vacío.
  **/
  ingredientes(){}

  /**
  * @brief constructor de copia de la Clase
  * @param objeto que va a ser copiado.
  * @post Ahora en el Objeto Ingredientes actual, se encuentran
  * los valores del objeto copiado.
  **/
  ingredientes(const ingredientes &ing);

  /**
  * @brief metodo get de obtención de ingredientes dato un tipo determinado
  * @param tipo  tipo de ingrediente sobre el cual se van a obtener los ingredientes.
  * @pre el tipo de ingrediente debe existir dentro de los ingredientes
  * almacenados en datos.
  * @return Nuevo objeto ingrediente que contiene unicamente los ingedientes de un tipo
  * determinado
  **/
  ingredientes getIngredienteTipo(string tipo) const;

  /**
  * @brief Metodo para introducir un nuevo ingrediente en los vectores
  * datos e indices.
  * @param ing ingrediente que se va a introducir
  * @post Este metodo introduce el ingrediente tanto en el vector de datos
  * como en el de indices de forma que estos mantengan el orden establecido.
  **/
  void addingrediente(const ingrediente & ing);

  /**
  * @brief Metodo pra eliminar un ingrediente tanto del vector principal de datos
  * como en el de indices.
  * @param ing ingrediente que se va a intentar eliminar.
  * @post Este metodo elimina un ingrediente de forma que ambos vectores,
  * de datos e indices mantengan el orden establecido en cada uno de ellos.
  **/
  void deleteingrediente(ingrediente &ing);

  /**
  * @brief Metodo para obtener el tamaño del objeto
  * @return numero de elementos utilizados en los vectores del objeto.
  **/
  int size()const{return datos.size();}//

  /**
  * @brief Metodo que actualiza los datos del vector secundario despues de
  * haber insertado un dato en el vector principar.
  * @param desde valor a partir del cual se van a actualizar los datos
  * @post Al insertar un nuevo elemento en el vector principal, debemos
  * incrementar en 1 el valor de los datos que el vector secundario
  * almancena para poder mantener el orden establecido. Este metodo se
  * encarga de esto.
  **/
  void actualizarPosDatosInsert(int desde);

  /**
  * @brief Metodo que actualiza los datos del vector secundario despues de
  * haber borrado un dato en el vector principar.
  * @param desde valor a partir del cual se van a actualizar los datos
  * @post Al borrar un nuevo elemento en el vector principal, debemos
  * decrementar en 1 el valor de los datos que el vector secundario
  * almancena para poder mantener el orden establecido. Este metodo se
  * encarga de esto.
  **/
  void actualizarPosDatosBorrar(int desde);

  /**
  * @brief set del nombre de un un ingrediente.
  * @param indice posicion en el que se encuentra el ingrediente deseado.
  * @param nuevoNombre nombre que va a tener el ingrediente.
  * @post El ingrediente con la posicion de indice pasa a tener el nombre
  * indicado en el segundo parametro.
  **/
  void setNombreingrediente(int indice, string nuevoNombre);

  /**
  * @brief set del tipo de un un ingrediente.
  * @param indice posicion en el que se encuentra el ingrediente deseado.
  * @param nuevoTipo tipo al que va a pertenecer el ingrediente.
  * @post El ingrediente con la posicion de indice pasa a a pertenecer al tipo
  * indicado en el segundo parametro.
  **/
  void setTipoingrediente(int indice, string nuevoTipo);

  /**
  * @brief set de las calorias de un un ingrediente.
  * @param indice posicion en el que se encuentra el ingrediente deseado.
  * @param nuevoValor valor que va a tener calorias en el ingrediente.
  * @post El ingrediente con la posicion de indice pasa a tener las calorias
  * indicadas en el segundo parametro.
  **/
  void setCaloriasingrediente(int indice, int nuevoValor);

  /**
  * @brief set de hc de un un ingrediente.
  * @param indice posicion en el que se encuentra el ingrediente deseado.
  * @param nuevoValor valor que va a tener hc en el ingrediente.
  * @post El ingrediente con la posicion de indice pasa a tener los hidratos
  * indicadas en el segundo parametro.
  **/
  void setHcingrediente(int indice, int nuevoValor);

  /**
  * @brief set de las Proteinas de un un ingrediente.
  * @param indice posicion en el que se encuentra el ingrediente deseado.
  * @param nuevoValor valor que van a tener las Proteinas en el ingrediente.
  * @post El ingrediente con la posicion de indice pasa a tener las Proteinas
  * indicadas en el segundo parametro.
  **/
  void setProteinasingrediente(int indice, int nuevoValor);

  /**
  * @brief set de las grasas de un un ingrediente.
  * @param indice posicion en el que se encuentra el ingrediente deseado.
  * @param nuevoValor valor que van a tener las grasas en el ingrediente.
  * @post El ingrediente con la posicion de indice pasa a tener las grasas
  * indicadas en el segundo parametro.
  **/
  void setGrasasingrediente(int indice, int nuevoValor);

  /**
  * @brief set de la fibra de un un ingrediente.
  * @param indice posicion en el que se encuentra el ingrediente deseado.
  * @param nuevoValor valor que va a tener la fibra en el ingrediente.
  * @post El ingrediente con la posicion de indice pasa a tener la fibra
  * indicada en el segundo parametro.
  **/
  void setFibraingrediente(int indice, int nuevoValor);

  /**
   * @brief metodo get de ingrediente
   * @param indice indice del ingrediente deseado
   * @return devuelve el ingrediente encontrado en la posicion determinada
   * por el argumento indice.
  **/
  ingrediente getingrediente(int indice)const{return datos[indice];}

  /**
   * @brief metodo get de nombre de ingrediente
   * @param indice indice del ingrediente deseado
   * @return devuelve el nombre del ingrediente encontrado en la posicion determinada
   * por el argumento indice.
  **/
  string getNombreingrediente(int indice)const{return datos[indice].getNombre();}

  /**
   * @brief metodo get del tipo de ingrediente
   * @param indice indice del ingrediente deseado
   * @return devuelve el tipo del ingrediente encontrado en la posicion determinada
   * por el argumento indice.
  **/
  string getTipoingrediente(int indice) const{return datos[indice].getTipo();}

  /**
   * @brief metodo get de calorias del ingrediente
   * @param indice indice del ingrediente deseado
   * @return devuelve las calorias del ingrediente encontrado en la posicion determinada
   * por el argumento indice.
  **/
  int getCaloriasingrediente(int indice) const{return datos[indice].getCalorias();}

  /**
   * @brief metodo get de hidratos del ingrediente
   * @param indice indice del ingrediente deseado
   * @return devuelve los hidratos del ingrediente encontrado en la posicion determinada
   * por el argumento indice.
  **/
  int getHcingrediente(int indice) const{return datos[indice].getHc();}

  /**
   * @brief metodo get de proteinas del ingrediente
   * @param indice indice del ingrediente deseado
   * @return devuelve las proteinas del ingrediente encontrado en la posicion determinada
   * por el argumento indice.
  **/
  int getProteinasingrediente(int indice) const{return datos[indice].getProteinas();}

  /**
   * @brief metodo get de grasas del ingrediente
   * @param indice indice del ingrediente deseado
   * @return devuelve las grasas del ingrediente encontrado en la posicion determinada
   * por el argumento indice.
  **/
  int getGrasasingrediente(int indice) const{return datos[indice].getGrasas();}

  /**
   * @brief metodo get de fibra del ingrediente
   * @param indice indice del ingrediente deseado
   * @return devuelve la fibra del ingrediente encontrado en la posicion determinada
   * por el argumento indice.
  **/
  int getFibraingrediente(int indice) const{return datos[indice].getFibra();}

  /**
  * @brief Metodo para obtener los tipos de ingredientes
  * @return Devuelve un vector disperso de String que contiene los tipos de ingredientes
  * encontrados en el vector principal de datos.
  **/
  vector<string> getTipos();

  /**
  * @brief Metodo get de ingrediente
  * @param nombreIng nombre del ingrediente a buscar.
  * @return devuelve el ingrediente que tiene el nombre pasado como parametro
  * en el metodo
  **/
  ingrediente get(const string nombreIng)const;

  /**
  * @brief borrar un ingrediente segun el nombre
  * @param nombreIng nombre del ingedientes que se va a intentar borrar.
  * @post borra el ingrediente tanto del vector principal como de su posicion
  * en el segundo, actualizando además las posiciones para mantener el orden establecido.
  **/
  void borrar(string nombreIng);

  /**
  * @brief sobrecarga del operador =
  * @param lista objeto ingredientes cuyos valores van a ser asignados
  * al objeto actual.
  * @post Ahora el objeto actual cuenta con los valores del objeto pasado como argumento
  * en el metodo.
  **/
  ingredientes& operator=(const ingredientes &lista);

  /**
  * @brief Sobrecarga del operador []
  * @param i, valor del indice del valor que vamos a consultar dentro del vector principal
  * @return devuelve el valor almacenado dentro del vector principal con indice i
  **/
  ingrediente &operator[](int i){return datos[i];}

  /**
  * @brief Sobrecarga del operador [] const
  * @param i, valor del indice del valor que vamos a consultar dentro del vector principal
  * @return devuelve el valor almacenado dentro del vector principal con indice i
  * de forma que este no pueda ser modificado.
  **/
  const ingrediente &operator[](int i) const {return datos[i];}

  /**
  * @brief Sobrecarga del operador de salida de datos
  * @param o  flujo de salida de datos.
  * @param lista ingredientes que se van a inroducir en la salida de datos.
  * @post Una vez sobrecargado el operador, se puede insertar en el flujo de salida
  * de datos un objeto  ingredientes sin problemas.
  **/
  friend ostream & operator<<(ostream &o, const ingredientes &lista);

  /**
  * @brief Sobrecarga del operador de entrada de datos
  * @param i  flujo de entrada de datos.
  * @param lista ingredientes que se van a inroducir en la entrada de datos.
  * @post Una vez sobrecargado el operador, se puede insertar en el flujo de entrada
  * de datos un objeto ingredientes sin problemas.
  **/
  friend istream & operator>>(istream &i, ingredientes &lista);

  /**
  * @brief Metodo que imprime los ingredientes por su tipo
  * @param out flujo de salida de datos donde se van a introducir
  * los datos.
  * @post se van a imprimir los ingredientes de forma que esten ordenados segun su tipo
  * pero manteniendo tambien su oren alfabético dentro de cada tipo.
  **/
  void ImprimirPorTipo( ostream &out);

  //---------------------------------------------------------------------------------
  //---------------------------------------------------------------------------------
  //METODOS NECESARIOS PARA CALCULAR LA ESTADISTICA
  //DE UN TIPO DE ingrediente
  //---------------------------------------------------------------------------------
  //---------------------------------------------------------------------------------

  /**
  * @brief Método que calcula las estadisticas de un tipo de ingrediente
  * @param tipo tipo de ingrediente sobre el cual se van a obtener las estadisticas.
  * @post se obtendrán:
  * -el valor promedio y la desviación tipica de los nutrientes de los ingedientes
  * pertenecientes al tipo determinado-
  * -Los máximos y minimos de cada nutriente con los respectivos nombres de los Ingredientes
  * que lo contienen
  **/
  void getEstadistica(const string tipo);

  /**
  * @brief Metodo que obtiene el valor promedio de varios valores.
  * @param datosIng datos sobre los cuales se va a obtener el promedio.
  * @return valor promedio en float.
  **/
  float getPromedio(const vector<int> &datosIng);

  /**
  * @brief Metodo que obtiene la desviación de varios valores.
  * @param datosIng datos sobre los cuales se va a obtener la desviación.
  * @return valor de la desviación en float.
  **/
  float getDesviacion(const vector<int> &datosIng);

  /**
  * @brief Metodo que obtiene los valores maximos de un conjunto de ingredientes
  * @param ing ingredientes sobre los que se va a obtener el maximo.
  * @return devuelve un vector disperso que contiene a los ingredientes cuyos valores de
  * calorias, hidratos, proteinas, grasas y fibra han sido máximos.
  **/
  vector<ingrediente> getMaximos(const ingredientes & ing);

  /**
  * @brief Metodo que obtiene los valores minimos de un conjunto de ingredientes
  * @param ing ingredientes sobre los que se va a obtener el minimo.
  * @return devuelve un vector disperso que contiene a los ingredientes cuyos valores de
  * calorias, hidratos, proteinas, grasas y fibra han sido minimos.
  **/
  vector<ingrediente> getMinimos(const ingredientes &ing);

  /**
  * @brief Metodo que comprueba si el ingrediente se encuentra dentro del objeto.
  * @param string nombreIng que contiene el nombre del ingrediente a comprobar.
  * @return devuelve true en el caso de que encuentre el elemento
  * @return devuelve false en caso de que el elemento no exista dentro del objeto.
  **/
  bool contains(const string &nombreIng);
////////////////////////////////////////////////////////////////////////////////
/////////////////////////////Nuevas clases//////////////////////////////////////

class const_iterator;

/**
 * @brief Clase iterator de ingredientes
 *
 * Esta clase ha sido implementada para poder utilizar iteradores para la clase
 * @c ingredientes. Se iterará sobre el vector de ingrediente perteneciente a la
 * clase ingredientes.
 *
 */
class iterator{
private:

 /**
  * @brief Iterador sobre el vector que almacena los ingredientes.
  *
  **/
  vector<ingrediente>::iterator it;
public:

  /**
  * @brief Constructor vacio de la clase
  *
  **/
  iterator(){}

  /**
  * @brief Sobrecarga del operador ==
  * @param Objeto iterator con el cual se va a realizar la comparacion
  * @return true si ambos objetos son iguales
  * @return false si los objetos no son iguales
  **/
  bool operator== (const iterator &i) const {return i.it == it;}

  /**
  * @brief Sobrecarga del operador !=
  * @param Objeto iterator con el cual se va a realizar la comparacion
  * @return false si ambos objetos son iguales
  * @return true si los objetos no son iguales
  **/
  bool operator!= (const iterator &i) const {return i.it != it;}

  /**
  * @brief Sobrecarga del operador * de consulta
  * @return Nos devuelve un puntero al objeto actual de la iteración
  **/
  ingrediente& operator*(){ return *it;}

  /**
  * @brief Sobrecarga del operador ++
  * @return devuelve el valor del iterador incrementado una vez
  **/
  iterator& operator++(){++it; return *this;}

  /**
  * @brief Sobrecarga del operador --
  * @return devuelve el valor del iterador decrementado una vez
  **/
  iterator& operator--(){--it; return *this;}
friend class ingredientes;
friend  class const_iterator;
};

/**
* @brief Clase const_iterator de ingredientes
*
* Esta clase ha sido implementada para poder utilizar iteradores constantes para la clase
* @c ingredientes. Se iterará sobre el vector de ingrediente perteneciente a la
* clase ingredientes.
*
*/
class const_iterator{
private:
  /**
  * @brief Iterador constante sobre el vector que almacena los ingredientes.
  *
  **/
  vector<ingrediente>::const_iterator it;

public:

  /**
  * @brief Constructor vacio de la clase
  *
  **/
  const_iterator(){}

  /**
  * @brief Sobrecarga del operador ==
  * @param Objeto iterator con el cual se va a realizar la comparacion
  * @return true si ambos objetos son iguales
  * @return false si los objetos no son iguales
  **/
  bool operator== (const const_iterator &i) const{return i.it == it;}

  /**
 * @brief Sobrecarga del operador !=
 * @param Objeto iterator con el cual se va a realizar la comparacion
  * @return false si ambos objetos son iguales
  * @return true si los objetos no son iguales
  **/
  bool operator!= (const const_iterator &i) const {return i.it != it;}

  /**
  * @brief Sobrecarga del operador * de consulta
  * @return Nos devuelve un puntero al objeto actual de la iteración
  **/
  const ingrediente& operator*()const{return *it;}

  /**
  * @brief Sobrecarga del operador ++
  * @return devuelve el valor del iterador incrementado una vez
  **/
  const_iterator & operator++(){++it; return *this;}

  /**
  * @brief Sobrecarga del operador --
  * @return devuelve el valor del iterador decrementado una vez
  **/
  const_iterator & operator--(){--it; return *this;}
  friend class ingredientes;
};

  /**
  * @brief metodo begin para clase ingredientes
  * @return iterador apuntando al comienzo del vector de la clase
  **/
  iterator begin(){
      iterator iter;
      iter.it = datos.begin();
      return iter;
    }

  /**
  * @brief metodo end para clase ingredientes
  * @return iterador apuntando al ultimo elemento del vector de la clase
  **/
  iterator end(){
      iterator iter;
      iter.it = datos.end();
      return iter;
    }

  /**
  * @brief metodo constante begin para clase ingredientes
  * @return iterador constante apuntando al comienzo del vector de la clase
  **/
  const_iterator cbegin()const{
      const_iterator citer;
      citer.it = datos.begin();
      return citer;
    }

  /**
  * @brief metodo constante end para clase ingredientes
  * @return iterador constante apuntando al ultimo elemento del vector de la clase
  **/
  const_iterator cend()const{
      const_iterator citer;
      citer.it = datos.end();
      return citer;
    }

/////////////////////////Fin de Implementacion/////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
};
#endif
