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

int ran(int l,int r) {
  l=max(l,1);
  r=max(l,r);
  if (l==r) return l;
  return l+(rand()+rand()*1000)%(r-l);
}

int main() {
  freopen("travel10.in","w",stdout);
  srand(time(0));
  int n=100000;
  printf("%d\n",n);
  FOR(i,1,n/10) printf("%d ",(1<<29)-(rand()+rand()*1000));
  FOR(i,n/10+1,n) printf("%d ",(1<<29)-(15000000-i*3-rand()%50));
  printf("\n");
  FOR(i,1,n/10) printf("%d ",rand()%(n/10)+1);
  FOR(i,n/10+1,n) printf("%d ",ran(i-10,i-1));
  printf("\n");
  return 0;
}
