#include "receta.h"
#include "recetas.h"
#include "ingredientes.h"
#include "ingrediente.h"
#include <fstream>
using namespace std;
int main(int argc,char *argv[]){
  if (argc!=3){
    cout<<"Dime primero el fichero de las recetas y luego el fichero de los ingredientes"<<endl;
    return 0;

  }
  ifstream f(argv[1]);    //Stream de recetas
  ifstream f2(argv[2]);   //Stream de ingredientes
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
  cout << "Archivo de recetas leido..." << endl;

  string aux;
  getline(f2, aux);
  ingredientes allIngre;
  f2 >> allIngre;
  cout << "Archivo de ingredientes leido..." << endl;

  //Calculo nutrientes de cada receta
  recetas::iterator it;
  for(it = rall.begin(); it != rall.end(); ++it)
    (*it).second.calcularNutrientes(allIngre);

  //Imprime los valores nutricionales calculados en el paso anterior
  recetas::const_iterator cit;
  for(cit = rall.cbegin(); cit != rall.cend(); ++cit){
    (*cit).second.imprimeValNutricionales();
  }

}
