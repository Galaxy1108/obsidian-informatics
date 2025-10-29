#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200005],f[200005][6],ans;
signed main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n;
	for(int i = 1; i <= n; i++) cin>>a[i];
	for(int i = 1; i <= n; i++)
	{
		f[i][1]=f[i-1][1]+a[i];
		f[i][2]=min(f[i-1][2],f[i-1][1])+(a[i]&1);
		f[i][3]=min({f[i-1][3],f[i-1][2],f[i-1][1]})+(1-(a[i]&1));
		f[i][4]=min({f[i-1][4],f[i-1][3],f[i-1][2],f[i-1][1]})+(a[i]&1);
		f[i][5]=min({f[i-1][5],f[i-1][4],f[i-1][3],f[i-1][2],f[i-1][1]})+a[i];
		if(a[i]==0)
		{
			f[i][2]+=2;
			f[i][4]+=2;
		}
	}
	cout<<min({f[n][1],f[n][2],f[n][3],f[n][4],f[n][5]})<<endl;
}
