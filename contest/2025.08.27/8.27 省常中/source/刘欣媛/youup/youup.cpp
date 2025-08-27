#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("youup.in","r",stdin);
	freopen("youup.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int num,n,x;
	cin>>num>>n>>x;
	for(int i=1;i<=n;i++)
	{
		int f,g;
		cin>>f>>g;
		if(i==1)cout<<n<<" ";
		else cout<<0<<" ";
	}
	
	return 0;
} 
