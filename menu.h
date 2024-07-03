
#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <windows.h>
#include <cmath>
#include <fstream>
#include "POLYNOME.h"
#include "MATRICE.h"
#include "TFCT.h"
#include "MODELE_ETAT.h"
#include "siggnal.h"
#include "echelon.h"
#include "rampe.h"
#include "sinus.h"
#include "complexe.h"


class menu {
public:
	menu();

	int menu_principal();
	void menu_POLYNOME();
	void menu_MATRICE();
	void menu_TFCT();
	void menu_rep_etat(void);

protected:

private:

};

void Go_Menu();
#endif
