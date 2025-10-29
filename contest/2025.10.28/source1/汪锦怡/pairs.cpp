#include<bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for(int i=(j);i<=(k);++i)
#define ROF(i,j,k) for(int i=(j);i>=(k);--i)
#define FOE(i,pos) for(int i=h[pos];i;i=nxt[i])
#define rd read() 
#define gc getchar()
#define pc(x) putchar(x)
#define maxn 205
#define int long long
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

int n,mod;
int dp[maxn][maxn*maxn];
int f[maxn];
int fac[maxn],inv_fac[maxn];
int ans;

void ouu(int a,int b,int &x,int &y){
	if(!b) return x=1,y=0,void();
	ouu(b,a%b,y,x);
	y-=x*(a/b);
}

int inv(int x){
	int k1=0,k2=0;
	ouu(x,mod,k1,k2);
	return k1;
}

int C(int x,int y){
	return 1LL*fac[x]*inv(y)%mod*inv(x-y)%mod;
}

signed main(){
	freopen("pairs.in","r",stdin);
	freopen("pairs.out","w",stdout);
	n=rd,mod=rd;
	fac[0]=1;
	FOR(i,1,n) fac[i]=1LL*fac[i-1]*i%mod;
	dp[1][0]=1;
	FOR(i,2,n){
		dp[i][0]=1;
		FOR(j,1,n*n) FOR(k,0,i-1) if(j>=k) dp[i][j]=(dp[i][j]+dp[i-1][j-k])%mod;
	}
	FOR(i,0,n-2){
		FOR(x,1,n-i) FOR(y,x+1,n-i) FOR(a,0,n*n){
			if(!dp[n-i-1][a]) continue;
			FOR(b,0,x+a-y-1){
				if(!dp[n-i-1][b]) continue;
				f[i]=(f[i]+1LL*dp[n-i-1][a]*dp[n-i-1][b]%mod)%mod;
			}
		}
		ans=(ans+1LL*f[i]*C(n,i)%mod)%mod;
	}
	printf("%lld",ans);
	return 0;
}
