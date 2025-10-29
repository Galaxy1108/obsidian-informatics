#include<bits/stdc++.h>
using namespace std;
const int N=305;
int n,p,anslt=1,mx,lt=0x3f3f3f3f,dep[N];
vector<int>vec[N];
vector<int>inf;
bool pro[N];
void getdep(int u,int fa)
{
	dep[u]=dep[fa]+1;
	mx=max(mx,dep[u]);
	for(int i=0;i<vec[u].size();i++)
	{
		int v=vec[u][i];
		if(v==fa)continue;
		getdep(v,u);
	}
}
void dfs(int tu)
{
	if(tu>=mx||inf.size()==0)
	{
		lt=min(lt,anslt);
		return;	
	}
	for(int i=1;i<=n;i++)
	{
		if(dep[i]!=tu+1)continue;
		pro[i]=true;
		vector<int>cd=inf,nw;
		for(int j=0;j<inf.size();j++)
			for(int k=0;k<vec[inf[j]].size();k++)
			{
				if(dep[vec[inf[j]][k]]<dep[inf[j]]||pro[vec[inf[j]][k]])continue;
				anslt++;
				nw.push_back(vec[inf[j]][k]);
			}
		inf=nw;
		dfs(tu+1);
		inf=cd;
		for(int j=0;j<inf.size();j++)
			for(int k=0;k<vec[inf[j]].size();k++)
			{
				if(dep[vec[inf[j]][k]]<dep[inf[j]]||pro[vec[inf[j]][k]])continue;
				anslt--;
			}
		pro[i]=false;
	}
}
int main()
{
	freopen("disease.in","r",stdin);
	freopen("disease.out","w",stdout);
	cin>>n>>p;
	for(int i=1;i<=p;i++)
	{
		int u,v;
		cin>>u>>v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	inf.push_back(1);
	getdep(1,0);
	dfs(1);
	cout<<lt;
	
	return 0;
} 
