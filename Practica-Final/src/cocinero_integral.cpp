#include <iostream>
#include <string>
#include <fstream>
#include "recetas.h"
#include "receta.h"
#include "ingredientes.h"
#include "acciones.h"
#include "arbolbinario.h"

/*
bin/cocinero_integral
datos/Acciones.txt
datos/recetas.txt
datos/ingredientes.txt
datos/instrucciones

*/
using namespace std;

int main(int argc, char *argv[]){
  if(argc!=4){
    cout << "Faltan argumentos de entrada por insertar." << endl;
    return 0;
  }

  ifstream fAcciones(argv[1]);
  ifstream fRecetas(argv[2]);
  ifstream fIngredientes(argv[3]);
  //ifstream f5(argv[4]);

  if(!fAcciones)
    cout << "El archivo de acciones no ha sido encontrado." << argv[1]<<endl;
  else if(!fRecetas)
    cout << "El archivo de recetas no ha sido encontrado." << argv[2]<<endl;
  else if(!fIngredientes)
    cout << "El archivo de ingredientes no ha sido encontrado."<<argv[3]<<endl;

  acciones acc;
  fAcciones >> acc;
  cout << "Archivo de acciones leido.\n";

  recetas rall;
  fRecetas >> rall;
  cout << "Archivo de recetas leido.\n";

  ingredientes allIngre;
  fIngredientes >> allIngre;
  cout << "Archivo de ingredientes leido.\n";

  cout << "Imprimir recetas:\n\n";
  cout << rall << endl << endl;

  cout << "Escribe el código de una receta para ver su informacion:";
  string codigo;
  cin >> codigo;

  if (rall[codigo].getNombre()!="Undefined"){
    receta aux = rall[codigo];
    aux.calcularNutrientes(allIngre);
    aux.imprimeInfoReceta();
  }
  else{
    cout<<"La receta con codigo "<<codigo<<" no existe"<<endl;
  }


  codigo.clear();
  cout <<"Introduce el codigo de la primera receta para fusionar: ";
  cin >> codigo;
  receta receta1 = rall[codigo];
  cout<<endl;
/*
  if (rall[codigo].getNombre()!="Undefined"){
    receta receta1 = rall[codigo];
  }
  else{
    cout<<"La receta con codigo "<<codigo<<" no existe"<<endl;
  }*/

  codigo.clear();
  cout <<"Ahora introduce el codigo de la segunda receta para fusionar: ";
  cin >> codigo;
  receta receta2 = rall[codigo];
  cout<<endl;
/*
  if (rall[codigo].getNombre()!="Undefined"){
    receta receta2 = rall[codigo];
  }
  else{
    cout<<"La receta con codigo "<<codigo<<" no existe"<<endl;
  }*/

  receta nuevaReceta = rall.fusionaRecetas(receta1, receta2);
  rall.insert(nuevaReceta);

  cout << "Se ha insertado la nueva receta. Ahora se van a motrar sus valores:" << endl;
  cout<<endl<<endl;
  receta fusionada = rall[nuevaReceta.getCode()];
  fusionada.calcularNutrientes(allIngre);
  fusionada.imprimeInfoReceta();

}
