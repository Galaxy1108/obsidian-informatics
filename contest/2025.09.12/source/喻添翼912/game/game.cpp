#include<bits/stdc++.h> 
using namespace std;
const int mx=3e5+10;
struct edge
{
	int to;
	long long w;
};
long long w[mx];
vector<edge> e[mx];
bool cmp(long long a,long long b)
{
	return a>b;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++) e[i].clear();
		for(int i=1;i<=m;i++)
		{
			int u,v;
			cin>>u>>v;
			cin>>w[i];
		}
		sort(w+1,w+1+m,cmp);
		long long ans=0;
		for(int i=1;i<=m;i++)
			if(i%2==0) ans+=w[i];
		cout<<ans<<endl;
	}
	return 0;
}

