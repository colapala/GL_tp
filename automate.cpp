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
   /* if(s->isTerminal()) {
        lexer->Avancer();
    }*/
}

void Automate :: reduction(int n, Symbole *s) {
    stack<Symbole *> aEnlever;

    for (int i = 0; i < n; i++) {
      delete (statestack.top());
      statestack.pop();
      aEnlever.push(symbolstack.top());
      symbolstack.pop();
    }

    int val;

    if (n == 1) {
      val = aEnlever.top()->getValue();
    } else if (n == 3) {
      if (*aEnlever.top() == OPENPAR) {
        aEnlever.pop();
        val = aEnlever.top()->getValue();
      } else {
        val = aEnlever.top()->getValue();
        aEnlever.pop();
        if (*aEnlever.top() == MULT) {
          aEnlever.pop();
          val = val * aEnlever.top()->getValue();
        } else {
          aEnlever.pop();
          val = val + aEnlever.top()->getValue();
        }
      }
    }

    statestack.top()->transition(*this, new Expression(val));
    lexer->putSymbol(s);
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
      cout << "Syntaxe non reconnu : caractere invalide" << endl;
    }
}
