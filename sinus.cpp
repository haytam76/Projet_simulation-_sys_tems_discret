#include <iostream>
#include <cmath>
#include "siggnal.h"
#include "sinus.h"

using namespace std;

//CONSTRUCTEURS

sinus::sinus() : amps(), f(), siggnal(0, 0) {

}

sinus::sinus(float _amps, float _f, const int _N, const float _Te) : amps(_amps), f(_f), siggnal(_N, _Te) {
		for (int i = 0; i < _N; i++)
			Amp[i] = amps*sin(6.28 * f * i);
}

sinus::sinus(const sinus& s) : amps(s.amps), f(s.f) {

}

//ACCESSEURS ET MODIFICATEURS

float sinus::get_amps() const {
	return amps;
}

void sinus::set_amps(const float _amps) {
	amps = _amps;
}

float sinus::get_f() const {
	return f;
}

void sinus::set_f(const float _f) {
	f = _f;
}


