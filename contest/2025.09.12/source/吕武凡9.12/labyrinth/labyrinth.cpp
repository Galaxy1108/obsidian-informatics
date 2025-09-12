#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int t;
int n;
int x,y;
int tot=0;
int head[500001];
int f[200010];
struct Edge
{
	int nx,to;
}e[500001];
void edge(int u,int v)
{
	e[++tot].nx=head[u];
	e[tot].to=v;
	head[u]=tot;
}
void DFS(int j,int s,int fa,int sum)
{
	for(int i=head[s];i;i=e[i].nx)
	{
		int y=e[i].to;
		if(y==fa)
		{
			continue;
		}
		DFS(j,y,s,sum+1);
	}
	f[j]=max(f[j],sum);
}
int calc(int x)
{
	if(x==1)
	{
		return 1;
	}
	return calc(x-(x+1)/2)+1;
}
int main()
{
	freopen("labyrinth.in","r",stdin);
	freopen("labyrinth.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		tot=0;
		cin>>n;
		for(int i=1;i<n;i++)
		{
			cin>>x>>y;
			edge(x,y);
			edge(y,x);
		}
		cout<<calc(n)<<endl;
	}
}
/*
1
11
1 10
1 7
4 1
5 4
10 6
9 8
5 11
2 4
5 3
9 5
*/
