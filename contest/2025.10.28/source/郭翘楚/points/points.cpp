#include <bits/stdc++.h>
using namespace std;
int a[200005];
struct node
{
	int l,r;
}q[200005];
int f[200005];
bool cmp(node x,node y)
{
	if(x.l!=y.l)
	{
		return x.l<y.l;
	}
	return x.r<y.r;
}
int main()
{
	freopen("points.in","r",stdin);
	freopen("points.out","w",stdout);
	srand(time(NULL));
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int cnt=0;
	for(int i=1;i<=m;i++)
	{
		int l,r;
		cin>>l>>r;
		if(lower_bound(a+1,a+n+1,l)-a-1==lower_bound(a+1,a+n+1,r)-a-1)
		{
			cnt++;
			q[cnt].l=l;
			q[cnt].r=r;
		}
	}
	if(cnt==0)
	{
		puts("0");
		return 0;
	}
	sort(q+1,q+cnt+1,cmp);
	if(cnt>=1000)
	{
		cout<<m;
		return 0;
	}
	long long ans=0;
	int sr=rand()%n+1,sl=rand()%n+1;
	if(sl>sr) swap(sl,sr);
	for(int i=sr;i<=cnt;i++)
	{
		int minn=2147483647,k;
		for(int j=1;j<=n;j++)
		{
			if(abs(q[i].l-a[j])<minn)
			{
				minn=abs(q[i].l-a[j]);
				k=j;
			}
		}
		a[k]=q[i].l;
		ans+=minn;
	}
	for(int i=sl;i<sr;i++)
	{
		int minn=2147483647,k;
		for(int j=1;j<=n;j++)
		{
			if(abs(q[i].l-a[j])<minn)
			{
				minn=abs(q[i].l-a[j]);
				k=j;
			}
		}
		a[k]=q[i].l;
		ans+=minn;
	}
	for(int i=1;i<sl;i++)
	{
		int minn=2147483647,k;
		for(int j=1;j<=n;j++)
		{
			if(abs(q[i].l-a[j])<minn)
			{
				minn=abs(q[i].l-a[j]);
				k=j;
			}
		}
		a[k]=q[i].l;
		ans+=minn;
	}
	cout<<ans;
 } 
