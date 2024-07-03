
#ifndef SINUS_H
#define SINUS_H

#include <iostream>
#include <cmath>
#include "siggnal.h"

class sinus : public siggnal {
public:
	sinus();
	sinus(float, float, const int, const float);
	sinus(const sinus&);

	float get_amps()const;
	void set_amps(const float);

	float get_f()const;
	void set_f(const float);

protected:

private:
	float amps;
	float f;
};

#endif
