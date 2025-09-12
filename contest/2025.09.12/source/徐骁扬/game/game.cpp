#include <bits/stdc++.h>
using namespace std;
int Qread()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return x;
}
long long val[200010];
int n,m,u,v,w,o;long long ans;
priority_queue<long long>Q;
void solve()
{
	memset(val,0,(n+2)<<3);
	n=Qread(),m=Qread();
	for(int i=1;i<=m;i++)
	{
		u=Qread(),v=Qread(),w=Qread();
		val[u]+=w,val[v]+=w;
	}
	for(int i=1;i<=n;i++) Q.push(val[i]);
	for(o=1,ans=0;!Q.empty();Q.pop(),o=-o) ans+=o*Q.top();
	printf("%lld\n",ans/2);
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int T=Qread();
	while(T--) solve();
	return 0;
}
