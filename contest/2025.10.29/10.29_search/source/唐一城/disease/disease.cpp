#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(time(0));
#define il inline
const int N=305;
int n,m,p[N];
struct edge {
	int v,nxt;
}e[N<<1];
int head[N],et=0;
il void add(int u,int v) {
	e[++et].v=v;
	e[et].nxt=head[u];
	head[u]=et;
}
int ans=INT_MAX,can[N<<1],sum=0;
il void dfs(int u,int fa,int dis) {
	sum++;
	for(int i=head[u];i;i=e[i].nxt) {
		int v=e[i].v;
		if(v==fa||can[i]<=dis)continue;
		dfs(v,u,dis+1);
	}
}
il int getres() {
	for(int i=1;i<=m;i++)can[p[i]*2]=can[p[i]*2-1]=i;
	sum=0;dfs(1,0,1);
	return sum;
}
il void SA() {
	random_shuffle(p+1,p+m+1);
	for(int i=1,x,y;i<=2000;i++) {
		x=rand()%m+1,y=rand()%m+1;
		swap(p[x],p[y]);
		int res=getres();
		if(res<ans)ans=res;
		else swap(p[x],p[y]);
	}
} 
int main() 
{
	freopen("disease.in","r",stdin);
	freopen("disease.out","w",stdout);
	cin>>n>>m;
	for(int i=1,u,v;i<n;i++) {
		cin>>u>>v;
		add(u,v),add(v,u);
	}
	for(int i=1;i<=m;i++)p[i]=i;
	for(int i=1;i<=100;i++)SA();
	cout<<ans;
	return 0;
}
/*
11 10
1 2
1 3
1 4
2 5
2 6
3 7
5 8
5 9
6 10
6 11
*/
