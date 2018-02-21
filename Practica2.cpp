/*
 * Practica2.cpp
 *
 *  Created on: Feb 17, 2018
 *      Author: marga
 */
#include <iostream>
#include<cstring>
#include<sstream>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<cstdio>

using namespace std;

bool analize(string s, string **t, string q0, vector<string> Z, vector<string> Q, vector<string> F);

int main(){
	string sigma;
	string qs;
	string fs;
	string funciona;
	string cads;
	vector<string> Z;
	vector<string> Q;
	vector<string> F;
	vector<string> W;
	char* z;
	char* q;
	char* f;
	char* w;
	bool res;


	vector<string> ::iterator iteW;

	cout << "Ingresa el alfabeto Sigma separado por comas" <<endl;
	getline(cin, sigma);
	cout << "Ingresa los estados" <<endl;
	getline(cin, qs);
	cout << "Ingresa los estados finales" <<endl;
	getline(cin, fs);


	char *alpha = const_cast<char*>(sigma.c_str());    //convierte el string a char* para separar con strtok
	char *iniciales = const_cast<char*>(qs.c_str());
	char *finales = const_cast<char*>(fs.c_str());




	 q = strtok (iniciales," ,.-");		//apuntamos al inicio de words y lo convierte a char*
		 while (q != NULL)				//mientras aun se obtengan elementos del string
		 	  {
		 		Q.push_back(string(q));	//convierte nuevamente a string y lo agrega a la vectora
		 	    q = strtok (NULL, " ,.-");		//apunta a donde termino el token anterior
		 	  }

	f = strtok (finales," ,.-");		//apuntamos al inicio de words y lo convierte a char*
			 while (f != NULL)				//mientras aun se obtengan elementos del string
			  {
			 	F.push_back(string(f));	//convierte nuevamente a string y lo agrega a la vectora
			    f = strtok (NULL, " ,.-");		//apunta a donde termino el token anterior
			  }

	 z = strtok (alpha," ,.-");		//apuntamos al inicio de words y lo convierte a char*
			while (z != NULL)				//mientras aun se obtengan elementos del string
			  {
			   Z.push_back(string(z));	//convierte nuevamente a string y lo agrega a la vectora
			   z = strtok (NULL, " ,.-");		//apunta a donde termino el token anterior
			  }

	string **transiciones;			//se crea una matriz dinamica del tamaño |Q| x |Z|
	transiciones= (string**)calloc(Q.size(),sizeof(string*));

			for(unsigned int i=0;i<Q.size();i++){
			 	transiciones[i]= (string*)calloc(Z.size(),sizeof(string));
			 }



		//Se llena la matriz mediante entradas del usuario
	for(unsigned int i=0; i< Q.size();i++){
		for (unsigned int j=0; j<Z.size(); j++){
			cout << "d(" << Q[i] << ", " << Z[j] << ")" << endl;
			getline(cin, funciona);
			transiciones[i][j] = funciona;

			cout << transiciones[i][j] <<endl;
		}
	}//




	cout << "Ingresa las cadenas a analizar, separadas por comas" << endl;
	getline(cin, cads);
	//recibe las cadenas a analizar
		char *chains = const_cast<char*>(cads.c_str());
	 w = strtok (chains," ,.-");		//apuntamos al inicio de words y lo convierte a char*
		 while (w != NULL)				//mientras aun se obtengan elementos del string
		 	  {
		 		W.push_back(string(w));	//convierte nuevamente a string y lo agrega a la vectora
		 	    w = strtok (NULL, " ,.-");		//apunta a donde termino el token anterior
		 	  }

		 //recorre el vector W mediante un iterador y a traves de este, llama a la funcion
		 //analize pasando como cadena a analizar el elemento en la posicion del iterador
	for (iteW = W.begin(); iteW != W.end(); iteW++){
		 		  res = analize(*iteW,transiciones, Q[0], Z, Q, F);
		 		  if (res)
		 			 cout<< "La cadena " << *iteW << " es aceptada" << endl;
		 		  else
		 			 cout<< "La cadena " << *iteW << " no es aceptada"<<endl;
		 	  }

		 	 cin.get();
}


	bool analize(string s, string** t, string q0, vector<string> Z, vector<string> Q, vector<string> F){
		bool r = false;				//inicializa el resultado en false
		size_t q = 0;				//crea e inicializa variables
		size_t z=0;
		string status = q0;
		string current;

		//recorre cada elemento de la cadena recibida para analizar, s
			for(unsigned int o = 0 ; o<s.length(); o++){
				current = s[o];								//por cada letra,
				for(unsigned int i =0; i<Q.size(); i++){	//itera en el vector de estados
					if(status == Q[i]){						//buscando el actual
						q=i;								//una vez encontrado, lo guarda en q
						break;
					}

				}

				for(unsigned int i =0; i<Z.size(); i++){	//realiza el mismo prodecimiento descrito
					if(current== Z[i]){						//para el vector de estados, pero en el
						z=i;								//vector del alfabeto, buscando la letra
						break;								//que se esta analizando en el vector
					}										//una vez que se encuentra, lo guarda en z
				}

			   status = t[q][z];							//se accede a la matriz con los indices
			}												//obtenidos anteriormente y se reasiga a status

				for (unsigned int i=0; i<F.size(); i++){	//una vez que se recorrieron todos
					if (F[i] == status)						//los elementos de la palabra
						r = true;							//busca si el estado en que se quedo
				 }											//se encuentra en el vector de estados finales
				return r;									//en caso de ser asi, r = true y acepta la cadena
			}
