#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
const int MOD=1000000007;
typedef long long ll;
struct T
{
	ll a[10][10];
	void set()
	{
		memset(a,0,sizeof(a));
	}
	T operator *(const T b)const
	{
		T c;c.set();
		for(int i=0;i<10;i++)
			for(int j=0;j<10;j++)
				for(int k=0;k<10;k++)
					c.a[i][k]=(c.a[i][k]+a[i][j]*b.a[j][k])%MOD;
		return c;
	}
}A;
T mypow(T a,ll b)
{
	if(b==0)return A;
	T mi=mypow(a,b>>1);
	mi=mi*mi;
	if(b&1)mi=mi*a;
	return mi;
}
int main()
{
	freopen("sam.in","r",stdin);
	freopen("sam.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	A.set();
	for(int i=0;i<10;i++)A.a[i][i]=1;
	ll n;
	cin>>n;
	T u;u.set();
	for(int i=0;i<=9;i++)
		for(int k=max(0,i-2);k<=min(9,i+2);k++)
			u.a[k][i]=1;
	u=mypow(u,n-1);
	ll ans=0;
	for(int i=1;i<=9;i++)
		for(int j=0;j<=9;j++)
			ans+=u.a[i][j];
	cout<<ans%MOD<<'\n';
	return 0;
}
