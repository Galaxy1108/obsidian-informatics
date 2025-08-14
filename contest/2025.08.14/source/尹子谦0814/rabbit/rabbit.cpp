#include<bits/stdc++.h>
using namespace std;
const int N=1e3+100;
int n,m,s,t;
int road[N][N];
bool sp1=1,sp2=1;
signed main()
{
	freopen("rabbit.in","r",stdin);
	freopen("rabbit.out","w",stdout);
	cin>>n>>m>>s>>t;
	memset(road,-1,sizeof road);
	for(int i=1;i<=m;i++)
	{
		int u,v,op;
		cin>>u>>v>>op;
		road[u][v]=op;
		if(op!=1) sp1=0;
		if(op!=0) sp2=0;
	}
	if(sp2) cout<<0<<' '<<0<<endl;
	
}
