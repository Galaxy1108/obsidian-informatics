//我把变量名一改还有oiwiki味吗 
#include<bits/stdc++.h>
using namespace std;
int simgcd(int n,int a,int b,int c) 
{
	if(a==0)
	{
        return (b/c)*(n+1); 
    } 
    if (a>=c||b>=c)
	{
		return (n*(n+1))/2*(a/c)+(b/c)*(n+1)+simgcd(n,a%c,b%c,c);
	}
	int m=(a*n+b)/c; 
	return n*m-simgcd(m-1,c,c-b-1,a); 
} 
int main()
{
	int ans=simgcd(10,5,3,5);
	cout<<ans;
}
