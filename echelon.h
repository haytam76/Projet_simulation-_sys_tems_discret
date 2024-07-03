#ifndef ECHELON_H
#define ECHELON_H

#include <iostream>
#include "siggnal.h"

class echelon : public siggnal {
public:
	echelon();
	echelon(float, float, const int, const float);
	echelon(const echelon&);

	float get_ech()const;
	void set_ech(const float);

	float get_t0()const;
	void set_t0(const float);

protected:

private:
	float vech;
	float t0;
};

#endif
