#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;
const int N=301;
int n,p,u,v,i,j,f,cnt=0,ans;
struct Node{
	vector<int> son;
	int father,sum=1,dfn,outsum;
	bool cut=0;
} tree[N];
unordered_set<int> edge[N];
bool dfsv[N];
queue<int> topu;
vector<int> lun[N];
inline void dfs(int x)
{
	dfsv[x]=1;
	if(edge[x].size()==1&&x!=1)
	{
		tree[x].dfn=tree[tree[x].father].dfn+1;
		tree[x].outsum=0;
		topu.push(x);
		return;
	}
	for(const int &val:edge[x])
	{
		if(dfsv[val])
		{
			tree[x].father=val;
			tree[x].dfn=tree[val].dfn+1;
			break;
		}
	}
	for(const int &val:edge[x])
	{
		if(!dfsv[val])
		{
			tree[x].son.push_back(val);
			tree[val].father=x;
			dfs(val); 
		}
	}
	tree[x].outsum=tree[x].son.size();
	return;
}
inline void cut_tag(int x)
{
	tree[x].cut=1;
	for(const int &val:tree[x].son)
	{
		cut_tag(val);
	}
	return;
}
int main()
{
	freopen("disease.in","r",stdin);
	freopen("disease.out","w",stdout);
	scanf("%d %d",&n,&p);
	ans=n;
	while(p--)
	{
		scanf("%d %d",&u,&v);
		edge[u].insert(v);
		edge[v].insert(u);
	}
	tree[1].dfn=0;
	dfs(1);
	while(!topu.empty())
	{
		f=topu.front();
		if(f==1)
			break;
		tree[tree[f].father].sum+=tree[f].sum;
		tree[tree[f].father].outsum--;
		if(!tree[tree[f].father].outsum)
		{
			topu.push(tree[f].father);
		}
		topu.pop();
	}
/*	for(i=1;i<=n;i++)
	{
		printf("%d  %d %d %d %d\n",i,tree[i].father,tree[i].dfn,tree[i].outsum,tree[i].sum);
		for(const int &val:tree[i].son)
		{
			printf("%d ",val);
		}
		putchar('\n');
	}	*/
	for(i=1;i<=n;i++)
	{
		cnt=max(cnt,tree[i].dfn);
		lun[tree[i].dfn].push_back(i);
	}
	for(i=1;i<=cnt;i++)
	{
		int mx=0,jl=0,mxe=0;
		for(const int &val:lun[i])
		{
			if(!tree[val].cut&&tree[val].sum>mx)
			{
				mx=tree[val].sum;
			}
		}
		for(const int &val:lun[i])
		{
			if(!tree[val].cut&&tree[val].sum==mx)
			{
				if(tree[val].son.size()>mxe)
				{
					jl=val;
					mxe=tree[val].son.size();
				}
			}
		}
		if(jl)
		{
			ans-=tree[jl].sum;
			cut_tag(jl);
		}
			
	} 
/*	for(i=1;i<=n;i++)
	{
		if(!tree[i].cut)
			printf("%d ",i);
	}	*/	
	printf("%d",ans);
	return 0;
}
/*
3 2
1 2
2 3

13 14
1 2
1 9
9 1
2 3
2 4
2 5
4 6
4 7
5 8
10 9
11 9
9 11
11 12
11 13

*/
