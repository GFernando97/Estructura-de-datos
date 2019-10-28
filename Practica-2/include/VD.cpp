using namespace std;

template <class T>
void VD<T>::resize(int nuevoTam){
  T* aux = new T[nuevoTam];
  int minimo = (n<nuevoTam)?n:nuevoTam;

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
  delete[] datos;
  n = 0;
  reservados = 0;
}

template <class T>
VD<T>::VD(){
  reservados = 0;
  datos = new T[reservados];
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
VD<T> & VD<T>::operator=(const VD<T> &v){
  if(this != &v){
    Liberar();
    Copiar(v);
  }

  return *this;
}

template <class T>
void VD<T>::Insertar(const T &d, int pos){
  cout << d;
  cout << "Voy a intentar acceder a los datos de VD" << endl;
  cout << "valor de n: " << reservados;

  if(n >= (reservados/2)){
    resize(2*reservados);
  }
    cout << "--reservados ahora: " << reservados;
    cout << "--valor de n: " << n;

  for(int i = n; i > pos; i--){
    datos[i] = datos[i-1];
  }

  datos[pos] = d;
  n++;
}

template <class T>
void VD<T>::Borrar(int pos){
  for(int i = 0; i < n-1; i++)
    datos[i] = datos[i+1];

  n--;

  if(n < (reservados/4))
    resize(reservados/2);
}
