#include<bits/stdc++.h>
using namespace std;
int n,p;
int x,y;
int tot=0;
int head[1000100];
struct Edge
{
    int nx,to;
}e[1001000];
void edge(int u,int v)
{
    e[++tot].nx=head[u];
    e[tot].to=v;
    head[u]=tot;
}
int dep[100010],siz[100010],fa[100010],son[1010];
void DFS(int s,int f)
{
	fa[s]=f;
	dep[s]=dep[f]+1;
	siz[s]=1;
    for(int i=head[s];i;i=e[i].nx)
    {
        int y=e[i].to;
        if(y==f)
        {
            continue;
        }
        DFS(y,s);
        siz[s]+=siz[y];
        son[s]++;
    }
}
int ans;
bool tick[1010];
vector<int> ds[400];
bool cmp(int x,int y)
{
	if(siz[x]!=siz[y])
	{
		return siz[x]>siz[y];	
	}
	else
	{
		return son[x]>son[y];
	}
}
void clear(int s)
{
	tick[s]=1;
	for(int i=head[s];i;i=e[i].nx)
	{
		int y=e[i].to;
		if(y==fa[s])
		{
			continue;
		}
		clear(y);
	}
}
int main()
{
    freopen("disease.in","r",stdin);
    freopen("disease.out","w",stdout);
    cin>>n>>p;
    ans=n;
    for(int i=1;i<=p;i++)
    {
        cin>>x>>y;
        edge(x,y);
        edge(y,x);
    }
    DFS(1,0);
    int maxn=0;
    for(int i=1;i<=n;i++)
    {
    	ds[dep[i]].push_back(i);
    	maxn=max(maxn,dep[i]);
	}
	for(int i=2;i<=maxn;i++)
	{
		sort(ds[i].begin(),ds[i].end(),cmp);
	}
	for(int i=2;i<=maxn;i++)
	{
		int p=0;
		for(auto j:ds[i])
		{
			if(tick[j]==0)
			{
				p=j;
				break;
			}
		}
		if(p==0)
		{
			break;
		}
		ans-=siz[p];
		clear(p);
	}
	cout<<ans;
}
