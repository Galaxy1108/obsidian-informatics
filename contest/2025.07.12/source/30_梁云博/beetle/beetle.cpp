#include <bits/stdc++.h>
#define N 2500005
#define ll long long
#define p 1000000007
using namespace std;
int n,k;
ll s[N];
ll q[N],t,h=1;
ll evrk[N];//��i��β�ĳ���Ϊk�����仨�� 
ll minw[N];//evrk��i-k~i-1����С����ֵ 
int main()
{
	freopen("beetle.in","r",stdin);
	freopen("beetle.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%lld",&s[i]),s[i]%=p;
	for(int i=1;i<=n;i++)
	{
		while(h<=t && s[q[t]]<=s[i])t--;
		while(h<=t && q[h]<i-k+1)h++;
		q[++t]=i;
		evrk[i]=s[q[h]];
	}
	t=0,h=1;
	memset(q,0,sizeof(q));
	ll ans=0; 
	for(int i=1;i<=n;i++)//��ǰλ��Ϊi-1 ��hС��i-k 
	{
		while(h<=t && minw[q[t]]>=minw[i-1])t--;
		while(h<=t && q[h]<i-k)h++;
		q[++t]=i-1;
		minw[i]=(evrk[i]+minw[q[h]])%p;
	}
	ll power=1;
	for(int i=n;i>=1;i--)
	{
		ans=(ans+(minw[i]*power)%p)%p;
		power=(power*23)%p;
	}printf("%lld",ans);
	return 0;
}
