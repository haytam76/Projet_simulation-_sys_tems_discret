#ifndef COMPLEXE_H_
#define COMPLEXE_H_
class complexe;

#include <iostream>
#include <cmath>
#include "POLYNOME.h"
#include "TFCT.h"
using namespace std;


class complexe {
public:
	complexe();
	complexe(double _reel, double _imaginaire);
	complexe(const complexe& I);
	complexe(const float);
	virtual ~complexe();

	/*Partie Reelle*/
	double Getreel();
	void Setreel(double _reel);

	/*Partie Imaginaire*/
	double Getimaginaire();
	void Setimaginaire(double _imaginaire);

	/*Opérateurs*/
	complexe& operator=(const complexe& I);
	friend complexe operator+(const complexe& I1, const complexe& I2);
	friend complexe operator-(const complexe& I1, const complexe& I2);
	friend complexe operator*(const complexe& I1, const complexe& I2);
	friend complexe operator/(const complexe& I1, const complexe& I2);
	friend ostream& operator<<(ostream& out, const complexe& I);

	/*Module & Arguments*/
	complexe poly2cplx(POLYNOME& p, const int w0, const float Te);		//Passer de la forme en z à la forme complexe

	double module();											        // méthode pour déterminer le module d'un complexe
	double argument();										          	// méthode pour déterminer l'argument d'un complexe


	/*Méthodes Maths*/
	friend complexe exp2cplx(int mod, double teta);					// de la forme exponentielle à la forme complexe
	complexe puissance(complexe I, int n);							// permet de calculer un nombre complexe élevé à la puissance



protected:

private:
	float reel;
	float imaginaire;
};

#endif
