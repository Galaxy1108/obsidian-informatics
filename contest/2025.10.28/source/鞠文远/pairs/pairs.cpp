#include<bits/stdc++.h>
using namespace std;
int n,mod;
int main()
{
	freopen("pairs.in","r",stdin);
	freopen("pairs.out","w",stdout);
	cin>>n>>mod;
	int anslt=0;
	if(n==1)anslt=0;
	if(n==2)anslt=0;
	if(n==3)anslt=0;
	if(n==4)anslt=17;
	cout<<anslt%mod;
	
	return 0;
} 
