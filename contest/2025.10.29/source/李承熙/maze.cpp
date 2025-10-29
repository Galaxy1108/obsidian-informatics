#include<bits/stdc++.h>
using namespace std;
inline int qread()
{
	register int a=0,f=1;register char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){(a*=10)+=(ch^48);ch=getchar();}
	return a*f;
}
int n,m,x,y,mp[20][20],dp[20][20],ans[20][20],st=1,ed;
struct qu
{
	int x,y;
}que[100010],p;
int main()
{
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	n=qread();
	m=qread();
	x=qread();
	y=qread();
	for(register int i=0;i<=n+1;++i)mp[i][0]=mp[i][m+1]=1;
	for(register int i=0;i<=m+1;++i)mp[0][i]=mp[n+1][i]=1;
	for(register int i=1;i<=n;++i)
	{
		for(register int j=1;j<=m;++j)
		{
			mp[i][j]=qread();
		}
	}
	que[++ed]=(qu){1,1};
	memset(dp,127,sizeof(dp));
	dp[1][1]=0;ans[1][1]=1;
	while(st<=ed)
	{
		p=que[st];
		++st;
		if(!mp[p.x+1][p.y])
		{
			if(dp[p.x][p.y]+1<dp[p.x+1][p.y])
			{
				dp[p.x+1][p.y]=dp[p.x][p.y]+1;
				ans[p.x+1][p.y]=ans[p.x][p.y];
				que[++ed]=(qu){p.x+1,p.y};
			}
			else if(dp[p.x][p.y]+1==dp[p.x+1][p.y])ans[p.x+1][p.y]+=ans[p.x][p.y];
		}
		if(!mp[p.x-1][p.y])
		{
			if(dp[p.x][p.y]+1<dp[p.x-1][p.y])
			{
				dp[p.x-1][p.y]=dp[p.x][p.y]+1;
				ans[p.x-1][p.y]=ans[p.x][p.y];
				que[++ed]=(qu){p.x-1,p.y};
			}
			else if(dp[p.x][p.y]+1==dp[p.x-1][p.y])ans[p.x-1][p.y]+=ans[p.x][p.y];
		}
		if(!mp[p.x][p.y+1])
		{
			if(dp[p.x][p.y]+1<dp[p.x][p.y+1])
			{
				dp[p.x][p.y+1]=dp[p.x][p.y]+1;
				ans[p.x][p.y+1]=ans[p.x][p.y];
				que[++ed]=(qu){p.x,p.y+1};
			}
			else if(dp[p.x][p.y]+1==dp[p.x][p.y+1])ans[p.x][p.y+1]+=ans[p.x][p.y];
		}
		if(!mp[p.x][p.y-1])
		{
			if(dp[p.x][p.y]+1<dp[p.x][p.y-1])
			{
				dp[p.x][p.y-1]=dp[p.x][p.y]+1;
				ans[p.x][p.y-1]=ans[p.x][p.y];
				que[++ed]=(qu){p.x,p.y-1};
			}
			else if(dp[p.x][p.y]+1==dp[p.x][p.y-1])ans[p.x][p.y-1]+=ans[p.x][p.y];
		}
	}
	printf("%d",ans[x][y]);
	return 0;
}
