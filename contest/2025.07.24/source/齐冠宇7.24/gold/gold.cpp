#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=1e3+5,mod=1e9+7;
int n,k;
int val[N][N];
int trans(int i)
{
	int res=1;
	while(i)
		res=res*(i%10),i/=10;
	return res;
}
multiset<int,greater<> >st;
int ans;
signed main()
{
	freopen("gold.in","r",stdin);
	freopen("gold.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			val[trans(i)][trans(j)]++;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			st.insert(val[i][j]);
	while(k-- && !st.empty())
		ans+=*st.begin(),st.erase(st.begin()); 
	cout<<ans;
	return 0;
}
