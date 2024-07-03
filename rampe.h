#ifndef RAMPE_H
#define RAMPE_H

#include <iostream>
#include "siggnal.h"

class rampe : public siggnal {
public:
	rampe();
	rampe(float, const int, const float);
	rampe(const rampe&);

	float get_r0()const;
	void set_r0(const float);

protected:

private:
	float r0;
};

#endif
