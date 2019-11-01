using namespace std;

template <class T>
void VD<T>::resize(int nuevoTam){
  T* aux = new T[nuevoTam];
  int minimo = (n<nuevoTam) ? n:nuevoTam;

  for(int i=0; i<minimo;i++)
    aux[i]=datos[i];

  reservados = nuevoTam;
  n = minimo;
  delete[] datos;
  datos =aux;
}

template <class T>
void VD<T>::Copiar (const VD<T> &v){
  reservados = v.reservados;
  n = v.n;
  datos = new T[reservados];
  for(int i=0; i<n; i++)
    datos[i] = v.datos[i];
}

template <class T>
void VD<T>::Liberar(){
  if(datos != 0){
    delete[] datos;
  }
}

template <class T>
VD<T>::VD(int tam){
  datos = new T[tam];
  reservados = tam;
  n=0;
}

template <class T>
VD<T>::VD(const VD<T> &original){
  Copiar(original);
}

template <class T>
VD<T>::~VD(){
  Liberar();
}

template <class T>
VD<T> & VD<T>::operator=(const VD<T> & v){
  if(this != &v){
    Liberar();
    Copiar(v);
  }

  return *this;
}

template <class T>
void VD<T>::Insertar(const T &d, int pos){
  cout << "Ha entrado en la funcion insertar en la posicion\n";
  cout << pos <<"\n";
  cout << n << "   " << reservados << "\n";
  cout << "lerolero\n";
  if(n >= (reservados/2)){
    resize(2*reservados);
  }

  if(n == 0 && pos == 0){
     cout << size() << "\n";
    datos[pos] = d;
    n++;
  }
  else{
    for(int i = n; i >= pos; i--){
      cout << i << "maria no es realidad\n";
      datos[i+1] = datos[i];
    }

  datos[pos] = d;
  n++;
}
  cout << "Ha llegado hasta aqui\n";
}

template <class T>
void VD<T>::Borrar(int pos){
  for(int i = 0; i < n-1; i++)
    datos[i] = datos[i+1];

  n--;

  if(n < reservados/4)
    resize(reservados/2);
}
