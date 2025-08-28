#include <bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
	freopen("thief.in","r",stdin);
	freopen("thief.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m,l,r,c;
	cin>>n>>m;
	for(register int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(register int i=1;i<=m;i++)
	{
		cin>>l>>r>>c;
		for(register int j=l;j<=r;j++)
		{
			if(c<a[j]) c++;
			if(c>a[j]) c--;
			
		}
		cout<<c<<"\n";
	}
	return 0;
} 
