
#ifndef _ERREUR_H_
#define _ERREUR_H_
#include <string>

class Erreur
{
   private:
      int c;
      std::string exp;

   public:
      static const int ncarre = 0,
                       multiplication = 1,
                       notinmat = 2,
                       dbzero = 3;

      Erreur();
      Erreur(Erreur &s);
      Erreur(int a);
      int cause() const;
      std::string explic() const ;
};
#endif
