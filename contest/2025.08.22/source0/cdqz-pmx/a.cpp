#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=1e7+3;
ll n,m,H,f[N],g[N],sf[N],sg[N],tf[N],tg[N];
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	cin>>m>>n>>H;
	for(int i=n;i>=1;i--)f[i]=(f[i+1]+n-i+1)%H,sf[i]=(sf[i+1]+f[i])%H;
	for(int i=1;i<=n;i++)g[i]=(g[i-1]+i)%H,sg[i]=(sg[i-1]+g[i])%H;
	for(int t=2;t<=m;t++)
	{
		for(int i=1;i<=n;i++)tf[i]=f[i],tg[i]=g[i],f[i]=g[i]=0;
		for(int i=n;i>=1;i--)f[i]=(f[i+1]+(n-i+1)*(tf[1]-tg[i-1]+H)-sf[i+1]+H)%H;
		for(int i=1;i<=n;i++)g[i]=(g[i-1]+i*(tf[1]-tf[i+1]+H)-sg[i-1]+H)%H;
		for(int i=n;i>=1;i--)sf[i]=(sf[i+1]+f[i])%H;
		for(int i=1;i<=n;i++)sg[i]=(sg[i-1]+g[i])%H;
	}
	cout<<f[1];
}
