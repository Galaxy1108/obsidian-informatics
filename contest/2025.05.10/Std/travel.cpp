#include <map>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <fstream>
#include <iostream>
#include <algorithm>
#define PB push_back
#define MP make_pair
#define BG begin()
#define ED end()
#define SZ(x) ((int)((x).size()))
#define FF first
#define SS second
#define foreach(i,x) for (__typeof((x).begin()) i=(x).begin();i!=(x).end();i++)
#define FOR(i,l,r) for (int i=(l);i<=(r);i++)
#define ROF(i,r,l) for (int i=(r);i>=(l);i--)
using namespace std;
#define N 100005
int t,mx,ans,z[N],o[N],d[N],p[N],w[N],f[N],fa[N],nxt[N];

void link(int a,int b) {nxt[++t]=d[a],d[a]=t,p[t]=b;}

void dfs(int i) {
  ans=max(ans,mx);
  o[i]=1;
  for (int k=d[i],j=p[k];k;k=nxt[k],j=p[k]) if (!o[j]) {
    int l=0,r=mx,pmx=mx;
    while (l<r) {
      int mid=(l+r+1)>>1;
      if (f[mid]<w[j]) l=mid; else r=mid-1;
    };
    int pf=f[l+1];
    f[l+1]=w[j];
    if (l==mx) mx++;
    dfs(j);
    f[l+1]=pf;
    mx=pmx;
  };
}

int main() {
  freopen("travel.in","r",stdin);
  freopen("travel.out","w",stdout);
  int n;
  scanf("%d",&n);
  FOR(i,1,n) scanf("%d",&w[i]),w[i]=w[i];
  FOR(i,1,n) scanf("%d",&fa[i]),link(fa[i],i);
  FOR(i,1,n) if (!o[i]) {
    int t=0,j=i;
    while (!o[j]) z[++t]=j,o[j]=1,j=fa[j];
    int tt=0;
    ROF(k,t,1) {
      f[++tt]=w[z[k]];
      if (z[k]==j) break;
    };
    FOR(k,1,t) if (z[k]==j) break; else o[z[k]]=0;
    sort(f+1,f+tt+1);
    mx=0;
    FOR(k,1,tt) 
      if (k==1 || f[k]!=f[k-1])
        f[++mx]=f[k];
    ROF(k,t,1) {
      dfs(z[k]);
      if (z[k]==j) break;
    };
  };
  printf("%d",ans);
  return 0;
}
