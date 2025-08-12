#include<bits/stdc++.h>
using namespace std;
const int mx=290;
int dis[mx],h[mx],cnt;
int n,m,s,q;
int en;
int fread()
{
	int x=0,w=1;char ch=getchar();
	while(ch<'0'||ch>'9') w=ch=='-'?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch-'0'),ch=getchar();
	return x*w;
 } 
 struct road
 {
 	int a,b,l,c;
 }r[mx];
 struct edge
 {
 	int to,nxt,ti,w;
 }e[2*mx];
 void build(int u,int v,int w,int c)
 {
 	e[++cnt].to=v;
 	e[cnt].nxt=h[u];
 	e[cnt].w=w;
 	e[cnt].ti=c;
 	h[u]=cnt;
 	return ;
 }
 void dfs(int k,int t)
 {
// 	cout<<"?"<<t<<endl;
 	dis[k]=min(dis[k],t);
 	if(dis[k]<=t) return ;
 	for(int i=h[k];i;i=e[i].nxt)
 	{
 		int v=e[i].to;
// 		cout<<v<<endl;
 		if(t%s+e[i].w>e[i].ti) dfs(v,t+s-t%s+e[i].w);
 		else
 		dfs(v,t+e[i].w);
	 }
 }
int main()
{
	freopen("route.in","r",stdin);
	freopen("route.out","w",stdout);
	n=fread(),m=fread(),s=fread(),q=fread();
//	memset(h,-1,sizeof(h));
	for(int i=1;i<=m;i++)
	{
		r[i].a=fread(),r[i].b=fread(),r[i].l=fread(),r[i].c=fread();
		build(r[i].a,r[i].b,r[i].l,r[i].c);build(r[i].b,r[i].a,r[i].l,r[i].c);
	}
	 while(q--)
	 {
	 	memset(dis,0x3f,sizeof(dis));
	 	int u=fread(),v=fread(),tt=fread();
	 	en=v;
	 	dis[u]=0;
	 	dfs(u,tt);
//	 	for(int i=0;i<n;i++)
//	 	cout<<dis[i]<<' ';
//	 	cout<<endl;
	 	cout<<dis[v]-tt<<endl;
	 }
	return 0;
}
