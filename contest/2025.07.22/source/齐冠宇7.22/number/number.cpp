#include <bits/stdc++.h>
#define it multiset<int>::iterator
#define int long long
using namespace std;
constexpr int N=2005,inf=1e18;
int n,m;
int x[25];
namespace bf
{
	int a[25];
	int ans=-inf;
	void dfs(int u)
	{
		if(u==m+1)
		{
			int sum=0;
			for(int i=1;i<=n;i++)
				sum+=a[i];
			ans=max(ans,sum);
			return;
		}
		for(int i=1;i<=n;i++)
		{
			a[i]=x[u]-a[i];
			dfs(u+1);
			a[i]=x[u]-a[i];
		}
	}
	void solve()
	{
		ans=-inf;
		dfs(1);
		cout<<ans<<'\n';
	}
}
namespace sub
{
	int sum,a[N];
	multiset<int,greater<> >st;
	void solve()
	{
		sum=0;
		for(int i=m-1;~i;i--)
			a[i]=x[m-i],sum+=a[i];
		sum=-sum;
		st.clear();
    	for(int i=0,p=0;i<m;i++)
		{
	     	int l=i+2>>1,r=i+n+1>>1;
	      	st.insert(a[i]<<1);
	     	while(p<l)
			 	sum+=*st.begin(),st.erase(st.begin()),p++;
	      	while(p+st.size()>r)
			  	st.erase(prev(st.end()));
    	}
    	for(it i=st.begin();i!=st.end();i++)
    		if(*i>0)
    			sum+=*i;
	    cout<<sum<<'\n';
	}
}
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		for(int i=1;i<=m;i++)
			cin>>x[i];
		if(n<=2 && m<=20)
			bf::solve();
		else
			sub::solve();
	}
	return 0;
}
