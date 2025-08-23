#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("imperishable.in","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	mt19937 rand(time(0));
	int id=0,n=200000,T=200000;
	cout<<id<<'\n'<<n<<'\n';
	for(int i=1;i<=n;i++)cout<<rand()%200000+1<<'\n';
	cout<<T<<'\n';
	while(T--)
	{
		int x=rand()%n+1,y=rand()%200000+1;
		cout<<x<<' '<<y<<'\n';
	}
	return 0;
}
