#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=105,INF=0x3f3f3f3f3f3f;
int n,m,k,sum1[N],sum2[N];
int memal[N][N][12];
bool visal[N][N][12];
#define mem memal[x1][x2][lk]
#define vis visal[x1][x2][lk]
int dfs(int x1,int x2,int lk)
{
	if(vis)return mem;
	vis=true;
	if(x1==n&&x2==n)
	{
		if(lk==k)return mem=0;
		else return mem=(-INF);
	}
	int res=-INF;
	if(x1<=n)res=max(res,dfs(x1+1,x2,lk));
	if(x2<=n)res=max(res,dfs(x1,x2+1,lk));
	if(lk<k)for(int i=x1+1;i<=n;i++)res=max(res,dfs(i,x2,lk+1)+sum1[i]-sum1[x1]);
	if(lk<k)for(int i=x2+1;i<=n;i++)res=max(res,dfs(x1,i,lk+1)+sum2[i]-sum2[x2]);
	if(lk<k)if(x1==x2)for(int i=x1+1;i<=n;i++)res=max(res,dfs(i,i,lk+1)+sum1[i]-sum1[x1]+sum2[i]-sum2[x2]);
	return mem=res;
}
int memsp[N][12];
bool vissp[N][12];
#define msp memsp[x][lk]
#define vsp vissp[x][lk]
int dfsp(int x,int lk)
{
	if(vsp)return msp;
	vsp=true;
	if(x==n)
	{
		if(lk==k)return msp=0;
		else return msp=(-INF);
	}
	int res=-INF;
	res=max(res,dfsp(x+1,lk));
	if(lk<k)for(int i=x+1;i<=n;i++)res=max(res,dfsp(i,lk+1)+sum1[i]-sum1[x]);
	return msp=res;
}
signed main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	cin>>n>>m>>k;
	if(m==1)
	{
		for(int i=1;i<=n;i++)
		{
			int a;
			cin>>a;
			sum1[i]=sum1[i-1]+a;
		}
		cout<<dfsp(0,0);
	}
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			int a1,a2;
			cin>>a1>>a2;
			sum1[i]=sum1[i-1]+a1;
			sum2[i]=sum2[i-1]+a2;
		}
		cout<<dfs(0,0,0);
	}
	
	return 0;
} 
