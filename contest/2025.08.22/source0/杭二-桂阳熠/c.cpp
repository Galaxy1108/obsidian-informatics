#include<bits/stdc++.h>
#define For(i,j,k) for(int i=(j);i<=(k);++i)
#define ForDown(i,j,k) for(int i=(j);i>=(k);--i)
#define within :
#define LJY main
using namespace std;
typedef long long ll;
const int N=5005;
mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
inline int read(){
  char ch=getchar();int x=0,f=1;
  while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
  while(ch>='0'&&ch<='9')
    x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
  return x*f;
}
int a[N][N],pos[N][N],n,seed;
bool f[N][N];int r[N];
void gen(){
  std::mt19937 rng(seed);
  for(int i=1;i<=n;++i)
    for(int j=1;j<=n+1;++j){
      a[i][j]=j;
      std::swap(a[i][j],a[i][rng()%j+1]);
    }
}
signed LJY(){
  freopen("c.in","r",stdin);
  freopen("c.out","w",stdout);
  n=read(),seed=read();
  if(!seed) For(i,1,n) For(j,1,n+1) a[i][j]=read();
  else gen();
  For(i,1,n) For(j,1,n+1) pos[i][a[i][j]]=j;
  For(i,1,n+1) f[n][i]=1;
  ForDown(i,n,1){
    int Mn=0;
    For(j,1,n+1) if(f[i][j]&&(!Mn||a[i][Mn]>a[i][j])) Mn=j;
    f[i][Mn]=0;r[i]=a[i][Mn];
    For(j,1,n+1) f[i-1][j]=f[i][j];
  }For(i,1,n+1) if(f[1][i]) printf("%d ",i);
  For(i,1,n-1){
    For(j,1,n+1) f[i][j]=1;
    int val=pos[i][1];f[i][val]=0;
    int nw=i+n-1,lst=val;r[i]=1;
    while(nw!=i){
      int p=nw>n?nw-n:nw;
      if(pos[p][r[p]]==lst){
        while(r[p]<=n+1&&!f[p][pos[p][++r[p]]]);
        f[p][pos[p][r[p]]]=0;lst=pos[p][r[p]];
      }else f[p][lst]=0;
      nw--;
    }For(j,1,n+1) if(f[i+1][j]) printf("%d ",j);
  }
  return 0;
}