
/**
 * @file VD.h
 * @brief Archivo cabecera para la clase template @c VD
 */

#ifndef _VD_
#define _VD_

using namespace std;

/**
 * @brief Clase para representar un vector disperso de datos.
 *
 * El modo de representación de este vector va a ser tal que existe
 * un puntero para los datos y dos valores enteros que representan el
 * número de elementos utilizados y el número de elementos reservados para
 * dicho vector.
 */
template <class T>
class VD{
  private:
    /**
    * @brief Vector que almacena los datos
    *
    * Este puntero apunta a un vector dinámico en el cual se almacenan los
    * datos utilizados.
    **/
    T* datos;

    /**
    * @brief Número de datos
    *
    * En este entero se almacenan el número de elementos introducidos en el vector.
    **/
    int n;

    /**
    * @brief Número de reservados
    * En este entero se almacena el valor del espacio que se ha reservado en
    * el vector.
    * @pre Este valor va a ser siempre mayor (o igual) que el numero de
    * elementos utilizados en el vector.
    **/
    int reservados;


    /**
    * @brief Modifica el tamaño del vector disperso.
    *
    * @param nuevoTam: nuevo valor del tamaño del vector
    *
    * @pre  El valor de @a nuevoTam deber ser positivo.
    * @post El vector tiene ahora un tamaño igual a @a nuevoTam.
    **/
    void resize(int nuevoTam);


    /**
    * @brief Copia el contenido de un vector en el actual.
    * @param v: vector del cual se va a realizar la copia.
    *
    **/
    void Copiar(const VD<T> &v);


    /**
    * @brief elimina los datos del vector, de forma que éste queda completamente
    * vacío.
    *
    **/
    void Liberar();


  public:

    /**
    * @brief Constructor por defecto de la clase.
    *
    * @param tam tamaño del vector, por defecto 10.
    * @pre @a tam debe ser positivo.
    * @post Crea un Vector con el tamaño indicado o con el tamaño por
    * defecto de 10.
    *
    **/
    VD(int tam = 10);


    /**
    * @brief Constructor de Copia
    * @param original, VD del cual se van a copiar los datos
    *
    **/
    VD(const VD<T> &original);


    /**
    * @brief destructor de la clase
    *
    **/
    ~VD();


    /**
    * @brief Sobrecarga del operador de igualdad =
    * @param v, vector dinamico del cual se van a copiar los datos
    * @return devuelve un puntero apuntando al objeto actual.
    **/
    VD<T> &operator= (const VD<T> & v);


    /**
    * @brief  Método para consultar el tamaño del vector.
    * @return Devuelve el valor entero del tamaño del vector.
    **/
    int size() const {return n;}

    /**
    * @brief Sobrecarga del operador []
    * @param i, valor del indice del valor que vamos a consultar dentro del vector
    * @return devuelve el valor almacenado dentro del vector disperso con indice i
    **/
    T & operator[] (int i) {return datos[i];}

    /**
    * @brief Sobrecarga del operador [] const
    * @param i, valor del indice del valor que vamos a consultar dentro del vector
    * @return devuelve el valor almacenado dentro del vector disperso con indice i
    * de forma que este no pueda ser modificado.
    **/
    const T & operator[] (int i) const {return datos[i];}

    /**
    * @brief Añade un nuevo valor en la posicion deseada
    * @param d dato que se va a añadir
    * @param pos posicion en el vector en el cual se va a introducir el nuevo dato
    **/
    void Insertar (const T & d, int pos);

    /**
    *@brief Borra el elemento de una determinada posicion
    *@param pos: posicion en el vector cuyo dato se va a eliminar
    **/
    void Borrar (int pos);

    /**
    * @brief Método que comprueba si un elemento se encuentra en el vector.
    * @param d Elemento a buscar en el vector.
    * @return En el caso de haber encontrado el elemento, devuelve true,
    * en caso contrario, devuelve false.
    **/
    bool Esta( T &d);


};

#include "VD.cpp"

#endif
