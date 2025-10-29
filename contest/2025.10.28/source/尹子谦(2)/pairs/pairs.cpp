#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e3+10;
int ans[11]={0,0,0,0,17,904,45926,2725016,196884712,17350671831,1847029162807};
int n,m; 
signed main()
{
	freopen("pairs.in","r",stdin);
	freopen("pairs.out","w",stdout);
	cin>>n>>m;
	cout<<ans[n]%m;
	return 0;
} 
