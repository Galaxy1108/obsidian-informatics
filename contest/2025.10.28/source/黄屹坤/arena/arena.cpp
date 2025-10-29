#include<bits/stdc++.h>
#define Mod 998244353
#define gc getchar()
#define ll long long
#define I inline int 
#define V inline void
#define LL inline long long
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,b,a) for(int i=b;i>=a;i--)
using namespace std;
I read(){
	int x=0;bool fl=0;char s=gc;
	while('0'>s||s>'9'){fl|=(s=='-');s=gc;}
	while('0'<=s&&s<='9'){x=x*10+s-48;s=gc;}
	return fl?-x:x;
}
LL fast(ll x,ll p){ll now=1;while(p){if(p&1)now=now*x%Mod;x=x*x%Mod;p>>=1;}	return now;}
const int N=1011;
int n,X;
ll ans,f[N][N],C[N][N];
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout); 
	
	n=read(),X=read();
	if(n>X){cout<<fast(X,n);return 0;}
	FOR(i,0,N-11)C[i][0]=1;
	FOR(i,1,N-11)FOR(j,1,i)C[i][j]=(C[i-1][j]+C[i-1][j-1])%Mod;	
	f[n][0]=1;
	ROF(i,n,2)
		for(int j=0;j<=X-1;j++)
			for(int k=0;k<=i;k++)
				f[i-k][j+i-1]=(f[i-k][j+i-1]+f[i][j]*C[i][k]%Mod*fast(min(X-j,i-1),k)%Mod)%Mod;
	FOR(i,0,X+n)ans=(ans+f[0][i])%Mod;
	cout<<ans;
	return 0;
}
/*
5 2

*/

