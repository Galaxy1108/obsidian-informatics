#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define il inline
#define db double
il int gi()
{
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0' or ch>'9')
	{
		if(ch=='-')
		{
			y=-1;
		}
		ch=getchar();
	}
	while(ch>='0' and ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*y;
}
int a[145];
int minx[145];
int b[145][145];
int k[145];
int main()
{
	freopen("save.in","r",stdin);
	freopen("save.out","w",stdout);
	memset(minx,127/3,sizeof(minx));
	int n=gi();
	for(int i=1;i<=n;i++)
	{
		a[i]=gi();
		for(int j=1;j<a[i];j++)
		{
			b[i][j]=gi();
			minx[i]=min(minx[i],b[i][j]);
		}
		k[i]=gi();
		if(a[i]==1)
		{
			minx[i]=1;
		}
	}
	int now=n,ans=0;
	while(now!=0)
	{
		k[now]-=minx[now];
		ans++;
		if(k[now]<=0)
		{
			now--;
			ans++;
			k[5]+=now;
		}
		k[5]+=now;
		if(ans>1440)
		{
			break;
		}
	}
	cout<<ans-1;
	return 0;
}
