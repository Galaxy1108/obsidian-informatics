#include<bits/stdc++.h>
using namespace std;
int fa[500005],sz[500005],n,x,y,m,xp,yp;
int find(int xx)
{
	return (xx==fa[xx]?xx:fa[xx]=find(fa[xx]));
}
int main()
{
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	cin>>n>>m;
	for(int i = 1; i <= n; i++)
	{
		fa[i]=i;
		sz[i]=1;
	}
	if(m<n)
	{
		for(int i = 1; i <= m; i++)
		{
			cin>>x>>y;
			xp=find(x);
			yp=find(y);
			if(xp!=yp)
			{
				fa[xp]=yp;
				sz[yp]+=sz[xp];
				sz[xp]=0;
			}
		}
		int ans=0;
		for(int i = 1; i <= n; i++)
		{
			ans+=(sz[i]-1)/2;
		}
		cout<<ans<<endl;
	}
}
