#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e7+10,M=1e9+7;
int n,num[N],pre[N],ans[N],cnt[N],pcnt[N];
int qpow(int a,int b) 
{
  int sum=1;
  a=(a%M+M)%M;
  for (;b;b>>=1) 
  {
    if(b&1) sum=(a*sum)%M;
    a=(a*a)%M;
  }
  return sum%M;
}
signed main()
{
    freopen("dice.in","r",stdin);
    freopen("dice.out","w",stdout);
    cin>>n;
    pre[0]=1;
    for(int i=1;i<=n;i++) cin>>num[i],cnt[num[i]]++;
    sort(num+1,num+n+1);
    for(int i=num[n];i>=1;i--) pcnt[i]=(pcnt[i+1]+cnt[i])%M;
    for(int i=1;i<=num[n];i++) pre[i]=pre[i-1]*qpow(i,cnt[i])%M;
	int ny=qpow(pre[num[n]],M-2)%M;
    ans[1]=1;
    for(int i=2;i<=num[n];i++)
    {
    	ans[i]=(pre[i-1]%M*((qpow(i,pcnt[i])-qpow(i-1,pcnt[i])+M)%M))%M;
    	//cout<<ans[i]<<' ';
	}
	int fans=0;
	for(int i=1;i<=num[n];i++) fans+=(ans[i]*i%M),fans%=M;
	cout<<fans*ny%M;
    return 0;
}
