#include <bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
constexpr int N=45,V=1e6+5,mod=998244353;
int n,m;
pii q[N];
int a[N];
int k=1,ans;
bitset<V>ok;
int f[12][V];
int dfs(int x,int sm)
{
	if(~f[x][sm])
		return f[x][sm];
	if(!x)
		return ok[sm];
	int res=0;
	for(int i=q[x].fi;i<=q[x].se;i++)
		a[x]=i,(res+=dfs(x-1,sm^i))%=mod;
	return f[x][sm]=res;
}
int main()
{
	freopen("far.in","r",stdin);
	freopen("far.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	memset(f,-1,sizeof f);
	for(int i=0;i<(1<<m);i++)
	{
		ok[i]=1;
		for(int l=0,r=m-1;l<=r;l++,r--)
			if(((i>>l)&1)!=((i>>r)&1))
			{
				ok[i]=0;
				break;
			}
	}
	for(int i=1;i<=n;i++,k++)
	{
		cin>>q[i].fi>>q[i].se;
		ans=0;
		cout<<dfs(i,0)<<'\n';
	}
	return 0;
}
