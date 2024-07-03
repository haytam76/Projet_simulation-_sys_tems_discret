
#include <iostream>
#include "siggnal.h"

using namespace std;

//CONSTRUCTEURS ET DESTRUCTEUR

siggnal::siggnal() : Te(), N(), Amp(new float[0]), Time(new float[0]) {

}

siggnal::siggnal(int _N, float _Te) : N(_N), Te(_Te), Amp(new float[_N]), Time(new float[_N]) {
	float t = 0;
	for (int i = 0; i < N; i++){
		Amp[i] = 0;
		Time[i] = t;
		t = t + Te;
	}
}

siggnal::siggnal(const siggnal& S) : N(S.N), Te(S.Te), Amp(new float[S.N]), Time(new float[S.N]) {
	for (int i = 0; i < N; i++)
		Amp[i] = S.Amp[i];
}

siggnal::~siggnal() {
	delete[] Amp;
	delete[] Time;
}

//ACCESSEURS ET MODIFICATEURS

float siggnal::get_amp(const int _i)const {
	if (_i<0 || _i > N)
		throw "ERREUR";
	else
		return Amp[_i];
}

void siggnal::set_amp(const int _i, const float _amp) {
	if (_i<0 || _i > N)
		throw "ERREUR";
	else
		Amp[_i] = _amp;
}

int siggnal::get_n()const {
	return N;
}

void siggnal::set_n(const int _N) {
	N = _N;
	float* Amp;
	Amp = new float[N];
	Time = new float[N];
	float t = 0;
	for (int i = 0; i < N; i++) {
		Time[i] = t;
		t = t + Te;
	}
}

float siggnal::get_te() const {
	return Te;
}

void siggnal::set_te(const int _Te) {
	Te = _Te;
	float t = 0;
	for (int i = 0; i < N; i++) {
		Time[i] = t;
		t = t + Te;
	}
}

//AFFICHAGE DU SIGNAL

void siggnal::Print_siggnal() const {
	cout << endl << "La periode d'echantillonnage est Te = " << Te << " s";
	for (int i = 0; i < N; i++) {
		cout << endl << "[" << Time[i] << "  ;  " << Amp[i] << "]";
	}
}
