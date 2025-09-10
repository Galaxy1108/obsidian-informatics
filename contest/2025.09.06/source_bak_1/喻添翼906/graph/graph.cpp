#include<bits/stdc++.h>
using namespace std; 
const int mx=1e5+10;
int n,m;
int cnt;
int main()
{
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	cin>>n>>m;
	int ans=m/2;
	if(ans==1) ans=0;
	cout<<ans;
	return 0;
}
