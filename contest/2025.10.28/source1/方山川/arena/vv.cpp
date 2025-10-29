#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N=510,mod=998244353;
int n,m,a[N],ans,b[N],ans1,ans2,ans3;
inline bool check()
{
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		b[i]=a[i];
		if(b[i])cnt++;
	}
	while(cnt>0)
	{
		for(int i=1;i<=n;i++)
		b[i]=max(b[i]-(cnt-1),0);
		cnt=0;
		for(int i=1;i<=n;i++)
		if(b[i])cnt++;
		if(cnt==1)return 0;
	}
	return 1;
}
void dfs(int pos)
{
	if(pos==n+1)
	{
		if(check())
		{
			int maxx=0,c1=0,c2=0;
			for(int i=1;i<=n;i++)maxx=max(maxx,a[i]);
			for(int i=1;i<=n;i++)
			if(a[i]==maxx)c1++;
			else if(a[i]==maxx-1)c2++;
			if(c1>1)ans1++;
			else if(c2<=1)
			{
				for(int j=1;j<=n;j++)cout<<a[j]<<' ';
				cout<<'\n';
				ans3++;
			}
			else if(c1==1&&c2>1)ans2++;
			ans++;
		}
		return;
	}
	for(int i=1;i<=m;i++)
	{
		a[pos]=i;
		dfs(pos+1);
	}
}
signed main()
{
//	freopen("arena2.in","r",stdin);
//	freopen("arena.out","w",stdout);
	cin>>n>>m;
	dfs(1);
	cout<<ans<<'\n';
//	cout<<ans1<<'\n';
//	cout<<ans2<<'\n';
//	cout<<ans3<<'\n';
//	cout<<(ans1+ans2+ans3)<<'\n';
	return 0;
} 
