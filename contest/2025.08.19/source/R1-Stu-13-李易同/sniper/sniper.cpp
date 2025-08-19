#include <iostream>
using namespace std;
int n;
int map[25010][25],w,u,t;
int ap,ip=25;
int jv[25010];
int dp[25010][25][3];
bool vis[25010][25][3];
int value[22]={0,100,100,97,96,95,90,85,80,82,78,75,70,65,55,50,15,12,10,8,5,2};
int ans;
int read()
{
	int s=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		s=(s<<3)+(s<<1)+(ch^48);
		ch=getchar();
	}
	return s*f;
}
int dfs(int time,int pos,int state)
{
	if(vis[time][pos][state]) return dp[time][pos][state];
	vis[time][pos][state]=1;
	dp[time][pos][state]=0;
	if(time>t) return 0;
	if(jv[time])
	{
		if(jv[time]==pos && state!=1) dp[time][pos][state]=dfs(time+1,pos,1)+map[time][pos];
		else dp[time][pos][state]=-800000;
		return dp[time][pos][state];
	}
	if(state==1)
	{
		dp[time][pos][state]=dfs(time+1,pos,0);
		return dp[time][pos][state];
	}
	if(map[time][pos]) dp[time][pos][state]=dfs(time+1,pos,1)+map[time][pos];
	dp[time][pos][state]=max(dp[time][pos][state],dfs(time+1,pos,0));
	if(state==0)
	{
		if(pos-1>=ip) dp[time][pos][state]=max(dp[time][pos][state],dfs(time,pos-1,2));
		if(pos-2>=ip) dp[time][pos][state]=max(dp[time][pos][state],dfs(time,pos-2,2));
		if(pos+1<=ap) dp[time][pos][state]=max(dp[time][pos][state],dfs(time,pos+1,2));
		if(pos+2<=ap) dp[time][pos][state]=max(dp[time][pos][state],dfs(time,pos+2,2));
	}
	return dp[time][pos][state];
}
int main()
{
	freopen("sniper.in","r",stdin);
	freopen("sniper.out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i)
	{
		w=read();
		u=read();
		t=read();
		ap=max(ap,u);
		ip=min(ip,u);
		map[t][u]=value[w];
		if(w==15) jv[t]=u;
	}
	for(int i=ip;i<=ap;++i) ans=max(ans,dfs(0,i,2));
	cout<<ans;
	return 0;
}
