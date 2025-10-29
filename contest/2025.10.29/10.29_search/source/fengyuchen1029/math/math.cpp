#include<bits/stdc++.h>
#define il inline
#define ll long long
#define gcd __gcd
using namespace std;
ll ans[10000];
bitset<1000000> vis;
int cnt=0;
il void huajian(int &a,int &b){
	int g=gcd(a,b);
	if(g>1) a/=g,b/=g;
}
il ll lcm(ll a,ll b){
	return a*b/gcd(a,b);
}
il void jian(int &a,int &b,int c,int d)
{
	int p=lcm(b,d);
	int tmp=1ll*a*p/b,s=1ll*c*p/d;
	huajian(tmp-=s,p);
	a=tmp,b=p;
}
il bool cmp(int a,int b,int c,int d){
	return 1ll*a*d>1ll*b*c;
}
il void solve(int a,int b)
{
	huajian(a,b);
	if(a>b){
		ans[++cnt]=1;a-=b;
	}
	for(int i=2;;++i)
	{
		if(a==1) {ans[++cnt]=b;break;}
		else
		{
			if(cmp(a,b,1,i))
			{
				jian(a,b,1,i);
				ans[++cnt]=i;
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	freopen("math.in","r",stdin);
	freopen("math.out","w",stdout);
	int a,b;
	cin>>a>>b;
	solve(a,b);
	cout<<cnt<<'\n';
	for(int i=1;i<=cnt;++i) cout<<ans[i]<<' ';
	return 0;
}
