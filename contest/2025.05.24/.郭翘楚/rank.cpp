#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
const int MOD=1e9+7;
ll n,k,t,p[N],jc[N],ne[N];
struct T
{
	ll x,id;
}a[N];
bool cmp(T a,T b)
{
	return a.x<b.x;
}
ll mypow(ll a,ll b)
{
	if(b==0)return 1;
	ll mi=mypow(a,b>>1);
	mi=mi*mi%MOD;
	if(b&1)mi=mi*a%MOD;
	return mi;
}
ll C(ll a,ll b)
{
	return jc[a]*mypow(jc[a-b],MOD-2)%MOD*mypow(jc[b],MOD-2)%MOD;
}
int main()
{
	freopen("rank.in","r",stdin);
	freopen("rank.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k>>t;
	jc[0]=1;
	for(ll i=1;i<=n+10;i++)jc[i]=jc[i-1]*i%MOD;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x;
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	//cout<<a[511].x<<'\n';
	int r=1;
	for(int i=n;i>=1;i--)
	{
		if(a[i].x!=a[i+1].x)ne[i]=i;
		else ne[i]=ne[i+1];
	}
	for(int i=1;i<=n;i++)
	{
		while(a[r].x*t<=a[i].x)r++;
		//if(a[i].id==87)cout<<r<<' '<<i<<"  ";
		//if(a[i].id==87)cout<<r-1+n-ne[i]<<' '<<C(r-1+n-ne[i],k)<<' ';
		ll ans=C(r-1+n-ne[i],k);
		int u=i,v=n+1,mid;
		while(u<v)
		{
			mid=(u+v)>>1;
			if(a[mid].x<=a[i].x*t)u=mid+1;
			else v=mid;
		}
		u--;
		//if(a[i].id==87)cout<<u<<' '<<i-1+n-u<<' '<<C(i-1+n-u,k-(u-i)-1)<<'\n';
		if(k>u-i)ans+=C(i-1+n-u,k-(u-i)-1);
		p[a[i].id]=ans%MOD;
	}
	for(int i=1;i<=n;i++)cout<<p[i]<<'\n';
	return 0;
}
