#ifndef _VD_
#define _VD_

using namespace std;

template <class T>
class VD{
  private:
    T* datos;
    int n;
    int reservados;

    /**
    *@brief modificar el tamaño del vector disperso
    *@param nuevoTam: nuevo valor del tamaño del vector
    **/
    void resize(int nuevoTam);


    /**
    *@brief Copia el contenido de un vector en el actual.
    *@param v: vector del cual se va a realizar la copia.
    **/
    void Copiar(const VD<T> &v);


    /**
    *@brief elimina el vector
    **/
    void Liberar();

  public:
    /**
    *@brief Crea un vetor dinamico
    *@param tam tamaño del vector, por defecto 10.
    **/
    VD(int tam=10);


    /**
    *@brief Constructor de Copia
    *@param original, VD del cual se van a copiar los datos
    *
    **/
    VD(const VD<T> &original);


    /**
    *@brief destructor de la clase
    *
    **/
    ~VD();


    /**
    *@brief Sobrecarga del operador de igualdad =
    *@param v, vector dinamico del cual se van a copiar los datos
    *@return devuelve un puntero apuntando al objeto actual.
    **/
    VD<T> &operator= (const VD<T> &v);


    int size() const {return n;}


     /**
     *@brief Sobrecarga del operador []
     *@param i, valor del indice del valor que vamos a consultar dentro del vector
     *@return devuelve el valor almacenado dentro del vector disperso con indice i
     **/
     T &operator[] (int i) {return datos[i];}


    /**
    *@brief Sobrecarga del operador []
    *@param i, valor del indice del valor que vamos a consultar dentro del vector
    *@return devuelve el valor almacenado dentro del vector disperso con indice i
    **/
     const T &operator[] (int i) const {return datos[i];}


     /**
     *@brief Añade un nuevo valor en la posicion deseada
     *@param d: dato que se va a añadir, pos: posicion en el vector en el cual se va a introducir el nuevo dato
     **/
     void Insertar (const T &d, int pos);

     /**
     *@brief Borra el elemento de una determinada posicion
     *@param pos: posicion en el vector cuyo dato se va a eliminar
     **/
     void Borrar (int pos);

};

#include "VD.cpp"
