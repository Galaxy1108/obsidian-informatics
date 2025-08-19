#include <bits/stdc++.h>
using namespace std;
int Qread()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x;
}
const int v[]={0,100,100,97,96,95,90,85,80,82,78,75,70,65,55,50,15,12,10,8,5,2};
int n,i,j,k,w,u,t,ans;
int dp[25010][30],f[25010][30];
int jjs[25010];
void get_max(int &a,int b)
{
	if(a<b) a=b;
	return;
}
int main()
{
	freopen("sniper.in","r",stdin);
	freopen("sniper.out","w",stdout);
	n=Qread();
	for(i=1;i<=n;i++)
	{
		w=Qread();
		u=Qread();
		t=Qread();
		if(w==15) jjs[t]=u;
		get_max(f[t][u],v[w]);
	}
	memset(dp,-127,sizeof(dp));
	for(i=1;i<=20;i++)
		dp[t+1][i]=dp[t+2][i]=0;
	for(i=t;i>=0;i--)
	{
		if(jjs[i])
		{
			for(k=max(1,jjs[i]-2);k<=min(20,jjs[i]+2);k++)
				get_max(dp[i][jjs[i]],f[i][jjs[i]]+dp[i+2][k]);
			continue;
		}
		for(j=1;j<=20;j++)
		{
			if(!jjs[i+1])
				for(k=max(1,j-2);k<=min(20,j+2);k++)
					get_max(dp[i][j],f[i][j]+dp[i+2][k]);
			for(k=max(1,j-2);k<=min(20,j+2);k++)
				get_max(dp[i][j],dp[i+1][k]);
		}
	}
	for(i=1;i<=20;i++)
		get_max(ans,dp[0][i]);
	cout<<ans;
	return 0;
}
