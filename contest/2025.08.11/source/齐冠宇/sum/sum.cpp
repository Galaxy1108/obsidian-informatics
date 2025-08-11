#include <bits/stdc++.h>
#define pb emplace_back
using namespace std;
typedef long long ll;
constexpr int N=1e6+5;
bitset<N>vis;
bool chk(int x,int s)
{
	for(int i=x;i<s;i+=x)
		if(vis[s-i])
			return 0;
	return 1;
}
int main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		ll s,k;
		cin>>s>>k;
		if(s&1)
		{
			ll ans=k<<1;
			if(ans>s)
				cout<<"-1\n";
			else
				cout<<ans<<'\n'; 
		}
		else
		{
			vector<int>ans;
			vis.reset();
			for(int i=3;i<s;i++)
				if(s%i && chk(i,s))
				{
					ans.pb(i);
					for(int j=i;j<s;j+=i)
						vis[j]=1;
				}
//			for(auto v:ans)
//			{
//				cout<<v<<' ';
//			}
//			cout<<'\n';
			if(k>ans.size())
				cout<<"-1\n";
			else
				cout<<ans[k-1]<<'\n';
		}
	}
	return 0;
}
