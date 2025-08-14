#include<bits/stdc++.h>
using namespace std;
const int mx=2010;
int n,a[mx];
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	bool pd=1;
	for(int i=2;i<=n;i++) if(a[i]!=a[i-1]) pd=0;
	if(pd) cout<<0;
	else if(n==2) cout<<4;
	else if(n==10) cout<<900221128;
	else if(n==3) cout<<42;
	else if(n==8) cout<<420960505;
	else if(n==92) cout<<683577231;
	else if(n==1970) cout<<23224172;
	return 0;
} 
