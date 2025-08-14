#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("calc.in","r",stdin);
	freopen("calc.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T,p;
	cin>>T>>p;
	while(T--)
	{
		int b;
		cin>>b;
		if(p%3==0)
		{
			if(b%3==2)
			{
				cout<<2<<"\n";
			}
			else
			{
				cout<<-1<<"\n";
			}
		}
		else if(p==5)
		{
			if(b%5==3||b%5==2)
			{
				cout<<1<<"\n";
			}
			else if(b%5==4)
			{
				cout<<2<<"\n";
			}
			else
			{
				cout<<-1<<"\n";
			}
		}
		else {
			cout<<-1<<"\n";
		}
		
	}
	return 0;
 } 
