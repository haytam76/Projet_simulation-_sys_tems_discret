#include "POLYNOME.h"
#ifndef MATRICE_H
#define MATRICE_H
#include <iostream>


class MATRICE
{
   private:
      int get_degre_matrice(void) {return n;}
      typedef double *ligne;
      ligne *lignes;
      unsigned int n; // Nombre de lignes
      unsigned int m; // Nombre de colonnes
      void echange(double &a, double &b) const;
      MATRICE supligne(const MATRICE &mat, unsigned int lig, unsigned int col) const;
      double det(const MATRICE &mat) const;
      float expo(unsigned int n) const;


   public:

      float get_coef(int i,int j) {return lignes[i][j];}
      //les constructeurs/destructeur
      MATRICE();
      MATRICE(unsigned int nl, unsigned int nc);
      MATRICE(unsigned int nl, unsigned int nc, double valeur);
      MATRICE(const MATRICE &source);
      ~MATRICE(void);
      //les operateurs
      MATRICE &operator=(const MATRICE &mat);
      double &operator()(unsigned int i, unsigned int j);
      MATRICE operator+(const MATRICE &mat) const;
      MATRICE operator-(const MATRICE &mat) const;
      MATRICE operator*(const MATRICE &mat) const;
      MATRICE operator*(const double nb) const;
      friend MATRICE operator*(const double nb,const MATRICE &mat);
      MATRICE & operator*=(const MATRICE &mat);
      MATRICE & operator*=(const double nb);
      MATRICE & operator+=(const MATRICE &mat);
      MATRICE & operator-=(const MATRICE &mat);
      MATRICE & operator/=(const double);
      MATRICE  operator/(const double) const;
      //accesseur et manipulations
      MATRICE t();
      double trace() const;
      double det() const;
      MATRICE co() const;
      MATRICE inverse() const;
      int dim() const;
      int Getnbligne() const;
	  void Setnbligne(const int);
	  int Getnbcolonne() const;
	  void Setnbcolonne(const int);
      unsigned int nb_colones() const;
      unsigned int nb_lignes() const;
      friend std::ostream& operator<<(std::ostream &os,const MATRICE &mat);
      void saisie(void);
      void Setcoeff(const int, const int, const float);
      void vecteurligne(const int)const;


};





#endif
