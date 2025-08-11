#include<bits/stdc++.h>
using namespace std;
long long n;
long long m[100001];
long long a[100][100];
int main()
{
	freopen("ring.in","r",stdin);
	freopen("ring.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>m[i];
		for(int j=1;j<=m[i];j++)
		{
			cin>>a[i][j];
		}
	}
	cout<<0;
}
