#include "erreur.h"
#include <iostream>
#include "MATRICE.h"
using namespace std;

//CONSTRUCTEURS ET DESTRUCTEURS

void MATRICE::echange(double &a,double &b) const
{
   a+=b;
   b=a-b;
   a-=b;
}

MATRICE::MATRICE()
{
   n = 0;
   m = 0;
   lignes = NULL;
}

MATRICE::MATRICE(unsigned int nl, unsigned int nc)
{
   n = nl;
   m = nc;
   lignes = new ligne[n];  // allocations
   for (unsigned int i=0; i<n; i++)
   {
      lignes[i] = new double[m];
      for(unsigned int j=0; j<m; j ++)
         lignes[i][j] = 0;  //initialisation à '0'
   }
}

MATRICE::MATRICE(const MATRICE &source)
{
   n = source.n;
   m = source.m;

   lignes = new ligne[n];
   for(unsigned int i=0; i<n; i ++)
   {
      lignes[i] = new double[m];
      for(unsigned int j=0; j<m; j ++)
         lignes[i][j] = source.lignes[i][j]; //recopie
   }

}

MATRICE::MATRICE(unsigned int nl, unsigned int nc, double valeur)
{
   n = nl;
   m = nc;

   lignes = new ligne[n];
   for(unsigned int i=0; i<n; i ++)
   {
      lignes[i] = new double[m];
      for(unsigned int j=0; j<m; j ++)
         lignes[i][j] = valeur; //initialisation à 'valeur'
   }
}

MATRICE::~MATRICE()
{
   for(unsigned int i=0; i<n; i ++) //destruction
      delete[] lignes[i];

   delete[] lignes;
}


//SURCHARGE DES OPERATEURS

MATRICE &MATRICE::operator=(const MATRICE &mat)
{
   if(this != &mat) //assignation M = M impossible
   {
      if(mat.n != n || mat.m != m) // si tailles pas compatibles
      {
         for(unsigned int i=0; i<n; i++) // on détruit...
            delete[] lignes[i];
         delete[] lignes;

         n = mat.n;
         m = mat.m,

         lignes = new ligne[n];   // on réalloue
         for(unsigned int i=0; i<n; i++)
            lignes[i] = new double[m];
      }

      for(unsigned int i=0; i<n; i ++)
         for(unsigned int j=0; j<m; j ++)
            lignes[i][j] = mat.lignes[i][j]; // et on copie...
   }
   return *this;
}

double &MATRICE::operator()(unsigned int i, unsigned int j)
{
  if( i> n || j > m) // si out of range exception
  {
    Erreur a(Erreur::notinmat);
    throw (a);
  }
  return lignes[i][j];
}

MATRICE MATRICE::operator+(const MATRICE &mat) const
{
  MATRICE tmp(n,m);
   for (unsigned int i=0; i<n; i++) // Double boucle.
      for (unsigned int j=0; j<m; j++)
         tmp.lignes[i][j] = lignes[i][j] + mat.lignes[i][j]; //addition

   return tmp;
}

MATRICE MATRICE::operator-(const MATRICE &mat) const
{
   MATRICE tmp(n,m);
   for (unsigned int i=0; i<n; i++) // Double boucle.
      for (unsigned int j=0; j<m; j++)
         tmp.lignes[i][j] = lignes[i][j] - mat.lignes[i][j]; //soustraction

   return tmp;
}

MATRICE MATRICE::operator*(const double nb) const
{
   MATRICE tmp(n,m);
   for (unsigned int i=0; i<n; i++) // Double boucle.
      for (unsigned int j=0; j<m; j++)
         tmp.lignes[i][j] = lignes[i][j] * nb; // produit

   return tmp;
}

MATRICE MATRICE::operator*(const MATRICE &mat) const
{
   MATRICE tmp(n,mat.m,0);
   if(m == mat.n) // si nb_colone == nb_ligne de l'autre MATRICE...
   {
      for(unsigned int i=0; i<n; i++) //pour chq ligne...
         for(unsigned int j=0; j<mat.m; j++) // pour chaque colone
         {
            for(unsigned int k=0; k<m; k++) // produit scalaire
               tmp.lignes[i][j] += lignes[i][k]*mat.lignes[k][j];
         }
   }
   else //multiplication impossible, exception
   {
      Erreur err(Erreur::multiplication);
      throw(err);
   }
   return tmp;
}

MATRICE operator*(const double nb,const MATRICE &mat)
{
   return mat*nb;
}

MATRICE &MATRICE::operator*=(const double nb)
{
   MATRICE tmp(n,m,0);
   for(unsigned int i=0; i<n; i++) // Double boucle.
         for(unsigned int j=0; j<m; j++)
            tmp.lignes[i][j] = lignes[i][j]*nb; //produit

      *this = tmp;

   return *this;
}

MATRICE &MATRICE::operator*=(const MATRICE &mat)
{
   MATRICE tmp(n,mat.m,0);
   if(m == mat.n) //si multiplication possible....
   {
      for(unsigned int i=0; i<n; i++)
         for(unsigned int j=0; j<mat.m; j++)
         {
            for(unsigned int k=0; k<m; k++)
               tmp.lignes[i][j] += lignes[i][k]*mat.lignes[k][j];
         }
      *this = tmp;
   }
   else //...sinon exception
   {
      Erreur err(Erreur::multiplication);
      throw(err);
   }

   return *this;
}

MATRICE &MATRICE::operator+=(const MATRICE &mat)
{
   for (unsigned int i=0; i<n; i++) // Double boucle.
      for (unsigned int j=0; j<m; j++)
         lignes[i][j] += mat.lignes[i][j]; // +=

   return *this;
}

MATRICE &MATRICE::operator-=(const MATRICE &mat)
{
   for (unsigned int i=0; i<n; i++) // Double boucle.
      for (unsigned int j=0; j<m; j++)
         lignes[i][j] -= mat.lignes[i][j]; //-=

   return *this;
}

MATRICE MATRICE::operator/(const double nb) const
{
   MATRICE tmp = *this;
   if(nb)
   {
      for(unsigned int i=0; i<n; i++)
         for(unsigned int j=0; j<n; j++)
            tmp.lignes[i][j]/=nb;
   }
   else //exception division par 0
   {
      Erreur a(Erreur::dbzero);
      throw(a);
   }
   return tmp;
}

MATRICE &MATRICE::operator/=(const double nb)
{
   if(nb)
   {
      for(unsigned int i=0; i<n; i++)
         for(unsigned int j=0; j<n; j++)
            lignes[i][j]/=nb;
   }
   else //exception division par 0
   {
      Erreur a(Erreur::dbzero);
      throw(a);
   }
   return *this;
}

std::ostream &operator<<(std::ostream &os,const MATRICE &mat)
{
   for(unsigned int i=0; i<mat.n; i++)
   {
      for(unsigned int j=0; j<mat.m; j++)
         os << mat.lignes[i][j] << "   ";

      os << std::endl;
   }

   return os;
}

//OPERATIONS MATHEMATIQUES

MATRICE MATRICE::t()//Transposée
{
   MATRICE tmp(m,n);
   for(unsigned i=0; i<n; i++)
      for(unsigned j=0; j<m; j++)
         tmp.lignes[j][i]=lignes[i][j];
   return tmp;
}

double MATRICE::trace() const
{
   double sum=0;
   if(n == m) // trace => MATRICE carrée
   {
      for(unsigned int i=0; i<n; i++)
            for(unsigned int j=0; j<m; j++)
               if(i == j)
                  sum+= lignes[i][j];
   }
   else //pas carrée => exception
   {
      Erreur a(Erreur::ncarre);
      throw(a);
   }
   return sum;
}

MATRICE MATRICE::supligne(const MATRICE &mat, unsigned int lig, unsigned int col) const//supprimer une ligne
{
   unsigned int dim = mat.n;
   unsigned int ld = 0,cd=0;
   MATRICE dest(mat.n-1,mat.n-1,0); // -1 ligne et -1 colone
   for (unsigned int L=0; L<dim; L++)
   {
      cd = 0; // revient a colone 0
      if(L != lig) // sauf ligne a virer
      {
         for(unsigned int c=0; c<dim; c++)
            if(c != col) // sauf colone a virer
               dest.lignes[ld][cd++]=mat.lignes[L][c]; // recopie
         ld++;
      }
   }
   return dest;
}

float MATRICE::expo(unsigned int n) const
{
if(!(n%2)){return (1);}
return (-1);
}

double MATRICE::det(const MATRICE &mat) const
{
   MATRICE m2(mat.n,mat.n,0);
   double x=0;

   if(mat.n==1) //final
      return mat.lignes[0][0];

   for(unsigned int i=0; i<mat.n; i++)
   {
      m2 = supligne(mat,i,0); //extrait la sous MATRICE
      x=x+(expo(i)*mat.lignes[i][0]*det(m2));
   }
   return x;
}

double MATRICE::det()const
{
   if(n != m) // si MATRICE pas carrée excecption
   {
      Erreur a(Erreur::ncarre);
      throw(a);
   }
   return det(*this);
}


MATRICE MATRICE::co() const
{
   MATRICE m2(n,m,0);
   MATRICE ret(n,m,0);
   if(n != m) // si pas carré...
   {
      Erreur a(Erreur::ncarre);
      throw(a);
   }
   if (n==1)
   {
      ret.lignes[0][0]=1;
   }
   else
   {
      for (unsigned int i=0;i<n;i++)
         for (unsigned int j=0;j<n;j++)
         {
            m2 = supligne(*this,i,j);// sous_MATRICE
            ret.lignes[i][j]=expo(i+j)*m2.det();
         }
   }
   return ret;
}



MATRICE MATRICE::inverse() const
{
   MATRICE inv(n,m,0);
   if(n != m) // si pas carrée
   {
      Erreur a(Erreur::ncarre);
      throw(a);
   }
   inv = (this->co().t())/(this->det());

   return inv;
}

int MATRICE::dim() const
{
   if(n != m) // si pas carrée
   {
      Erreur a(Erreur::ncarre);
      throw(a);
   }
   return (n == m)?static_cast<int>(n):-1;
}

//ACCESSEURS ET MODIFICATEURS

unsigned int MATRICE::nb_colones() const
{
   return m;
}

unsigned int MATRICE::nb_lignes() const
{
   return n;
}

void MATRICE::Setcoeff(const int _ligne, const int _colonne,
		const float _value) {
	if (lignes != 0 && _ligne >= 0 && _ligne < n && _colonne >= 0
			&& _colonne < m) {
		lignes[_ligne][_colonne] = _value;

		/*cout << "La valeur associée au coefficient " << _ligne + 1 << 'x'
				<< _colonne + 1 << " est bien :" << mat[_ligne][_colonne]
				<< endl;
		*/
	} else {
		throw "ERREUR, vous êtes en dehors de la MATRICE";
		//cout << "Erreur , vous êtres en dehors de la MATRICE" << endl;
	}
}

int MATRICE::Getnbligne() const {
	return n;
}

void MATRICE::Setnbligne(const int _nbligne) {

	n= _nbligne;
}

int MATRICE::Getnbcolonne() const {
	return m;
}

void MATRICE::Setnbcolonne(const int _nbcolonne) {

	m = _nbcolonne;
}

//SAISIE MATRICE

void MATRICE::saisie(void)
 {
  std::cout<<"donner le nombre de lignes" <<std::endl;
  std::cin>> n ;
  std::cout<<"donner le nombre de colonnes"<<std::endl;
  std::cin>>m;
  for(int i=0; i<n; i++)
   {
      for(int j=0; j<m; j++)
      {
         std::cout<<"valeur de " << i << "," << j <<std::endl;
         std::cin>> lignes[i][j] ;
      }

   }
 }


//AFFICHER UNE LIGNE (POUR L'AFFICHAGE DE LA REPRESENTATION D'ETAT)

void MATRICE::vecteurligne(const int l) const {
	cout.precision(2);
	for (int j = 0; j < m; j++) {
		if (j == m- 1)
			cout << showpos << showpoint << lignes[l - 1][j];
		else
			cout << showpos << showpoint << lignes[l - 1][j] << ' ';	//pour afficher convenablement les coefficients.
	}
}
