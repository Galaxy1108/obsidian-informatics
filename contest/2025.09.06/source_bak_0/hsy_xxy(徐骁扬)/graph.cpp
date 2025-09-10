#include <bits/stdc++.h>
using namespace std;
int Qread()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return x;
}
struct Edge{
	int nxt,poi;
}l[600010];
int cnt;
struct Point{
	int sta,num;
	bool vis;
}p[100010];
void add_edge(int u,int v)
{
	l[++cnt].poi=v,l[cnt].nxt=p[u].sta,p[u].sta=cnt;
	l[++cnt].poi=u,l[cnt].nxt=p[v].sta,p[v].sta=cnt;
	p[u].num++,p[v].num++;
	return;
}
int n,m,i,ans;
int dfs(int a)
{
	if(p[a].vis) return 0;
	p[a].vis=true;
	int rem=0;
	for(int k=p[a].sta;k;k=l[k].nxt)
		rem+=dfs(l[k].poi);
	return rem+p[a].num;
}
int main()
{
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	n=Qread(),m=Qread();
	for(i=1;i<=m;i++)
		add_edge(Qread(),Qread());
	for(i=1;i<=n;i++)
		if(!p[i].vis)
			ans+=(dfs(i)>>2);
	printf("%d\n",ans);
	return 0;
}