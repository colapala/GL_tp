#include "symbole.h"
#include <iostream>

void Symbole::affiche() {
   cout<<Etiquettes[identificateur];
}

void Entier::affiche() {
   Symbole::affiche();
   cout<<"("<<valeur<<")";
}

void Expression::affiche() {
	Symbole::affiche();
	cout << "(" << valeur << ")";
}

int Symbole::getValeur(){
    return -1;
}

int Entier::getValeur(){
    return valeur;
}

int Expression::getValeur(){
    return valeur;
}
