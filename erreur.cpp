#include "erreur.h"
#include <iostream>

Erreur::Erreur():c(-1)
{
}

Erreur::Erreur(Erreur &source):c(source.c)
{
   exp = source.exp;
}

Erreur::Erreur(int a):c(a)
{
   switch(a)
   {
      case ncarre:
         exp = "matrice non carre, operation impossible";
         break;
      case multiplication:
         exp = "erreur de dimension, operation impossible";
         break;
      case notinmat:
         exp = "erreur de taille, operation impossible";
         break;
      case dbzero:
         exp = "division par 0, operation impossible";
         break;
      default:
         exp= "erreur inconnue";
   }
}

int Erreur::cause() const
{
   return c;
}

std::string Erreur::explic() const
{
   return exp;
}
