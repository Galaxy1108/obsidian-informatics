#include <bits/stdc++.h>
using namespace std;
long long Qread()
{
	long long x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return x;
}
typedef pair<long long,int> pr;
long long X,T,W;
int n,m,tmp;
long long S[200010],D[200010];
pr p[200010];
long long sd[200010],sum[200010],f[200010];

int top;
long long k[200010],b[200010];
void insert(long long b,long long k)
{
	while(top>1&&(__int128)(b-::b[top-1])*(k-::k[top])>=(__int128)(b-::b[top])*(k-::k[top-1])) top--;
	++top,::k[top]=k,::b[top]=b;
}
long long calc(long long x)
{
	int l=1,r=top,mid;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(-k[mid]*x+b[mid]<=-k[mid+1]*x+b[mid+1]) r=mid;
		else l=mid+1;
	}
	return -k[l]*x+b[l];
}
int main()
{
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	X=Qread(),n=Qread(),m=Qread(),W=Qread(),T=Qread();
	for(int i=1;i<=n;i++) S[i]=Qread();
	for(int i=1;i<=m;i++) p[i].first=Qread(),p[i].second=Qread();
	sort(p+1,p+m+1);
	for(int i=1;i<=m;i++) sum[i]=sum[i-1]+p[i].second,D[i]=p[i].first;
	memset(sd,0x3f,sizeof(sd));
	for(int i=1;i<=n;i++)
	{
		tmp=lower_bound(D+1,D+m+1,S[i]%T)-D-1;
		if(tmp) sd[tmp]=min(sd[tmp],S[i]/T);
	}
	tmp=lower_bound(D+1,D+m+1,X%T)-D-1;
	if(tmp) sd[tmp]=min(sd[tmp],X/T);

	f[0]=W*(X/T+1);
	insert(f[0],0);
	for(int i=1;i<=m;i++)
	{
		if(sd[i]!=0x3f3f3f3f3f3f3f3f) f[i]=calc(W*sd[i])+sum[i]+W*i*sd[i];
		else f[i]=0x3f3f3f3f3f3f3f3f;
		f[i]=min(f[i],f[i-1]+W*(X/T+(X%T>=D[i])));
		insert(f[i]-sum[i],i);
	}
	printf("%lld\n",f[m]);
	return 0;
}