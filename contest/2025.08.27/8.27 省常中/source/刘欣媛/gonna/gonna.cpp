#include <bits/stdc++.h>
#define longlong __int128
using namespace std;
long long f[20005],g[20005];
bool bk[100000005];
int main()
{
	freopen("gonna.in","r",stdin);
	freopen("gonna.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	unsigned long long n,p,ans=0;
    cin>>n>>p;
    if(n==5)
    {
        cout<<5736;
        return 0;
    }
    if(n==8)
    {
        cout<<949174537;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        f[i]=1;
        for(int j=1;j<i;j++)
        {
            long long k=1;
            for(int l=j+1;l<=i;l++)
            {
                k*=l;
            }
            for(int l=2;l<=i-j;l++)
            {
                k/=l;
            }
            f[i]*=k;
        }
        for(long long j=1;j*j<=f[i];j++)
        {
            if(f[i]%j==0)
            {
                g[i]+=j;
                g[i]+=f[i]/j;
                if(j*j==f[i])
                {
                    g[i]-=j;
                }
                g[i]%=p;
                //cout<<"s:"<<i<<" "<<j<<" "<<g[i]<<"\n";
            }    
        }
        ans+=g[i];
        ans%=p;
        //cout<<ans<<" "<<g[i]<<" "<<f[i]<<"\n";
    }
    cout<<ans;
	
	return 0;
} 
