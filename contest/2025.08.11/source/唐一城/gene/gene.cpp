#include <bits/stdc++.h>
using namespace std;
#define il inline
#define pii pair<int,int>
#define fi first
#define se second
const int N=1e6+5;
int n,l,r,a[N],t[N],nxt[N],lst[N],p[N];
il void solve1()
{
	int minn=INT_MAX;
	for(int i=1;i<=n;i++)
	{
		lst[i]=p[a[i]];
		p[a[i]]=i;
	}
	for(int i=1;i<=n;i++)p[i]=n+1;
	for(int i=n;i>=1;i--)
	{
		nxt[i]=p[a[i]];
		p[a[i]]=i;
	}
	for(int i=max(1,l-7000);i<l;i++)
	{
		for(int j=r+1,ed=min(n,r+7000);j<=ed;j++)
		{
			if(lst[i]==0&&nxt[i]>j&&
			   nxt[j]==n+1&&lst[j]<i)
			{
				minn=min(minn,j-i+1);
			}
		}
	}
	if(minn==INT_MAX)cout<<-1;
	else cout<<minn;
}
il void solve2()
{
	for(int i=1;i<=n;i++)t[a[i]]++;
	int x,y,flag1=0,flag2=0;
	int minn=INT_MAX;
	for(int i=l-1;i>=1;i--)
	{
		if(t[a[i]]==1)
		{
			flag1=1,x=i;
			break;
		}
	}
	for(int i=r+1;i<=n;i++)if(t[a[i]]==1){flag2=1,y=i;break;}
	if(flag1&&flag2)minn=y-x+1;
	for(int i=1;i<=n;i++)
	{
		lst[i]=p[a[i]];
		p[a[i]]=i;
	}
	for(int i=1;i<=n;i++)p[i]=n+1;
	for(int i=n;i>=1;i--)
	{
		nxt[i]=p[a[i]];
		p[a[i]]=i;
	}
	for(int i=max(1,l-7000);i<l;i++)
	{
		for(int j=r+1,ed=min(n,r+7000);j<=ed;j++)
		{
			if(lst[i]==0&&nxt[i]>j&&
			   nxt[j]==n+1&&lst[j]<i)
			{
				minn=min(minn,j-i+1);
			}
		}
	}
	if(minn==INT_MAX)cout<<-1;
	else cout<<minn;
}
int main()
{
	freopen("gene.in","r",stdin);
	freopen("gene.out","w",stdout);
	cin>>n>>l>>r;
	for(int i=1;i<=n;i++)cin>>a[i];
	solve2();
	return 0;
}

