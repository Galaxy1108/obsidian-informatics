#include<bits/stdc++.h>
using namespace std;
const int mx=1e6+10;
int T;
long long g[mx],e[mx],f[mx];
long long getgcd(long long a,long long b)
{
	if(a%b==0) return b;
	return getgcd(b,a%b);
}
int main()
{
	freopen("lcm.in","r",stdin);
	freopen("lcm.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--)
	{
		memset(g,0,sizeof(g));
		memset(e,0,sizeof(e));
		memset(f,0,sizeof(f));
		e[1]=f[1]=1;
		int n,p;
		cin>>n>>p;
		for(int i=2;i<=n;i++) 
		{
			f[i]=e[i-1]+f[i-1],e[i]=f[i]+f[i-1];
			f[i]%=p,e[i]%=p;
		}
		g[1]=1;
		for(int i=2;i<=n;i++)
		{
			g[i]=f[i]*g[i-1]/getgcd(g[i-1],f[i])%p;
			if(g[i]==0) break;
		}
		long long ans=0;
		for(int i=1;i<=n;i++)
			ans=(ans+i*g[i]%p)%p;
		cout<<ans<<"\n";
	}
	return 0;
} 
