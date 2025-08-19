#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=1e5+5,mod=1e9+7;
int pr[19]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67};
int n;
int d[25];
int cnt;
int get(int x)
{
	int res=0;
	for(int i=0;i<=18;i++)
	{
		int cnt=0;
		while(x%pr[i]==0)
			x/=pr[i],cnt^=1;
		res|=(cnt<<i);
	}
	return res;
}
void insert(int x)
{
	for(int i=18;i>=0;i--)
	{
		if(x&(1<<i))
		{
			if(!d[i])
			{
				d[i]=x;
				cnt++;
				return;
			}
			x^=d[i];
		}
	}
}
int qpow(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1)
			res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
signed main()
{
	freopen("square.in","r",stdin);
	freopen("square.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1,a;i<=n;i++)
		cin>>a,insert(get(a));
	cout<<(qpow(2,n-cnt)-1+mod)%mod;
	return 0;
}
