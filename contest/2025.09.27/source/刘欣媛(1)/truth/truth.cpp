#include <bits/stdc++.h>
using namespace std;
int a[50005];
int main()
{
	freopen("truth.in","r",stdin);
	freopen("truth.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,k,m;
	cin>>n>>k>>m;
	for(register int i=1;i<=n;i++)
	{
		cin>>a[i]; 
	}
	for(register int i=1;i<=m;i++)
	{
		int o;
		cin>>o;
		if(o==1)
		{
			int p,v;
			cin>>p>>v;
			a[p]=v;
		}
		else
		{
			int mn=1e9;
			for(register int i=1;i<=n-k;i++)
			{
				int cnt=k;
				bool bk[50];
				memset(bk,0,sizeof(bk));
				for(register int j=i;j<=n;j++)
				{
					if(bk[a[j]]==0)
					{
						cnt--;
						bk[a[j]]=1;
					}
					if(cnt==0)
					{
						mn=min(mn,j-i+1);
						break;
					}
				}
			}
			if(mn==1e9)
			{
				cout<<"-1\n";
			 } 
			 else
			 {
			 	cout<<mn<<"\n";
			 }
			
		}
	}
	
	return 0;
}
