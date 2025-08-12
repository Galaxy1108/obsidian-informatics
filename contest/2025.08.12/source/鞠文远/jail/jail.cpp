#include<bits/stdc++.h>
using namespace std;
const int N=3e5+5;
int T,dep[N],s[N],t[N],dg[N],fa[N][20];
vector<int>vec[N],tp[N];
map<pair<int,int>,bool>mp;
void dfs(int u,int ufa)
{
	fa[u][0]=ufa;
	dep[u]=dep[ufa]+1;
	for(int i=0;i<vec[u].size();i++)
	{
		int v=vec[u][i];
		if(v==ufa)continue;
		dfs(v,u);
	}
}
int lca(int a,int b)
{
	while(true)
	{
		if(a==b)break;
		if(dep[a]<dep[b])swap(a,b);
		int cnt=0;
		for(int i=0;i<20;i++)
		{
			if(dep[fa[a][i]]<=dep[b])break;
			cnt=i; 
		}
		a=fa[a][cnt];
	}
	return a;
}
int main()
{
	freopen("jail.in","r",stdin);
	freopen("jail.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--)
	{
		int n,m;
		cin>>n;
		dep[0]=0x3f3f3f3f;
		mp.clear();
		for(int i=1;i<=n;i++)vec[i].clear();
		memset(fa,0,sizeof(fa));
		memset(dg,0,sizeof(dg));
		for(int i=1,u,v;i<n;i++)
		{
			cin>>u>>v;
			vec[u].push_back(v);
			vec[v].push_back(u);
		}
		dfs(1,0);
		for(int i=1;i<20;i++)
			for(int j=1;j<=n;j++)
				fa[j][i]=fa[fa[j][i-1]][i-1];
		cin>>m;
		for(int i=1;i<=m;i++)tp[i].clear();
		for(int i=1;i<=m;i++)cin>>s[i]>>t[i];
		bool pd=false;
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(i==j)continue;
				int l1=lca(s[i],t[i]);
				bool p1=false,p2=false;
				int c1=s[i],c2=t[i];
				if(c1==s[j]||c2==s[j])p1=true;
				while(c1!=l1)
				{
					c1=fa[c1][0];
					if(c1==s[j])p1=true;
					if(c1==t[j])p2=true;
				}
				if(c1==t[j]||c2==t[j])p2=true;
				while(c2!=l1)
				{
					c2=fa[c2][0];
					if(c2==s[j])p1=true;
					if(c2==t[j])p2=true;
				}
				if(p1)
				{
					if(!mp[make_pair(j,i)])
					{
						mp[make_pair(j,i)]=true;
						tp[j].push_back(i);
						dg[i]++;
					}	
				}
				if(p2)
				{
					if(!mp[make_pair(i,j)])
					{
						mp[make_pair(i,j)]=true;
						tp[i].push_back(j);
						dg[j]++;	
					}
				}
			}
		}
		queue<int>vb;
		for(int i=1;i<=m;i++)if(!dg[i])vb.push(i);
		while(!vb.empty())
		{
			int u=vb.front();
			vb.pop();
			for(int i=0;i<tp[u].size();i++)
			{
				int v=tp[u][i];
				if(!--dg[v])vb.push(v);
			}
		}
		for(int i=1;i<=m;i++)if(dg[i])pd=true;
		cout<<(pd?"No\n":"Yes\n");
	}	
	
	return 0;
} 
