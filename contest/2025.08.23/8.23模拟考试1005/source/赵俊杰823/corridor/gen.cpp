#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("corridor.in","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	mt19937 rand(time(0));
	int n=50000,m=50000,k=50000,T=1000;
	cout<<0<<' '<<n<<' '<<m<<' '<<k<<'\n';
	for(int i=1;i<=k/2;i++)
	{
		int x=rand()%n+1,y=rand()%m+1;
		cout<<i<<' '<<i<<'\n';
		cout<<i<<' '<<i+1<<'\n';
	}
	cout<<T<<'\n';
	while(T--)
	{
		int op=rand()%2+1;
		cout<<op<<' ';
		if(op==1)
		{
			int x=rand()%n+1,y=rand()%m+1;
			cout<<x<<' '<<y<<'\n';
		}
		else
		{
			int t=rand()%2+1;
			int x=rand()%1+1,y=rand()%1+1;
			if(t==0)cout<<x<<' '<<0<<' ';
			else cout<<0<<' '<<x<<' ';
			cout<<rand()%k+1<<'\n';
		}
	}
	return 0;
}
