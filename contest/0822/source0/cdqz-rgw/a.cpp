#include<bits/stdc++.h>
#define Add(x,y) (x+y>=mod)?(x+y-mod):(x+y)
#define lowbit(x) x&(-x)
#define pi pair<ll,ll>
#define pii pair<ll,pair<ll,ll>>
#define iip pair<pair<ll,ll>,ll>
#define ppii pair<pair<ll,ll>,pair<ll,ll>>
#define fi first
#define se second
#define full(l,r,x) for(auto it=l;it!=r;it++) (*it)=x
#define Full(a) memset(a,0,sizeof(a))
#define open(s1,s2) freopen(s1,"r",stdin),freopen(s2,"w",stdout);
#define For(i,l,r) for(register int i=l;i<=r;i++)
#define _For(i,l,r) for(register int i=r;i>=l;i--)
using namespace std;
typedef double db;
typedef unsigned long long ull;
typedef long long ll;
bool Begin;
const int N=1e7+10; 
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')
          f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x*f;
}
inline void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9)
	  write(x/10);
	putchar(x%10+'0');
}
int n,m,st,s1,s2,s3,s4,mod;
int f[2][N],g[2][N];
bool End;
int main(){
	open("a.in","a.out");
	n=read(),m=read(),mod=read();
	For(i,1,m)
	  f[0][i]=(f[0][i-1]+i)%mod;
	_For(i,1,m)
	  g[0][i]=(g[0][i+1]+m-i+1)%mod;
	For(i,2,n){
		st^=1;
		For(j,0,m+1)
		  f[st][j]=g[st][j]=0; 
		s1=s2=s3=s4=0;
		For(j,1,m){
			s1=(s1+j)%mod;
			s2=(s2+1ll*g[st^1][j+1]*j%mod)%mod;
			s3=(s3+f[st^1][j-1])%mod;
			s4=(s4+1ll*f[st^1][j-1]*(j-1)%mod)%mod;
			f[st][j]=(1ll*s1*f[st^1][m]%mod-s2-1ll*s3*j%mod+s4+mod*2ll)%mod;
		}
		s1=s2=s3=s4=0;
		_For(j,1,m){
			s1=(s1+m-j+1)%mod;
			s2=(s2+1ll*f[st^1][j-1]*(m-j+1)%mod)%mod;
			s3=(s3+1ll*g[st^1][j+1]*j%mod)%mod;
			s4=(s4+g[st^1][j+1])%mod;
			g[st][j]=(1ll*s1*f[st^1][m]%mod-s2-s3+1ll*s4*(j-1)%mod+mod*2)%mod;
		}
	}
	write(f[st][m]);
	cerr<<'\n'<<abs(&Begin-&End)/1048576<<"MB";
	return 0;
}
