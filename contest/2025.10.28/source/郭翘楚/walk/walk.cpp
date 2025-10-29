#include <bits/stdc++.h>
using namespace std;
long long a[200005];
long long f[200005][5];
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	long long n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0)
		{
			f[i][0]=f[i-1][0];
			f[i][1]=min(f[i-1][0],f[i-1][1])+2;
			f[i][2]=min({f[i-1][0],f[i-1][1],f[i-1][2]})+1;
			f[i][3]=min({f[i-1][0],f[i-1][1],f[i-1][2],f[i-1][3]})+2;
			f[i][4]=min({f[i-1][0],f[i-1][1],f[i-1][2],f[i-1][3],f[i-1][4]});
		}
		else if(a[i]%2==0)
		{
			f[i][0]=f[i-1][0]+a[i];
			f[i][1]=min(f[i-1][0],f[i-1][1]);
			f[i][2]=min({f[i-1][0],f[i-1][1],f[i-1][2]})+1;
			f[i][3]=min({f[i-1][0],f[i-1][1],f[i-1][2],f[i-1][3]});
			f[i][4]=min({f[i-1][0],f[i-1][1],f[i-1][2],f[i-1][3],f[i-1][4]})+a[i];
		}
		else
		{
			f[i][0]=f[i-1][0]+a[i];
			f[i][1]=min(f[i-1][0],f[i-1][1])+1;
			f[i][2]=min({f[i-1][0],f[i-1][1],f[i-1][2]});
			f[i][3]=min({f[i-1][0],f[i-1][1],f[i-1][2],f[i-1][3]})+1;
			f[i][4]=min({f[i-1][0],f[i-1][1],f[i-1][2],f[i-1][3],f[i-1][4]})+a[i];
		}
		
	}
	cout<<min({f[n][0],f[n][1],f[n][2],f[n][3],f[n][4]});
}
