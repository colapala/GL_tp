#include "symbole.h"
#include <iostream>

void Symbole::Affiche() {
   cout<<Etiquettes[ident];
}

void Entier::Affiche() {
   Symbole::Affiche();
   cout<<"("<<valeur<<")";
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
