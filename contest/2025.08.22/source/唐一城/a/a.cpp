#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
const int N=1e6+5;
int n,m,mod;
//map<pii,int>mp[N],pre;
vector<vector<vector<ll>>>mp;
vector<vector<ll>>pre;
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	cin>>n>>m>>mod;
	if(n==1)
	{
		cout<<1ll*m*(m+1)/2;
		return 0;
	}
//	for(int i=1;i<=m;i++)for(int j=1;j<=m;j++)mp[1][make_pair(i,j)]=(i<=j?1:0);
//	for(int i=2;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//			for(int k=1;k<=m;k++)
//				pre[make_pair(j,k)]=((j==1?0:pre[make_pair(j-1,k)])+(k==1?0:pre[make_pair(j,k-1)])-(j==1||k==1?0:pre[make_pair(j-1,k-1)])+mp[i-1][make_pair(j,k)])%mod;
//		for(int j=1;j<=m;j++)
//		{
//			for(int k=j;k<=m;k++)
//			mp[i][make_pair(j,k)]=(pre[make_pair(k,m)]+pre[make_pair(m,k)]-pre[make_pair(j-1,j-1)]-pre[make_pair(k,k)]+mod)%mod;
//		}
//	}
	vector<ll>tt;
	vector<vector<ll>>t;
	tt.push_back(0);
	pre.push_back(tt); 
	t.push_back(tt);
	for(int i=1;i<=m;i++)
	{
		pre.push_back(tt);
		for(int j=1;j<=m;j++)pre[i].push_back(0);
	}
	mp.push_back(pre); 
	for(int i=1;i<=n;i++)mp.push_back(pre);
	for(int i=1;i<=m;i++)for(int j=i;j<=m;j++)mp[1][i][j]=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=m;j++)for(int k=1;k<=m;k++)pre[j][k]=((j==1?0:pre[j-1][k])+(k==1?0:pre[j][k-1])-(j==1|k==1?0:pre[j-1][k-1])+mp[i-1][j][k])%mod;
		for(int j=1;j<=m;j++)for(int k=j;k<=m;k++)mp[i][j][k]=(pre[k][m]+pre[m][k]-pre[j-1][j-1]-pre[k][k]+mod)%mod;
	}
	ll ans=0;
	for(int i=1;i<=m;i++)for(int j=i;j<=m;j++)ans=(ans+mp[n][i][j])%mod;
//	for(int i=1;i<=m;i++)for(int j=i;j<=m;j++)ans=(ans+mp[n][make_pair(i,j)])%mod;
	cout<<ans;
	return 0;
}
/*
         1          3          6         10         15         21         28         36         45         55
         1          7         26         70        155        301        532        876       1365       2035
         1         17        120        528       1737       4697      11032      23304      45321      82489
         1         41        550       3954      19321      72737     226996     615084    1492833    3317017
         1         99       2526      29676     215401    1128983    4681486   16272058   49286579  133692229
         1        239      11600     222696    2401005   17520235   96530716  430391812 1626887903 1092376905
         1        577      53274    1671282   26765023  271907525 1990562878 -1500401214
*/
