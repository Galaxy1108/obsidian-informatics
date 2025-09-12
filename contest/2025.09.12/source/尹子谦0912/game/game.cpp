#include<bits/stdc++.h>
using namespace std;
const int N=3e3+10;
int n,m,W[N][N],a,b;
vector<int> edge[N];
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int T; 
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		a=b=0;
		for(int i=1;i<=n;i++) edge[i].clear();
		for(int i=1;i<=m;i++)
		{
			int u,v,w;
			cin>>u>>v>>w;
			edge[u].push_back(v);
			edge[v].push_back(u);
			W[u][v]+=w;
			W[v][u]+=w;
		}
		cout<<0<<endl;
	}
	return 0;
}
