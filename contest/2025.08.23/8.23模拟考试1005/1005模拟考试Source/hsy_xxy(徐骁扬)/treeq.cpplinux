#include <bits/stdc++.h>
using namespace std;
int Qread()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x;
}
struct Point{
	int fa,siz,sons,nxt;
	long long len;
}p[1000010];
struct Xds{
	long long maxn;
	int pas,ind1,ind2;
}s[8000010];
int f[1000010];
#define mid (l+r>>1)
#define ls (pos<<1)
#define rs ((pos<<1)+1)
int lim;
void update(int pos)
{
	if(s[ls].maxn>s[rs].maxn) s[pos].maxn=s[ls].maxn,s[pos].pas=s[ls].pas;
	else if(s[rs].maxn>s[ls].maxn) s[pos].maxn=s[rs].maxn,s[pos].pas=s[rs].pas;
	else
	{
		s[pos].maxn=s[rs].maxn;
		s[pos].pas=pos,s[pos].ind1=s[ls].pas,s[pos].ind2=s[rs].pas;
	}
	return;
}
void build(int pos=1,int l=2,int r=lim)
{
	if(l==r) return s[pos].maxn=p[l].len*p[l].siz,s[pos].pas=pos,s[pos].ind2=l,void();
	else return build(ls,l,mid),build(rs,mid+1,r),update(pos);
}
void change_num(int k,long long num,int pos=1,int l=2,int r=lim)
{
	if(l==r) return s[pos].maxn=num,void();
	if(k<=mid) return change_num(k,num,ls,l,mid),update(pos);
	return change_num(k,num,rs,mid+1,r),update(pos);
}
void get_solve(int pos=1)
{
	if(s[pos].pas==pos)
	{
		if(s[pos].ind1) return get_solve(s[pos].ind1),get_solve(s[pos].ind2);
		else return f[s[pos].ind2]++,void();
	}
	return get_solve(s[pos].pas);
}
#undef mid
#undef ls
#undef rs
int n,i,ans;
void sfd(int a)
{
	if(a!=1) change_num(a,p[a].len*(n-p[a].siz));
	get_solve();
	for(int k=p[a].sons;k;k=p[k].nxt)
		sfd(k);
	if(a!=1) change_num(a,p[a].len*p[a].siz);
	return;
}
int main()
{
	freopen("treeq.in","r",stdin);
	freopen("treeq.out","w",stdout);
	n=Qread();lim=n;
	for(i=2;i<=n;i++)
	{
		p[i].fa=Qread(),p[i].len=Qread();
		p[i].nxt=p[p[i].fa].sons;
		p[p[i].fa].sons=i;
	}
	for(i=n;i>=1;i--)
		p[p[i].fa].siz+=(++p[i].siz);
	build();
	sfd(1);
	for(i=2;i<=n;i++)
		ans^=f[i];
	printf("%d\n",ans);
	return 0;
}