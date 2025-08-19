#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=(1<<19)+5,mod=1e9+7;
int n,cntpri,pri[20];//1-70中只有19个质数 
int cnti[75],pw[N],sp[75];//1-70中每个数的分解质因数 
int dp[75][N];
bool pdpri(int x)
{
	if(x<2)return false;
	for(int i=2;i*i<=x;i++)if(x%i==0)return false;
	return true;
}
void getpri(){for(int i=1;i<=70;i++)if(pdpri(i))pri[++cntpri]=i;}
void getsp()
{
	for(int i=1;i<=70;i++)
	{
		int ni=i;
		while(ni!=1)
		{
			for(int j=1;j<=cntpri;j++)
				while(ni%pri[j]==0)
				{
					sp[i]^=(1<<(j-1));	
					ni/=pri[j];
				}	
		}
	}
}
int ftp(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1)res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
signed main()
{
	freopen("square.in","r",stdin);
	freopen("square.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	getpri();
	getsp();
	cin>>n;	
	pw[0]=1;
	for(int i=1;i<=n;i++)pw[i]=pw[i-1]*2%mod;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		cnti[x]++;
	}
	dp[1][0]=(pw[cnti[1]])%mod;
	for(int i=2;i<=70;i++)
	{
		if(cnti[i]==0)
		{
			for(int S=0;S<(1<<19);S++)dp[i][S]=dp[i-1][S];
			continue;
		}
		for(int S=0;S<(1<<19);S++)dp[i][S]=(dp[i][S]+(dp[i-1][S]*pw[cnti[i]-1])%mod)%mod;
		for(int S=0;S<(1<<19);S++)dp[i][S^sp[i]]=(dp[i][S^sp[i]]+(dp[i-1][S]*pw[cnti[i]-1])%mod)%mod;
	}
	cout<<(dp[70][0]-1+mod)%mod;
	
	return 0;
} 
