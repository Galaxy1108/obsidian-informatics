#include<bits/stdc++.h> 
using namespace std;
const int N=8010,T=2.5e5+10;
int WT[22]={0,100,100,97,96,95,90,85,80,82,78,75,70,65,55,50,15,12,10,8,5,2};
int dp[N],n,w[N],u[N],t[N],jjs[N],cnt,finans;
bool kill[N];
void solve(int st,int en)
{
	memset(dp,0,sizeof dp);
	for(int i=st+1;i<=en;i++)  t[i]-=t[st],u[i]-=u[st];
	dp[1]=w[st+1];
	for(int i=st+2;i<=en;i++)
	{
		for(int j=i-1;j>=st+1;j--)
		{
			if((t[i]-t[j])*2>=abs(u[i]-u[j]))
			{
				dp[i]=max(dp[i],dp[j]+w[i]);
			}
		}
		t[i]+=2;
	}
	finans+=dp[en];
	return ;
}
signed main()
{
	freopen("sniper.in","r",stdin);
	freopen("sniper.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i]>>u[i]>>t[i];
		w[i]=WT[w[i]];
		if(w[i]==50) jjs[++cnt]=i;
	}
	for(int i=1;i<=cnt;i++) solve(jjs[i-1],jjs[i]);
	memset(dp,0,sizeof dp);
	for(int i=jjs[cnt]+1;i<=n;i++)  t[i]-=t[jjs[cnt]],u[i]-=u[jjs[cnt]];
	for(int i=jjs[cnt]+2;i<=n;i++)
	{
		for(int j=i-1;j>=jjs[cnt]-1;j--)
		{
			if((t[i]-t[j])*2>=abs(u[i]-u[j]))
			{
				dp[i]=max(dp[i],dp[j]+w[i]);
			}
		}
		t[i]+=2;
	}
	int ans=0;
	for(int i=jjs[cnt]+1;i<=n;i++) ans=max(ans,dp[i]);
	cout<<finans+ans;
	return 0;
}
