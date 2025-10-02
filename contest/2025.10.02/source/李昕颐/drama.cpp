#include<iostream>
#include<algorithm>
#include<cmath>
#include<stdio.h>
using namespace std;
int a[2000001];
int ma[200001][22];
int mi[2000001][22];
int main()
{
	freopen("drama.in","r",stdin);
	freopen("drama.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ma[i][0]=mi[i][0]=a[i];
	}
	for(int j=1;(1<<j)<=n;j++)
	{
		for(int i=1;i+(1<<j)-1<=n;i++)
		{
			ma[i][j]=max(ma[i][j-1],ma[i+(1<<(j-1))][j-1]);
			mi[i][j]=min(mi[i][j-1],mi[i+(1<<(j-1))][j-1]);
		}
	}
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		ans=max(1LL*a[i]*a[i],ans);
		for(int j=i+1;j<=n;j++)
		{
			int k=log2(j-i+1);
			ans=max(ans,1LL*max(ma[i][k],ma[j-(1<<k)+1][k])*min(mi[i][k],mi[j-(1<<k)+1][k])*(j-i+1));
		}
	}
	cout<<ans;
	return 0;
 } 
