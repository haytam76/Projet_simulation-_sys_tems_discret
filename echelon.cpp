#include <iostream>
#include "siggnal.h"
#include "echelon.h"

using namespace std;

//CONSTRUCTEURS ET DESTRUCTEURS

echelon::echelon() : vech(), t0(),siggnal(0,0) {

}

echelon::echelon(float _vech, float _t0, const int _N, const float _Te) : vech(_vech), t0(_t0), siggnal (_N, _Te) {
	if (t0 > (_N * _Te) || t0 < 0)
		throw "ERREUR";
	else {
		float ti = 0;
		int i = 0;
		while (ti < t0) {
			ti = ti + _Te;
			i = i + 1;
		}
		for (int j = 0; j < i; j++)
			Amp[j]= 0;
		for (int j = i; j < _N; j++)
			Amp[j] = vech;
	}
}

echelon::echelon(const echelon& e) : vech(e.vech), t0(e.t0) {

}

//ACCESSEURS ET MODIFICATEURS

float echelon::get_ech() const {
	return vech;
}

void echelon::set_ech(const float _vech) {
	vech = _vech;
}

float echelon::get_t0() const {
	return t0;
}

void echelon::set_t0(const float _t0) {
	t0 = _t0;
}


