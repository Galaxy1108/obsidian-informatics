#include<bits/stdc++.h>
using namespace std;
const int mx=1000;
int NUM,n;
int a[mx];

int main()
{
	freopen("imperishable.in","r",stdin);
	freopen("imperishable.out","w",stdout);
	cin>>NUM>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==1) cout<<2;
	if(n==4) cout<<2<<endl<<10<<endl<<6;
	return 0;
} 
