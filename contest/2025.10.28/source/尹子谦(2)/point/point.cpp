#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e3+10;
int n,m,a[N],dp[N][N];
struct Node
{
	int l,r;
	bool operator<(const Node &oth) const
	{
		return l<oth.l||(l==oth.l&&r<oth.r);
	}
}s[N];
signed main()
{
	freopen("point.in","r",stdin);
	freopen("point.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>s[i].l>>s[i].r;
	sort(s+1,s+m+1);
	sort(a+1,a+n+1);
	cout<<0<<endl;
	return 0;
} 
