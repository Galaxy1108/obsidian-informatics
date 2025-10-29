#include <bits/stdc++.h>
using namespace std;
constexpr int N=15;
int n,mod;
bool vis[N];
int p[N];
int ans;
struct BIT{
	int t[N*N];
#define lowbit(x) (x&-x)
	void add(int x,int v){x+=2;while(x<=n*n)(t[x]+=v)%=mod,x+=lowbit(x);}
	int ask(int x){x+=2;int res=0;while(x)(res+=t[x])%=mod,x-=lowbit(x);return res;}
#undef lowbit
}T;
void dfs(int x)
{
	if(x==n+1)
	{
		int sum=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(p[j]>p[i])
					sum++;
		(ans+=T.ask(sum-1))%=mod;
		T.add(sum,1);
		return;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			vis[i]=1;
			p[x]=i;
			dfs(x+1);
			vis[i]=0;
		}
}
int main()
{
	freopen("pairs.in","r",stdin);
	freopen("pairs.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>mod;
	dfs(1);
	cout<<ans;
	return 0;
}