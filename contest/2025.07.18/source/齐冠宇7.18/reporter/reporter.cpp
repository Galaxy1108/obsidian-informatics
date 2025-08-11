#include <bits/stdc++.h>
using namespace std;
constexpr int N=2e5+5;
int n,a[N],h[N],c[N];
int f[N][2];
int g[N][2];
bool spc=1;
int main()
{
	freopen("reporter.in","r",stdin);
	freopen("reporter.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>h[i]>>c[i];
		if(i==1 && a[i]!=1)
			spc=0;
		if(i!=1 && a[i]!=i-1)
			spc=0;
	}
	if(!spc)
		return cout<<"0",0;
	memset(f,0x3f,sizeof f);
	memset(g,0x3f,sizeof g);
	f[1][0]=0;
	f[1][1]=c[1];
	g[1][0]=h[1];
	g[1][1]=1;
	for(int i=2;i<=n;i++)
	{
		g[i][0]=h[i];
		if(h[i]>=g[i-1][0])
			f[i][0]=min(f[i][0],f[i-1][0]);
		else
		{
			f[i][1]=min(f[i][1],f[i-1][0]+c[i]);
			g[i][1]=g[i-1][0];
		}
		if(h[i]>=g[i-1][1])
			f[i][0]=min(f[i][0],f[i-1][1]);
		else
		{
			if(f[i][1]>=f[i-1][1]+c[i])
				f[i][1]=f[i-1][1]+c[i],g[i][1]=min(g[i][1],g[i-1][1]);
		}
	}
	cout<<min(f[n][0],f[n][1]);
	return 0;
}
