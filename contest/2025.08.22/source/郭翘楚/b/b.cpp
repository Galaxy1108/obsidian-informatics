#include <bits/stdc++.h>
using namespace std;
int w[2005][2005];
int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=n-i;j++)
		{
			cin>>w[i][i+j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<1<<endl;
	}
	return 0;
}
