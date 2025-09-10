#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1100][1100];
int n,k;
int mod=1000000007;
int ans=0;
int find(int x)
{
	if(x>=0&&x<=9)
	{
		return x;
	}
	int sum=1;
	sum*=x%10;
	sum*=find(x/10);
	return sum;
}
bool cmp(int x,int y)
{
	return x>y;
}
signed main()
{
	freopen("find.in","r",stdin);
	freopen("find.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			a[i][j]=1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			a[i][j]--;
			int x=find(i),y=find(j);
			if(x>=1&&x<=n&&y>=1&&y<=n)
			{
				a[x][y]++;
			}
		}
	}
	int b[1000100];
	int len=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			b[++len]=a[i][j];
		}
	}
	sort(b+1,b+len+1,cmp);
	for(int i=1;i<=k;i++)
	{
		ans+=b[i];
		ans%=mod;
	}
	cout<<ans;
}
