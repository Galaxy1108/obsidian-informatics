#include<bits/stdc++.h>
//#define int long long
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=510,mod=998244353;
int n,m,f[N][N],ans,C[N][N];
inline int qpw(int x,int p)
{
	int s=1;
	for(;p>0;p>>=1,x=1ll*x*x%mod)
		if(p&1)s=1ll*s*x%mod;
	return s;
}
inline void add(int &x,int y){x+=y;if(x>=mod)x-=mod;}
signed main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	FOR(i,0,n)C[i][0]=1;
	FOR(i,1,n)FOR(j,1,i)C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	f[0][0]=1; 
	FOR(i,1,n)
	{
		FOR(j,1,m)
		{
			if(j<=(i-1))add(f[i][j],(qpw(j,i)-qpw(j-1,i)+mod)%mod);
			FOR(k,1,i)add(f[i][j],1ll*f[k][max(0,j-(i-1))]*C[i][i-k]%mod*qpw(min(j,i-1),i-k)%mod);
		}
	}
	for(int j=1;j<=m;j++)add(ans,f[n][j]);
	cout<<ans<<'\n';
	
	return 0;
} 
