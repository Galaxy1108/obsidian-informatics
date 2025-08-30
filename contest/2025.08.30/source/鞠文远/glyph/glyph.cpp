#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=305;
int n,q,ary[N][N],dp[N][N];
signed main()
{
	freopen("glyph.in","r",stdin);
	freopen("glyph.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>ary[i][j];
	while(q--)
	{
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		for(int i=a;i<=b;i++)
			for(int j=c;j<=d;j++)
				dp[i][j]=0;
		dp[a][c]=ary[a][c];
		for(int i=a+1;i<=b;i++)dp[i][c]=dp[i-1][c]+ary[i][c];
		for(int i=c+1;i<=d;i++)dp[a][i]=dp[a][i-1]+ary[a][i];
		for(int i=a+1;i<=b;i++)
			for(int j=c+1;j<=d;j++)
				dp[i][j]=min(dp[i-1][j],dp[i][j-1])+ary[i][j];
		cout<<dp[b][d]<<"\n";
	}
	
	return 0;
} 
