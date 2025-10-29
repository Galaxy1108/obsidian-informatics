#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2333;
struct node
{
	int l,r;
	bool operator<(const node&t)const
	{
		if(r==t.r)return l<t.l;
		return r<t.r;
	}
}r[N],rr[N];
int n,m,a[N],f[N][N],vis[N];
signed main()
{
	freopen("points.in","r",stdin);
	freopen("points.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)cin>>r[i].l>>r[i].r;
	sort(a+1,a+1+n);
	sort(r+1,r+1+m);
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<i;j++)
		if(r[j].l>=r[i].l){vis[i]=1;break;}	
		for(int j=1;j<=n;j++)
		if(r[i].l<=a[j]&&a[j]<=r[i].r){vis[i]=1;break;}
	}
	int cnt=0;
	for(int i=1;i<=m;i++)if(!vis[i])rr[++cnt]=r[i];
	for(int i=1;i<=cnt;i++)r[i]=rr[i]; m=cnt;
	
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		if(a[i]<=r[1].r)f[i][j]=r[j].l-a[i];
		else if(a[i]>=r[j].l)f[i][j]=a[i]-r[1].r;
		else f[i][j]=min(a[i]-r[1].r,r[j].l-a[i])+r[j].l-r[1].r;
		if(i-1)f[i][j]=min(f[i][j],f[i-1][j]);
		
		for(int k=1,t;k<j;k++)
		{
			if(a[i]<=r[k+1].r)t=r[j].l-a[i];
			else if(a[i]>=r[j].l)t=a[i]-r[k+1].r;
			else t=min(r[j].l-a[i],a[i]-r[k+1].r)+r[j].l-r[k+1].r;
			f[i][j]=min(f[i][j],f[i-1][k]+t);
		}
	}
	
	int ans=1e17;
	for(int i=1;i<=n;i++)
		ans=min(ans,f[i][m]);
	cout<<ans<<'\n';
	
	return 0;
}
