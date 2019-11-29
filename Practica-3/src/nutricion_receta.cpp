#include "receta.h"
#include "recetas.h"
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

  //Voy a calcular todos los valores nutricionales de cada receta
  recetas::const_iterator cit;
  


  string aux;
  getline(f2, aux);
  ingredientes allIngre;
  f2 >> allIngre;
  cout << "Archivo de ingredientes leido..." << endl;


  //SECTION 4: Consultar una receta por codigo
  cout<<"Dime el codigo de una receta:";
  string c;
  cin>>c;
  if (rall[c].getNombre()!="Undefined"){
	  cout<<"La receta es "<<rall[c]<<endl;
  }
  else{
	  cout<<"La receta con codigo "<<c<<" no existe"<<endl;
  }

  /***********************************************************************/

  //SECTION 5: Borramos la receta con un código. Comprobamos el
  //funcionamiento del iterador de recetas
  rall.borrar(c);
  cout<<"Tras el borrado "<<endl;
  recetas::iterator its;
  for (its=rall.begin();its!=rall.end();++its){
	cout<<*its<<endl;

  }
  cout<<endl;
  cout<<"Numero de recetas "<<rall.size()<<endl;


}
