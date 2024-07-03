#include <iostream>
#include "POLYNOME.h"
#include <cmath>

//INITIALISATION
void POLYNOME::raz(void)
 {
  int i;
  for (i=0;i<20;i++) coef[i]=0;
  degre=0;
 }

//AJUSTEMENT
void POLYNOME::ajuste_degre(void)
 {
  if(degre>0)while(coef[degre]==0)degre--;
 }

 //COPIE
 void POLYNOME::copie(POLYNOME p)
 {
  int i;
  degre=p.get_degre();;
  for (i=0;i<=degre;i++) coef[i]=p.get_coef(i);
 }

//SAISIE
 void POLYNOME::saisie(void)
 {

  int i;
  std::cout<<"degre ?";
  std::cin>>degre;
  for(i=degre;i>=0;i--)
   {
    std::cout<<"coef d'ordre "<<i<<" ? ";
    std::cin>>coef[i];
   }
  ajuste_degre();
 }

//AFFICHAGE
 void POLYNOME::affiche(void)
 {
  int i,prem=1;
  for(i=degre;i>0;i--) if (coef[i])
   {
    if(!prem) std::cout<<"+"; else prem=0;
    if(coef[i]!=1)std::cout<<coef[i];
    std::cout<<"z";
    if(i!=1)std::cout<<"^"<<i;
   }
  if(prem) std::cout<<coef[0];
  else if(coef[i]) std::cout<<"+"<<coef[0];
 }

 //DEF DE OPERATOR +
 POLYNOME operator + (POLYNOME& p,POLYNOME& q)
 {
  POLYNOME r;
  r.copie(p);
  r.additionner(q);
  return r;
 }

 //DEF DE OPERATOR *
 POLYNOME operator * (POLYNOME& p,POLYNOME& q)
 {
  POLYNOME r;
  r.copie(p);
  r.multiplier(q);
  return r;
 }

 //DEF DE OPERATOR <<
std::ostream& operator << (std::ostream&, POLYNOME& p)
 {
  p.affiche();
  return std::cout;
 }

 //ADDITIONNER
 void POLYNOME::additionner(POLYNOME p)
 {
  int i,dp;
  if(p.get_degre()>degre)
   {
    for(i=p.get_degre();i>degre;i--)coef[i]=p.get_coef(i);
    dp=degre;
    degre=p.get_degre();
   }
  else dp=p.get_degre();
  for(i=dp;i>=0;i--)coef[i]+=p.get_coef(i);
  ajuste_degre();
 }

//MULTIPLIER
void POLYNOME::multiplier(POLYNOME p)
 {
  int i,j,nd;
  POLYNOME q;
  q.copie(*this);
  nd=q.get_degre()+p.get_degre();
  if(nd>20)std::cout<<"multiplication impossible\n";
  for(i=0;i<=nd;i++)coef[i]=0;
  for(i=0;i<=q.get_degre();i++)
   for(j=0;j<=p.get_degre();j++)
    coef[i+j]+=(q.get_coef(i)*p.get_coef(j));
  degre=nd;
 }

 //EVALUATION DU POLYNOME
float POLYNOME::Eval(int val)
{
	float result = 0;
	float coeff;
	for (int i = 0; i <= degre; i++)
	{
		coeff = get_coef(i);
		result = result + coeff * pow(val,i);
	}
	return result;
}



