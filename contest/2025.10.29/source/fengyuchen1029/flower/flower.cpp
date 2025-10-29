#include<bits/stdc++.h>
#define il inline
#define ll long long
using namespace std;
string s[85];
int ans[85];
int n,cnt=0;
il void dfs(int x)
{
	if(cnt==n) return ;
	for(int i=1;i+x+1<=(n<<1);++i){
		if(ans[i]||ans[i+x+1]) continue;
		ans[i]=ans[i+x+1]=x;
		++cnt;
		dfs(x-1);
		if(cnt==n) return ;
		ans[i]=ans[i+x+1]=0;
		--cnt;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>s[i];
	dfs(n);
	for(int i=1;i<=(n<<1);++i)
		cout<<s[ans[i]]<<'\n';
	return 0;
}
