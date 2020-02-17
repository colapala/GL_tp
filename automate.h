#pragma once

#include "lexer.h"
#include "symbole.h"
#include <stack>
#include <string>

class Etat;

using namespace std;

class Automate {

public:
  Automate(string flux);
  void decalage(Symbole *s, Etat *e);
  void reduction(int n, Symbole *s);
  void run();

protected:
  stack <Symbole *> symbolstack;
  stack <Etat *> statestack;
  Lexer *lexer;
};
