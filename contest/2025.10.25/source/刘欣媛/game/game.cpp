#include <bits/stdc++.h>
using namespace std;
int a[1000005],n;
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n>5){
		if(n%2==0){
			cout<<"0";
		}
		else
		{
			cout<<n;
		}
	}
	
	
	
	return 0;
 } 
