#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,ary[N],num[N],sum[N];
double anslt[N];
vector<int>vec[N];
bool cmp(int a,int b){return anslt[a]>anslt[b];}
void dfs(int u)
{
	num[u]=1,sum[u]=ary[u];
	double res=1.0*sum[u]/num[u];
	for(int i=0;i<vec[u].size();i++)
	{
		int v=vec[u][i];
		dfs(v);
	}
	sort(vec[u].begin(),vec[u].end(),cmp);
	for(int i=0;i<vec[u].size();i++)
	{
		int v=vec[u][i];
		if(anslt[v]>res)
		{
			num[u]+=num[v];
			sum[u]+=sum[v];
			res=1.0*sum[u]/num[u];
		}
	}
	anslt[u]=res;
}
signed main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		int fa;
		cin>>fa;
		vec[fa].push_back(i);
	}
	for(int i=1;i<=n;i++)cin>>ary[i];
	dfs(1);
	for(int i=1;i<=n;i++)printf("%.10lf\n",anslt[i]);
	
	return 0;
}
