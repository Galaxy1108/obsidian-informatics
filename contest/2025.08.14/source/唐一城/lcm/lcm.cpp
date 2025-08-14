#include <bits/stdc++.h>
using namespace std;
#define il inline
#define ll long long
#define intt __int128
const int N=1e6+5;
int n,p;
intt pre[N],suf[N],pr2[N];
il void print(intt x)
{
	if(x>9)print(x/10);
	putchar(x%10+'0');
}
il void solve1()
{
	pre[0]=1,pr2[0]=1;
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]*i;
	for(int i=1;i<=n;i++)pr2[i]=pr2[i-1]*2;
	ll aans=0;intt ans=1;
	for(int i=1;i<=n;i++)
	{
		intt now=0;
		for(int j=1;j<=i;j+=2)now=(now+pre[i]/pre[j]/pre[i-j]*pr2[j/2]);
		ans=ans/__gcd(now,ans)*now;
		aans=(aans+ans%p*i%p)%p;
	}
	cout<<(aans+p)%p<<'\n';
}
il void solve()
{
	cin>>n>>p;
	if(n<=20)solve1();
}
int main()
{
	freopen("lcm.in","r",stdin);
	freopen("lcm.out","w",stdout);
	int T;
	cin>>T;
	while(T--)solve();
	return 0;
}
/*
2
18 998244353
19 998244353
*/
