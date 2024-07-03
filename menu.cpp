
#include <iostream>
#include <cmath>
#include <windows.h>
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
#include "menu.h"

using namespace std;
//CREATION D'UNE INTERFACE
menu::menu(){}

int menu::menu_principal() {

	string Men[5];
	Men[0] = "POLYNOME";
	Men[1] = "MATRICE";
	Men[2] = "Fonction de transfert";
	Men[3] = "Representation d etat";
	Men[4] = "Quitter";
	int pointer = 0;
	while (true)
	{
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 900);
		cout << endl << " ====================================================";
		cout << endl << "|               Projet C++ BAYA Haytam              |";



		cout << endl << " ====================================================";
		cout << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		cout << "Menu Principal \n\n";

		for (int i = 0; i < 5; ++i)
		{
			if (i == pointer)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				cout << Men[i] << endl;
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << Men[i] << endl;
			}
		}
		while (true)
		{
			if (GetAsyncKeyState(VK_UP) != 0)
			{
				pointer -= 1;
				if (pointer == -1)
				{
					pointer = 4;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_DOWN) != 0)
			{
				pointer += 1;
				if (pointer == 5)
				{
					pointer = 0;
				}
				break;
			}
			else if (GetAsyncKeyState(VK_RETURN) != 0)
			{
				switch (pointer)
				{
				case 0:
				{
					cout << endl << "Vous avez choisi POLYNOME/";
					menu_POLYNOME();

				} break;
				case 1:
				{
					cout << endl << "Vous avez choisi MATRICE/";
					menu_MATRICE();
				} break;
				case 2:
				{
					cout << endl << "Vous avez choisi Fonction de transfert/";
					menu_TFCT();
				} break;
				case 3:
				{
					cout << endl << "Vous avez choisi Representation d Etat/";
					menu_rep_etat();

				} break;
				case 4:
				{
					return 0;
				} break;
				}
			}
		}
	}return 0;
}

void menu::menu_POLYNOME() {
	cout << "Votre POLYNOME P"<< endl ;
	POLYNOME p;
	p.saisie();
	p.affiche();
	//on pourrait ajouter les opérations(méthodes) implémentées dans la classe polynome
	cout << endl << "Merci :D";
}

void menu::menu_MATRICE() {

	cout  << "Votre MATRICE M1"<< endl;
    cout  << "nombre de lignes de M1:"<< endl;
    int n1;
    cin>> n1;
    cout  << "nombre de colonnes de M1:"<< endl;
    int m1;
    cin>> m1;
	MATRICE M1(n1,m1,0);
for(int i=0; i<n1; i++)
   {
      for(int j=0; j<m1; j++)
      {
         std::cout<<"valeur de " << i << "," << j <<std::endl;
         std::cin>> M1(i,j) ;
      }
   }
	cout<<"Votre MATRICE M1: "<<endl;
	std::cout<< M1<<std::endl;
	cout  << "Votre MATRICE M2"<< endl;
    cout  << "nombre de lignes de M2:"<< endl;
    int n2;
    cin>> n2;
    cout  << "nombre de colonnes de M2:"<< endl;
    int m2;
    cin>> m2;
	MATRICE M2(n2,m2,0);
for(int i=0; i<n2; i++)
   {
      for(int j=0; j<m2; j++)
      {
         std::cout<<"valeur de " << i << "," << j <<std::endl;
         std::cin>> M2(i,j) ;
      }
   }
    cout<<"Votre MATRICE M2: "<<endl;
	std::cout<< M2<<std::endl;
	cout << endl << "quelle operation faire :1 pour M1*M2/2 pour M1+M2/3 pour inverse M1 " << endl ;//on pourrait ajouter les autres opérations implémentées:ceci est pour demonstration
	int choix=0 ;
	cin>>choix;
	if(choix==1 && m1==n2)
    {
      MATRICE M3;
      M3=M1*M2 ;
      cout<< "le produit donne: " <<M3 ;
    }
    else if (choix==2 && n1==n2 && m2==m2)
    {
      MATRICE M3;
      M3=M1+M2 ;
      cout<< "la somme donne: " <<M3 ;
    }
    else if (choix ==3 )
    {
      MATRICE M3;
      M3=M1.inverse() ;
      cout<< "l'inverse est: " <<M3 ;
    }
    else{
        cout<<"erreur" ;
    }
	cout << endl << "Merci :D";
}


void menu::menu_TFCT() {
	cout  << "Votre ft est compose de numerateur et denominateur : "<< endl;
	TFCT F;
	F.saisie_tfct();
	F.affiche_tfct();

        cout<<"Nous allons dresser dans un premier temps le diagramme de Bode puis verifier la stabilite a l aide du critere de Jury"<<endl;
		cout << endl << "Bode";
		cout << endl << "Donnez la pulsation min et la pulsation max (rad/s): ";
		cout << endl << "wmin = ";
		int wmin;
		cin >> wmin;
		cout << endl << "wmax = ";
		int wmax;
		cin >> wmax;
        cout << endl << "nombre de points(precision) = ";
        int NBRE_POINTS ;
        cin>> NBRE_POINTS;
		F.bode(wmin, wmax, NBRE_POINTS);
		cout << endl << "Merci :D";

		cout << endl << "Jury";
		F.Jury();



	}




void menu::menu_rep_etat()
 {
	cout  << "Votre systeme a quatre MATRICE  A(n,n)  B(n,1)  C(1,n)  D(1,1)"<< endl;


	cout << endl << endl << "On commence par definir le systeme d'etat ,n est la dimension du vecteur d etat"<<endl;
        MODELE_ETAT syst;
		syst.saisie_mod_e();
		syst.Affiche_RepresentationEtat();

		cout << endl << endl << "Simulation de la reponse temporelle de la sortie du systeme";
		cout << endl << "Donnez la condition initale (vecteur X(k=0)):";
		int CI;
		cin >> CI;
		char choix;
		cout << "\n\te: Echelon\n\tr: Rampe  \n\ts: Sinus" << endl << "Choix du signal d'entrer ";
		cin >> choix;
		switch (choix) {
		case 'e':{
			cout << endl << "\t\t Echelon  ";
			cout << endl << "Vous avez choisi un signal d'entree de type Echelon";
			cout << endl << "Donnez l'amplitude : ";
			float _amplitude;
			cin >> _amplitude;
			cout << "Donnez le top depart du signal d'entree t0 = ";
			int _v0;
			cin >> _v0;
			cout << "Le nombre de point du signal d'entree N = ";
			int _N;
			cin >> _N;
			cout << "La periode d'echantillonnage du signal d'entree Te = ";
			float _Te;
			cin >> _Te;
			echelon entree(_amplitude, _v0, _N, _Te);
			entree.Print_siggnal();
			syst.simu(CI, entree);
			cout << endl << "Merci :D";
			break;
		}
		case 'r':{
			cout << endl << "\t\t Rampe  ";
			cout << endl << "Vous avez choisi un signal d'entree de type Rampe";
			cout << "Donnez le top départ du signal d'entrée t0 = ";
			int _v0;
			cin >> _v0;
			cout << "Le nombre de point du signal d'entree N = ";
			int _N;
			cin >> _N;
			cout << "La periode d'echantillonnage du signal d'entree Te = ";
			float _Te;
			cin >> _Te;
			rampe entree(_v0, _N, _Te);
            entree.Print_siggnal();

			syst.simu(CI, entree);
			cout << endl << "Merci :D";
			break;
		}


		case 's':
		{
			cout << endl << "\t\t Sinus  ";
			cout << endl << "Vous avez choisi un signal d'entree de type Sinus";
			cout << endl << "Donnez l'amplitude : ";
			float _amplitude;
			cin >> _amplitude;
			cout << "Donnez la frequence du sinus <  1  ";
			int _v0;
			cin >> _v0;
			cout << "Le nombre de point du signal d'entree N = ";
			int _N;
			cin >> _N;
			cout << "La periode d'echantillonnage du signal d'entree Te = ";
			float _Te;
			cin >> _Te;
			sinus entree(_amplitude, _v0, _N, _Te);
            entree.Print_siggnal();

			syst.simu(CI, entree);
			cout << endl << "Merci :D";
			break; }
		default:
			cout << endl << "Donnez un choix ?";
			break;
		}
}

void Go_Menu() {
	menu Go;
	Go.menu_principal();
}
