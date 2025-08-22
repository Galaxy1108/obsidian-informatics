#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e7+10;
int n,m,p,L[N],R[N],ans=0;
void dfs(int step,int ll,int lr)
{
	if(step>n) 
	{
		ans++;
		//for(int i=1;i<=n;i++) cout<<L[i]<<' '<<R[i]<<endl;
		//cout<<endl;
		return ;
	}
	for(int l=1;l<=lr;l++)
	{
		for(int r=max(l,ll);r<=m;r++)
		{
			dfs(step+1,l,r);
		}
	}
}
signed main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	cin>>n>>m;
	p=1e9+7;
	if(m==1)
	{
		cout<<1<<endl;
		return 0;
	}
	if(n==1)
	{
		cout<<(m*(m+1)/2)%p;
		return 0;
	}
	if(n<=10&&m<=54)
	{
		dfs(1,1,m);
		cout<<ans;
		return 0;
	}
	return 0;
} 
