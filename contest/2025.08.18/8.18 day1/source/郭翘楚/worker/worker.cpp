#include <bits/stdc++.h>
using namespace std;
int x[105];
int n;
int dp[105][11][11][11];
int f(int k,int a,int b,int c)
{
	int d=10-a-b-c;
	for(int i=1;i<=d;i++)
	{
		k++;
		if(k>n) break;
		if(x[k]==1) a++;
		if(x[k]==2) b++;
		if(x[k]==3) c++;
	}
	if(dp[k][a][b][c]) return dp[k][a][b][c];
	if(k>n)
	{
		int cnt=(a>0)+(b>0)+(c>0);
		dp[k][a][b][c]=cnt;
		return cnt;
	}
	int ans=2147483647;
	if(a>0) ans=min(ans,f(k,0,b,c)+1);
	if(b>0) ans=min(ans,f(k,a,0,c)+1);
	if(c>0) ans=min(ans,f(k,a,b,0)+1);
	dp[k][a][b][c]=ans;
	return ans; 
}
int main()
{
	freopen("worker.in","r",stdin);
	freopen("worker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		char c;
		cin>>c;
		int cn=c-'A'+1;
		x[i]=cn;
	}
	cout<<f(0,0,0,0);
	return 0;
} 
