#include <iostream>
#include <stdio.h>      /* printf */
#include <time.h>       /* time_t, struct tm, difftime, time, mktime */

using namespace std;

int main ()
{
  time_t timer;
  struct tm y2k = {0};
  double seconds;
  int d, m, a;

  y2k.tm_hour = 0;   y2k.tm_min = 0; y2k.tm_sec = 0;

  cout<<"Dia: ";
  cin>>d;
  cout<<"Mes: ";
  cin>>m;
  cout<<"Ano: ";
  cin>>a;

  y2k.tm_year = a; y2k.tm_mon = m-1; y2k.tm_mday = d;

  time(&timer);  /* pega o tempo atual  */

  seconds = difftime(timer,mktime(&y2k));

  printf ("O tempo passado, em segundos, desde %.d/%.d/%.d, foi: %.f \n", d, m, a, seconds);
  //cout<<"O tempo passado, em segundos, desde "<<y2k.tm_mday<<"/"<<y2k.tm_mon+1<<"/"<<y2k.tm_year<<" foi: "<<seconds<<endl;

  return 0;
}