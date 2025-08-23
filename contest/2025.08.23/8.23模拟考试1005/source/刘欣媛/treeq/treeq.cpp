#include <bits/stdc++.h>
using namespace std;
int n,f[10000007],w[10000007];
int main()
{
    freopen("treeq.in","r",stdin);
    freopen("treeq.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
	cin>>n;
	int mn=0;
	for(int i=2;i<=n;i++)
	{
		cin>>f[i]>>w[i];
		mn=max(mn,w[i]);
	}
	long long ans=0;
	for(int i=2;i<=n;i++)
	{
		if(w[i]==mn)
		{
			ans^=n;
		}
	}
	cout<<ans;
	


    return 0;
}
