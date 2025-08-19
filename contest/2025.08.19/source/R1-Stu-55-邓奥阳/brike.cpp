#include<cstdio>
using namespace std;
const int inf=1145141919;
int n,m,a[55][55];
bool vis[55][55];
int ans;
int max(int a,int b){return a>b?a:b;}
void dfs(int x,int y,int ls,int an)
{
	int nx=x,ny=y+1;
	if(ny>n-x+1)ny=1,nx++;
	if(nx==n+1||!ls){ans=max(an,ans);return;}
	
	if(x==1||(vis[x-1][y]&&vis[x-1][y+1]))vis[x][y]=1,dfs(nx,ny,ls-1,an+a[x][y]),vis[x][y]=0;
	dfs(nx,ny,ls,an);
}
int main()
{
	freopen("brike.in","r",stdin);
	freopen("brike.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n-i+1;++j)
			scanf("%d",&a[i][j]);
	
	dfs(1,1,m,0);
	printf("%d",ans);
	return 0;	
}
