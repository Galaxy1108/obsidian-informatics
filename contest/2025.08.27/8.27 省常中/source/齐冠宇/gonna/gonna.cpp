#include <bits/stdc++.h>
#define vi vector<int>
#define pb emplace_back
using namespace std;
constexpr int N=2e3+5;
bool m1;
int n,mod;
int cnt[N][N];//阶乘的质因数个数 
int pre[N][N];//阶乘的前缀积的质因数个数 
int f[N][N];//f的质因数个数 
vi pr;
bitset<N>vis;
int ans;
bool m2;
inline int add(int x,int y)
{
	x+=y;
	return (x>mod)?x-mod:x;
}
inline int del(int x,int y)
{
	x-=y;
	return (x<0)?x+mod:x;
}
void init()
{
	for(int i=2;i<=n;i++)
	{
		if(!vis[i])
			pr.pb(i);
		for(auto v:pr)
		{
			if(v*i>n)
				break;
			vis[v*i]=1;
			if(i%v==0)
				break;
		}
	}
}
void solve(int x)
{
	int nx=x;
	for(int i=0;i<pr.size();i++)
		while(x%pr[i]==0)
			cnt[nx][i]++,x/=pr[i];
	for(int i=0;i<pr.size();i++)
		cnt[nx][i]=add(cnt[nx][i],cnt[nx-1][i]);
	for(int i=0;i<pr.size();i++)
		pre[nx][i]=add(add(pre[nx][i],cnt[nx][i]),pre[nx-1][i]);
}
int qpow(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1)
			res=1ll*res*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return res;
}
int main()
{
	freopen("gonna.in","r",stdin);
	freopen("gonna.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>mod;
	init();
	for(int i=1;i<=n;i++)
		solve(i);
	for(int i=1;i<=n;i++)
		for(int j=0;j<pr.size();j++)
			f[i][j]=del(1ll*cnt[i][j]*(i+1)%mod,2ll*pre[i][j]%mod); 
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int sum=1;
		for(int j=0;j<pr.size();j++)
		{
			int nsum=0;
			for(int k=1;k<=f[i][j];k++)
				nsum=add(nsum,1ll*sum*qpow(pr[j],k)%mod);//忘等比数列求和通项，少拿30分 
			sum=add(sum,nsum);
		}
		ans=add(ans,sum);
	}
	cout<<ans;
//	cerr<<fabs(&m1-&m2)/1024.0/1024.0<<"MB";
	return 0;
}
