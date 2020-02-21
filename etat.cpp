#include "etat.h"
#include "automate.h"
#include "symbole.h"
#include <stdio.h>
#include <iostream>

Etat :: Etat(string s) {
    nom = s;
}

void Etat :: affiche() const {
    cout<< nom <<endl;
}

bool Etat0 :: transition(Automate &automate, Symbole *s) {
    switch (*s) {
        case EXP :
            automate.decalage(s, new Etat1());
            break;
        case INT :
            automate.decalage(s, new Etat3());
            break;
        case OPENPAR :
            automate.decalage(s, new Etat2());
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
            automate.decalage(s, new Etat5());
            break;
        case PLUS :
            automate.decalage(s, new Etat4());
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
            automate.decalage(s, new Etat6());
            break;
        case INT :
            automate.decalage(s, new Etat3());
            break;
        case CLOSEPAR :
            automate.decalage(s, new Etat2());
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
		case CLOSEPAR:
			automate.reduction(3, new ClosePar);
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
		case CLOSEPAR:
			automate.reduction(3, new ClosePar);
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
            automate.decalage(s, new Etat7());
            break;
        case INT :
            automate.decalage(s, new Etat3());
            break;
        case OPENPAR :
            automate.decalage(s, new Etat2());
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
            automate.decalage(s, new Etat8());
            break;
        case INT :
            automate.decalage(s, new Etat3());
            break;
        case OPENPAR :
            automate.decalage(s, new Etat2());
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
            automate.decalage(s, new Etat4());
            break;
        case MULT :
            automate.decalage(s, new Etat5());
            break;
        case CLOSEPAR :
            automate.decalage(s, new Etat9());
            break;
        default :
            automate.decalage(new Symbole(ERREUR, true), NULL);
            return false;
      }
    return true;
}
