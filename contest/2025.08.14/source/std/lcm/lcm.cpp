#include <bits/stdc++.h>
using namespace std;
int Qread()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return x;
}
int n,p;
inline int chk(int a){return a>=p?a-p:a;}
inline int qpow(int a,int t)
{
	int ret=1;
	for(;t;t>>=1,a=1ll*a*a%p)
		if(t&1) ret=1ll*ret*a%p;
	return ret;
}
vector<int> yz[1000010];
bool vis[1000010];
int mu[1000010],prim[100010],top;
int f[1000010],e[1000010],nyf[1000010],g,ans;
void solve()
{
	n=Qread(),p=Qread();
	e[0]=1;
	for(int i=1;i<=n;i++)
		f[i]=chk(f[i-1]+e[i-1]),
		e[i]=chk(f[i-1]+f[i]),
		nyf[i]=qpow(f[i],p-2);
	
	g=1,ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j:yz[i]) if(mu[j])
			g=1ll*g*(mu[j]==1?f:nyf)[i/j]%p;
		ans=(ans+1ll*g*i)%p;
	}
	printf("%d\n",ans);
}
int main()
{
	freopen("lcm.in","r",stdin);
	freopen("lcm.out","w",stdout);
	
	mu[1]=1;
	for(int i=2;i<=1000000;i++)
	{
		if(!vis[i]) prim[++top]=i,mu[i]=-1;
		for(int j=1;i*prim[j]<=1000000&&j<=top;j++)
		{
			vis[i*prim[j]]=true;
			mu[i*prim[j]]=-mu[i];
			if(i%prim[j]==0)
			{
				mu[i*prim[j]]=0;
				break;
			}
		}
	}
	for(int i=1;i<=1000000;i++)
	for(int j=i;j<=1000000;j+=i)
		yz[j].push_back(i);

	int T=Qread();
	while(T--) solve();
	return 0;
}