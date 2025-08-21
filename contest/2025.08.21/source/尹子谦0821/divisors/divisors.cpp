#include<bits/stdc++.h>
using namespace std;
const int N=50;
int n,h[N],dp[N];
int main()
{
    freopen("divisors.in","r",stdin);
    freopen("divisors.out","w",stdout);
    cin>>n;
    if(n<=10)
    {
    	int sum=1;
    	for(int i=2;i<=n;i++) sum=sum*i/__gcd(sum,i);
    	cout<<sum<<' ';
   	 	for(int i=2;i<=n;i++) cout<<i<<' ';
    	for(int i=2;i<=n;i++) cout<<1<<' '<<i<<endl;
	}
    return 0;
}
