/*
1-2 链
3-6 QN
7-10 QNM!
11-12 QNM log M
13-14 QNM
15-16 ? 
*/
#include<bits/stdc++.h>
using namespace std;
int q,n,m,x,y,a[120005],b[120005],fa[120005],dep[120005];
vector<int> v[120005];
vector<int> w[120005];
int f[120005][20];
void dfs(int x,int faa)
{
	dep[x]=dep[faa]+1;
	f[x][0]=faa;
	for(int i = 1; (1<<i) <= dep[x]; i++)
	{
		f[x][i]=f[f[x][i-1]][i-1];
	}
	for(int i = 0; i < v[x].size(); i++)
	{
		if(v[x][i]!=faa)
		{
			dfs(v[x][i],x);
		}
	}
	return;
}
int lca(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	int les=dep[x]-dep[y];
	for(int i = 20; i >= 0; i--)
	{
		if(les&(1<<i))
		{
			x=f[x][i];
		}
	}
	if(x==y) return x;
	for(int i = 19; i >= 0; i--)
	{
		if(f[x][i]!=f[y][i])
		{
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}
queue<int> s,emp;
vector<int> vv;
int in[120005];
bool topo()
{
	vv.clear();
	s=emp;
	for(int i = 1; i <= n; i++)
	{
		if(in[i]==0)
		{
			s.push(i);
		}
	}
	while(!s.empty())
	{
		int ff=s.front();
		s.pop();
		vv.push_back(ff);
		for(int i = 0; i < w[ff].size(); i++)
		{
			in[w[ff][i]]--;
			if(in[w[ff][i]]==0)
			{
				s.push(w[ff][i]);
			}
		}
	}
	if(vv.size()==n)
	{
		return 1;
	}
	return 0;
}
int ll[120005];
void sol()
{
	cin>>n;
	for(int i = 1; i <= n; i++)
	{
		v[i].clear(); 
		w[i].clear();
		in[i]=0;
	}
	for(int i = 1; i < n; i++)
	{
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1,0);
	cin>>m;
	for(int i = 1; i <= m; i++)
	{
		cin>>a[i]>>b[i];
		ll[i]=lca(a[i],b[i]);
	}
	//cout<<lca(2,5);
	/*
	如果一个点的起点下面有起点/终点 那么这个点必须在前面行动
	如果一个点终点下面有起点/终点 那么这个点必须在后面行动 
	
	如果能topo出顺序 则可以
	否则不行 
	*/ 
	//cout<<lca(3,4)<<endl;
	for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(i==j) continue;
			if(lca(a[i],a[j])==a[i]&&lca(ll[j],a[i])==ll[j])
			{
				w[i].push_back(j);
				in[j]++;
				//cout<<i<<" "<<j<<" in[j]++(ai is aj's father)"<<endl;
			}
			if(lca(a[i],b[j])==a[i]&&lca(ll[j],a[i])==ll[j])
			{
				w[i].push_back(j);
				in[j]++;
				//cout<<i<<" "<<j<<" in[j]++(ai is bj's father)"<<endl;
			}
			if(lca(b[i],a[j])==b[i]&&lca(ll[j],b[i])==ll[j])
			{
				w[j].push_back(i);
				in[i]++;
				//cout<<i<<" "<<j<<" in[i]++(bi is aj's father)"<<endl;
			}
			if(lca(b[i],b[j])==b[i]&&lca(ll[j],b[i])==ll[j])
			{
				w[j].push_back(i);
				in[i]++;
				//cout<<i<<" "<<j<<" in[i]++(bi is bj's father)"<<endl;
			}
			/*if(lca(a[i],a[j])==a[i])
			{
				w[i].push_back(j);
				in[j]++;
				//cout<<i<<" "<<j<<" in[j]++(ai is aj's father)"<<endl;
			}
			if(lca(a[i],b[j])==a[i])
			{
				w[i].push_back(j);
				in[j]++;
				//cout<<i<<" "<<j<<" in[j]++(ai is bj's father)"<<endl;
			}
			if(lca(b[i],a[j])==b[i])
			{
				w[j].push_back(i);
				in[i]++;
				//cout<<i<<" "<<j<<" in[i]++(bi is aj's father)"<<endl;
			}
			if(lca(b[i],b[j])==b[i])
			{
				w[j].push_back(i);
				in[i]++;
				//cout<<i<<" "<<j<<" in[i]++(bi is bj's father)"<<endl;
			}*/
		}
	}
	if(topo()) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}
int main()
{
	freopen("jail.in","r",stdin);
	freopen("jail.out","w",stdout); 
	cin>>q;
	while(q--) sol();
 } 
