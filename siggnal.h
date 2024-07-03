#ifndef siggnal_H
#define siggnal_H

#include <iostream>

using namespace std;

class siggnal {
public:
	siggnal();
	siggnal(int  , float  );
	siggnal(const siggnal& );
	virtual ~siggnal();

	float get_amp(const int )const;
	void set_amp(const int , const float );

	int get_n()const;
	void set_n(const int );

	float get_te()const;
	void set_te(const int );

	void Print_siggnal() const;
protected:
	float* Amp;
	float* Time;
	int N;
	float Te;
private:

};

#endif

