#include <bits/stdc++.h>
#define Mod 1000000007
using namespace std;
int Qread()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return x;
}
int n;
int h[100010],w[100010];
#define ls (pos<<1)
#define rs (pos<<1|1)
#define mid (l+r>>1)
pair<int,int> mn[400010];
void init(int pos=1,int l=1,int r=n)
{
	if(l==r) mn[pos]=make_pair(h[l],l);
	else init(ls,l,mid),init(rs,mid+1,r),mn[pos]=min(mn[ls],mn[rs]);
}
pair<int,int> qry(int L,int R,int pos=1,int l=1,int r=n)
{
	if(L<=l&&r<=R) return mn[pos];
	if(r<L||R<l) return make_pair(0x3f3f3f3f,0);
	return min(qry(L,R,ls,l,mid),qry(L,R,rs,mid+1,r));
}
#undef ls
#undef rs
#undef mid
long long sumw[100010];
int ans;
int calc(int a){return 1ll*a*(a+1)/2%Mod;}
void solve(int L,int R,int lash)
{
	if(L>R) return;
	pair<int,int> tk=qry(L,R);
	if(tk.first!=lash)
		ans=(ans+(1ll*(tk.first-lash)*lash+calc(tk.first-lash))%Mod*calc((sumw[R]-sumw[L-1])%Mod))%Mod;
	solve(L,tk.second-1,tk.first);
	solve(tk.second+1,R,tk.first);
}
int main()
{
	freopen("fence.in","r",stdin);
	freopen("fence.out","w",stdout);
	n=Qread();
	for(int i=1;i<=n;i++) h[i]=Qread();
	for(int i=1;i<=n;i++) w[i]=Qread();
	for(int i=1;i<=n;i++) sumw[i]=sumw[i-1]+w[i];
	init();
	solve(1,n,0);
	printf("%d\n",ans);
	return 0;
}