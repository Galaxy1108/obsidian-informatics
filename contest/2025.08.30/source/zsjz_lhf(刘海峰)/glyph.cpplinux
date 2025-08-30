#define ll long long
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
const int N=310;
struct node{
	int x1,y1,x2,y2,id;
};
ll f[N][N],g[N][N],s[N],ans[200010];
void init(int l,int r,int mid)
{
	for(int i=l;i<=mid+1;i++)
		memset(g,0x3f,sizeof(g));
	for(int i=mid-1;i<=r;i++)
		memset(f,0x3f,sizeof(f));
}
int a[N][N],n;
void solve(int l,int r,vector<node> q)
{
	if(l>r) return;
	if(l==r)
	{
		for(int i=1;i<=n;i++) s[i]=s[i-1]+a[l][i];
		for(node x:q) ans[x.id]=s[x.y2]-s[x.y1-1];
	}
	int mid=(l+r)>>1;
	for(int i=1;i<=n;i++)
	{
		init(l,r,mid);
		for(int k=mid;k<=r;k++)
			for(int j=i;j<=n;j++)
				if(k==mid&&j==i) f[k][j]=a[k][j];
				else f[k][j]=min(f[k-1][j],f[k][j-1])+a[k][j];
		for(int k=mid;k>=l;k--)
			for(int j=i;j;j--)
				if(k==mid&&j==i) g[k][j]=0;
				else g[k][j]=min(g[k+1][j],g[k][j+1])+a[k][j];
		for(node x:q)
			if(x.x1<=mid&&x.x2>=mid)
				ans[x.id]=min(ans[x.id],g[x.x1][x.y1]+f[x.x2][x.y2]);
	}
	vector<node> v1,v2;
	for(node x:q)
		if(x.x2<mid) v1.push_back(x);
		else if(x.x1>mid) v2.push_back(x);
	solve(l,mid-1,v1),solve(mid+1,r,v2);
}
int main()
{
	freopen("glyph.in","r",stdin);
	freopen("glyph.out","w",stdout);
	int q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	vector<node> v(q);
	for(int i=0;i<q;i++)
		scanf("%d%d%d%d",&v[i].x1,&v[i].x2,&v[i].y1,&v[i].y2),ans[v[i].id=i]=1e18;
	solve(1,n,v);
	for(int i=0;i<q;i++) printf("%lld\n",ans[i]);
}