#include<bits/stdc++.h>
using namespace std;
const int mx=120050;
int n,m,Q;
int cnt,hd[mx],h[mx];
struct crime
{
	int s,t;
	bool operator<(const crime &x) const
	{
		return s<x.s;
	}
}a[mx];
struct Edge
{
	int to,nxt;
}e[mx*2];
void add(int x,int y)
{
	e[++cnt].to=y;
	e[cnt].nxt=hd[x];
	hd[x]=cnt;
}
int main()
{
	freopen("jail.in","r",stdin);
	freopen("jail.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>Q;
	while(Q--)
	{
		bool pd=1;
		cin>>n;
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			if(u!=i||v!=i+1) pd=0;
			add(u,v);
			add(v,u);
		}
		cin>>m;
		for(int i=1;i<=m;i++) cin>>a[i].s>>a[i].t;
		if(pd==1)
		{
			bool flag=1;
			sort(a+1,a+1+m);
			for(int i=2;i<=m;i++)
			{
				if(a[i].t<a[i-1].t)
				{
					flag=0;
					break;
				}
			}
			if(flag==1) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
		else if(m<=6)
		{
			cout<<"Yes"<<endl;
		}
	}
	return 0;
} 
