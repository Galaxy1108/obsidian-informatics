#include <bits/stdc++.h>
#define sol xw[stax][stay]
using namespace std;
int Qread()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return x;
}
typedef pair<int,int> pr;
int n,Q,i,j;
int stax,stay,enx,eny,lim;
int a[310][310];
long long f[310][310];
vector<pr> xw[310][310];
long long ans[200010];
int main()
{
	freopen("glyph.in","r",stdin);
	freopen("glyph.out","w",stdout);
	n=Qread(),Q=Qread();
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
		a[i][j]=Qread();
	for(i=1;i<=Q;i++)
	{
		stax=Qread(),enx=Qread(),stay=Qread(),eny=Qread();
		sol.push_back(make_pair((eny-1)*n+enx-1,i));
	}
	for(stax=n;stax;stax--)
	for(stay=n;stay;stay--)
	{
		if(sol.empty()) continue;
		for(i=stax;i<=n;i++)
		for(j=stay;j<=n;j++)
		{
			if(i==stax)
			{
				if(j==stay) f[i][j]=a[i][j];
				else f[i][j]=f[i][j-1]+a[i][j];
			}
			else
			{
				if(j==stay) f[i][j]=f[i-1][j]+a[i][j];
				else f[i][j]=min(f[i-1][j],f[i][j-1])+a[i][j];
			}
		}
		lim=sol.size();
		for(i=0;i<lim;i++)
			ans[sol[i].second]=f[sol[i].first%n+1][sol[i].first/n+1];
	}
	for(i=1;i<=Q;i++)
		printf("%lld\n",ans[i]);
	return 0;
}