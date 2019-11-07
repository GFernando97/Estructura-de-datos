/**
 * @file ingrediente.h
 * @brief Cabecera de la clase @c ingrediente::ingrediente.
 *
 * En esta clase se guarda la información nutricional de un ingrediente.
 */

#ifndef _ingrediente_
#define _ingrediente_

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/**
 * @brief Clase implementada para representar un ingrediente.
 *
 * Esta clase representa un ingrediente valiéndose de dos string y cinco int
 * que representan el nombre, el tipo, las calorias, hidratos, proteinas,
 * grasas y fibra del mismo.
 *
 */
class ingrediente{
private:

  /**
	* @brief Nombre del ingrediente.
	**/
  string nombre;

  /**
  * @brief Calorias del ingrediente.
  **/
  int calorias;

  /**
  * @brief Hidratos del ingrediente.
  **/
  int hidratos;

  /**
  * @brief Proteinas del ingrediente.
  **/
  int proteinas;

  /**
  * @brief Grasas del ingrediente.
  **/
  int grasas;

  /**
  * @brief Fibra del ingrediente.
  **/
  int fibra;

  /**
  * @brief Tipo de ingrediente.
  **/
  string tipo;


  /**
  * @brief copia un ingrediente
  * @param ing: ingrediente cuyos valores se van a copiar
  *
  **/
  void Copiar(const ingrediente &ing);

public:

  /**
  * @brief consructor vacío, en este caso crea un ingrediente sin valores
  **/
  ingrediente(){}


  /**
  * @brief constructor de copia
  * @param original: objeto original del cual se van a copiar los datos
  *
  **/
  ingrediente(const ingrediente &original);


  /**
  * @brief constructor con parametros
  * @param nombre: nombre que va a recibir el objeto
  * @param calorias: cantidad de calorias que va a contener el ingrediente
  * @param hidratos: cantidad de hidratos que va a contener el ingrediente
  * @param proteinas: cantidad de proteinas que va a contener el ingrediente
  * @param grasas: cantidad de grasas que va a contener el ingrediente
  * @param fibra: cantidad de fibra que va a contener el ingrediente
  * @param tipo: tipo de ingrediente al que va a pertenecer
  *
  * @post Se ha creado un ingrediente con los valores que han sido pasados como
  * argumentos en el constructor.
  **/
  ingrediente(string nombre, int calorias, int hidratos, int proteinas, int grasas, int fibra, string tipo);


  /**
  * @brief sobrecarga del operador =
  * @param ing: ingrediente del cual se van a copiar los datos
  *
  **/
  ingrediente &operator= (const ingrediente &ing);

  /**
  * @brief sobrecarga del operador ==
  * @param ing: ingrediente del cual se van a copiar los datos
  *
  **/
  bool operator ==(const ingrediente &ing);


  /**
  * @brief Método get del nombre del ingrediente.
  * @return nombre del objeto actual.
  *
  **/
  string getNombre() const{return this->nombre;}


  /**
  * @brief Metodo get del tipo de ingrediente.
  * @return tipo de ingrediente al que pertenece.
  *
  **/
  string getTipo() const{return this->tipo;}

  /**
  * @brief Metodo get de calorias
  * @return numero de calorias del ingrediente
  *
  **/
  int getCalorias() const{return this->calorias;}

  /**
  * @brief Metodo get de Hidratos
  * @return numero de Hidratos del ingrediente
  *
  **/
  int getHc() const{return this->hidratos;}

  /**
  * @brief Metodo get de Proteinas
  * @return numero de Proteinas del ingrediente
  *
  **/
  int getProteinas() const{return this->proteinas;}

  /**
  * @brief Metodo get de Grasas
  * @return numero de Grasas del ingrediente
  *
  **/
  int getGrasas() const{return this->grasas;}

  /**
  * @brief Metodo get de Fibra
  * @return numero de fibra del ingrediente
  *
  **/
  int getFibra() const{return this->fibra;}

  /**
  * @brief Metodo set de Nombre
  * @param nombre del ingrediente
  * @post  ahora el ingrediente tiene el nombre pasado como argumento
  * en el metodo.
  *
  **/
  void setNombre(string nombre){this->nombre = nombre;}

  /**
  * @brief Metodo set de Tipo
  * @param tipo del ingrediente
  * @post  ahora el ingrediente tiene el tipo pasado como argumento
  * en el metodo.
  *
  **/
  void setTipo(string tipo){this->tipo = tipo;}

  /**
  * @brief Metodo set de Calorias
  * @param Calorias del ingrediente
  * @post  ahora el ingrediente tiene las calorias pasadas como argumento
  * en el metodo.
  *
  **/
  void setCalorias(int calorias){this->calorias = calorias;}

  /**
  * @brief Metodo set de Hidratos
  * @param Hidratos del ingrediente
  * @post  ahora el ingrediente tiene los hidratos pasados como argumento
  * en el metodo.
  *
  **/
  void setHc(int hidratos){this->hidratos = hidratos;}

  /**
  * @brief Metodo set de Proteinas
  * @param proteinas del ingrediente
  * @post  ahora el ingrediente tiene las proteinas pasadas como argumento
  * en el metodo.
  *
  **/
  void setProteinas(int proteinas){this->proteinas = proteinas;}

  /**
  * @brief Metodo set de Grasas
  * @param grasas del ingrediente
  * @post  ahora el ingrediente tiene las grasas pasadas como argumento
  * en el metodo.
  *
  **/
  void setGrasas(int grasas){this->grasas = grasas;}

  /**
  * @brief Metodo set de Fibra
  * @param fibra del ingrediente
  * @post  ahora el ingrediente tiene la fibra pasada como argumento
  * en el metodo.
  *
  **/
  void setFibra(int fibra){this->fibra = fibra;}

  /**
  * @brief Sobrecarga del operardor de salida de datos
  * @param o  flujo de salida de datos.
  * @param ing ingrediente que se va a inroducir en la salida de datos.
  * @post Una vez sobrecargado el operador, se puede insertar en el flujo de salida
  * de datos un ingrediente sin problemas.
  **/
  friend ostream& operator << (ostream &o, const ingrediente &ing);

  /**
  * @brief Sobrecarga del operardor de entrada de datos
  * @param i  flujo de entrada de datos.
  * @param ing ingrediente que se va a inroducir en la entrada de datos.
  * @post Una vez sobrecargado el operador, se puede insertar en el flujo de entrada
  * de datos un ingrediente sin problemas.
  **/
  friend istream& operator >> (istream &i, ingrediente &ing);

};

#endif
