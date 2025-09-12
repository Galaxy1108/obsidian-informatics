#include <bits/stdc++.h>
using namespace std;
vector<int> v[200005];
bool bk[200005];
int s[200005];
int a[200005];
inline bool cmp(int a,int b)
{
	return a>b;
}
inline void dfs(int i,int fa,int dep)
{
	if(bk[i]) return;
	bk[i]=1;
	s[i]=dep;

	for(auto u:v[i])
	{
		dfs(u,i,dep+1);
	}
	s[fa]=max(s[fa],s[i]);
}
int main()
{
	freopen("labyrinth.in","r",stdin);
	freopen("labyrinth.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		memset(v,0,sizeof(v));
		memset(bk,0,sizeof(bk));
		memset(a,0,sizeof(a));
		int n,m;
		cin>>n;
		int u,j;
		for(int i=1;i<n;i++)
		{
			cin>>u>>j;
			v[u].push_back(j);
			v[j].push_back(u);
		}
		dfs(1,0,1);
		int tot=0;
		for(auto i:v[1])
		{
			a[++tot]=s[i];
		}
//		for(int i=1;i<=n;i++)
//		{
//			cout<<s[i]<<" ";
//		}
//		cout<<"\n";
		sort(a+1,a+tot+1,cmp);
		cout<<(a[1]+a[2]+2)/2<<"\n";
	}
	
	
	
	return 0;
} 
