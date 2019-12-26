#include "receta.h"
#include "recetas.h"
#include "ingredientes.h"
#include "ingrediente.h"
#include <fstream>
using namespace std;
int main(int argc,char *argv[]){
  if (argc!=4){
    cout<<"Dime primero el fichero de las recetas y luego el fichero de los ingredientes"<<endl;
    return 0;

  }
  ifstream f(argv[1]);    //Stream de recetas
  ifstream f2(argv[2]);
  float valor = stof(argv[3]);
  if (!f){
	  cout<<"No existe el fichero de recetas "<<argv[1]<<endl;
  }
  else if (!f2){
    cout<<"No existe el fichero de ingredientes"<<argv[2]<<endl;
  }


  /***********************************************************************/

  //SECTION 1: Crea los objetos recetas e ingredientes
  recetas rall;
  f >> rall;
  cout << "Archivo de recetas leido..."  << endl;

  string aux;
  getline(f2, aux);
  ingredientes allIngre;
  f2 >> allIngre;
  cout << "Archivo de ingredientes leido..." << endl;

  //Calculo nutrientes de cada receta
  recetas::iterator it;
  for(it = rall.begin(); it != rall.end(); ++it)
    (*it).second.calcularNutrientes(allIngre);

  cout << "Se han calculado los repspectivos nutrientes de cada receta.\n\n\n";
  //Imprime los valores nutricionales calculados en el paso anterior

  cout << "Se van a imprimir as recetas junto con los nutrientes:\n\n";
  recetas::const_iterator cit;
  for(cit = rall.cbegin(); cit != rall.cend(); ++cit){
    (*cit).second.imprimeValNutricionales();
  }

/*
  cout << "Se van a imprimir los valores de codigo de receta junto con calorias y razon: \n";
  for(cit = rall.cbegin(); cit != rall.cend(); ++cit){
    cout << (*cit).first << "-- Cal: " << (*cit).second.getCalorias() << " Razon: "<<(*cit).second.getRazon() << endl ;
  }
  */

  list<receta>elegidos;
  elegidos = rall.recetasAdecuadas(valor);
  list<receta>::iterator iter;
  float caloriasTotales = 0;
  float proteinasTotales = 0;
  float razonMax = 0;

  cout << "Las recetas escogidas son: " << endl;
  for(iter= elegidos.begin(); iter != elegidos.end(); ++iter){
    (*iter).calcularNutrientes(allIngre);
    cout << (*iter) << endl;
    caloriasTotales += (*iter).getCalorias();
    proteinasTotales += (*iter).getProteinas();
    razonMax += (*iter).getRazon();
  }
  cout << endl;
  cout << "Calorias Totales " << caloriasTotales << "  Proteinas Totales " << proteinasTotales << endl;
  cout << "\nEl mayor valor de la razon que hemos obtenido es: " << razonMax << endl;

}
