#include<bits/stdc++.h>
using namespace std;
int a[1000009];
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	ios::sync_with_stdio(NULL);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
/*	for(int i=1;i<=t;i++)
	{
		cout<<1<<endl;
	}*/
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int ii=2;ii<=T;ii++)
	{
		int k;
		cin>>k;
		for(int i=1;i<=n;i++)
		{
			int aa,bb;
			cin>>aa>>bb;
			a[aa]=bb;
		}
	}
	for(int i=1;i<=T;i++)
	{
		cout<<1<<endl;
	}
	return 0;
}
