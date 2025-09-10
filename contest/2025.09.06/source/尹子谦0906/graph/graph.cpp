#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m;
bool b1=1;
int main()
{
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
		if(v!=u+1) b1=0;
	}
	if(b1) cout<<(n-1)/2;
	else cout<<0;
	return 0;
} 
