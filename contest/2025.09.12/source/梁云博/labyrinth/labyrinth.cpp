#include <bits/stdc++.h>
#define N 200005
//#define int long long
using namespace std;
int n;
vector<int>g[N];
int t;
int main()
{
//	freopen("ex_labyrinth3.in","r",stdin);
	freopen("labyrinth.in","r",stdin);
	freopen("labyrinth.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--)
	{
		int flg=1;
		cin>>n;
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1,u,v;i<n;i++)
		{
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		for(int i=1;i<=n;i++)
		{
			if(g[i].size()==1)flg--;
			if(g[i].size()>2 || g[i].size()<1){flg=-2;break;}
		}
		if(flg==-1)
		{
			int lg[N]={0};
			for(int i=2;i<=n+2;i++)lg[i]=lg[i/2]+1; 
//			if(lg[n]==lg[n+1])cout<<lg[n]+1<<"\n";
//			else cout<<lg[n]<<"\n";
			cout<<lg[n]+1<<"\n";
		}
		else
		{
			
		}
	}
	return 0;
} 
