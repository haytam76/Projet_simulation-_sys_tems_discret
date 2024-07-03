#include <iostream>
#include "siggnal.h"
#include "rampe.h"

using namespace std;

//CONSTRUCTEURS

rampe::rampe() : r0(), siggnal(0, 0) {

}

rampe::rampe(float _r0, const int _N, const float _Te) : r0(_r0), siggnal(_N, _Te) {
	if (r0 > (_N * _Te) || r0 < 0)
		throw "ERREUR";
	else {
		float ri = 0;
		int i = 0;
		while (ri < r0) {
			ri = ri + _Te;
			i = i + 1;
		}
		for (int j = 0; j < i; j++)
			Amp[j] = 0;
		for (int j = i; j < _N; j++)
			Amp[j] = Amp[j-1]+1;
	}
}

rampe::rampe(const rampe& e) : r0(e.r0) {

}

//ACCESSEURS ET MODIFICATEURS

float rampe::get_r0() const {
	return r0;
}

void rampe::set_r0(const float _r0) {
	r0 = _r0;
}


