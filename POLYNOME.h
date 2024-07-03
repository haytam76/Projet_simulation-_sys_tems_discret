#include <iostream>
#ifndef POLYNOME_H
#define POLYNOME_H



class POLYNOME
 {
  private:
  int degre;
  float coef[20];

  public:

  int get_degre(void) {return degre;}
  float get_coef(int i) {return coef[i];}
  void raz(void);
  void ajuste_degre(void);
  void saisie(void);
  void affiche(void);
  void additionner(POLYNOME);
  void multiplier(POLYNOME);
  void copie(POLYNOME);
  friend std::ostream& operator<<(std::ostream& , const POLYNOME& );


  float Eval(int val);


};
POLYNOME operator + (POLYNOME&,POLYNOME&);
POLYNOME operator * (POLYNOME&,POLYNOME&);
std::ostream& operator << (std::ostream&, POLYNOME&);

#endif
