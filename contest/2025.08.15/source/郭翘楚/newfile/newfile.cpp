#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+9; 
long long a[5005][5005];
int main()
{
	freopen("newfile.in","r",stdin);
	freopen("newfile.out","w",stdout);
	int n,m,q;
	cin>>n>>m>>q;
	for(int i=1;i<=m;i++)
	{
		int l,r,x;
		cin>>l>>r>>x;
		for(int j=1;j<=n;j++)
		{
			if(j<l)
			{
				a[i][j]=a[i-1][j];
			}
			else if(j>=l and j<=r)
			{
				a[i][j]=a[i-1][j]+(j-l+1)*x; 
			} 
			else
			{
				a[i][j]=a[i-1][j]+(r-l+1)*x;
			}
			a[i][j]%=mod;
		}
	}
	while(q--)
	{
		int u,d,l,r;
		cin>>u>>d>>l>>r;
		long long ans=0;
		for(int i=u;i<=d;i++)
		{
			ans+=a[i][r]-a[i][l-1];
			ans%=mod; 
		}
		cout<<ans<<endl;
	}
}
