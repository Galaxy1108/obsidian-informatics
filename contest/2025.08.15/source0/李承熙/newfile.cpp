#include<bits/stdc++.h>
using namespace std;
#define mod 1000000009 
inline void Mod(int &x)
{
	if(x<0)x+=mod;
	if(x>=mod)x-=mod;
	return ;
}
inline int qread()
{
	int a=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){(a*=10)+=(ch^48);ch=getchar();}
	return a*f;
}
int n,m,q,ans[100010],L[100010],R[100010],X[100010];
struct node
{
	int l,r,id,op;
};
vector<node>S[100010];
struct seg
{
	#define ls (rt<<1)
	#define rs (rt<<1|1)
	#define mid ((l+r)>>1) 
	int val[400010],sum[400010],tim[400010],tag_x[400010],tag_t[400010],tag_s[400010];
	inline void add_tag(int rt,int l,int r,int x,int ti,int s)
	{
		sum[rt]=(1ll*sum[rt]+1ll*val[rt]*(ti-tim[rt]))%mod;
		tim[rt]=ti;val[rt]=(1ll*val[rt]+1ll*x*(r-l+1))%mod;sum[rt]=(1ll*sum[rt]+1ll*s*(r-l+1))%mod;
		tag_s[rt]=(1ll*tag_s[rt]+1ll*(ti-tag_t[rt])*(tag_x[rt]))%mod;Mod(tag_s[rt]+=s);
		Mod(tag_x[rt]+=x);tag_t[rt]=ti;
		return ;
	}
	inline void push_down(int rt,int l,int r)
	{
		if(tag_t[rt])
		{
			add_tag(ls,l,mid,tag_x[rt],tag_t[rt],tag_s[rt]);
			add_tag(rs,mid+1,r,tag_x[rt],tag_t[rt],tag_s[rt]);
			tag_x[rt]=tag_t[rt]=tag_s[rt]=0;
		}
		return ;
	}
	inline void upd(int rt,int l,int r)
	{
		if(tim[ls]^tim[rs])
		{
			push_down(rt,l,r);
			if(tim[ls]<tim[rs])add_tag(ls,l,mid,0,tim[rs],0);
			else add_tag(rs,mid+1,r,0,tim[ls],0);
		}
		tim[rt]=tim[ls];
		Mod(val[rt]=val[ls]+val[rs]);
		Mod(sum[rt]=sum[ls]+sum[rs]);
		return ;
	}
	inline void adds(int L,int R,int x,int ti,int rt=1,int l=1,int r=n)
	{
		if(L<=l&&r<=R)return add_tag(rt,l,r,x,ti,0);
		push_down(rt,l,r);
		if(L<=mid)adds(L,R,x,ti,ls,l,mid);
		if(R>mid)adds(L,R,x,ti,rs,mid+1,r);
		return upd(rt,l,r);
	}
	inline int Q(int L,int R,int ti,int rt=1,int l=1,int r=n)
	{
		if(L<=l&&r<=R)return (1ll*sum[rt]+1ll*val[rt]*(ti-tim[rt]+1))%mod;
		int an=0;
		push_down(rt,l,r);
		if(L<=mid)Mod(an+=Q(L,R,ti,ls,l,mid)); 
		if(R>mid)Mod(an+=Q(L,R,ti,rs,mid+1,r));
		return an;
	}
}t;
int main()
{
	freopen("newfile.in","r",stdin);
	freopen("newfile.out","w",stdout);
	n=qread();m=qread();q=qread();
	for(int i=1;i<=m;++i)L[i]=qread(),R[i]=qread(),X[i]=qread();
	for(int i=1,u,d,l,r;i<=q;++i)
	{
		u=qread();d=qread();l=qread();r=qread();
		if(u)S[u-1].emplace_back((node){l,r,i,-1});
		S[d].emplace_back((node){l,r,i,1});
	}
	for(int i=1;i<=m;++i)
	{
		t.adds(L[i],R[i],X[i],i);
		for(node j:S[i])ans[j.id]=(1ll*ans[j.id]+1ll*t.Q(j.l,j.r,i)*j.op)%mod; 
	}
	for(int i=1;i<=q;++i)Mod(ans[i]),printf("%d\n",ans[i]);
	return 0;	
}
