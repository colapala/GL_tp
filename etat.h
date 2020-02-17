#include "automate.h"
#include <string>
using namespace std;

class Etat1;
class Etat2;
class Etat3;
class Etat4;
class Etat5;
class Etat6;
class Etat7;
class Etat8;
class Etat9;

class Etat {

public:
  Etat();
  Etat(string s);
  virtual ~Etat();
  void afficher() const;
  virtual bool transition(Automate &automate, Symbole *s) = 0;
  virtual int etat();

protected:
  string nom;
};

class Etat0 : public Etat {
public:
  Etat0();
  bool transition(Automate &automate, Symbole *s);
  virtual int etat();

protected:
  int valeur;
};

class Etat1 : public Etat {
public:
  Etat1();
  bool transition(Automate &automate, Symbole *s);
  virtual int etat();

protected:
  int valeur;
};

class Etat2 : public Etat {
public:
  Etat2();
  bool transition(Automate &automate, Symbole *s);
  virtual int etat();

protected:
  int valeur;
};

class Etat3 : public Etat {
public:
  Etat3();
  bool transition(Automate &automate, Symbole *s);
  virtual int etat();

protected:
  int valeur;
};

class Etat4 : public Etat {
public:
  Etat4();
  bool transition(Automate &automate, Symbole *s);
  virtual int etat();

protected:
  int valeur;
};

class Etat5 : public Etat {
public:
  Etat5();
  bool transition(Automate &automate, Symbole *s);
  virtual int etat();

protected:
  int valeur;
};

class Etat6 : public Etat {
public:
  Etat6();
  bool transition(Automate &automate, Symbole *s);
  virtual int etat();

protected:
  int valeur;
};

class Etat7 : public Etat {
public:
  Etat7();
  bool transition(Automate &automate, Symbole *s);
  virtual int etat();

protected:
  int valeur;
};

class Etat8 : public Etat {
public:
  Etat8();
  bool transition(Automate &automate, Symbole *s);
  virtual int etat();

protected:
  int valeur;
};

class Etat9 : public Etat {
public:
  Etat9();
  bool transition(Automate &automate, Symbole *s);
  virtual int etat();

protected:
  int valeur;
};
