#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAXN = 1e6 + 12;
int n,k;
char s[MAXN<<1];
int a[MAXN<<1],b[MAXN<<1];
long long ans;
bool check()
{
	int cnt0=0,cnt1=0,cntk=0;
	int i=1;
	while (1)
	{
		cntk++;
		cnt0 = 0;
		while(i<=2*n)
		{
			if (a[i]==0) cnt0 ++;
			else if (cnt1) cnt1--;
			else break;
			i++;
		}
		if (i>2*n) return 1;
		if (cnt0==0) return 0;
		if (cntk>k) return 0;
		cnt1+=cnt0;
	}
}
int temp1[MAXN],temp2[MAXN];
long long cal()
{
	int cnt1 = 0,cnt2 = 0;
	for (int i=1;i<=2*n;i++)
	{
		if (a[i]) temp1[++cnt1] = i;
		if (b[i]) temp2[++cnt2] = i;
	}
	long long res = 0;
	for (int i=1;i<=n;i++)
		res += abs(temp1[i]-temp2[i]);
	return res;
}
void dfs(int id,int cnt0,int cnt1)
{
	if (cnt0>n||cnt1>n) return ;
	if (id>2*n)
	{
		if (check())
		{
			ans = min(ans,cal());
		}
		return ;
	}
	a[id] = 0;
	dfs(id+1,cnt0+1,cnt1);
	a[id] = 1;
	dfs(id+1,cnt0,cnt1+1);
}
int main()
{
	freopen("transfer.in","r",stdin);
	freopen("transfer.out","w",stdout);
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	for (int i=1;i<=n*2;i++)
		b[i] = s[i] - 'A';
	for (int i=1;i<=n*2;i++)
		a[i] = s[i] - 'A';
	if (check()) printf("0");
	else if (k==1)
	{
		for (int i=1;i<=n;i++) a[i] = 0;
		for (int j=n+1;j<=n*2;j++) a[j] = 1;
		printf("%lld",cal());
	}
	else 
	{
		ans = 1e18;
		dfs(1,0,0);
		printf("%lld",ans);
	}
	return 0;
}
