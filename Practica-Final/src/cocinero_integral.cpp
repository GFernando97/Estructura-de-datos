#include <iostream>
#include <stdlib.h>
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


string BuscadorInstrucciones(const string &ruta, const string &recetaCode){
  string fullNameFile = "/"+recetaCode+"m.txt";
  string fullRoute = ruta+fullNameFile;
  cout << fullRoute << endl << endl;

  ifstream fAux(fullRoute);
  if(!fAux){
    fAux.close();
    cout << "Fstream cerrado \n";
    return "Undefined";
  }
  else{
    fAux.close();
    return fullRoute;
  }
}

void AsignarInstrucciones(const string &rutaInstrucciones, receta &rec, const acciones &acc){
  cout << "Voy a asignar las instrucciones a la receta\n\n";
  string codigo = rec.getCode();
  string rutaInst = BuscadorInstrucciones(rutaInstrucciones, codigo);
  cout << "RUTA:\n";
  cout << rutaInst << endl;
  if(rutaInst == "Undefined"){
    cout << "Instrucciones asociadas al código no encontradas\n";
    abort();
  }
  else{
    instrucciones inst;
    cout << "Asignando Acciones....\n";
    inst.setAcciones(acc);
    cout << "Abriendo ruta.....\n\n";
    ifstream fInstrucciones(rutaInst);
    cout << "Intentando leer ruta de instrucciones...\n";
    fInstrucciones >> inst;
    cout << "Objeto instrucciones creado correctamente\n";
    fInstrucciones.close();
    cout << "Asignando instrucciones a receta....\n";
    rec.setInstrucciones(inst);
    cout << "ASIGNACION TERMINADA CORRECTAMENTE!!\n\n\n";
  }
}


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

  /*cout << "\nLa ruta definida para los arhivos de instrucciones es: \n",
  cout<< ruta << endl << endl;*/
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

  cout << "Se ha insertado la nueva receta. Ahora se van a motrar sus valores:" << endl;
  cout<<endl<<endl;
  rall[codigoFusionado].calcularNutrientes(allIngre);
  rall[codigoFusionado].imprimeInfoReceta();

}
