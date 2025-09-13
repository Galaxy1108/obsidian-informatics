#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
string s;
int n,q,lk,rk,nl=0,nr=0,lnr=0,fa[N],nxt[N],sum[N];
int fdfa(int x){return (x==fa[x]?x:fa[x]=fdfa(fa[x]));}
int main()
{
	freopen("virtual.in","r",stdin);
	freopen("virtual.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>lk>>rk;
	cin>>s;
	s='.'+s; 
	int pra=0;
	for(int i=n;i>=1;i--)
	{
		nxt[i]=pra;
		if(s[i]=='a')pra=i;
	}
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+(s[i]=='a');
	for(int i=1;i<=n;i++)
	{
		if(sum[i]==lk)
		{
			nl=i;
			break;
		}
	}
	for(int i=1;i<=n;i++)if(sum[i]<=rk)nr=i;
	lnr=nl;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=n;i++)
	{
		if(!nl)continue;
		for(int j=max(nl,lnr);j<=nr;j++)
		{
			int x=fdfa(i),y=fdfa(j);
			if(x==y)continue;
			fa[y]=x;
		}
		if(nl&&nr&&i!=1&&nl<=lnr)
		{
			int x=fdfa(i),y=fdfa(i-1);
			if(x!=y)fa[y]=x;
		}
		lnr=nr;
		if(s[i]=='a')
		{
			nl=nxt[nl];
			nr=nxt[nr];
			if(!nr)nr=n;
			else 
			{
				if(!nxt[nr])nr=n;
				else nr=nxt[nr]-1;
			}
		}
	}
	cin>>q;
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		x=fdfa(x),y=fdfa(y);
		if(x==y)cout<<"Yes\n";
		else cout<<"No\n";
	}
	
	return 0;
} 
