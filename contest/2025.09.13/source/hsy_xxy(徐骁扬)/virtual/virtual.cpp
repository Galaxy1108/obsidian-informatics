#include <bits/stdc++.h>
using namespace std;
int Qread()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return x; 
}
int f[8000010];
int get_fa(int a){return (f[a]==a)?a:f[a]=get_fa(f[a]);}
void merge(int u,int v)
{
	if((u=get_fa(u))!=(v=get_fa(v)))
		f[u]=v;
	return;
}
int abl[8000010],n,Q,lk,rk,i,u,v;
int ind[2000010],top,cnt;
int id[2000010];
#define mid (l+r>>1)
#define ls (pos<<1)
#define rs (pos<<1|1)
void init(int pos=1,int l=1,int r=n)
{
	if(l==r) return id[l]=pos,void();
	return init(ls,l,mid),init(rs,mid+1,r);
}
void add_lin(int L,int R,int id,int pos=1,int l=1,int r=n)
{
	if(L<=l&&r<=R) return abl[pos]=true,merge(pos,id);
	if(r<L||R<l) return;
	return add_lin(L,R,id,ls,l,mid),add_lin(L,R,id,rs,mid+1,r);
}
void push_all(int pos=1,int l=1,int r=n)
{
	if(l==r) return;
	if(abl[pos]) merge(pos,ls),merge(pos,rs),abl[ls]=abl[rs]=true;
	return push_all(ls,l,mid),push_all(rs,mid+1,r);
}
char s[2000010];
int main()
{
	freopen("virtual.in","r",stdin);
	freopen("virtual.out","w",stdout);
	n=Qread(),lk=Qread(),rk=Qread();
	for(i=(n<<2);i;i--) f[i]=i;
	init();
	scanf("%s",s+1);
	for(i=1;i<=n;i++)
		if(s[i]=='a')
			ind[++top]=i;
	ind[top+1]=n+1;
	for(i=1;i<=n;i++)
	{
		if(cnt+lk<=top)
			add_lin(ind[cnt+lk],ind[min(cnt+rk+1,top+1)]-1,id[i]);
		if(s[i]=='a') cnt++;
	}
	push_all();
	Q=Qread();
	while(Q--)
	{
		u=Qread(),v=Qread();
		if(get_fa(id[u])==get_fa(id[v])) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}