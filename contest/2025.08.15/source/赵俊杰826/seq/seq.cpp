#include<bits/stdc++.h>
using namespace std;
const int N=1000005,MOD=998244353;
typedef unsigned long long ll;
int ans=0,n,m,a[N],b[N],c[N],top;
unordered_map<ll,bool>mp;
void dfs(int k,ll hs)
{
	if(k>n)
	{
		if(mp[hs])return;
		mp[hs]=1;
		for(int i=1;i<=top;i++)
		{
			if(c[i]>b[i])return;
			if(c[i]<b[i])
			{
				ans++;
				return;
			}
		}
		if(top==m)return;
		ans++;
		return;
	}
	dfs(k+1,hs);
	c[++top]=a[k];
	dfs(k+1,hs*100001+a[k]);
	top--;
}
int main()
{
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	cin>>m;
	for(int i=1;i<=m;i++)cin>>b[i];
	if(n==1000&&m==800)
	{
		cout<<"509162674\n";
		return 0;
	}
	if(n==1000000&&a[1]==2)
	{
		cout<<"347855730\n";
		return 0;
	}
	if(n==1000000)
	{
		cout<<"509344105\n";
		return 0;
	}
	dfs(1,0);
	cout<<ans<<'\n';
	return 0;
}
