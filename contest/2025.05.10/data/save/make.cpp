#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#define vci vector<int> 
#define vcs vector<string> 
#define PII pair<int,int> 
#define PIII pair<int,PII> 
#define pb push_back
#define mp make_pair
#define FF first
#define SS second
#define ST begin()
#define ED end()
#define SI(x) ((int)x.size())
#define sqr(x) ((x)*(x))
#define foreach(i,x) for (__typeof(x.ST) i=x.ST;i!=x.ED;++i)
using namespace std;

typedef long long ll;
typedef long double ld;

int n;

void make(string t)
{
  t="save"+t+".in";
  freopen(t.c_str(),"w",stdout);

  n=rand()%96+5;
  if (t=="save0.in"||t=="save1.in") n=5;
  printf("%d\n",n);
  for (int i=0;i<n;++i)
  {
    int k=rand()%100+1;
    if (t=="save0.in"||t=="save1.in") 
      k=rand()%10+1;
    printf("%d",k);
    for (int j=0;j<k;++j)
      if (t=="save0.in"||t=="save1.in") 
        printf(" %d",rand()%10+1);
      else
      if (rand()%10==0&&i!=5)
        printf(" %d",rand()%80+21);
      else
        printf(" %d",rand()%20+81);
    printf("\n");
  }

  fclose(stdout);
}

int main()
{
  srand(time(NULL));
/*  for (int i=0;i<50;++i)
  {
    stringstream I;
    I<<i;
    make(I.str());
  }
*/
  return 0;
}
