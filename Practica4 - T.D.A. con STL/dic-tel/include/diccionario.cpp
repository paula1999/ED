/**
 * @file diccionario.cpp
 * @author Paula Villanueva Nuñez
*/

#include <iostream>
#include <string>
#include <list>

using namespace std;

template <class T,class U>
void Diccionario<T,U>::Copiar(const Diccionario<T,U>& D){
 datos.assign(D.datos.begin(), D.datos.end());
}

template <class T,class U>
void Diccionario<T,U>::Borrar(){
    this->datos.erase(datos.begin(),datos.end());
}

template <class T,class U>
Diccionario<T,U> & Diccionario<T,U>::operator=(const Diccionario<T,U> &D){
    if (this != &D){
        Borrar();
        Copiar(D);
    }

    return *this;
}

template <class T,class U>
bool Diccionario<T,U>::Esta_Clave(const T &p, typename  list<data<T,U> >::iterator &it_out){
    if (datos.size() > 0){
      typename list<data<T,U> >::iterator it;

      for (it=datos.begin(); it!=datos.end(); ++it){
         if ((*it).clave == p) {
            it_out = it;
            return true;
         }
         else if ((*it).clave > p){
            it_out = it;
            return false;
         }
      }

      it_out = it;

      return false;
   }
   else {
      it_out = datos.end();

      return false;
   }
}

template <class T,class U>
void Diccionario<T,U>::Insertar(const T& clave,const list<U> &info){
    typename list<data<T,U> >::iterator it;

    if (!Esta_Clave(clave,it)){
        data<T,U> p;

        p.clave = clave;
        p.info_asoci = info;

        datos.insert(it,p);
    }

}

template <class T,class U>
void Diccionario<T,U>::AddSignificado_Palabra(const U & s ,const T &p){
    typename list<data<T,U> >::iterator it;

    if (!Esta_Clave(p,it)){
       datos.insert(it,p);
    }

    //Insertamos el siginificado al final
    (*it).info_asoci.insert((*it).info_asoci.end(),s);
}

template <class T, class U>
void Diccionario<T,U>::borrar_Palabra (const T &p){
  typename list<data<T,U> >::iterator it;

  if (Esta_Clave(p,it)){
    datos.erase(it);
  }

}

template <class T, class U>
Diccionario<T,U> Diccionario<T,U>::buscar_Letra(const T &letra){
  Diccionario<T,U> Daux;
  typename list<data<T,U> >::iterator it;
  T a;

  for (it=datos.begin(); it!=datos.end(); ++it){
     a = (*it).clave;

     if (a[0] == letra[0]){
       Daux.Insertar((*it).clave, (*it).info_asoci);
     }
  }

  return Daux;
}

template <class T,class U>
Diccionario<T,U> Diccionario<T,U>::max_significado(){
  Diccionario<T,U> Daux;
  typename list<data<T,U> >::const_iterator it;
  int max = 0;
  T smax;
  list<U> sinfo;

  for (it=this->begin(); it!=this->end(); ++it){
      if ((int)(*it).info_asoci.size() >= max){
        // Si es estrictamente mayor, borramos todo.
        // Así podemos almacenar más de un máximo que tienen igual de números de significados
        if ((int)(*it).info_asoci.size() > max)
          Daux.Borrar();

        max = (*it).info_asoci.size();
        smax = (*it).clave;
        sinfo = (*it).info_asoci;
        Daux.Insertar(smax, sinfo);
      }
  }

  return Daux;
}


template <class T,class U>
list<U> Diccionario<T,U>::getInfo_Asoc(const T & p) {
   typename list<data<T,U> >::iterator it;

   if (!Esta_Clave(p,it)){
         return list<U>();
   }
   else{
         return (*it).info_asoci;
   }
}

/*Operator<<. Obsérvese el uso de 2 tipos diferentes de iteradores. Uno sobre
listas de listas y otro sobre listas
*/
ostream & operator<< (ostream & os, const Diccionario<string,string> & D){
	  list<data<string,string> >::const_iterator it;
		list<string>::const_iterator it_s;

	  for (it=D.begin(); it!=D.end(); ++it){
		    os << endl << (*it).clave << endl << " informacion asociada:" << endl;

		    for (it_s=(*it).info_asoci.begin(); it_s!=(*it).info_asoci.end(); ++it_s){
			      os << (*it_s) << endl;
		    }

		    os << "**************************************" << endl;
	  }

	  return os;
}

/*Operator >>. El formato de la entrada es:
     numero de claves en la primera linea
     clave-iésima retorno de carro
     numero de informaciones asociadas en la siguiente linea
     y en cada linea obviamente la informacion asociada
*/
istream & operator>> (istream & is,Diccionario<string,string> &D){
	  int np, ns;
		Diccionario<string,string> Daux;
		string clave, s;
		list<string> laux;

	  is >> np;

		is.ignore();//quitamos \n

		for (int i=0; i<np; i++){
		    getline(is,clave);

		    is >> ns;

				is.ignore();//quitamos \n
        laux.clear();

				for (int j=0; j<ns; j++){
			      getline(is,s);

			      laux.insert(laux.end(),s);
		    }

		    Daux.Insertar(clave,laux);
	  }

	  D = Daux;

	  return is;
}

template <class T,class U>
int Diccionario<T,U>::size()const{
    return datos.size();
}

template <class T,class U>
typename list<data<T,U> >::iterator Diccionario<T,U>::begin(){
    return datos.begin();
}

template <class T,class U>
typename list<data<T,U> >::iterator Diccionario<T,U>::end(){
    return datos.end();
}

template <class T,class U>
typename list<data<T,U> >::const_iterator Diccionario<T,U>::begin() const{
    return datos.begin();
}

template <class T,class U>
typename list<data<T,U> >::const_iterator Diccionario<T,U>::end() const{
    return datos.end();
}
