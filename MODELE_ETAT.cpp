
#include "MATRICE.h"
#include "TFCT.h"
#include <iostream>
#include "MODELE_ETAT.h"
#include <fstream>
#include "siggnal.h"

//ACCESSEURS ET MODIFICATEURS

float MODELE_ETAT::GetTe() const {
	return Te;
}

void MODELE_ETAT::SetTe(const float _Te) {
	Te = _Te;
}

MATRICE& MODELE_ETAT::GetA() {
	return A;
}

void MODELE_ETAT::SetA(MATRICE _A) {
	A = _A;
}
MATRICE& MODELE_ETAT::GetB() {
	return B;
}

void MODELE_ETAT::SetB(MATRICE _B) {
	B = _B;
}

MATRICE& MODELE_ETAT::GetC() {
	return C;
}

void MODELE_ETAT::SetC(MATRICE _C) {
	C = _C;
}

MATRICE& MODELE_ETAT::GetD() {
	return D;
}

void MODELE_ETAT::SetD(MATRICE _D) {
	D = _D;
}

//SAISIE MODELE D'ETAT

void MODELE_ETAT::saisie_mod_e(void)
{
std::cout<<"donner n"<<std::endl;
int taille_A =0;
std::cin>> taille_A;


MATRICE A1(taille_A,taille_A,1);
std::cout<<"donner A"<<std::endl;
A1.saisie();

MATRICE A2(taille_A,1,1);
std::cout<<"donner B"<<std::endl;
A2.saisie();

MATRICE A3(1,taille_A,1);
std::cout<<"donner C"<<std::endl;
A3.saisie();

std::cout<<"donner D"<<std::endl;
MATRICE A4(1,1,1);
A4.saisie();



A=A1;
B=A2;
C=A3;
D=A4;

}

//AFFICHAGE MODELE D'ETAT

void MODELE_ETAT::affiche_mod_e(void)
{
 int k=0;
 int h = 0;
 int nb_l=A.nb_lignes();



     std::cout<<"Te = "<<std::endl;
     std::cout<< Te <<std::endl;


     std::cout<<"A = "<<std::endl;
     std::cout<< A <<std::endl;

     std::cout<<"B = "<<std::endl;
     std::cout<< B <<std::endl;

     std::cout<<"C = "<<std::endl;
     std::cout<< C <<std::endl;

     std::cout<<"D = "<<std::endl;
     std::cout<< D <<std::endl;




}

//CONSTRUCTEURS

 MODELE_ETAT::MODELE_ETAT(MATRICE a,MATRICE b,MATRICE c, MATRICE d ,float T ):A(a),B(b),C(c),D(d),Te(T)
{

}

//TRANSFORMATION TFCT TO MODELE D'ETAT POUR LA SIMULATION DEPUIS TFCT

void MODELE_ETAT::TFCT_to_MODELE_E_COMMANDE(TFCT &H)
 {
   int s ;
   s=H.GetDEN().get_degre();
   MATRICE A1(s,s,0);
   MATRICE A2(s,1,0);
   MATRICE A3(1,s,0);
   MATRICE A4(1,1,0);

   for  (int i =0 ;i<s ;i++)
   {
       A1.Setcoeff(s-1 , i ,-H.GetDEN().get_coef(i));

   }
   int k=1;
   int l=0;
   A1.Setcoeff(0,1,1);
   while(k<s-1 && l<s-1)
   {

         k=k+1;
         l=l+1;
         A1.Setcoeff(l , k , 1);
   }
   A2.Setcoeff(s-1,0,1);
   A3.Setcoeff(0,0,-H.GetDEN().get_coef(0));


A=A1;
B=A2;
C=A3;
D=A4;


}

//SIMULATION

void MODELE_ETAT::simu(const int CI, siggnal entree)
 {
	ofstream file("Simu.txt", ios::out | ios::trunc);
	if (file) {
		cout << endl << endl << "Simu:" << endl << 'k' << "\t" << "U(k)" << "\t" << "Y(k)";
		file << "Les resultats de la simulation:" << endl << 'k' << "\t" << "U(k)" << "\t" << "Y(k)";

		MATRICE sortie(1, 1);
		int k;
		MATRICE X(A.Getnbcolonne(), 1);
		MATRICE Xk(X.Getnbligne(), X.Getnbcolonne());

		for (int i = 0; i < X.Getnbligne(); i++) {
			for (int j = 0; j < X.Getnbcolonne(); j++)
				X.Setcoeff(i, j, CI);
		}

		for (k = 0; k < entree.get_n(); k++) {
			Xk = A * X + B * entree.get_amp(k);
			sortie = C * X + D * entree.get_amp(k);
			cout << endl << k << "\t" << entree.get_amp(k) << "\t"<< sortie;
			file << endl << k << "\t" << entree.get_amp(k) << "\t";
			for (int i = 0; i < 1; i++) {
				file << "[  ";
				for (int j = 0; j < 1; j++) {
					file << showpoint << sortie(i, j) << "  ";
				}
				file << "]" << endl;
			}
			X = Xk;
		}
		file.close();
	}
	else
		cerr << "BUG du fichier !" << endl;
}

//NOUVELLE FONCTION D'AFFICHAGE(ADAPTEE A L'AFFICHAGE DU MODELE D'ETAT

void MODELE_ETAT::Affiche_RepresentationEtat() const {
	cout << endl << "x(k+1)= ";
	A.vecteurligne(1);
	cout << " *x(k)+ ";
	B.vecteurligne(1);
	cout << " *u(k)";
	for (int n = 2; n < A.Getnbligne() + 1; n++) {
		cout << endl << "\t";
		A.vecteurligne(n);
		cout << "        ";
		B.vecteurligne(n);
	}

	cout << endl << endl << " y(k) = ";
	C.vecteurligne(1);
	cout << " *x(k)+ ";
	D.vecteurligne(1);
	cout << " *u(k)";
	for (int p = 2; p < C.Getnbligne() + 1; p++) {
		cout << endl << "\t";
		C.vecteurligne(p);
		cout << "        ";
		D.vecteurligne(p);
	}
}
