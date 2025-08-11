#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+100;
int n,w[N],size[N],out[N];
double dp[N];
vector<int> edge[N];
bool sp1=1; 
struct kid
{
	int sz;
	int sum;
};
bool cmp(kid a,kid b)
{
	double aav=1.0*a.sum/a.sz,bav=1.0*b.sum/b.sz;
	return (aav==bav&&a.sum<b.sum)||(aav<bav);
}
void dfs(int u)
{
	if(out[u]==0)
	{
		dp[u]=w[u]*1.0;
		return ;
	} 
	if(sp1)
	{
		dfs(u*2),dfs(u*2+1);
		int sz1=1+size[2*u],sz2=1+size[2*u+1],sz3=1+size[2*u+1]+size[2*u];
		double ans1,ans2,ans3;
		ans1=(w[u]+dp[2*u])/(size[2*u]+1);
		ans2=(w[u]+dp[2*u+1])/(size[2*u+1]+1);
		ans3=(w[u]+dp[2*u]+dp[2*u+1])/(size[2*u]+1+size[2*u+1]);
		if(ans1>dp[u]) dp[u]=ans1,size[u]=sz1;
		if(ans2>dp[u]) dp[u]=ans2,size[u]=sz2;
		if(ans3>dp[u]) dp[u]=ans3,size[u]=sz3;
		return ;
	}
	kid ans[N];
	int cnt=0;
	for(int v:edge[u])
	{
		dfs(v);
		ans[++cnt].sum=dp[v]*size[v];
		ans[cnt].sz=size[v];
	}
	sort(ans+1,ans+1+cnt,cmp);
	for(int i=1;i<=cnt;i++)
	{
		double neww=1.0*(dp[u]*size[u]+ans[i].sum)/(size[u]+ans[i].sz);
		if(neww>=dp[u])
		{
			dp[u]=neww;
			size[u]+=ans[i].sz;
		}
	}
}
signed main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n;
	for(int v=2;v<=n;v++)
	{
		int u;
		cin>>u;
		if(u!=v/2) sp1=0;
		edge[u].push_back(v);
		out[u]++;
	}
	for(int i=1;i<=n;i++) cin>>w[i],dp[i]=w[i],size[i]=1;
	dfs(1);
	for(int i=1;i<=n;i++) cout<<fixed<<setprecision(10)<<dp[i]<<endl;
	return 0;
} 
