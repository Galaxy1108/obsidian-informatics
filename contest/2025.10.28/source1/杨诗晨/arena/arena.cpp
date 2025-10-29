#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=998244353;
const int mm=505;
int n,x,ans,mx=0;
int a[mm],b[mm];
void clean()
{
	for(int i=1;i<=x;i++) b[i]=0;
	mx=0;
}
void find()
{
	clean();
	for(int i=1;i<=n;i++)
	{
		b[a[i]]++;
		mx=max(a[i],mx);
	}
	if(b[mx]>=2) ans=(ans+1)%mod;
}
void dfs(int i)
{
	if(i==n+1) find();
	else
	{
		for(int j=1;j<=x;j++) 
		{
			a[i]=j;
			i++;
			dfs(i);
			i--;
		}
	}
}
int main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>x;
	if(n==2) cout<<x<<endl;
	else
	{
		dfs(1);
		cout<<ans<<endl;
	}
	return 0; 
}
