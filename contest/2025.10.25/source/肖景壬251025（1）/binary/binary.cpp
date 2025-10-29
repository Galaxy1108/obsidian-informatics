#include<bits/stdc++.h>
using namespace std;
int n,m,sum[2][100005],a[100005],op,l,r;
int main()
{
	freopen("binary.in","r",stdin);
	freopen("binary.out","w",stdout);
	cin>>n;
	for(int i = 1; i <= n; i++) cin>>a[i];
	for(int j = 1; j <= n; j++)
	{
		sum[0][j]=sum[0][j-1]+(a[j]==0);
		sum[1][j]=sum[1][j-1]+(a[j]==1);
	}
	cin>>m;
	for(int i = 1; i <= m; i++)
	{
		cin>>op>>l;
		if(op==1)
		{
			a[l]=1-a[l];
			for(int j = 1; j <= n; j++)
			{
				sum[0][j]=sum[0][j-1]+(a[j]==0);
				sum[1][j]=sum[1][j-1]+(a[j]==1);
			}
		}
		else
		{
			cin>>r;
			int ans=0;
			for(int j = l; j <= r; j++)
			{
				for(int k = j; k <= r; k++)
				{
					if(((sum[1][k]-sum[1][j-1])&1)==0)
					{
						ans++;
						//cout<<j<<" "<<k<<endl;
					}
					else if((sum[1][k]-sum[1][j-1])>=3&&(sum[0][k]-sum[0][j-1])>=2)
					{
						//cout<<j<<" "<<k<<endl;
						ans++;
					}
				}
			}
			cout<<ans<<endl;
		}
	}
}
