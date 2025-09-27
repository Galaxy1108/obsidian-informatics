#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=100002;
ll a[N],tree[N<<2],tag[N<<2];//n<<2==n*4
ll ls(ll p)
{
	return p<<1;//x<<1==x*2
}
ll rs(ll p)
{
	return p<<1|1;
}
void push_up(ll p)
{
	tree[p]=max(tree[ls(p)],tree[rs(p)]);
}
void build(ll p,ll pl,ll pr)
{
	tag[p]=0;
	if(pl==pr)
	{
		tree[p]=a[pl];
		return;
	}
	ll mid=(pl+pr)>>1;
	build(ls(p),pl,mid);
	build(rs(p),mid+1,pr);
	push_up(p);
}
void add_tag(ll p,ll pl,ll pr,ll d)
{
	tag[p]+=d;
	tree[p]+=d*(pr-pl+1);
}
void push_down(ll p,ll pl,ll pr)
{
	if(tag[p])
	{
		ll mid=(pl+pr)>>1;
		add_tag(ls(p),pl,mid,tag[p]);
		add_tag(rs(p),mid+1,pr,tag[p]);
		tag[p]=0;
	}
}
void update(ll L,ll R,ll p,ll pl,ll pr,ll d)
{
	if(L<=pl&&pr<=R)
	{
		add_tag(p,pl,pr,d);
		return;
	}
	push_down(p,pl,pr);
	ll mid=(pl+pr)>>1;
	if(L<=mid)
		update(L,R,ls(p),pl,mid,d);
	if(mid+1<=R)
		update(L,R,rs(p),mid+1,pr,d);
	push_up(p);
}
ll query(ll L,ll R,ll p,ll pl,ll pr)
{
	if(L<=pl&&pr<=R)
		return tree[p];
	push_down(p,pl,pr);
	ll w=0;
	ll mid=(pl+pr)>>1;
	if(L<=mid)
		w=max(w,query(L,R,ls(p),pl,mid));
	if(mid+1<=R)
		w=max(w,query(L,R,rs(p),mid+1,pr));
	return w;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	build(1,1,n);
	int tot=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(i==j)
			{
				tot++;
			}
			else
			{
				ll yh=a[j];
				ll maxn=0;
				for(int k=j+1;k<=i;k++)
				{
					yh=yh^a[k];
				}
				/*for(int k=j;k<=i;k++)
				{
					maxn=max(maxn,a[k]);
//					cout<<a[k]<<endl;
				}*/
				maxn=query(j,i,1,1,n);
//				cout<<yh<< " "<<maxn<<endl;
				if(maxn>=yh)
				{
					tot++;
//					cout<<j<<" "<<i<<endl;
				}
			}
		}
	}
	cout<<tot;
	/*	while(m--)
{
	cin>>q;
	if(q==1)
{
	cin>>L>>R>>d;
	update(L,R,1,1,n,d);
	}
	else
{
	cin>>L>>R;
	cout<<query(L,R,1,1,n)<<'\n';
	}
	}*/
	return 0;
}
