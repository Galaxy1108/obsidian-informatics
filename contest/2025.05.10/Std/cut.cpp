#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <cmath>
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
#define SI(x) (int)x.size()
#define sqr(x) ((x)*(x))
#define O(x,y) (x>=0&&x<SI(A)&&y>=0&&y<SI(A[x]))
using namespace std;

typedef long long ll;

const int N=51*51+5;

int f(int i,int j) {return i*51+j;}

int a[N],b[N],c[N];
vci g[N];

void link(int x,int y) {g[x].pb(y);g[y].pb(x);++a[x];++a[y];}

void dfs(int i)
{
  if (c[i]) return;
  c[i]=1;
  for (int j=0;j<SI(g[i]);++j) dfs(g[i][j]);
}

struct CuttingPaper
{
  int minCuts(vcs A)
  {
    for (int i=0;i<SI(A);++i)
      for (int j=0;j<SI(A[i]);++j)
      {
        if (i+1<SI(A)&&j<SI(A[i+1])&&A[i][j]!=A[i+1][j]&&A[i][j]!=' '&&A[i+1][j]!=' ') link(f(i+1,j),f(i+1,j+1));
        if (j+1<SI(A[i])&&A[i][j]!=A[i][j+1]&&A[i][j]!=' '&&A[i][j+1]!=' ') link(f(i,j+1),f(i+1,j+1));
      }
    for (int x=0;x<51;++x)
      for (int y=0;y<51;++y)
      {
        b[f(x,y)]=!O(x,y)||!O(x-1,y)||!O(x,y-1)||!O(x-1,y-1)||A[x][y]==' '||A[x-1][y]==' '||A[x][y-1]==' '||A[x-1][y-1]==' ';
        if (b[f(x,y)]) dfs(f(x,y));
      }
    int ans=0;
    for (int i=0;i<51*51;++i)
    {
      if (a[i]&&!c[i]) {return -1;}
      ans+=(a[i]&1)+(a[i]==4)*2;
      if (a[i]==2&&b[i]) ans+=2;
    }
    return ans/2;
  }
};

int main()
{
  freopen("cut.in","r",stdin);
  freopen("cut.out","w",stdout);

  ios_base::sync_with_stdio(0);
  string s;
  getline(cin,s);
  vcs a;
  int z=0;
  string b;
  for (int i=0;i<SI(s);++i)
  {
    if (s[i]=='"') 
    {
      z^=1;
      if (!z) a.pb(b),b.clear();
    }
    else
    if (z)
      b+=s[i];
  }
  CuttingPaper o;
  cout<<o.minCuts(a)<<endl;

  return 0;
}
