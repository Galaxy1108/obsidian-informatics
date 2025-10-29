#include<bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for(int i=(j);i<=(k);++i)
#define ROF(i,j,k) for(int i=(j);i>=(k);--i)
#define FOE(i,pos) for(int i=h[pos];i;i=nxt[i])
#define rd read() 
#define gc getchar()
#define pc(x) putchar(x)
#define maxn 505 
int rd{
	int x=0,f=1;char c=gc;
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=gc;}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c-'0');c=gc;}
	return x*f;
}
void write(int x){
	if(x<0) pc('-'),x=-x;
	if(x>9) write(x/10);
	pc(x%10+'0');
}

int n,mx;
int f[maxn][maxn]; 
int mm[maxn][maxn];
int fac[maxn],inv_fac[maxn];
const int mod=998244353;

int ksm(int x,int y){
	int z=1;
	while(y){
		if(y&1) z=1LL*z*x%mod;
		x=1LL*x*x%mod;
		y>>=1;
	}
	return z;
}

int C(int x,int y){
	return 1LL*fac[x]*inv_fac[y]%mod*inv_fac[x-y]%mod;
}

int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	n=rd,mx=rd;
	fac[0]=1;
	FOR(i,1,n) fac[i]=1LL*fac[i-1]*i%mod;
	inv_fac[n]=ksm(fac[n],mod-2);
	ROF(i,n-1,0) inv_fac[i]=1LL*inv_fac[i+1]*(i+1)%mod;
	FOR(i,1,n){
		mm[i][0]=1;
		FOR(j,1,n) mm[i][j]=1LL*mm[i][j-1]*i%mod;
	}
	FOR(i,2,n){
		FOR(j,1,mx){
			if(j<=i-1) f[i][j]=(mm[j][i]-mm[j-1][i]+mod)%mod;
			else{
				FOR(k,1,i) f[i][j]=(f[i][j]+1LL*f[k][j-i+1]*mm[i-1][i-k]%mod*C(i,k)%mod)%mod;
			}
		}
	}
	int ans=0;
	FOR(i,1,mx) ans=(ans+f[n][i])%mod;
	printf("%d",ans);
	return 0;
}
