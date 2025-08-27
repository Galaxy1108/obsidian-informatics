#include <bits/stdc++.h>
using namespace std;
long long n,s,t,x,y;
int main()
{
	freopen("never.in","r",stdin);
	freopen("never.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T;
    cin>>T;
    while(T--)
    {
        cin>>n>>s>>t>>x>>y;
        long long ans=s;
        if(x==y)
        {
            if(ans<t)
            {
                long long k=(t-ans+y-1)/y;
                k=min(n,k);
                n-=k;
                ans+=k*y;
                //cout<<k<<" ";
                if(n%2) cout<<ans-x;
                else cout<<ans;
                
                cout<<"\n";
            }
            else
            {
                long long k=(ans-t+x)/x;
                k=min(n,k);
                n-=k;
                ans-=k*x;
                if(n%2) cout<<ans+x;
                else cout<<ans;
                cout<<"\n";
            }
        }
        else
        {
        	while(n)
        	{
        		if(ans<t)
	            {
	                long long k=(t-ans+y-1)/y;
	                k=min(n,k);
	                n-=k;
	                ans+=k*y;
	            }
	            else
	            {
	                long long k=(ans-t+x)/x;
	                k=min(n,k);
	                n-=k;
	                ans-=k*x;
	            }
	            //cout<<ans<<" "<<n<<"\n";
			}
			cout<<ans<<"\n";
		}

    }
	
	return 0;
} 
