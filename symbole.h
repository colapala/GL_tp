#pragma once

#include <string>
#include <map>
using namespace std;

enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR, EXP};

const string Etiquettes[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR", "EXP" };

class Symbole {
   public:
      Symbole(int i, bool b) : ident(i), terminal(b) {  }
      virtual ~Symbole() { }
      operator int() const { return ident; }
      virtual void affiche();
      bool isTerminal() { return terminal; }
      virtual int getValue ();

   protected:
      int ident;
      bool terminal;
};

class Entier : public Symbole {
   public:
      Entier(int v) : Symbole(INT, true), valeur(v) { }
      ~Entier() { }
      virtual void affiche();
      int getValue ();
   protected:
      int valeur;
};

class Expression : public Symbole {
    public:
    Expression (int v) : Symbole(EXP,false), valeur(v) {}
    virtual~Expression() {}
	virtual void affiche();
    int getValue ();

protected :
	int valeur;
};

class OpenPar : public Symbole {
    public:
    OpenPar () : Symbole(OPENPAR,true) {}
    virtual~OpenPar() {}
};

class ClosePar : public Symbole {
    public:
    ClosePar () : Symbole(CLOSEPAR,true) {}
    virtual~ClosePar() {}
};

class Mult : public Symbole {
    public:
    Mult () : Symbole(MULT,true) {}
    virtual~Mult() {}
};

class Plus : public Symbole {
    public:
    Plus () : Symbole(PLUS,true) {}
    virtual~Plus() {}
};

class Fin : public Symbole {
    public:
    Fin () : Symbole(FIN,true) {}
    virtual~Fin() {}
};

class Erreur : public Symbole {
    public:
    Erreur () : Symbole(ERREUR,true) {}
    virtual ~Erreur() {}
};

