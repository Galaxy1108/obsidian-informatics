#include <bits/stdc++.h>
using namespace std;
long long tot;
long long f[1000005],g[1000005],ans[1000005];
long long p;
inline long long gcd(long long a,long long b)
{
	return b?gcd(b,a%b):a;
}
inline long long lcm(long long a,long long b)
{
	return a/gcd(a,b)*b;
}
int main()
{
	freopen("lcm.in","r",stdin);
	freopen("lcm.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	f[1]=1,f[2]=2,f[3]=5,f[4]=12;
	g[1]=1,g[2]=2,g[3]=10,g[4]=60;
	ans[1]=1,ans[2]=5,ans[3]=35,ans[4]=275;
	int T;
	cin>>T;
	while(T--)
	{
		long long n;
		cin>>n>>p;
//		while(tot<n)
//		{
//			f[++tot]=f[tot-1]*2+f[tot-2];
//			g[tot]=lcm(g[tot-1],f[tot]);
//			ans[tot]=ans[tot-1]+tot*g[tot];
//			//cout<<f[tot]<<" "<<g[tot]<<" "<<ans[tot]<<"\n";
//		}
		for(int i=4;i<=n;i++)
		{
			
			f[i]=(f[i-1]*2+f[i-2])%p;
			g[i]=lcm(g[i-1],f[i])%p;
			
			ans[i]=ans[i-1]+i*g[i];
			ans[i]%=p;
			cout<<f[i]<<" "<<g[i]<<" "<<ans[i]<<"\n";
		}
		cout<<ans[n]<<" "<<ans[n]%p<<"\n";
	}
	return 0;
 } 
