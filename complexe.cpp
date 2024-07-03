
#include <iostream>
#include <cmath>
#include "complexe.h"
#include "POLYNOME.h"
#include "TFCT.h"
#define i sqrt(-1)
using namespace std;

//CONSTRUCTEURS ET DESTRUCTEURS

complexe::complexe() :
		reel(0), imaginaire(0) {


}

complexe::complexe(double _reel, double _imaginaire) :
		reel(_reel), imaginaire(_imaginaire) {

}

complexe::complexe(const complexe& I) :
		reel(I.reel), imaginaire(I.imaginaire) {

}

complexe::complexe(const float a): reel(a), imaginaire(0){

}

complexe::~complexe() {

}

//ACCESSEURS ET MODIFICATEURS

double complexe::Getreel() {
	return reel;
}

void complexe::Setreel(double _reel) {
	reel = _reel;
}

double complexe::Getimaginaire() {
	return imaginaire;
}

void complexe::Setimaginaire(double _imaginaire) {
	imaginaire = _imaginaire;
}

//SURCHARGE DES OPERATEURS

complexe& complexe::operator =(const complexe& I) {
	if (&I != this) {
		reel = I.reel;
		imaginaire = I.imaginaire;
	}
	return *this;
}

complexe operator+(const complexe& I1, const complexe& I2) {
	complexe I;


	I.reel = I1.reel + I2.reel;
	I.imaginaire = I1.imaginaire + I2.imaginaire;
	return I;
}

complexe operator-(const complexe& I1, const complexe& I2) {
	complexe I;
	I.reel = I1.reel - I2.reel;
	I.imaginaire = I1.imaginaire - I2.imaginaire;
	return I;
}

complexe operator*(const complexe& I1, const complexe& I2) {
	/*
	 * I1 = Re(I1) + i*Im(I1)
	 * I2 = Re(I2) + i*Im(I2)
    */
	complexe I;
	I.reel = I1.reel * I2.reel + I1.imaginaire * I2.imaginaire;
	I.imaginaire = I1.reel * I2.imaginaire + I1.imaginaire * I2.reel;
	return I;
}

complexe operator/(const complexe& I1, const complexe& I2){
	complexe I;
	I.reel = (I1.reel*I2.reel+I1.imaginaire*I2.imaginaire)/(pow(I2.reel,2)+pow(I2.imaginaire,2));
	I.imaginaire = (I1.imaginaire*I2.reel-I1.reel*I2.imaginaire)/(pow(I2.reel,2)+pow(I2.imaginaire,2));
	return I;
}

ostream& operator<<(ostream& out, const complexe& I) {
	out << I.reel;
	out << " + i* ";
	out << I.imaginaire;
	return out;
}

//TRANSFORMATION DISCRET TO COMPLEXE

complexe complexe::poly2cplx(POLYNOME& p, const int w0, const float Te){
	/*
	 * Z^n = e^(n*j*2*pi*f*Te)
	 * Z^n = e^(n*j*w0*Te) = cos(n*w0*Te)+ j*sin(n*w0*Te)
	*/
	double Teta = w0 * Te;
	for (int index = 0; index < p.get_degre() + 1; index++) {

		reel += p.get_coef(index) * cos(index * Teta);
		imaginaire += (p.get_coef(index) * sin(index * Teta));
		cout.precision(3);

	}
	complexe I;
	I.imaginaire = imaginaire;
	I.reel = reel;

	return I;
}

//CALCUL DU MODULE ET ARGUMENT

double complexe::module() {
	double res;
	res = sqrt((pow(reel,2)) + (pow(imaginaire,2)));
	return res;
}

double complexe::argument() {

	double res;
	double quotient = imaginaire/reel;
	res = atan(quotient);
	return res;
}

//CALCUL DE L'EXPO ET PUISSANCE

complexe exp2cplx(int mod, double teta){
	/*
	 * Z=e^(p*Te)	p=j*w	w=2*pi*f
	 * Z=e^(j*2*pi*f*Te)
	 * => mod = 1 et teta = w0*Te = 2*pi*f0*Te
    */
	complexe I;
	I.reel = mod*cos(teta);
	I.imaginaire = mod*sin(teta);
	return I;
}

complexe complexe::puissance(complexe I, int n) {
	complexe res(1,1);
	if (n == 0) {
		res = 1;
	} else {
		for (int j = 1; j < n; j++) {
			res = res * I;
		}
	}
	return res;
}



