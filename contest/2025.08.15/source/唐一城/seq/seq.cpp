#include <bits/stdc++.h>
using namespace std;
#define il inline
#define ll long long
const int N=1e6+5,mod=998244353;
int n,m,a[N],b[N],tot=0;;
ll s[N];
bool cmp(ll x,ll y)
{
	int t1[15],t2[15],num1=0,num2=0;
	while(x){t1[++num1]=x%10,x/=10;}
	while(y){t2[++num2]=y%10,y/=10;}
	for(int i=num1,j=num2;i>=1,j>=1;i--,j--)
	{
		if(t1[i]==t2[j])continue;
		else if(t1[i]<t2[j])return 1;
		else return 0;
	}
	return (num2>num1?1:0);
}
il void dfs(int x,ll now)
{
	if(now>0)s[++tot]=now;
	for(int i=x+1;i<=n;i++)
	{
		dfs(i,now*10ll+a[i]);
	}
}
signed main()
{
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	cin>>m;
	for(int i=1;i<=m;i++)cin>>b[i];
	ll tt=0;
	for(int i=1;i<=m;i++)tt=tt*10ll+b[i];
	dfs(0,0);
	sort(s+1,s+tot+1);
	int ttt=unique(s+1,s+tot+1)-s-1;
	sort(s+1,s+ttt+1,cmp);
	for(int i=1;i<=ttt;i++)
	{
//		cout<<s[i]<<' ';
		if(s[i]==tt)
		{
			cout<<i;
			return 0;
		}
	}
	return 0;
}

