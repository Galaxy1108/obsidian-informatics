#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1010,M=998244353;
int n,x,dp[N][N],jc[N],njc[N];
int qp(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b%2) res=res*a%M;
		b>>=1;
		a=a*a%M;
	}
	return res;
}
int C(int a,int b)
{
	if(b>a||a<0||b<0) return 0;
	return jc[a]*njc[b]%M*njc[a-b]%M;
}
signed main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>x;
	jc[0]=1;
	for(int i=1;i<=n;i++)jc[i]=jc[i-1]*i%M;
	for(int i=n;i>=0;i--) njc[i]=qp(jc[i],M-2);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=x;j++)
		{
			if(i<=j)
			{ 
				for(int k=1;k<=i;k++)
				{
					dp[i][j]+=dp[k][j-i+1]*qp(i-1,i-k)%M*C(i,k)%M;
					dp[i][j]%=M;
				}
			}
			else
			{
				dp[i][j]=(qp(j,i)-qp(j-1,i)+M)%M;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=x;i++) ans+=dp[n][i],ans%=M;
	cout<<ans<<endl;
	return 0;
} 
