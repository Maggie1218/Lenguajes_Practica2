/*
 * Pr2.cpp
 *
 *  Created on: Feb 20, 2018
 *      Author: marga
 */
#include <iostream>
#include<cstring>
#include<sstream>
#include<vector>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

bool analize(string s, string **t, string q0, vector<string> Z, vector<string> Q, vector<string> F);

int main(){
	string sigma;
	string estados;
	string finales;
	string value;
	vector<string> Q;
	vector<string> Z;
	vector<string> F;
	char* q;
	char* f;
	char* z;

	cout << "Ingresa el alfabeto separado por comas" << endl;
	getline(cin, sigma);
	cout << "Ingresa los estados" << endl;
	getline(cin, estados);
	cout << "Ingresa los estados finales" << endl;
	getline(cin, finales);

	cout << sigma << endl;
	cout << estados << endl;
	cout << finales << endl;

	char *qs = const_cast<char*>(estados.c_str());    //convierte el string a char* para separar con strtok
	char *fs = const_cast<char*>(finales.c_str());
	char *alpha = const_cast<char*>(sigma.c_str());    //convierte el string a char* para separar con strtok

	 q = strtok (qs," ,.-");		//apuntamos al inicio de words y lo convierte a char*
		 while (q != NULL)				//mientras aun se obtengan elementos del string
		 	  {
		 		Q.push_back(string(q));	//convierte nuevamente a string y lo agrega a la lista
		 	    q = strtok (NULL, " ,.-");		//apunta a donde termino el token anterior
		 	  }

	z = strtok (alpha," ,.-");		//apuntamos al inicio de words y lo convierte a char*
		while (z != NULL){				//mientras aun se obtengan elementos del string  {
			Z.push_back(string(z));	//convierte nuevamente a string y lo agrega a la lista
		    z = strtok (NULL, " ,.-");		//apunta a donde termino el token anterior
	   }

	 f = strtok (fs," ,.-");		//apuntamos al inicio de words y lo convierte a char*
		 while (f != NULL){				//mientras aun se obtengan elementos del string
			F.push_back(string(f));	//convierte nuevamente a string y lo agrega a la lista
			f = strtok (NULL, " ,.-");		//apunta a donde termino el token anterior
		}


	string **transiciones =  (string  **)calloc(Q.size() , sizeof(string*));
	for(int i = 0; i < Q.size(); i++)
		transiciones[i] = (string *)calloc(Z.size() , sizeof(string));

/*	for (int i = 0; i< Q.size(); i++){
		cout << Q[i] << endl;
	}
	for (int j = 0; j< Z.size(); j++){
			cout << Z[j] << endl;
		}
	*/
	for (int i = 0; i<Q.size(); i++ ){
		for (int j = 0; j<Z.size(); j++){
			cout << "d(" << Q[i] << ", " << Z[j] << ")" << endl;
			getline(cin, value);
			transiciones[i][j] = value;
			cout << transiciones[i][j];
		}
	}

 }
