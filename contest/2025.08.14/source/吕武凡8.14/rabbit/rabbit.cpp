#include<bits/stdc++.h>
using namespace std;
#define int long long
const long long mod=998244353;
int n,m,s,t;
int x,y,o;
int tot=0;
int sco=0,num=0,ans=0,fang=0;
int head[100001];
struct Edge
{
	int nx,to,w;
}e[1000001];
void edge(int u,int v,int val)
{
	e[++tot].nx=head[u];
	e[tot].to=v;
	e[tot].w=val;
	head[u]=tot;
}
void DFS(int s,int t)
{
	if(s==t)
	{
		sco+=ans;
		fang+=ans*ans;
		num++;
		return;
	}
	for(int i=head[s];i;i=e[i].nx)
	{
		int y=e[i].to;
		int p;
		if(e[i].w==1)
		{
			ans++;
		}
		else
		{
			p=ans;
			ans=0;
		}
		DFS(y,t);
		if(e[i].w)
		{
			ans--;
		}
		else
		{
			ans=p;	
		} 
	}
}
signed main()
{
	freopen("rabbit.in","r",stdin);
	freopen("rabbit.out","w",stdout);
	cin>>n>>m>>s>>t;
	bool f=1;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y>>o;
		if(o!=0)
		{
			f=0;
		}
		edge(x,y,o);
	}
	if(f==1)
	{
		cout<<"0 0";
		return 0;
	}
	DFS(s,t);
	cout<<sco%mod<<endl;
	cout<<(fang*num-sco*sco+mod)%mod;
}
/*
7 10 1 7
1 2 1
1 3 1
1 4 0
2 4 1
3 4 1
4 5 1
4 6 1
4 7 0
5 7 1
6 7 1
*/
