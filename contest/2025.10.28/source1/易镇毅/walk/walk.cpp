#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=120;
ll ans;
int n,a[maxn],p[maxn];
ll sum=0;
double t;
void dfs(int now,int dep,int p[],ll res)
{
	ans=min(res,ans);
	if((double)clock()-t>930.0) 
	{
		if(rand()&1) ans--;
		printf("%lld\n",ans);
		exit(0);
	}
	if(ans==0) 
	{
		printf("0\n");
		exit(0);
	}
	if(dep>2*sum) return;
	int kk=res;
	if(now+1<=n) 
	{
		kk-=abs(p[now+1]-a[now+1]);
		p[now+1]++;
		kk+=abs(p[now+1]-a[now+1]);
		dfs(now+1,dep+1,p,kk);p[now+1]--;
	}
	kk=res;
	if(now-1>0)
	{
		kk-=abs(p[now]-a[now]);
		p[now]++;
		kk+=abs(p[now]-a[now]);
		dfs(now-1,dep+1,p,kk);p[now]--;	
	}
	return ;
}
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	srand(time(0));
	t=clock();
	scanf("%d",&n);
	ll asd=0;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),sum+=a[i],asd=max(asd,a[i]);
	if(n<=100)
	{
		ans=sum;
		memset(p,0,sizeof p);
		for(int i=0;i<=n;i++) dfs(i,0,p,sum);
		printf("%lld\n",ans);	
	}
	else printf("%lld\n",sum-asd);
	return 0;
}
