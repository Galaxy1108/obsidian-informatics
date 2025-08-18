#include <iostream>
using namespace std;
int n;
int kind[101];
int times[101][101];
int dp[101][101];
char gc()
{
	char ch=getchar();
	while(isspace(ch)) ch=getchar();
	return ch;
}
int read()
{
	int s=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		s=(s<<3)+(s<<1)+(ch^48);
		ch=getchar();
	}
	return s*f;
}
int res(int _)
{
	int ret=0;
	if(_&1) ++ret;
	_>>=1;
	if(_&1) ++ret;
	_>>=1;
	if(_&1) ++ret;
	_>>=1;
	return ret;
}
int main()
{
	freopen("worker.in","r",stdin);
	freopen("worker.out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i)
	{
		char temp=gc();
		kind[i]=(temp=='A'?1:(temp=='B'?2:4));
	}
	for(int i=1;i<=n;++i)
		for(int j=i;j<=i+9 && j<=n;++j)
			times[i][j]=times[i][j-1]|kind[j],dp[i][j]=res(times[i][j]);
	for(int len=11;len<=n;++len)
		for(int i=1;i+len-1<=n;++i)
		{
			dp[i][i+len-1]=0x3f3f3f3f;
			for(int k=i;k+9<=i+len-1;++k)
				dp[i][i+len-1]=min(dp[i][i+len-1],dp[i][k-1]+dp[k+10][i+len-1]+dp[k][k+9]);
		}
	cout<<dp[1][n]-1;
	return 0;
}
