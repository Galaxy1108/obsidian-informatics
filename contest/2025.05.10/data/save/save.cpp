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
#define PUSH ++t;b[5][a[5]]+=i;
using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXT=60*24;
const int N=105;

int n,tot;
int a[N],c[N];
int b[N][N];

void work(string I)
{
  string O="save"+I+".out";
  I="save"+I+".in";
  freopen(I.c_str(),"r",stdin);
  freopen(O.c_str(),"w",stdout);

  scanf("%d",&n);
  for (int i=1;i<=n;++i)
  {
    scanf("%d",&a[i]);
    int s=0,m=101;
    for (int j=1;j<=a[i];++j)
    {
      scanf("%d",&b[i][j]);
      if (j<a[i]) s+=b[i][j],m<?=b[i][j];
    }
    m<?=s+1;
    c[i]=m;
  }
  int i=n,t=0;
  while (i&&t<MAXT)
  {
    b[i][a[i]]-=c[i];
    if (b[i][a[i]]<=0) 
    {
      --i;
      if (i) {PUSH}
    }
    PUSH
  }
  t<?=MAXT;
  printf("%d",t);
  if (t==MAXT) ++tot;
  fclose(stdin);
  fclose(stdout);
}

int main()
{
  for (int i=0;i<50;++i)
  {
    stringstream I;
    I<<i;
    work(I.str());
  }
  cerr<<tot<<endl;
  return 0;
}
