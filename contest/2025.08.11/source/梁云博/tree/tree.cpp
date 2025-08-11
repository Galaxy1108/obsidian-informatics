#include <bits/stdc++.h>
#define int long long
#define N 500005
using namespace std;
int n;
vector<int>g[N];
int w[N];
int dp[N];
int si[N];
//double res=-114514;
struct X 
{
	int d,s,v;
	X(){}
	X(int d,int s,int v):d(d),s(s),v(v){}
	bool operator <(const X x)const
	{
		if(d*x.s==x.d*s)return s<x.s;
		else return d*x.s<x.d*s;
	}
};
void Mobius(int p,int fa)
{
//	res=max(res,1.0*sum/(1.0*cnt));
	priority_queue<X>q;
	for(int v:g[p])
	{
		if(v==fa)continue;
		Mobius(v,p);
		q.push(X(dp[v],si[v],v));
	}
	si[p]=1;
	dp[p]=w[p];
//	int tmp=w[p];//average
	int len=q.size();
	for(int i=1;i<=len;i++)
	{
		int v=q.top().v,d=q.top().d,s=q.top().s;
		q.pop();
		if(v==fa)continue;
		if(dp[p]*s<d*si[p])
		{
			dp[p]+=d;
			si[p]+=s;
		}
		else break;
	}
	return ;
}
signed main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=2,f;i<=n;i++)
	{
		cin>>f;
		g[i].push_back(f);
		g[f].push_back(i);
	}
	for(int i=1;i<=n;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		memset(dp,0,sizeof(dp));
//		res=-114514;
		Mobius(i,0);
		printf("%.10f\n",1.0*dp[i]/(1.0*si[i]));
	}
	return 0;
}
