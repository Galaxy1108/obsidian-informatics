#include<bits/stdc++.h>
using namespace std;
const int N=54;

int n;
int a[N][N];int m;

int main()
{
	freopen("brike.in","r",stdin);
	freopen("brike.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	int ans=0;
	/////////////////////
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n-i+1;j++)
		cin>>a[i][j];
	int cnt=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n-i+1&&cnt<m;j++)
			ans+=a[i][j],cnt++;
	cout<<ans<<endl;
	return 0;
}
