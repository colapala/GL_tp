#include "symbole.h"
#include <iostream>

void Symbole::affiche() {
   cout<<Etiquettes[ident];
}

void Entier::affiche() {
   Symbole::affiche();
   cout<<"("<<valeur<<")";
}

void Expression::affiche() {
	Symbole::affiche();
	cout << "(" << valeur << ")";
}

int Symbole::getValue(){
    return -1;
}

int Entier::getValue(){
    return valeur;
}

int Expression::getValue(){
    return valeur;
}
