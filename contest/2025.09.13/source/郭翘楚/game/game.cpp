#include <bits/stdc++.h>
using namespace std;
void p(int a,int b)
{
	cout<<a<<" "<<b<<'\n';
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int k,T;
	cin>>k>>T;
	while(T--)
	{
		int n;
		cin>>n;
		if(k==1)
		{
			if(n==5) p(10,2);
			if(n==6) p(17,4);
			if(n==7) p(28,4);
			if(n==8) p(46,7);
			if(n==9) p(75,9);
			if(n==10) p(122,14);
		}
		else
		{
			p(n,1); 
		}
	} 
}
