#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2005,INF=0x3f3f3f3f3f3f;
int n,sum1[N],sum2[N];
int memal[N][N][6];
bool visal[N][N][6];
#define mem memal[pos][prev][num]
#define vis visal[pos][prev][num]
int dfs(int pos,int prev,int num)
{
	if(vis)return mem;
	vis=true;
	if(pos==n+1)
	{
		if(num==5)return mem=0;
		else return mem=(-INF);
	}
	int res=-INF;
	if(num==1)
	{
		res=max(res,dfs(pos,pos,num+1));
		res=max(res,dfs(pos+1,prev,num));
	}
	if(num==2)
	{
		res=max(res,dfs(pos,pos,num+1)+sum1[pos]-sum1[prev-1]+sum2[pos]-sum2[prev-1]);
		res=max(res,dfs(pos+1,prev,num));
	}
	if(num==3)
	{
		if(prev<pos-1)res=max(res,dfs(pos,pos,num+1)+sum2[pos-1]-sum2[prev]);
		res=max(res,dfs(pos+1,prev,num));
	}
	if(num==4)
	{
		res=max(res,dfs(pos,pos,num+1)+sum1[pos]-sum1[prev-1]+sum2[pos]-sum2[prev-1]);
		res=max(res,dfs(pos+1,prev,num));
	}
	if(num==5)res=max(res,dfs(pos+1,prev,num));
	return mem=res;
}
signed main()
{
	freopen("base.in","r",stdin);
	freopen("base.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>sum1[i],sum1[i]+=sum1[i-1];
	for(int i=1;i<=n;i++)cin>>sum2[i],sum2[i]+=sum2[i-1];
	cout<<dfs(1,0,1);
	
	return 0;
} 
