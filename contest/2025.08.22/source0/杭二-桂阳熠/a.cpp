#include<bits/stdc++.h>
#define For(i,j,k) for(int i=(j);i<=(k);++i)
#define ForDown(i,j,k) for(int i=(j);i>=(k);--i)
#define within :
#define LJY main
using namespace std;
typedef long long ll;
const int N=1e7+5;
mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
inline int read(){
  char ch=getchar();int x=0,f=1;
  while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
  while(ch>='0'&&ch<='9')
    x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
  return x*f;
}
int n,m,mod;
int f[N][2],s[N][2],ss[N][2];
inline int add(int x,int y){x+=y;if(x>=mod) return x-mod;else return x;}
signed LJY(){
  freopen("a.in","r",stdin);
  freopen("a.out","w",stdout);
  n=read();m=read();mod=read();
  f[1][0]=1;f[m][1]=1;
  For(i,1,n){
    ForDown(j,m,1) s[j][0]=add(s[j+1][0],f[j][0]);
    ForDown(j,m,1) ss[j][0]=add(ss[j+1][0],s[j][0]);
    For(j,1,m) s[j][1]=add(s[j-1][1],f[j][1]);
    For(j,1,m) ss[j][1]=add(ss[j-1][1],s[j][1]);
    int sum=s[1][0];
    For(j,1,m) f[j][0]=((ll)(m-j+1)*(sum-s[j-1][1]+mod)-ss[j+1][0]+mod)%mod;
    For(j,1,m) f[j][1]=((ll)j*(sum-s[j+1][0]+mod)-ss[j-1][1]+mod)%mod;
  }ll sum=0;For(i,1,m) sum+=f[i][0];
  printf("%lld",sum%mod);
  return 0;
}