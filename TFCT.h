#include "POLYNOME.h"
#ifndef TFCT_H
#define TFCT_H
#include "complexe.h"

class TFCT
 {
  private:

  POLYNOME NUM;
  POLYNOME DEN;
  float Te=1;

  public:

  void saisie_tfct(void);
  void affiche_tfct(void);
  void canonique();


	POLYNOME GetNUM()const;
	void SetNUM(POLYNOME);


	POLYNOME GetDEN()const;
	void SetDEN(POLYNOME);

    void bode(const double wmin,const double wmax,const int ndpoint) ;
	double gain(int);
	double phase(int);
	void Jury();
};
#endif
