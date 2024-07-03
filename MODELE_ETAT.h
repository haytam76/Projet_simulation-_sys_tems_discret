
#include <iostream>
#ifndef MODELE_ETAT_H
#define MODELE_ETAT_H
#include "MATRICE.h"
#include "TFCT.h"
#include <fstream>
#include "siggnal.h"
 class MODELE_ETAT

 {
   private:
   MATRICE A ;
   MATRICE B ;
   MATRICE C ;
   MATRICE D ;
   float Te;


   public:
    /*Période d'échantillonnage*/
	float GetTe() const;
	void SetTe(const float _Te);
	/*MATRICE d'état*/
	MATRICE& GetA();
	void SetA(MATRICE _A);

	/*MATRICE de commande*/
	MATRICE& GetB();
	void SetB(MATRICE _B);

	/*MATRICE d'observation*/
	MATRICE& GetC();
	void SetC(MATRICE _C);

	/*MATRICE d'action directe*/
	MATRICE& GetD();
	void SetD(MATRICE _D);

  MODELE_ETAT()=default;
  MODELE_ETAT(MATRICE a,MATRICE b,MATRICE c, MATRICE d ,float T);
  void saisie_mod_e(void);
  void affiche_mod_e(void);
  void Ft2Retat(TFCT& H);
  void TFCT_to_MODELE_E_COMMANDE(TFCT& H);
  void simu(const int, siggnal);
  void Affiche_RepresentationEtat() const ;



 };












#endif
