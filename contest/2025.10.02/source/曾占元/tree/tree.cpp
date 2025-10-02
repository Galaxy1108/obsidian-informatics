#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,id,op,q;
int p[200005],cxt[200005];
vector<int>tu[200005];
inline void decode(int &l,int &r,int &k,int lstans,int testop)
{
	lstans%=19260817;
	if(testop)
	{
		l^=lstans;
		l=(l%n+n)%n+1;
		r^=lstans;
		r=(r%n+n)%n+1;
		if(l>r)
			swap(l,r);
		k^=lstans;
		k=(k%min(r-l+1,100LL))+1;
	}
	return ;
}
signed main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>id>>op>>n;
	for(int i=1;i<n;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		tu[u].push_back(v);
		tu[v].push_back(u);
		cxt[i]=w;
	}
	for(int i=1;i<=n;i++)
		cin>>p[i];
	cin>>q;
	int ans=0;
	while(q--)
	{
		int l,r,k;
		cin>>l>>r>>k;
		decode(l,r,k,ans,op);
		ans=0;
		if(k==1)
			cout<<ans<<'\n';
		else if(k==n)
		{
			for(int i=1;i<n;i++)
				ans+=cxt[i];
			cout<<ans<<'\n';
		}
		else
			cout<<ans<<'\n';
	}
	return 0;
}
