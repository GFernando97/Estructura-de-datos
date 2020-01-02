#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include "recetas.h"
#include "receta.h"
#include "ingredientes.h"
#include "acciones.h"
#include "arbolbinario.h"

using namespace std;

int main(int argc, char *argv[]){
  if(argc!=5){
    cout << "Faltan argumentos de entrada por insertar." << endl;
    return 0;
  }

  ifstream fAcciones(argv[1]);
  ifstream fRecetas(argv[2]);
  ifstream fIngredientes(argv[3]);
  ifstream fInstrucciones;

  string ruta = argv[4];
  string rutaInst;
  string firstCode = "Undefined";
  string secondCode = "Undefined";

  cout << "\nLa ruta definida para los arhivos de instrucciones es: \n",
  cout<< ruta << endl << endl;

  //Errores en caso de no encontrar los archivos pasados como parametros;
  if(!fAcciones){
    cout << "El archivo de acciones no ha sido encontrado." << argv[1]<<endl;
    return 0;
  }
  else if(!fRecetas){
    cout << "El archivo de recetas no ha sido encontrado." << argv[2]<<endl;
    return 0;
  }
  else if(!fIngredientes){
    cout << "El archivo de ingredientes no ha sido encontrado."<<argv[3]<<endl;
    return 0;
  }

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
    rutaInst = aux.BuscadorInstrucciones(ruta);
    fInstrucciones.open(rutaInst);
    aux.insertarInstrucciones(fInstrucciones, acc);
    fInstrucciones.clear();
    fInstrucciones.close();
    aux.calcularNutrientes(allIngre);
    aux.imprimeInfoReceta();

  }
  else{
    cout<<"La receta con codigo "<<codigo<<" no existe"<<endl;
    abort();
  }

  codigo.clear();
  cout <<"Introduce el codigo de la primera receta para fusionar: ";
  cin >> codigo;

  if (rall[codigo].getNombre()!="Undefined"){
    firstCode = codigo;
    rutaInst = rall[codigo].BuscadorInstrucciones(ruta);
    fInstrucciones.open(rutaInst);
    rall[codigo].insertarInstrucciones(fInstrucciones, acc);
    fInstrucciones.clear();
    fInstrucciones.close();
    rall[codigo].calcularNutrientes(allIngre);

  }
  else{
    cout<<"La receta con codigo "<<codigo<<" no existe"<<endl;
    abort();
  }

  codigo.clear();
  cout <<"Ahora introduce el codigo de la segunda receta para fusionar: ";
  cin >> codigo;

  if (rall[codigo].getNombre()!="Undefined"){
    secondCode = codigo;
    rutaInst = rall[codigo].BuscadorInstrucciones(ruta);
    fInstrucciones.open(rutaInst);
    rall[codigo].insertarInstrucciones(fInstrucciones, acc);
    fInstrucciones.clear();
    fInstrucciones.close();
    rall[codigo].calcularNutrientes(allIngre);
  }
  else{
    cout<<"La receta con codigo "<<codigo<<" no existe"<<endl;
    abort();
  }

  string codigoFusionado = rall.fusionaRecetas(firstCode, secondCode, acc);


  cout << "\nSe ha insertado la nueva receta. Ahora se van a motrar sus valores:" << endl;
  cout<<endl;
  rall[codigoFusionado].calcularNutrientes(allIngre);
  rall[codigoFusionado].imprimeInfoReceta();

}
