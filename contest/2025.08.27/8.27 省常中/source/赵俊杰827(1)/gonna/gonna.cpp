#include<bits/stdc++.h>
using namespace std;
const int N=20005;
typedef long long ll;
int MOD,inv[N],n,pri[N],vis[N],k,t[N],lazy[N];
vector<int>v[N],c[N];
ll ans=1;
ll exgcd(int a,int b,int &x,int &y)
{
	if(!b)
	{
		x=1;
		y=0;
		return a;
	}
	int d=exgcd(b,a%b,y,x);
	y-=(a/b)*x;
	return d;
}
ll getinv(int a)
{
	int x,y;
	int d=exgcd(a,MOD,x,y);
	if(d>1)return -1;
	return (x%MOD+MOD)%MOD;
}
ll mypow(ll a,ll b)
{
	if(b==0)return 1;
	ll mi=mypow(a,b>>1);
	mi=mi*mi%MOD;
	if(b&1)mi=mi*a%MOD;
	return mi;
}
void add(int p,int x)
{
	ans=ans*getinv((mypow(p,t[p]+1)-1)*inv[p-1]%MOD)%MOD;
	t[p]+=x;
	ans=ans*((mypow(p,t[p]+1)-1)*inv[p-1]%MOD)%MOD;
}
int main()
{
	freopen("gonna.in","r",stdin);
	freopen("gonna.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>MOD;
	for(int i=1;i<=n;i++)inv[i]=getinv(i);
	for(int i=2;i<=n;i++)
	{
		if(!vis[i])pri[++k]=i;
		for(int j=2;i*j<=n;j++)
			vis[i*j]=1;
	}
	for(int i=1;i<=n;i++)
	{
		int x=i;
		for(int j=1;pri[j]*pri[j]<=n&&j<=k;j++)
		{
			int p=pri[j];
			if(x%p)continue;
			v[i].push_back(p);
			int cnt=0;
			while(x%p==0)
			{
				x/=p;
				cnt++;
			}
			c[i].push_back(cnt);
		}
		if(x>1)
		{
			v[i].push_back(x);
			c[i].push_back(1);
		}
	}
	ll sum=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<v[i].size();j++)
		{
			add(v[i][j],i*c[i][j]);
			lazy[v[i][j]]+=c[i][j];
		}
		for(int j=1;j<=k;j++)
		{
			if(!lazy[pri[j]])break;
			add(pri[j],-lazy[pri[j]]);
		}
		sum+=ans;
		sum%=MOD;
	}
	cout<<sum<<'\n';
	return 0;
}
