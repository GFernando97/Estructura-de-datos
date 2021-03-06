/**
 * @file tipos_ingredientes.cpp
 * @brief programa para obtener determinada informacion sobre algún determindo tipo de ingrediente
 *
 * Este programa toma una lista de ingredientes y un tipo de ingredientes como argumento
 * y devuelve información detallada de los ingredientes de dicho tipo.
 *
 **/
#include <iostream>
#include "ingrediente.h"
#include "ingredientes.h"
#include <fstream>
#include <cmath>

using namespace std;


int main(int argc, char *argv[]) {
	if (argc != 3) {
    cout << "\tNúmero de parámetros incorrecto." << endl;
  	cout << "\tUso correcto: " << endl;
  	cout << "\t\t./tipos_ingredientes <fichero de datos> <tipo a procesar>" << endl;
		return 1;
	}


	string archivo=argv[1];
	string tipo=argv[2];
	ifstream f(archivo);

	if(!f) {
		cerr << "ERROR: No se ha podido abrir el archivo" << endl;
		return 1;
	}

	ingredientes all_ingre;
	f >> all_ingre;


	VD<string> tipos=all_ingre.getTipos();

  cout<<"Los tipos de alimentos son:"<<endl;
  for (int i=0;i<tipos.size(); ++i){
     cout<<tipos[i]<<endl;
  }

  if(tipos.Esta(tipo) == true){
	ingredientes tipoPedido(all_ingre.getingredienteTipo(tipo));

	cout << endl << "Los ingredientes de tipo " << tipo << " son: " << endl;
	cout << tipoPedido << endl;

  cout << "Calculando Estadistica...\n";
  all_ingre.getEstadistica(tipo);
  }

  else{
    cout << "El tipo de ingrediente insertado a analizar no existe..." << endl;
    return 1;
  }
	return 0;
}
