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

map<PII,int> f;

void make(int T,int N)
{
  stringstream I;
  I<<T;
  string O;
  O="pass"+I.str()+".in";
  freopen(O.c_str(),"w",stdout);
  printf("%d %lf %lf\n",N,1.0*rand()/32767,1.0*rand()/32767);
  f.clear();
  for (int i=0;i<N+N;++i)
  {
    int x=rand()%101,y=rand()%101;
    while (f.count(mp(x,y))) x=rand()%101,y=rand()%101;
    f[mp(x,y)]=1;
    printf("%d %d\n",x,y);
  }
  fclose(stdout);
}

int main()
{
  srand(time(NULL));
  for (int i=0;i<20;++i)
    if (i<6)
      make(i,5);
    else
      make(i,50);

  return 0;
}
