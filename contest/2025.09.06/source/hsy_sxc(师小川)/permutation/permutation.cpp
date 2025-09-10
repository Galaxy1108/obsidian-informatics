#include<bits/stdc++.h>
#define rr register
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') {x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*f;
}

const int N=1e5+3,inf=1e9;
int n,p[N],q[N],ip[N],iq[N],h[N];
bool np[N],nq[N];
struct num
{
	int r,seq;
}sp[N],sq[N];

bool cmp(num x,num y) {return x.seq>y.seq;}

int main()
{
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	n=read();
	for(rr int i=1;i<=n;++i) p[i]=read(),ip[p[i]]=i,sp[i].r=i;
	for(rr int i=1;i<=n;++i) q[i]=read(),iq[q[i]]=i,sq[i].r=i;
	for(rr int i=1;i<=n;++i)
	{//p
		int j=0,s=p[i];
		while(j<n)
		{
			if(np[s]) break;
			np[s]=1;
			s=ip[s];
			++j;
		}
		sp[i].seq=j;
	} 
	for(rr int i=1;i<=n;++i)
	{//q
		int j=0,s=q[i];
		while(j<n)
		{
			if(nq[s]) break;
			nq[s]=1;
			s=iq[s];
			++j;
		}
		sq[i].seq=j;
	} 
	sort(sp+1,sp+n+1,cmp);
	sort(sq+1,sq+n+1,cmp);
	int i=1;
	while(sp[i].seq!=0&&i<=n)
	{
		if(sp[i].seq!=sq[i].seq)
		{
			printf("NO");
			return 0;
		}
		for(rr int j=1,qm=q[sq[i].r],pm=p[sp[i].r];j<=sq[i].seq;++j,qm=iq[qm],pm=ip[pm]) h[qm]=pm;
		++i;
	}
	printf("YES\n");
	for(rr int i=1;i<=n;++i) printf("%d ",h[i]);
	return 0;	
} 