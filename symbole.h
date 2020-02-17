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
      virtual void Affiche();
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
      virtual void Affiche();
      int getValue ();
   protected:
      int valeur;
};

class Expression : public Symbole {
    public:
    Expression () : Symbole(EXP,false) {}
    virtual~Expression() {}
    virtual double eval(const map <string,double> & valeurs) = 0;
    int getValue ();
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
