#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=1e6+3;
ll n,m,a[N];
struct Nod
{
    ll x,y;
    friend Nod operator +(Nod A,Nod B){return {A.x+B.x,A.y+B.y};}
    friend bool operator <(Nod A,Nod B){return A.x*B.y<A.y*B.x;}
};
Nod Max(Nod A,Nod B){return A<B?B:A;}
Nod Min(Nod A,Nod B){return A<B?A:B;}
Nod Get(Nod L,Nod R)
{
	Nod kl={0,1},kr={1,0};
	if(L<kl&&kl<R)return kl;
	while(1)
	{
		Nod t=kl+kr;
		if(L<t&&t<R)return t;
		L<t?kr=t:kl=t;
	}
	return {-1,-1};
}
void Solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	cin>>m;
	if(n==1)
	{
		while(m--)
		{
			int l,r;cin>>l>>r;
			cout<<0<<" "<<a[1]<<" "<<1<<"\n";
		}
		return;
	}
	ll za=(a[2]-a[1]),zb=a[1],mk=1;
	for(int i=1;i<=n;i++)if(za*(i-1)+zb!=a[i])mk=0;
	while(m--)
	{
		int l,r;cin>>l>>r;Nod mn={1,0},mx={-1,1};
		if(mk)
		{
			cout<<za<<" "<<a[l]<<" "<<1<<"\n";
			continue; 
		}
		for(int i=l;i<=r;i++)for(int j=i;j<=r;j++)
			mn=min(mn,{a[j]-a[i]+1,j-i}),mx=max(mx,{a[j]-a[i]-1,j-i});
		Nod t=Get(mx,mn);ll s=0;
		for(int i=l;i<=r;i++)s=max(s,t.y*a[i]-(i-l)*t.x);
		cout<<t.x<<" "<<s<<" "<<t.y<<"\n";
	}
}
int main()
{
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T;cin>>T;
	while(T--)Solve();
	return 0;
}
