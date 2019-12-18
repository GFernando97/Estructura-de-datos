#ifndef RECETAS_H
#define RECETAS_H
#include "receta.h"
#include <map>
#include "instrucciones.h"
#include "ingredientes.h"
class recetas{
   private:
     map<string,receta> datos;
    public:
      unsigned int size()const{
        return datos.size();   
      }
      void insertar(const receta &r);
      void borrar(const string &cod);
      receta operator[](const string &cod){
          map<string,receta>::iterator it=datos.find(cod);
		  if (it!=datos.end())
                       return it->second;
           else {
			   receta aux;
			   aux.setNombre("Undefined");
			   return aux;    
		   }        
                       
    
      }   
     receta operator[](const string &cod)const{
		  map<string,receta>::const_iterator it=datos.find(cod);
		  if (it!=datos.end())
                       return it->second;
           else {
			   receta aux;
			   aux.setNombre("Undefined");
			   return aux;    
		   }        
                       
      }
      void clear(){ datos.clear();};
      void setNutricion(ingredientes &ings);
      class iterator{
		  private:
		    map<string,receta>::iterator it;
		   public:
		      iterator(){}
		      bool operator==(const iterator &i)const{
				   return i.it==it;
			  }
			  bool operator!=(const iterator &i)const{
				  return i.it!=it;
			  }
			  receta& operator*(){
				  return it->second;
			  }
			  iterator & operator++(){
				  ++it;
				  return *this;
			  }
			  iterator & operator--(){
				  --it;
				  return *this;
			  }
			  friend class recetas;
		  };
      class const_iterator{
		  private:
		    map<string,receta>::const_iterator it;
		   public:
		      const_iterator(){}
		      bool operator==(const const_iterator &i)const{
				   return i.it==it;
			  }
			  bool operator!=(const const_iterator &i)const{
				  return i.it!=it;
			  }
			  const receta& operator*(){
				  return it->second;
			  }
			  const_iterator & operator++(){
				  ++it;
				  return *this;
			  }
			  const_iterator & operator--(){
				  --it;
				  return *this;
			  }
			  friend class recetas;
		  };
		  iterator begin(){
			  iterator i;
			  i.it=datos.begin();
			  return i;
		  }
		  iterator end(){
			  iterator i;
			  i.it=datos.end();
			  return i;
		  }
		  const_iterator begin()const{
			  const_iterator i;
			  i.it=datos.cbegin();
			  return i;
		  }
		  const_iterator end()const{
			  const_iterator i;
			  i.it=datos.cend();
			  return i;
		  }		  
		  friend ostream & operator<<(ostream &os,const recetas &R);
    	  friend istream & operator>>(istream &os,recetas &R);
    	  bool CargarRecetas(const string &nombre, const string &path_ins);

};
#endif
