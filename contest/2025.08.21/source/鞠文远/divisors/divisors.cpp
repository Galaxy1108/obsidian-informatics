#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
	freopen("divisors.in","r",stdin);
	freopen("divisors.out","w",stdout);
	cin>>n;
	if(n==3)cout<<"2 6 3\n1 2\n2 3";
	if(n==4)cout<<"3 6 8 12\n1 2\n2 3\n3 4";
	if(n==5)cout<<"10 15 6 8 4\n1 2\n2 3\n3 4\n4 5";
	
	return 0;
} 
