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

    for (int i = 0; i < n; i++) {
      delete (statestack.top());
      statestack.pop();
      aReduire.push(symbolstack.top());
      symbolstack.pop();
    }

    int val;

    if (n == 1) {
      val = aReduire.top()->getValue();
    } else if (n == 3) {
      if (*aReduire.top() == OPENPAR) {
        aReduire.pop();
        val = aReduire.top()->getValue();
      } else {
        val = aReduire.top()->getValue();
        aReduire.pop();
        if (*aReduire.top() == MULT) {
          aReduire.pop();
          val = val * aReduire.top()->getValue();
        } else {
          aReduire.pop();
          val = val + aReduire.top()->getValue();
        }
      }
    }

    statestack.top()->transition(*this, new Expression(val));
    lexer->garderSymbole(s);
}

void Automate :: run(){
    bool prochainEtat = true;

    while (prochainEtat) {
      Symbole *s = lexer->Consulter();
      lexer->Avancer();
      prochainEtat = statestack.top()->transition(*this, s);
    }
    if (*symbolstack.top() != ERREUR) {
      int resultat = symbolstack.top()->getValue();
      cout << "Syntaxe correcte" << endl << "Résultat : " << resultat << endl;
    } else {
      cout << "Syntaxe non reconnue" << endl;
    }
}
