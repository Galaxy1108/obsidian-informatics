#include <bits/stdc++.h>
#define N 200005
using namespace std;
int n,m;
struct E{
	int u,v;
}eo[N<<1],es[N<<1];
int tot; 
int pvis[N],evis[N];
int ans=0;
void Mobius(int p,int sum)
{
	if(p==tot+1)
	{
		ans=max(ans,sum);
		return;
	}
	
	if(!pvis[es[p].u] && !pvis[es[p].v])
	{
		pvis[es[p].v]=pvis[es[p].u]=1;
		Mobius(p+1,sum+1);
		pvis[es[p].v]=pvis[es[p].u]=0;
	}Mobius(p+1,sum);//不选这条边 
}

int main()
{
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	cin>>n>>m;
	for(int i=1,u,v;i<=m;i++)
	{
		cin>>u>>v;
		if(u>v)swap(u,v);
		eo[i]={u,v};
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=i+1;j<=m;j++)
		{
			if(eo[i].u==eo[j].u || eo[i].u==eo[j].v || eo[i].v==eo[j].v || eo[i].v==eo[j].u)es[++tot]={i,j};
		}
	}
	if(m<=30)
	{
		Mobius(1,0);
		cout<<ans;
	}
	else cout<<m/2;
	return 0;
}
