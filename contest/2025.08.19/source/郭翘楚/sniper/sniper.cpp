#include <bits/stdc++.h>
using namespace std;
int zjj[22]={0,100,100,97,96,95,90,85,80,82,78,75,70,65,55,50,15,12,10,8,5,2};
struct node
{
	int v,u,t;
}p[8005];
int dp[8005];
int sn[8005];
int main()
{
	freopen("sniper.in","r",stdin);
	freopen("sniper.out","w",stdout);
	int n;
	int N=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int w;
		cin>>w>>p[i].u>>p[i].t;
		p[i].v=zjj[w];
	}
	dp[1]=p[1].v;
	for(int i=2;i<=n;i++)
	{
		for(int j=i-1;j>=1;j--)
		{
			if((p[i].t-p[j].t)*2>=abs(p[i].u-p[j].u))
			{
				if(dp[j]+p[i].v>dp[i])
				{
					dp[i]=dp[j]+p[i].v;
				}
			}
		}
		p[i].t+=2;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,dp[i]);
	}
	cout<<ans;
	return 0;
} 
