#include <iostream>
#include "lexer.h"
#include "automate.h"


int main(void) {
   //string chaine("(1+34)*123");
	cout << "Tapez l'expression a tester :" << endl; 
	string chaine;
	cin >> chaine;

   Lexer l(chaine);

   cout << endl;
   cout << "Description de la chaine a analyser " << endl; 
   Symbole * s;
   while(*(s=l.Consulter())!=FIN) {
      s->affiche();
      cout<<endl;
      l.Avancer();
   }
   cout << endl; 

   Automate *a = new Automate(chaine);
   a->calcul();

   return 0;
}

