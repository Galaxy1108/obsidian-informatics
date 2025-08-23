#include <bits/stdc++.h>
#define pb emplace_back
using namespace std;
constexpr int N=2e5+5,mod=998244353;
int cid,n,a[N],b[N];
int ans,sum,mx;
int q;
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
int calc()
{
	sum=b[1];
	ans=2;
	set<int>st;
	st.insert(b[1]);
	b[1]=0;
	for(int i=n;i>=1;i--)
	{
		if(st.lower_bound(b[i])!=st.end())
			continue;
		// cout<<*st.lower_bound(b[i])<<'\n';
		int fl=0;
		for(int j=1;j<i;j++)
			if(sum+b[j]>=b[i])
			{
				st.insert(b[j]),fl=1,sum+=b[j],b[j]=0,ans=(ans+qpow(2,j))%mod;break;
			}
		if(!fl)
		{
			int tot=0;
			for(int j=1;j<i;j++)
				tot+=b[j];
			if(tot+sum<b[i])
				return (ans+qpow(2,i))%mod;
			for(int j=1;j<i;j++)
			{
				if(sum>=b[i])break;
				sum+=b[j],b[j]=0,ans=(ans+qpow(2,j))%mod;
				st.insert(b[j]);
			}
		}
	}
	return ans;
}
int main()
{
	freopen("imperishable.in","r",stdin);
	freopen("imperishable.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>cid>>n;
	if(cid==1)
		return cout<<2,0;
	for(int i=1;i<=n;i++)
		cin>>a[i],b[i]=a[i];
	cout<<calc()<<'\n';
	cin>>q;
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		a[x]=y;
		for(int i=1;i<=n;i++)
			b[i]=a[i];
		cout<<calc()<<'\n';
	}
	return 0;
}