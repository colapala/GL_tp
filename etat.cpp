#include "etat.h"
#include "automate.h"
#include "symbole.h"
#include <stdio.h>
#include <iostream>

Etat :: Etat () {}
Etat :: Etat(string s) {
    nom=s;
}
Etat :: ~Etat () {}

void Etat :: afficher() const {
    cout<< nom <<endl;
}

Etat0 :: Etat0() : Etat ("E0") {}
Etat1 :: Etat1() : Etat ("E1"){}
Etat2 :: Etat2 () : Etat ("E2") {}
Etat3 :: Etat3 () : Etat ("E3") {}
Etat4 :: Etat4 () : Etat ("E4") {}
Etat5 :: Etat5 () : Etat ("E5") {}
Etat6 :: Etat6 () : Etat ("E6") {}
Etat7 :: Etat7 () : Etat ("E7") {}
Etat8 :: Etat8 () : Etat ("E8") {}
Etat9 :: Etat9 () : Etat ("E9") {}

int Etat :: etat() { return -1 ;}
int Etat0 :: etat() { return 0 ;}
int Etat1 :: etat() { return 1 ;}
int Etat2 :: etat() { return 2 ;}
int Etat3 :: etat() { return 3 ;}
int Etat4 :: etat() { return 1 ;}
int Etat5 :: etat() { return 1 ;}
int Etat6 :: etat() { return 1 ;}
int Etat7 :: etat() { return 1 ;}
int Etat8 :: etat() { return 1 ;}
int Etat9 :: etat() { return 1 ;}

bool Etat0 :: transition(Automate &automate, Symbole *s) {
    switch (*s) {
        case EXP :
            automate.decalage(s, new Etat1);
            break;
        case INT :
            automate.decalage(s, new Etat3);
            break;
        case OPENPAR :
            automate.decalage(s, new Etat2);
            break;
        default :
            automate.decalage(new Symbole(ERREUR, true), NULL);
            return false;
      }
    return true;
}

bool Etat1 :: transition(Automate &automate, Symbole *s) {
    switch (*s) {
        case FIN :
            return false;
        case MULT :
            automate.decalage(s, new Etat5);
            break;
        case PLUS :
            automate.decalage(s, new Etat4);
            break;
        default :
            automate.decalage(new Symbole(ERREUR, true), NULL);
            return false;
      }
    return true;
}

bool Etat2 :: transition(Automate &automate, Symbole *s) {
    switch (*s) {
        case EXP :
            automate.decalage(s, new Etat6);
            break;
        case INT :
            automate.decalage(s, new Etat3);
            break;
        case CLOSEPAR :
            automate.decalage(s, new Etat2);
            break;
        default :
            automate.decalage(new Symbole(ERREUR, true), NULL);
            return false;
      }
    return true;
}

bool Etat3 :: transition(Automate &automate, Symbole *s) {
    switch (*s) {
        case PLUS :
            automate.reduction(1, new Plus);
            break;
        case CLOSEPAR :
            automate.reduction(1, new ClosePar);
            break;
        case MULT :
            automate.reduction(1, new Mult);
            break;
        case FIN :
            automate.reduction(1, new Fin);
            break;
        default :
            automate.decalage(new Symbole(ERREUR, true), NULL);
            return false;
      }
    return true;
}

bool Etat7 :: transition(Automate &automate, Symbole *s) {
    switch (*s) {
        case PLUS :
            automate.reduction(3, new Plus);
            break;
        case MULT :
            automate.reduction(3, new Mult);
            break;
        case FIN :
            automate.reduction(3, new Fin);
            break;
        default :
            automate.decalage(new Symbole(ERREUR, true), NULL);
            return false;
      }
    return true;
}

bool Etat8 :: transition(Automate &automate, Symbole *s) {
    switch (*s) {
        case PLUS :
            automate.reduction(3, new Plus);
            break;
        case MULT :
            automate.reduction(3, new Mult);
            break;
        case FIN :
            automate.reduction(3, new Fin);
        break;
        default :
            automate.decalage(new Symbole(ERREUR, true), NULL);
            return false;
      }
    return true;
}

bool Etat9 :: transition(Automate &automate, Symbole *s) {
    switch (*s) {
        case PLUS :
            automate.reduction(3, new Plus);
            break;
        case CLOSEPAR :
            automate.reduction(3, new ClosePar);
            break;
        case MULT :
            automate.reduction(3, new Mult);
            break;
        case FIN :
            automate.reduction(3, new Fin);
            break;
        default :
            automate.decalage(new Symbole(ERREUR, true), NULL);
            return false;
      }
    return true;
}

bool Etat4 :: transition(Automate &automate, Symbole *s) {
    switch (*s) {
        case EXP :
            automate.decalage(s, new Etat7);
            break;
        case INT :
            automate.decalage(s, new Etat3);
            break;
        case OPENPAR :
            automate.decalage(s, new Etat2);
            break;
        default :
            automate.decalage(new Symbole(ERREUR, true), NULL);
            return false;
      }
    return true;
}

bool Etat5 :: transition(Automate &automate, Symbole *s) {
    switch (*s) {
        case EXP :
            automate.decalage(s, new Etat8);
            break;
        case INT :
            automate.decalage(s, new Etat3);
            break;
        case OPENPAR :
            automate.decalage(s, new Etat2);
            break;
        default :
            automate.decalage(new Symbole(ERREUR, true), NULL);
            return false;
      }
    return true;
}

bool Etat6 :: transition(Automate &automate, Symbole *s) {
    switch (*s) {
        case PLUS :
            automate.decalage(s, new Etat4);
            break;
        case MULT :
            automate.decalage(s, new Etat5);
            break;
        case CLOSEPAR :
            automate.decalage(s, new Etat9);
            break;
        default :
            automate.decalage(new Symbole(ERREUR, true), NULL);
            return false;
      }
    return true;
}
