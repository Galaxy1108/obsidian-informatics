#include<bits/stdc++.h>
using namespace std;
const int mx=10010;
const int mod=1e9+7;
int n,k;
long long F(int x)
{
	long long res=1;
	while(x)
	{
		res=res*(x%10)%mod;
		x/=10;
	}
	return res;
}
priority_queue<int> q;
int ans=0;
int cnt[mx][mx];
int main()
{
	freopen("find.in","r",stdin);
	freopen("find.out","w",stdout);
	cin>>n>>k;
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cnt[F(i)][F(j)]++;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(cnt[i][j]) q.push(cnt[i][j]);
	for(int i=1;i<=k;i++) 
	{
		int x=q.top();
		ans+=x;
		q.pop();
	}
	cout<<ans;
	return 0;
} 
