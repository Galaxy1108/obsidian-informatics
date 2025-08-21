#include<bits/stdc++.h>
using namespace std;
const int mx=2550;
int n;
int a[mx];
int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
int main()
{
    freopen("divisors.in","r",stdin);
    freopen("divisors.out","w",stdout);
    cin>>n;
    int cnt=0;
    for(int i=n;i;i--)
    {
		cnt++;
    	if(a[cnt]==0) a[cnt]=i;
    	int x=a[cnt-1]/i;
    	for(int j=1;j<=10000;j++)
    	{
    		if(gcd(x,j)==1)
    		{
    			a[cnt]*=j;
    			break;
			}
		}
	}
	for(int i=1;i<=n;i++) cout<<a[i]<<' ';
	cout<<endl;
    for(int i=1;i<n;i++) cout<<i<<' '<<i+1<<endl;
    return 0;
}
