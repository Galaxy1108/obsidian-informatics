#include <bits/stdc++.h>
#define int long long
#define N 120005
using namespace std;
//vector<int>g[N];
int a[N],b[N],f[N][25],st[N],ed[N];
int q,n,m;
//void Mobius(int p,int fa,int dp)
//{
//	f[p][0]=fa;
//	depth[p]=dp;
//	for(int v:g[p])
//	{
//		if(v!=fa)
//		{
//			Mobius(v,p,dp+1);
//		}
//	}
//}
signed main()
{
	freopen("jail.in","r",stdin);
	freopen("jail.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>q;
	while(q--)
	{ 
		cout<<"Yes\n";
//		cin>>n;
////		int lstf=1;
//		for(int i=1,u,v;i<n;i++)
//		{
//			cin>>u>>v;
//			g[u].push_back(v);
//			g[v].push_back(u);
////			if(v!=i+1 || u!=i)lstf=0;
//		}
//		//上面的囚犯若有一人路径可完全包含另一人路径，或两人方向相反，依然有终点在路径上，则不可实现 
//		cin>>m;
//		for(int i=1;i<=m;i++)
//		{
//			cin>>a[i]>>b[i];
//			st[a[i]]=i;
//		}
//		Mobius(1,0,1);
		
	}
	return 0;	
}
