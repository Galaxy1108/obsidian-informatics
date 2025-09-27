#include<bits/stdc++.h>
#define int long long
using namespace std;
int zs[1000009];
int ys[1000009];
signed main()
{
	freopen("gloves.in","r",stdin);
	freopen("gloves.out","w",stdout);
	ios::sync_with_stdio(NULL);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>zs[i];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>ys[i];
	}
	sort(zs+1,zs+1+n);
	sort(ys+1,ys+1+m);
	if(m>=n)
	{
		int ans=0;
		int sy=0;
		for(int i=1;i<=n;i++)
		{
			auto it=lower_bound(ys+1+sy,ys+1+m,zs[i]);
			if(it==ys+1+m)
			{
				it--;
			}
			auto au=it-ys;
			if(zs[i]-ys[au]!=0)
			{
				au--;
			}
			while(au<=sy)
			{
				au++;
			}
			sy=au;
//			cout<<zs[i]<<" "<<ys[au]<<endl;
			ans=max(ans,abs(zs[i]-ys[au]));
		}
		cout<<ans;
	}
	else
	{
		int ans=0;
		int sy=0;
		for(int i=1;i<=m;i++)
		{
			auto it=lower_bound(zs+1+sy,zs+1+n,ys[i]);
			if(it==zs+n+1)
			{
				it--;
			}
			auto au=it-zs;
			if(ys[i]-zs[au]!=0)
			{
				au--;
			}
			while(au<=sy)
			{
				au++;
			}
			sy=au;
//			cout<<sy<<" "<<ys[i]<<" "<<zs[au]<<endl;
			ans=max(ans,abs(ys[i]-zs[au]));
		}
		cout<<ans;
	}
	return 0;
}
/*
---INFORMATIONS---
TIME:2025-09-27 07:25:46
*/
