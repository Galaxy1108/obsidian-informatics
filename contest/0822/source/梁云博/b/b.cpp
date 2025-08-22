#include <bits/stdc++.h>
#define N 2005 
#define int long long
#define pii pair<int,int>
using namespace std;
int n;
int cnt=0;
struct E
{
	int u,v,w;
}e[N*N];
int wv[N][N];

bool cmp(E a,E b)
{
	return a.w<b.w;
}

//void finds(int s)
//{
//	int minn=1e18;
//	for(int i=1;i<=cnt;i++)//枚举每一个边 
//	{
//		int u=e[i].u,v=e[i].v,w=e[i].w;
//		if(u==s || v==s)//如果s是优边的其中之一 
//		{
//			minn=min(minn,(n-1)*w);
//		}
//		else minn=min(minn,min(wv[s][u],wv[s][v])+(n-2)*w);
//	}
//	cout<<minn;
//}
/*
首先这个图是完全图
所以说找一个最小的边权的边
再从根连过去
如果这样不优就换第二小的边

如果有一个边，那根可以通过一条固定的边经过那条优边 
 
破产了
 
 
*/
//int vis[N];
int ans;

//好像不对，这个只会生成一个链 
/*
是不是和树的形态没关系啊
好像一条链可以是最优解 

*/ 
void dfs(int p,int fa,int sum,int minn,int st)
{
	if(st==n)
	{
		ans=min(ans,sum);
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(i==p || i==fa)continue;
		int w=wv[p][i];
		dfs(i,p,sum+min(minn,w),min(minn,w),st+1);
	}
}


signed main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=n-i;j++)
		{
			e[++cnt].u=i;
			e[cnt].v=i+j;
			cin>>e[cnt].w;
			wv[i][i+j]=wv[i+j][i]=e[cnt].w;
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++){
//			cout<<wv[i][j]<<" ";
//		}cout<<"\n";
//	}
	sort(e+1,e+1+cnt,cmp);
	
	for(int t=1;t<=n;t++)
	{
		ans=1e18;
		dfs(t,0,0,1e18,1); 
		cout<<ans<<"\n";
	}
	return 0;
}
