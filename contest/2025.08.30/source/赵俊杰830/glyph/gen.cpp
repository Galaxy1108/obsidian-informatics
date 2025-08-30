#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("glyph10.in","w",stdout);
	int n=300,m=200000;
	mt19937 rand(time(0));
	cout<<n<<' '<<m<<'\n';
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			cout<<rand()%1000000001<<' ';
		cout<<'\n';
	}
	while(m--)
	{
		int x1=rand()%n+1,x2=rand()%n+1,y1=rand()%n+1,y2=rand()%n+1;
		if(x1>x2)swap(x1,x2);
		if(y1>y2)swap(y1,y2);
		cout<<x1<<' '<<x2<<' '<<y1<<' '<<y2<<'\n';
	}
	return 0;
}
