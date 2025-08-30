#include <bits/stdc++.h>
#define N 505
using namespace std;
int n,k;
int w[N];
vector<int>g[N];
struct E{
	int u,v;
	E(){}
	E(int u,int v):u(u),v(v){}
}e[N];

int book[N][N]; //标记哪条边不能用 
int vis[N],ans;
int Mobius(int p,int fa,int res)
{
	for(int v:g[p])
	{
		if(v==fa || vis[v] || book[p][v])continue;
		vis[v]=1;
		res=__gcd(res,Mobius(v,p,w[v]));
	}
	return res;
}

void QPL(int p,int st)//上次选的位置 
{
	if(p>n)return ;
	if(st==k)
	{
		for(int i=1;i<=n;i++)vis[i]=0;
		int sum=0;
		for(int i=1;i<=n;i++)//枚举边找连通块 
		{
			//解析答案 
			if(!vis[i])
			{
				vis[i]=1;
				sum+=Mobius(i,0,w[i]);
			}
			
		}
		ans=max(ans,sum);
		return ;
	}
	for(int i=p+1;i<n;i++)
	{
		book[e[i].u][e[i].v]=1;
		book[e[i].v][e[i].u]=1;
		QPL(i,st+1);
		book[e[i].u][e[i].v]=0;
		book[e[i].v][e[i].u]=0;
	}
}

int main()
{
	freopen("plan.in","r",stdin);
	freopen("plan.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1,u,v;i<n;i++)
	{
		cin>>u>>v;
		if(u>v)swap(u,v);
		e[i]=E(u,v); 
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1;i<=n;i++)cin>>w[i];
	QPL(0,0);
	cout<<ans;
	return 0;
} 

