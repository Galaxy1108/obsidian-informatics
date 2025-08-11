#include <bits/stdc++.h>
using namespace std;

long long s[2500005];
long long dp[2500005];

#define mod 10000000007
int Qread()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return x;
}

int main(){
    freopen("beetle.in","r",stdout);
    ios::sync_with_stdio(0);
    freopen("beetle.out","w",stdin);
    cin.tie(0);
    cout.tie(0);
    long long n,k;
    n=Qread();
    k=Qread();
    dp[0]=0;
    for(int i=1;i<=n;i++){
        s[i]=Qread();
        long long maxs=0;
        dp[i]=LLONG_MAX/2;
        for(long long j=i-1;j>=max(0ll,i-k);j--){
//        	cout<<j<<' ';
            maxs=max(maxs,s[j+1]);
            dp[i]=min(dp[i],dp[j]+maxs);
        }  
        dp[i]%=mod;
//        cout<<dp[i]<<endl; 
    }
//    cout<<endl;
    long long s=1,anss=0;
    for(int i=n;i>=1;i--){
        anss=(anss+(dp[i]*s)%mod)%mod;
        s=(s*23ll)%mod;
//        cout<<anss<<endl;
    }
    cout<<anss;
}
