#include<bits/stdc++.h>
#define ll long long
#define INF 214748364719260817ll
using namespace std;
ll n;
ll w[2005][2005];
ll dis[2005],mv[2005];
bool vis[2005],use[2005];
int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	ll minn=214748364719260817ll;
	for(ll i=1;i<=n;++i)
		for(ll j=i+1;j<=n;++j)
		cin>>w[i][j],w[j][i]=w[i][j],minn=min(minn,w[i][j]);
	for(ll i=1;i<=n;++i)
		for(ll j=1;j<=n;++j)
			if(w[i][j]==minn)
			{
				use[i]=1;break;
			}
	for(ll i=1;i<=n;++i)
		for(ll j=1;j<=n;++j)
			if(i!=j)w[i][j]-=minn;	
	for(ll t=1;t<=n;++t)
	{
		if(use[t])
		{
			cout<<minn*(n-1)<<'\n';continue;
		}
		for(ll i=1;i<=n;++i)dis[i]=mv[i]=INF,vis[i]=0;
		dis[t]=0;
		ll cot=n-1;
		while(cot--)
		{
			ll minn=INF,uid=0;
			for(ll i=1;i<=n;++i)
				if((dis[i]==minn&&use[i]||dis[i]<minn)&&!vis[i])minn=dis[i],uid=i;
			vis[uid]=1;
			if(use[uid])break;
			ll nm=mv[uid];
			for(ll i=1;i<=n;++i)
			if(!vis[i])
			{
				if(dis[i]>dis[uid]+min(nm,w[uid][i]))
				dis[i]=dis[uid]+min(nm,w[uid][i]),mv[i]=min(nm,w[uid][i]);
				else if(dis[i]==dis[uid]+min(nm,w[uid][i]))
				mv[i]=min(mv[i],min(nm,w[uid][i]));
			}	
		}
		ll res=214748364719260817ll;
		for(ll i=1;i<=n;++i)
			if(use[i])res=min(res,dis[i]);
		cout<<res+minn*(n-1)<<'\n';
	}
}//prim 是正确的？？？验证一下/se
//I won't say it in twice!
//O(n^3) 启动？
//65 就 65 吧 

