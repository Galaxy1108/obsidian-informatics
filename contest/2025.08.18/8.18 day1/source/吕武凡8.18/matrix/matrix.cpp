#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[110][5];
bool tick[110][3][110][3];
int fu[110],len=0,zh=0;
int dp[110][110];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	}
	if(m==1)
	{
		int b[120];
		int c[120];
		int len1=0;
		int len=0;
		int i=1;
		int zh=0;
		for(int i=1;i<=n;)
		{
			int sum=0;
			if(a[i][1]>=0)
			{
				int p=i;
				while(a[p][1]>=0&&p<=n)
				{
					p++;
				}
				zh+=p-i;
				for(int j=i;j<p;j++)
				{
					sum+=a[j][1];
				}
				b[++len]=sum;
				sum=0;
				i=p;
				continue;
			}
			else
			{
				c[len1++]=a[i][1];
			}
			i++;
		}
		sort(b+1,b+len+1,cmp);
		int ans=0;
		if(zh>=k)
		{
			for(int i=1;i<=min(k,len);i++)
			{
				ans+=b[i];
			}
			cout<<ans;
		}
		else
		{
			for(int i=1;i<=min(k,len);i++)
			{
				ans+=b[i];
			}
			sort(c,c+len1,cmp);
			for(int i=0;i<=k-zh-1;i++)
			{
				ans+=c[i];
			}
			cout<<ans;
		}
		return 0;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=2;j++)
			{
				
			}
		}
	}
}
/*
20 1 20
0
0
2
2
0
2
-1
2
1
-5
1
0
1
-4
1
0
-1
20
-3
10
*/
