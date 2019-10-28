#ifndef _INGREDIENTE_
#define _INGREDIENTE_

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Ingrediente{
private:
  string nombre;
  int calorias;
  int hidratos;
  int proteinas;
  int grasas;
  int fibra;
  string tipo;


  /**
  *@brief copia un ingrediente
  *@param ing: ingrediente cuyos valores se van a copiar
  *IMPLEMENTADO
  **/
  void Copiar(const Ingrediente &ing);

public:

  /**
  *@brief consructor vacío
  **/
  Ingrediente(){}


  /**
  *@brief constructor de copia
  *@param original: objeto original del cual se van a copiar los datos
  *IMPLEMENTADO
  **/
  Ingrediente(const Ingrediente &original);


  /**
  *@brief constructor con parametros
  *@param nombre: nombre que va a recibir el objeto
  *@param calorias: cantidad de calorias que va a contener el ingrediente
  *@param hidratos: cantidad de hidratos que va a contener el ingrediente
  *@param proteinas: cantidad de proteinas que va a contener el ingrediente
  *@param grasas: cantidad de grasas que va a contener el ingrediente
  *@param fibra: cantidad de fibra que va a contener el ingrediente
  *@param tipo: tipo de ingrediente al que va a pertenecer
  *IMPLEMENTADO
  **/
  Ingrediente(string nombre, int calorias, int hidratos, int proteinas, int grasas, int fibra, string tipo);


  /**
  *@brief sobrecarga del operador =
  @param ing: ingrediente del cual se van a copiar los datos
  *IMPLEMENTADO
  **/
  Ingrediente &operator= (const Ingrediente &ing);

  ////////////////////////////////////////////////////
  bool operator ==(const Ingrediente &ing);


  /**
  *@brief Obtener el nombre del ingrediente
  *@return nombre del objeto actual
  *IMPLEMENTADO
  **/
  string getNombre() const{return this->nombre;}


  /**
  *@brief Obtiene el nombre del tipo
  *@return tipo de ingrediente al que pertenece
  *IMPLEMENTADO
  **/
  string getTipo() const{return this->tipo;}


  friend ostream& operator << (ostream &o, const Ingrediente &ing);
  friend istream& operator >> (istream &i, Ingrediente &ing);

  /**
  *@brief Metodo get de calorias
  *@return numero de calorias del ingrediente
  *IMPLEMENTADO
  **/
  int getCalorias() const{return this->calorias;}

  int getHc() const{return this->hidratos;}

  int getProteinas() const{return this->proteinas;}

  int getGrasas() const{return this->grasas;}

  int getFibra() const{return this->fibra;}

  void setNombre(string nombre){this->nombre = nombre;}

  void setTipo(string tipo){this->tipo = tipo;}

  void setCalorias(int calorias){this->calorias = calorias;}

  void setHc(int hidratos){this->hidratos = hidratos;}

  void setProteinas(int proteinas){this->proteinas = proteinas;}

  void setGrasas(int grasas){this->grasas = grasas;}

  void setFibra(int fibra){this->fibra = fibra;}


};

#endif
