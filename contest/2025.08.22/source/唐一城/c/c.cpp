#include <bits/stdc++.h>
using namespace std;
#define il inline
const int N=5005;
int n,A[N][N];
struct node
{
	int x,id;
}a[N][N];
bool cmp(node a,node b)
{
	return a.x<b.x;
}
void gen(int n,int seed){
    std::mt19937 rng(seed);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n+1;++j){
            A[i][j]=j;
            std::swap(A[i][j],A[i][rng()%j+1]);
        }
    }
}
int vis[N],s,lst[N],flag=0;
il int dfs(int x)
{
	if(x==s&&flag==1)
	{
		flag^=1;
		for(int i=1;i<=n+1;i++)if(!vis[i])return i;
	}
	if(x==s)flag=1;;
	int mx=0,id=-1;
	for(int i=1;i<=n+1;i++)
	{
		if(vis[i])continue;
		vis[i]=1;
		int tt=dfs((x==n?1:x+1));
		if(mx<A[x][tt])mx=A[x][tt],id=tt;
		vis[i]=0;
	}
	return id;
}
int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	int seed;
	cin>>n>>seed;
	if(seed==0)for(int i=1;i<=n;i++)for(int j=1;j<=n+1;j++)cin>>A[i][j];
	else gen(n,seed);
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof vis);flag=0;
		cout<<dfs(s=i)<<' ';
	}
	return 0;
}
/*

*/
