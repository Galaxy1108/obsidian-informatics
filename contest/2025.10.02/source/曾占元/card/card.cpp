#include<bits/stdc++.h>
using namespace std;
int a[1000005],b[1000005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,q;
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++)
	{
		int p,c;
		cin>>p>>c;
		b[p]=c;
	}
	for(int i=1;i<=q;i++)
	{
		int op,x,y;
		cin>>op>>x>>y;
		if(op==1)
		{
			cin>>x;
			b[x]=0;
		}
		else
		{
			cin>>x>>y;
			b[x]=y;
		}
		cout<<"0\n";
	}
	return 0;
}
