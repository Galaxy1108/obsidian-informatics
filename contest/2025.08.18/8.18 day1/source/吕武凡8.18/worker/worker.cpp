#include<bits/stdc++.h>
using namespace std;
int n;
int a[110];
bool tick[4];
char c;
int dp[110];
int ans=1000;
int a1[110],b1[110],c1[110];
int mem[110][11][11][11];
void DFS(int na,int nb,int nc,int pos,int sum)
{
	if(mem[pos][na][nb][nc]>sum)
	{
		mem[pos][na][nb][nc]=sum;
	}
	else
	{
		return;
	}
	if(sum>ans)
	{
		return;
	}
	if(na==0&&nb==0&&nc==0&&pos==n)
	{
		ans=min(ans,sum);
		return;
	}
	int k=min((pos+10-na-nb-nc),n);
	na+=(a1[k]-a1[pos]);
	nb+=(b1[k]-b1[pos]);
	nc+=(c1[k]-c1[pos]);
	if(na!=0) DFS(0,nb,nc,k,sum+1);
	if(nb!=0) DFS(na,0,nc,k,sum+1);
	if(nc!=0) DFS(na,nb,0,k,sum+1);
}
int main()
{
	freopen("worker.in","r",stdin);
	freopen("worker.out","w",stdout);
	memset(mem,0x3f,sizeof(mem));
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>c;
		if(c=='A')
		{
			a[i]=1;
			tick[1]=1;
			a1[i]=a1[i-1]+1;
			b1[i]=b1[i-1];
			c1[i]=c1[i-1];
		}
		if(c=='B')
		{
			a[i]=2;
			tick[2]=1;
			a1[i]=a1[i-1];
			b1[i]=b1[i-1]+1;
			c1[i]=c1[i-1];
		}
		if(c=='C')
		{
			a[i]=3;
			tick[3]=1;
			a1[i]=a1[i-1];
			b1[i]=b1[i-1];
			c1[i]=c1[i-1]+1;
		}
		if(i<=10)
		{
			dp[i]=tick[1]+tick[2]+tick[3];
		}
	}
	if(n<=10)
	{
		cout<<dp[n];
	}
	else
	{
		memset(dp,0,sizeof(dp));
		DFS(0,0,0,0,0);	
		cout<<ans;
	}
}
