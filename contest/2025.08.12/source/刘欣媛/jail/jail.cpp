#include <bits/stdc++.h>
using namespace std;
int Q,n,m,vis[120005],son[120005],dep[120005];
vector<int> v[120005];
void dfs(int i)
{
	if(vis[i]) return;
	vis[i]=1;
	son[i]=v[i].size()-1;
	for(auto u:v[i])
	{
		if(vis[u]) continue;
		dep[u]=dep[i]+1;
		dfs(u);
		son[i]+=son[u];
	}
}
struct node{
	int val,id;
}s[120005],t[120005];
bool cmp(node a,node b)
{
	return a.val<b.val;
}
int main()
{
	freopen("jail.in","r",stdin);
	freopen("jail.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>Q;
	while(Q--)
	{
		cin>>n;
		memset(v,0,sizeof(v));
		int a,b;
		for(int i=1;i<n;i++)
		{
		
			vis[i]=0;
			cin>>a>>b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		cin>>m;
		for(int i=1;i<=m;i++)
		{
			cin>>s[i].val>>t[i].val;
			s[i].id=i,t[i].id=i;
		}
		
		if(a==n-1&&b==n)
		{
			sort(s+1,s+m+1,cmp);
			sort(t+1,t+m+1,cmp);
			bool fl=0;
			for(int i=1;i<=m;i++)
			{
				if(s[i].id!=t[i].id)
				{
					cout<<"No\n";
					fl=1;
					break;
				}
			}
			if(!fl){
				cout<<"Yes\n";
			}
		}
		else
		{
			dfs(1);
			if(son[1]>2)
			{
				cout<<"Yes\n";
				continue;
			}
			if(dep[s[1].val]>dep[s[2].val]) {
				swap(s[1].val,s[2].val);
				swap(t[1].val,t[2].val);
			}
			if(son[s[1].val])
			{
				cout<<"Yes\n";
				continue;
			}
			else
			{
				
				cout<<"No\n";
			}
		}
	}
	return 0;
 } 
