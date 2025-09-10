#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
const int N=1000005;
map<ll,ll>mp;
ll C[15][15],n,f[N],k,s[N],a[15],L,pw[15],b[15],m;
ll get(ll p)
{
	ll cnt=0;
	for(int i=1;i<=m;i++)
	{
		int l=0,r=m,mid;
		while(l<r)
		{
			mid=(l+r+1)>>1;
			if(f[i]*f[mid]>=p)l=mid;
			else r=mid-1;
		}
		cnt+=l;
	}
	return cnt;
}
void dfs(int k,int s,ll v)
{
	if(k>9)
	{
		if(!s)return;
		if(s==L)
		{
			//cout<<s<<' '<<v<<' ';
			//int sum=0;
			for(int i=1;i<=9;i++)b[i]=a[i];
			for(int i=L-1;i>=0;i--)
			{
				int t=n/pw[i]%10;
				for(int j=1;j<t;j++)
				{
					if(!b[j])continue;
					b[j]--;
					s=0;
					for(int i=1;i<=9;i++)s+=b[i];
					ll cnt=1;
					for(int i=1;i<=9;i++)
					{
						cnt*=C[s][b[i]];
						s-=b[i];
					}
					//sum+=cnt;
					mp[v]+=cnt;
					b[j]++;
				}
				if(!b[t])
				{
					//cout<<i<<": "<<sum<<'\n';
					return;
				}
				b[t]--;
			}
			mp[v]++;
			//sum++;
			//cout<<sum<<'\n';
			return;
		}
		ll cnt=1;
		for(int i=1;i<=9;i++)
		{
			cnt*=C[s][a[i]];
			s-=a[i];
		}
		mp[v]+=cnt;
		return;
	}
	for(int i=0;i<=L;i++)
	{
		if(s+i>L)break;
		a[k]=i;
		dfs(k+1,s+i,v);
		v*=k;
	}
}
int main()
{
	freopen("find.in","r",stdin);
	freopen("find.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	C[0][0]=1;
	for(int i=1;i<=14;i++)
		for(int j=0;j<=i;j++)
		{
			C[i][j]=C[i-1][j];
			if(j)C[i][j]+=C[i-1][j-1];
		}
	pw[0]=1;
	for(int i=1;i<=14;i++)pw[i]=pw[i-1]*10;
	cin>>n>>k;
	ll t=1;
	while(t<n)
	{
		t*=10;
		L++;
	}
	dfs(1,0,1);
	for(map<ll,ll>::iterator it=mp.begin();it!=mp.end();it++)
		f[++m]=it->second;
	sort(f+1,f+m+1);reverse(f+1,f+m+1);
	//for(int i=1;i<=m;i++)cout<<f[i]<<' ';
	//cout<<'\n';
	if(k>m*m)k=m*m;
	ll l=0,r=1e18,mid,c;
	while(l<r)
	{
		mid=(l+r+1)>>1;
		if(get(mid)>=k)l=mid;
		else r=mid-1;
	}
	//return 0;
	c=l;
	for(int i=1;i<=m;i++)s[i]=(s[i-1]+f[i])%MOD;
	ll ans=0;
	for(int i=1;i<=m;i++)
	{
		int l=0,r=m,mid;
		while(l<r)
		{
			mid=(l+r+1)>>1;
			if(f[mid]*f[i]>c)l=mid;
			else r=mid-1;
		}
		ans+=s[l]*f[i]%MOD;
		k-=l;
	}
	cout<<(ans+k*c)%MOD<<'\n';
	return 0;
}
