#include <bits/stdc++.h>
using namespace std;
int T;
int x,y;
int n,k;
int a[1000005];
int main()
{
	cin>>T;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	T--;
	while(T--)
	{
		cin>>k;
		for(int i=0;i<k;i++)
		{
			cin>>x>>y;
			a[x]=y;
		}
	}
	return 0;
}
