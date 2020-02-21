#include "automate.h"
#include "etat.h"
#include "iostream"
#include "stdio.h"


Automate::Automate(string flux){
    this->lexer = new Lexer (flux);
    Etat0 * depart = new Etat0 ();
    statestack.push(depart);
}

void Automate :: decalage(Symbole *s, Etat*e){
    symbolstack.push(s);
    statestack.push(e);
   if(s->isTerminal()) {
        lexer->Avancer();
    }
}

void Automate :: reduction(int n, Symbole *s) {
    stack<Symbole *> aReduire;

	// Création de la pile avec les symboles à reduire
    for (int i = 0; i < n; i++) {
      delete (statestack.top());
      statestack.pop();
      aReduire.push(symbolstack.top());
      symbolstack.pop();
    }

    int valeurExpression;

    if (n == 1) {
		// L'expression se résume à un entier
      valeurExpression = aReduire.top()->getValeur();
    } else if (n == 3) {
		// L'expression est de type E+E, E*E, (E) 
      if (*aReduire.top() == OPENPAR) {
        aReduire.pop();
        valeurExpression = aReduire.top()->getValeur();
      } else {
		// Récupération de la valeur de la première expression
        valeurExpression = aReduire.top()->getValeur();
        aReduire.pop();
        if (*aReduire.top() == MULT) {
			// Application de la mutliplication
          aReduire.pop();
          valeurExpression *= aReduire.top()->getValeur();
        } else {
			// Application de l'addition
          aReduire.pop();
		  valeurExpression += aReduire.top()->getValeur();
        }
      }
    }
	// Transition avec la nouvelle Expression
    statestack.top()->transition(*this, new Expression(valeurExpression));
    lexer->garderSymbole(s);
}

void Automate :: calcul(){
    bool prochainEtat = true;

    while (prochainEtat) {
      Symbole *s = lexer->Consulter();
      lexer->Avancer();
      prochainEtat = statestack.top()->transition(*this, s);
    }
    if (*symbolstack.top() != ERREUR) {
      int resultat = symbolstack.top()->getValeur();
      cout << "Syntaxe correcte" << endl << "Resultat : " << resultat << endl;
    } else {
      cout << "Syntaxe non reconnue" << endl;
    }
}
