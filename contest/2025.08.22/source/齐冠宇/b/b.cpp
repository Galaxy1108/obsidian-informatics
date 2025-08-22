#include <bits/stdc++.h>
using namespace std;
constexpr int N=2005;
int n;
int w[N][N];
int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			cin>>w[i][j],w[j][i]=w[i][j];
	for(int i=1;i<=n;i++)
	{
		
	}
	return 0;
}
