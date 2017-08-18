#include<iostream>
#include <fstream>
#include<cmath>

/*------------------------------------------------------------------------------*/
void Dibujo(int N)
{
  std::cout<<"set terminal pdf"<<std::endl; 
  std::cout<<"set output 'Convergencia.pdf'"<<std::endl;
  std::cout<<"set logscale y"<<std::endl;
  std::cout<<"set autoscale"<<std::endl;
  std::cout<<"set term x11"<<std::endl;
  std::cout<<"plot 'S.data' index "<<N<<" w lp"<<std::endl;

}


double Termino(double x, int N)
{
  double T=1, S=1;
  for(int k=0;k<N;++k)
    {
      T *= std::pow(k+1,-1)*(-x);
      S += T;
    }
  return S;
}

/*------------------------------------------------------------------------------*/

int main(void)
{
  std::cout.precision(16);
  std::cout.setf(std::ios::scientific);
  double x=8.2;
  for(double x=1.2; x<=2.1; x+=0.1)
    {
      for(int NMAX=0;NMAX<=100;++NMAX)
	{
	  std::cout<<NMAX<<"\t"
		   <<fabs(Termino(x,NMAX)-std::exp(-x))*std::pow(std::exp(-x),-1)
		   <<std::endl;
	}
      std::cout<<"\n"<<std::endl;
    }

  /*
  for(int i=1;i<=10;++i)
    {
      Dibujo(i);
    }
  */
  return 0;
}

/*------------------------------------------------------------------------------*/

/*int factorial( int n)
{
  if(n<=0)
    return 1;
  return n*factorial(n-1);
}
*/
