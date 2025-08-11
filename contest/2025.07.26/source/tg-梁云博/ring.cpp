#include <bits/stdc++.h> 
#define N 2005
#define int unsigned long long
using namespace std;
int n;
//int suc[N];  
struct L
{
	int d[N],len;
}a[N];
int gd[N];
int minn=9e18;
void dfs(int p)//µÚp¸öÐòÁÐ 
{
	if(p==n+1)
	{
		int res=0;
		for(int i=1;i<n;i++)
		{
			vector<int>v;
			v.push_back(0);
			for(int j=gd[i];j<=a[i].len;j++)
			{
				v.push_back(a[i].d[j]);
			}
			for(int j=1;j<gd[i+1];j++)
			{
				v.push_back(a[i+1].d[j]);
			}
			v.push_back(2000000); 
			sort(v.begin(),v.end());
			for(int j=0;j<v.size()-1;j++)
			{
				res+=(v[j+1]-v[j])*(v[j+1]-v[j]);
			}
		}
		vector<int>v;v.push_back(2000000); v.push_back(0);
		for(int j=gd[n];j<=a[n].len;j++)
		{
			v.push_back(a[n].d[j]);
		}
		for(int j=1;j<gd[1];j++)
		{
			v.push_back(a[1].d[j]);
		}
		sort(v.begin(),v.end());
		for(int j=0;j<v.size()-1;j++)
		{
			res+=(v[j+1]-v[j])*(v[j+1]-v[j]);
		}
		if(res!=0)minn=min(minn,res);
		return ;
	}
	for(int i=1;i<=a[p].len;i++)
	{
		gd[p]=i;
		dfs(p+1);
		gd[p]=0;
	}
}
signed main()
{
	freopen("ring.in","r",stdin);
	freopen("ring.out","w",stdout);
	cin>>n;
	for(int i=1,m;i<=n;i++)
	{
		cin>>m;
		a[i].len=m;
		for(int j=1;j<=m;j++)
		{
			cin>>a[i].d[j];
		}
	}
	dfs(1);
	cout<<minn;
	return 0;
}
