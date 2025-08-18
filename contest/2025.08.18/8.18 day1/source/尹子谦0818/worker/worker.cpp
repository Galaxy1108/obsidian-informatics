#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,st[N],ans=110,cnt[N][10],dp[N][11][11][11];
int dfs(int k,int a,int b,int c)
{
	int d=10-a-b-c;
	for(int i=1;i<=d;i++)
	{
		k++;
		if(k>n) break;
		if(st[k]==1) a++;
		if(st[k]==2) b++;
		if(st[k]==3) c++;
	}
	if(k>n)
	{
		int cnt=(a>0)+(b>0)+(c>0);
		return cnt;
	}
	if(dp[k][a][b][c]) return dp[k][a][b][c];
	int ans=110;
	if(a>0) ans=min(ans,dfs(k,0,b,c)+1);
	if(b>0) ans=min(ans,dfs(k,a,0,c)+1);
	if(c>0) ans=min(ans,dfs(k,a,b,0)+1);
	dp[k][a][b][c]=ans;
	return ans;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		char ch;
		cin>>ch;
		st[i]=ch-'A'+1;
	}
	cout<<dfs(0,0,0,0);
	return 0;
} 
