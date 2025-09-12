#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,x,y;
signed main()
{
	freopen("labyrinth.in","r",stdin);
	freopen("labyrinth.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<ceil(log2(n+1))<<endl;
		for(int i = 1; i < n; i++) cin>>x>>y;
	 } 
}
