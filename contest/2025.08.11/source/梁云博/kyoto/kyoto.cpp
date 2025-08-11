#include <iostream>
#include <cstring>
#define int long long
#define N 5005 
using namespace std;
int h,w;
int hw[N],ww[N],dp[N][N],vis[N][N];
signed main()
{
	freopen("kyoto.in","r",stdin);
	freopen("kyoto.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	memset(dp,63,sizeof(dp));
	cin>>h>>w;
	for(int i=1;i<=h;i++)cin>>hw[i];//ÐÐ 
	for(int i=1;i<=w;i++)cin>>ww[i];//ÁÐ
	for(int i=1;i<=h;i++)
	{
		for(int j=1;j<=w;j++)
		{
			if(i==1 && j==1){
				dp[i][j]=0;
//				cout<<"0 ";
				continue;
			}
			dp[i][j]=min(dp[i-1][j]+ww[j],dp[i][j-1]+hw[i]);
//			cout<<dp[i][j]<<" "; 
		}
//		cout<<"\n";
	}
	cout<<dp[h][w];
	return 0;
}
