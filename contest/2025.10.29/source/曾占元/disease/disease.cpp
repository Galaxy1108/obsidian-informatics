#include<bits/stdc++.h>
using namespace std;
int fa[305];
bool gr[305];
vector<int>tu[305];
struct cxt
{
	int sz,deep;
}tree[305];
bool cmp(cxt x,cxt y)
{
	if(x.deep==y.deep)
		return x.sz>y.sz;
	return x.deep<y.deep;
}
void dfs(int x,int f)
{
	tree[x].sz=1;
	for(int i:tu[x])
	{
		if(i==f)
			continue;
		fa[i]=x;
		tree[i].deep=tree[x].deep+1;
		dfs(i,x);
		tree[x].sz+=tree[i].sz;
	}
	return ;
}
int main()
{
	freopen("disease.in","r",stdin);
	freopen("disease.out","w",stdout);
	int n,p;
	cin>>n>>p;
	for(int i=1;i<=p;i++)
	{
		int u,v;
		cin>>u>>v;
		tu[u].push_back(v);
		tu[v].push_back(u);
	}
	dfs(1,0);
	sort(tree+1,tree+n+1,cmp);
	int top=2,ans=n;
	for(int i=3;i<=n;i++)
	{
		if(tree[i].deep!=tree[i-1].deep)
		{
			ans-=tree[top].sz;
			gr[top]=1;
			top=i;
		}
		if(gr[fa[i]])
		{
			gr[i]=1;
			if(top==i)
				top++;
		}
		else if(tree[i].sz>tree[top].sz)
			top=i;
	}
	ans-=tree[top].sz;
	cout<<ans;
	return 0;
}
