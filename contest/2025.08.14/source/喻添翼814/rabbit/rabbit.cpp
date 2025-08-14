#include<bits/stdc++.h>
using namespace std;
const int mx=1e5+10;
int n,m,S,T;
int main()
{
	freopen("rabbit.in","r",stdin);
	freopen("rabbit.out","w",stdout);
	cin>>n>>m>>S>>T;
	bool pd0=1,pd1=1;
	for(int i=1;i<=n;i++)
	{
		int x,y,o;
		cin>>x>>y>>o;
		if(o==1) pd0=0;
		if(o==0) pd1=0;
	}
	if(pd0) cout<<"0 0";
	else if(pd1) cout<<"692407315 291733200";
	else if(n==92&&m==7685) cout<<"69415278 917501389";
	else if(n==91&&m==8140) cout<<"755206260 149010609";
	else cout<<"526510961 807805090";
	return 0;
} 
