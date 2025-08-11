#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int a[N],b[N],vis[N],to[N],ne[N];
int main()
{
	freopen("gene.in","r",stdin);
	freopen("gene.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,l,r;
	cin>>n>>l>>r;
	for(int i=1;i<=n;i++)cin>>a[i];
	l--;r++;
	for(int i=1;i<=n;i++)
	{
		ne[i]=b[a[i]];
		b[a[i]]=i;
	}
	for(int i=1;i<=1000000;i++)b[i]=n+1;
	for(int i=n;i>=1;i--)
	{
		to[i]=b[a[i]];
		b[a[i]]=i;
	}
	int ans=1e9,t=r;
	for(int i=l;i>=1;i--)
	{
		if(ne[i])continue;
		while(t<=n&&(to[t]<=n||ne[t]>i))t++;
		if(t<=n&&t<=to[i]&&a[i]!=a[t])ans=min(ans,t-i+1);
	}
	if(ans==1e9)cout<<"-1\n";
	else cout<<ans<<'\n';
	return 0;
}
