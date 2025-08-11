#include <bits/stdc++.h>
#define int long long
#define N 1000006
using namespace std;
int n,l,r;
int s[N];
int vis[N],rvis[N],lvis[N];
int lef[N],rig[N],li,ri;
signed main()
{
	freopen("gene.in","r",stdin);
	freopen("gene.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>l>>r;
	for(int i=1;i<=n;i++)cin>>s[i];
	for(int i=1;i<=r;i++)vis[s[i]]++;
	for(int i=l-1;i>=1;i--)
	{
		if(vis[s[i]]==1)
		{
			lef[++li]=i;
//			cout<<lef[li]<<" ";
		}
	}
//	cout<<"\n";
	memset(vis,0,sizeof(vis));
	for(int i=l;i<=n;i++)vis[s[i]]++;
	for(int i=r+1;i<=n;i++)
	{
		if(vis[s[i]]==1)
		{
			rig[++ri]=i;
//			cout<<rig[ri]<<" ";
		}
	}
	if(li==0 || ri==0)
	{
		cout<<-1;
		return 0;
	}
	int lx=1,rx=1,lvisi,rvisi;
	while(s[lef[lx]]==s[rig[rx]] && lx<=li && rx<=ri)
	{
//		while()
		if(s[rig[rx]]-s[lef[lx+1]]<s[rig[rx+1]]-s[lef[lx]])lx++;
		else rx++;
	}
	if(lx>li || rx>ri)
	{
		cout<<-1;
		return 0;
	}
	cout<<rig[rx]-lef[lx]+1;
	return 0;
}
