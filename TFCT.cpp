#include "TFCT.h"
#include <iostream>
#include "POLYNOME.h"
#include "complexe.h"
using namespace std ;

//AFFICHAGE
void TFCT::saisie_tfct(void)
{ POLYNOME p1,p2;
p1.raz();
p2.raz();
  std::cout <<"entrer Numerateur"<<std::endl;
  p1.saisie();
  std::cout <<"entrer Denominateur"<<std::endl;
  p2.saisie();
  NUM.copie(p1);
  DEN.copie(p2);
}

//SAISIE
 void TFCT::affiche_tfct(void)
 {   std::cout<<"votre fonction de transfert est:"<<std::endl;
     std::cout<<Te;
     std::cout<< NUM << std::endl;
     std::cout<<"-----------------"<<std::endl;
     std::cout<< DEN << std::endl;

 }


//GET SET NUM
POLYNOME TFCT::GetNUM()const{
	return NUM;
}

void TFCT::SetNUM(POLYNOME _num){
	NUM = _num;
}

//GET SET DEN
POLYNOME TFCT::GetDEN()const{
	return DEN;
}

void TFCT::SetDEN(POLYNOME _den){
	DEN = _den;
}

void TFCT::bode(double wmin,double wmax,int nbpoint){
	/*Diagramme de Gain*/
	cout << endl << endl << "Gain de la fonction de transfert" << endl;
	cout << endl << "w0" << '\t' << "gain";
	double inc = (wmax - wmin)/nbpoint;
	for (double w0 = wmin; w0 < wmax+1; w0+=inc){
		gain(w0);
	}

	/*Diagramme de Phase*/
	cout << endl << endl << "Phase de la fonction de transfert" << endl;
	cout << endl << "w0" << '\t' << "phase";
	for (double w0 = wmin; w0 < wmax+1; w0+=inc){
		phase(w0);

	}
}

//CALCUL DU GAIN
double TFCT::gain(int w0){
  POLYNOME P1;
  POLYNOME P2;
  P1.raz();
  P2.raz();
  P1.copie(NUM);
  P2.copie(DEN);
	double resg;
	complexe Inum;
	Inum.poly2cplx(P1,w0, Te);
	complexe Iden;
	Iden.poly2cplx(P2,w0, Te);
	resg = 20*(log10(Inum.module())-log10(Iden.module()));
	cout << endl << w0 << "\t" << resg;
	return resg;
}

//CALCUL DE LA PHASE
double TFCT::phase(int w0) {
    POLYNOME P1;
    POLYNOME P2;
  P1.raz();
  P2.raz();
  P1.copie(NUM);
  P2.copie(DEN);
	double res;
	complexe Inum;
	Inum.poly2cplx(P1,w0, Te);
	complexe Iden;
	Iden.poly2cplx(P2,w0,Te);
	res = Inum.argument() - Iden.argument();// il faut que l'appelant soit en paramètre
	cout << endl << w0 << "\t" << res;
	return res;
}

//JURY

void TFCT::Jury()
{
    POLYNOME Jury = DEN;
    int stable = 1; // Si stable = 1, le systeme et stable et sinon, il ne l'est pas
    int n = Jury.get_degre();
    float Juryl1[n + 1]; // On creer des tableaux pour effectuer les calculs pour les differentes lignes du tableaux
    float Juryl2[n + 1];
    float Jurycal[n + 1];
    float coef;
    float a0 = Jury.get_coef(0); // Premier coeff
    float an = Jury.get_coef(n); // Dernier coeff
    for (int i = 0; i <= n; i++)
    {
        coef = Jury.get_coef(i);
        Juryl2[n - i] = coef;
        Juryl1[i] = coef;
    }
    if (an < 0)
    {
        for (int i = 0; i <= n; i++)
        {
            coef = -Jury.get_coef(i); // On verifie ici la premiere condition
            Jury.get_coef(coef);
        }

    }
    float test1 = Jury.Eval(1);
    float test2;
    if (n % 2 == 0) // Utilisation du modulo pour voir si n est pair ou impair
    {
        test2 = Jury.Eval(-1);
    }
    else
    {
        test2 = -Jury.Eval(-1);
    }
    if (an > 0 && fabs(a0) < an && test2 > 0 && test1 > 0) // Boucle pour verifier les differentes conditions
    {
        while (n >= 3 && stable == 1)
        {
            for (int i = 0; i < n; i++)
            {
                Jurycal[i] = (Juryl1[0] * Juryl2[n - i]) - (Juryl1[n - i] * Juryl2[0]);  // On utilise la formule de Jury
            }
            cout << endl;
            for (int i = 0; i <= n; i++) // Boucle qui sert a afficher le tableaux
            {
                cout << Juryl1[i] << "\t";
            }
            cout << endl;
            for (int i = 0; i <= n; i++)
            {
                cout << Juryl2[i] << "\t";
            }

            if (fabs(Jurycal[0]) > fabs(Jurycal[n - 1]))
            {
                n = n - 1;
                for (int i = 0; i <= n; i++) // On change ici les coefficients pour la ligne suivante
                {
                    Juryl2[i] = Jurycal[n - i];
                    Juryl1[i] = Jurycal[i];
                }
            }
            else
            {
                stable = 0;
            }
        }
    }
    else
    {
        stable = 0;
    }
    cout << endl;
    for (int i = 0; i <= n; i++)
    {
        cout << Jurycal[i] << "\t";
    }
    if (stable == 1) // Resultat du critere de Jury sur la stabilite ou non du systeme
    {
        cout << endl << endl << "Le systeme est stable"<<endl<<endl;
    }
    else
    {
        cout << endl << endl << "Le systeme est instable"<<endl<<endl;
    }
}
