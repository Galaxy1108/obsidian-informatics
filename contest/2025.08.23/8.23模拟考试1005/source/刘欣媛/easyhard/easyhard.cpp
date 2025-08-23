#include <bits/stdc++.h>
using namespace std;
long long n,m,p;
long long res;
long long qp(long long a,long  long b)
{
    long long ans=1;
    while(b)
    {
        if(b&1)
        {
            ans=(ans*a)%p;
        }
        a=(a*a)%p;
        b>>=1;
    }
    return ans%p;
}
int main()
{
    freopen("easyhard.in","r",stdin);
    freopen("easyhard.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>p;
    res=qp(2,n);
    if(n==1)
    {
    	cout<<qp(2,m+1);
    	return 0;
	}
    if(m>n)
    {
		long long l=qp(2,2*m-n);
		l-=2*qp(2,m-n);
		res=(res*l)%p; 
    }
    else
    {
        res=qp(2,2*m);
    }
    cout<<res%p;
    return 0;
}
