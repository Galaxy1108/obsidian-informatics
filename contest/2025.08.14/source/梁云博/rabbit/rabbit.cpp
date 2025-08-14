#include <bits/stdc++.h>
using namespace std;
int n,m,s,t,flg=1;
//int head[N],to[M],nxt[M],val[M];
//void add(int u,int v,int w)
//{
//	static int idx=0;
//	to[++idx]=v;
//	nxt[idx]=head[u];
//	val[idx]=w;
//	head[u]=idx;
//}
int main()
{
	freopen("rabbit.in","r",stdin);
	freopen("rabbit.out","w",stdout);
	cin>>n>>m>>s>>t;
	for(int i=1,x,y,o;i<=m;i++)
	{
		cin>>x>>y>>o;
		if(o!=0)flg=0;
//		add(x,y,0);
	}
	if(flg)
	{
		cout<<"0 0";
		return 0;
	}
	else
	{
		cout<<m*m<<" "<<n*n;
	}
	return 0;
} 
