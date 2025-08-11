#include <bits/stdc++.h>
using namespace std;
int Qread()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return x;
}

int n,Q,hfn;
int p[200010];
#define ls (pos<<1)
#define rs (pos<<1|1)
#define mid (l+r>>1)
int mx[800010];
void init(int pos=1,int l=1,int r=n)
{
	if(l==r) mx[pos]=p[l];
	else init(ls,l,mid),init(rs,mid+1,r),mx[pos]=max(mx[ls],mx[rs]);
}
//get the smallest i that in [L,R] ans p_i > k
int query(int L,int R,int k,int pos=1,int l=1,int r=n)
{
	if(L<=l&&r<=R)
	{
		if(mx[pos]<=k) return R+1;
		if(l==r) return l;
		if(mx[ls]>k) return query(L,R,k,ls,l,mid);
		else return query(L,R,k,rs,mid+1,r);
	}
	if(r<L||R<l) return R+1;
	int ret=query(L,R,k,ls,l,mid);
	if(ret==R+1) return query(L,R,k,rs,mid+1,r);
	return ret;
}
#undef ls
#undef rs
#undef mid

#define ls s[pos].lson
#define rs s[pos].rson
mt19937 zsh(20070610);
struct Node{
	int lson,rson;
	int L,R,siz;
	unsigned int key;
}s[200010];
int poi_cnt;
int get_node(int L,int R)
{
	s[++poi_cnt].key=zsh();
	s[poi_cnt].L=L,s[poi_cnt].R=R,s[poi_cnt].siz=R-L+1;
	return poi_cnt;
}
void update(int pos){s[pos].siz=s[ls].siz+s[rs].siz+s[pos].R-s[pos].L+1;}
void split(int rt,int k,int &x,int &y)
{
	if(rt==0) return x=y=0,void();
	if(s[s[rt].lson].siz+s[rt].R-s[rt].L+1<=k)
		return x=rt,split(s[rt].rson,k-(s[s[rt].lson].siz+s[rt].R-s[rt].L+1),s[x].rson,y),update(rt); 
	else
		return y=rt,split(s[rt].lson,k,x,s[y].lson),update(rt);
}
void split_val(int rt,int k,int &x,int &y)
{
	if(rt==0) return x=y=0,void();
	if(p[s[rt].L]<=k)
		return x=rt,split_val(s[rt].rson,k,s[x].rson,y),update(x);
	else
		return y=rt,split_val(s[rt].lson,k,x,s[y].lson),update(y);
}
int merge(int u,int v)
{
	if(u&&v)
	{
		if(s[u].key<s[v].key) return s[u].rson=merge(s[u].rson,v),update(u),u;
		else return s[v].lson=merge(u,s[v].lson),update(v),v;
	}
	return u^v;
}
int get_kth(int k,int pos)
{
	if(k<=s[ls].siz) return get_kth(k,ls);
	k-=s[ls].siz;
	if(k<=s[pos].R-s[pos].L+1) return p[s[pos].L+k-1];
	k-=s[pos].R-s[pos].L+1;
	return get_kth(k,rs);
}
int get_lft_mst(int &pos)
{
	if(s[pos].lson) 
	{
		int ret=get_lft_mst(s[pos].lson);
		update(pos);
		return ret;
	}
	int ret=pos;
	pos=s[pos].rson;
	return ret;
}
void insert_node(int &x,int t)
{
	if(!x) x=t;
	else if(s[x].key>s[t].key) return split_val(x,p[s[t].L],s[t].lson,s[t].rson),update(x=t);
	else if(p[s[t].L]<p[s[x].L]) return insert_node(s[x].lson,t),update(x);
	else return insert_node(s[x].rson,t),update(x);
}
#undef ls
#undef rs

typedef pair<int,int> pr;
pr num[200010];int tot;

void build_tree(int &pos,int l,int r)
{
	if(l>r) return;
	else if(l==r) pos=get_node(num[l].first,num[l].second);
	else
	{
		int mid=(l+r>>1);
		pos=get_node(num[mid].first,num[mid].second);
		build_tree(s[pos].lson,l,mid-1),build_tree(s[pos].rson,mid+1,r);
		update(pos);
	}
}

struct Query{
	int t,x,ind;
}qry[1000010];
bool operator<(Query A,Query B){return A.t<B.t;}
int rt,L,R,las,sd,t;
int fl=1;
int ans[1000010];
int main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	
	n=Qread(),Q=Qread();hfn=n/2;
	for(int i=1;i<=n;i++) p[i]=Qread();
	for(int i=1;i<=Q;i++) qry[i].t=Qread(),qry[i].x=Qread(),qry[i].ind=i;
	init();
	
	las=L=1,R=hfn;
	while(las<=R)
	{
		sd=query(L,R,p[las]);
		if(las)	num[++tot]=make_pair(las,sd-1);
		las=sd;
	}
	las=L=hfn+1,R=n;
	while(las<=R)
	{
		sd=query(L,R,p[las]);
		if(las) num[++tot]=make_pair(las,sd-1);
		las=sd; 
	}

	sort(num+1,num+tot+1,[&](pr A,pr B){return p[A.first]<p[B.first];});
	build_tree(rt,1,tot);

	sort(qry+1,qry+Q+1);
	while(fl<=Q&&qry[fl].t==0)
		ans[qry[fl].ind]=p[qry[fl].x],fl++;

	for(int i=1,x,y;fl<=Q;i++)
	{
		while(fl<=Q&&qry[fl].t==i)
			ans[qry[fl].ind]=get_kth(qry[fl].x,rt),fl++;

		split(rt,hfn,x,y);

		if(s[x].siz==hfn)
		{
			rt=merge(x,y);
			break;
		}
		t=get_lft_mst(y);

		las=L=s[t].L+(hfn-s[x].siz),R=s[t].R;
		s[t].R=s[t].L+(hfn-s[x].siz)-1,s[t].lson=s[t].rson=0,s[t].siz=s[t].R-s[t].L+1;
		
		insert_node(x,t);

		while(las<=R)
		{
			sd=query(L,R,p[las]);
			if(las) insert_node(x,get_node(las,sd-1));
			las=sd;
		}
		rt=merge(x,y);
	}

	while(fl<=Q)
		ans[qry[fl].ind]=get_kth(qry[fl].x,rt),fl++;
	for(int i=1;i<=Q;i++)
		printf("%d\n",ans[i]);
	return 0;
}