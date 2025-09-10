#include<bits/stdc++.h>
using namespace std;
const int N=1010,M=1e9+7;
int n;
int	gold[N][N],ans[N*N],k,cnt;
int f(int x)
{
	int ans=1;
	while(x) ans=ans*(x%10),x/=10;
	return ans;
}
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("find.in","r",stdin);
	freopen("find.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			gold[f(i)][f(j)]++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			ans[++cnt]=gold[i][j];
		}
	}
	sort(ans+1,ans+1+cnt,cmp);
	int res=0;
	for(int i=1;i<=k;i++) res+=ans[i],res%=M;
	cout<<res%M;
	return 0;
} 
