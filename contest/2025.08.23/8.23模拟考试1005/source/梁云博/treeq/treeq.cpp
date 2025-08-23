#include <bits/stdc++.h>
#define int long long
#define N 2000005
using namespace std;
int n;
int head[N],to[N],nxt[N],val[N];
void add(int u,int v,int w)
{
	static int idx=0;
	to[++idx]=v;
	nxt[idx]=head[u];
	val[idx]=w;
	head[u]=idx;
}
int siz[N],f[N];
int dfs(int p,int fa)
{
	siz[p]=1;
	f[p]=fa;
	for(int i=head[p];i;i=nxt[i])
	{
		int v=to[i];
		if(v==fa)continue;
		siz[p]+=dfs(v,p);
	}
	return siz[p];
}
int e[N]={0};
vector<int>path;
signed main()
{
	freopen("treeq.in","r",stdin);
	freopen("treeq.out","w",stdout);
	cin>>n;
	int flg2=1;
	for(int i=2,u,w;i<=n;i++)
	{
		cin>>u>>w;
		add(i,u,w);
		add(u,i,w);
		if(w!=1)flg2=0;
	}
	dfs(1,0);
	if(flg2)
	{
		int ans=0; 
		for(int i=1;i<=n;i++)
		{
			//枚举i所有连着的边
			path.clear(); 
			int maxn=0;
			for(int j=head[i];j;j=nxt[j])
			{
				int v=to[j];
				if(v==f[i])
				{
					int res=siz[1]-siz[i];
					if(res>maxn)
					{
						maxn=res;
						path.clear();
						path.push_back(i);
					}
					else if(res==maxn)path.push_back(i);
				}
				else
				{
					if(siz[v]>maxn)
					{
						maxn=siz[v];
						path.clear();
						path.push_back(v);
					}
					else if(siz[v]==maxn)path.push_back(v);
				}
			}
			for(int j:path)e[j]++;
		}
		for(int i=1;i<=n;i++)ans^=e[i];
		cout<<ans;
		return 0;
	}
	return 0;
}
