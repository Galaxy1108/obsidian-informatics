#include<bits/stdc++.h>
using namespace std;
int f[105][12][12][12],n,ans=1e9;
char t[105];
void dfs(int x,int a,int b,int c,int k)
{
	if(f[x][a][b][c]<=k)return;
	f[x][a][b][c]=k;
	if(x==n)
	{
		ans=min(ans,k+(a!=0)+(b!=0)+(c!=0));
		return;
	}
	int a_=0,b_=0,c_=0;
	if(t[x+1]=='A')a_++;
	if(t[x+1]=='B')b_++;
	if(t[x+1]=='C')c_++;
	if(a>0)dfs(x+1,a_,b+b_,c+c_,k+1);
	if(b>0)dfs(x+1,a+a_,b_,c+c_,k+1);
	if(c>0)dfs(x+1,a+a_,b+b_,c_,k+1);
	if(a+b+c==10)return;
	dfs(x+1,a+a_,b+b_,c+c_,k);
}
int main()
{
	freopen("worker.in","r",stdin);
	freopen("worker.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>t[i];
	memset(f,0x3f,sizeof(f));
	dfs(0,0,0,0,0);
	cout<<ans<<'\n';
	return 0;
}
