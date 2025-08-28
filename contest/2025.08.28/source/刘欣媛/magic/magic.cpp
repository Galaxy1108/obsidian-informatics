#include <bits/stdc++.h>
using namespace std;
long long n,m,a[250005],b[250005],c[250005];
struct tree{
	int l,r;
	long long a,b,c,la,lb,lc,sa,sb,sc;
	bool fl;
}t[2000005];
struct node{
	long long qa,qb,qc;
}ans;
long long p=998244353;
void build(int i,int l,int r)
{
	if(l==r)
	{
		t[i].a=a[l],t[i].b=b[l],t[i].c=c[l];
		t[i].la=t[i].lb=t[i].lc=t[i].fl=t[i].sa=t[i].sb=t[i].sc=0;
		//cout<<i<<" "<<t[i].a<<" "<<t[i].b<<" "<<t[i].c<<"\n";
		return;
	}
	int mid=(l+r)>>1;
	build(i<<1,l,mid);
	build(i<<1|1,mid+1,r);
	t[i].a=t[i<<1].a+t[i<<1|1].a;
	t[i].b=t[i<<1].b+t[i<<1|1].b;
	t[i].c=t[i<<1].c+t[i<<1|1].c;
	t[i].a%=p,t[i].b%=p,t[i].c%=p;
}
void pd(int i,int l,int r)
{
	int mid=(l+r)>>1;
	if(t[i].sa)
	{
		t[i<<1].a+=t[i].sa*t[i<<1].b;
		t[i<<1|1].a+=t[i].sa*t[i<<1|1].b;
		t[i<<1].sa+=t[i].sa;
		t[i<<1|1].sa+=t[i].sa;
		t[i].sa=0;
		t[i<<1].a%=p,t[i<<1|1].a%=p;
		t[i<<1].sa%=p,t[i<<1|1].sa%=p;
	}
	if(t[i].sb)
	{
		t[i<<1].b+=t[i].sb*t[i<<1].c;
		t[i<<1|1].b+=t[i].sb*t[i<<1|1].c;
		t[i<<1].sb+=t[i].sb;
		t[i<<1|1].sb+=t[i].sb;
		t[i].sb=0;
		t[i<<1].b%=p,t[i<<1|1].b%=p;
		t[i<<1].sb%=p,t[i<<1|1].sb%=p;
	}
	if(t[i].sc)
	{
		t[i<<1].c+=t[i].sc*t[i<<1].a;
		t[i<<1|1].c+=t[i].sc*t[i<<1|1].a;
		t[i<<1].sc+=t[i].sc;
		t[i<<1|1].sc+=t[i].sc;
		t[i].sc=0;
		t[i<<1].c%=p,t[i<<1|1].c%=p;
		t[i<<1].sc%=p,t[i<<1|1].sc%=p;
	}
	if(t[i].la)
	{
		t[i<<1].a+=t[i].la*(mid-l+1);
		t[i<<1|1].a+=t[i].la*(r-mid);
		t[i<<1].la+=t[i].la;
		t[i<<1|1].la+=t[i].la;
		t[i].la=0;
		t[i<<1].a%=p,t[i<<1|1].a%=p;
		t[i<<1].la%=p,t[i<<1|1].la%=p;
	}
	if(t[i].lb)
	{
		t[i<<1].b+=t[i].lb*(mid-l+1);
		t[i<<1|1].b+=t[i].lb*(r-mid);
		t[i<<1].lb+=t[i].lb;
		t[i<<1|1].lb+=t[i].lb;
		t[i].lb=0;
		t[i<<1].b%=p,t[i<<1|1].b%=p;
		t[i<<1].lb%=p,t[i<<1|1].lb%=p;
	}
	if(t[i].fl==1)
	{
		t[i<<1].c=t[i].lc*(mid-l+1);
		t[i<<1|1].c=t[i].lc*(r-mid);
		t[i<<1].lc=t[i<<1|1].lc=t[i].lc;
		t[i<<1].fl=t[i<<1|1].fl=1;
		t[i].fl=0;
		t[i<<1].c%=p,t[i<<1|1].c%=p;
		t[i<<1].lc%=p,t[i<<1|1].lc%=p;
		return;
	}
	if(t[i].lc)
	{
		t[i<<1].c+=t[i].lc*(mid-l+1);
		t[i<<1|1].c+=t[i].lc*(r-mid);
		t[i<<1].lc+=t[i].lc;
		t[i<<1|1].lc+=t[i].lc;
		t[i].lc=0;
		t[i<<1].c%=p,t[i<<1|1].c%=p;
		t[i<<1].lc%=p,t[i<<1|1].lc%=p;
	}
}
void q(int i,int l,int r,int s,int tt)
{
	//cout<<i<<" ";
	t[i].a=t[i<<1].a+t[i<<1|1].a;
	t[i].b=t[i<<1].b+t[i<<1|1].b;
	t[i].c=t[i<<1].c+t[i<<1|1].c;
	t[i].a%=p,t[i].b%=p,t[i].c%=p;
	if(l>=s&&r<=tt)
	{
		pd(i,l,r);
		ans.qa+=t[i].a;
		ans.qb+=t[i].b;
		ans.qc+=t[i].c;
		ans.qa%=p,ans.qb%=p,ans.qc%=p;
		return ;
		
	}
	pd(i,l,r);
	int mid=(l+r)>>1;
	if(mid>=s)q(i<<1,l,mid,s,tt);
	if(mid<tt)q(i<<1|1,mid+1,r,s,tt);
}
void c1(int i,int l,int r,int s,int tt,int type)
{
	if(l>=s&&r<=tt)
	{
		if(type==1)
		{
			t[i].sa++;
			t[i].a+=t[i].b;
			t[i].a%=p;
		}
		if(type==2)
		{
			t[i].sb++;
			t[i].b+=t[i].c;
			t[i].b%=p;
		}
		if(type==3)
		{
			t[i].sc++;
			t[i].c+=t[i].a;
			t[i].c%=p;
		}
		pd(i,l,r);
		return;
	}
	pd(i,l,r);
	int mid=(l+r)>>1;
	if(mid>=s) c1(i<<1,l,mid,s,tt,type);
	if(mid<tt) c1(i<<1|1,mid+1,r,s,tt,type);
	
}
void c2(int i,int l,int r,int s,int tt,long long v,int type)
{
	if(l>=s&&r<=tt)
	{
		if(type==1)
		{
			t[i].la+=v;
			t[i].a+=v*(l-r+1);
			t[i].a%=p;
		}
		if(type==2)
		{
			long long k=v*(t[i].b-1);
			k%=p;
			t[i].lb+=k;
			t[i].b+=k*(l-r+1);
			t[i].b%=p;
		}
		if(type==3)
		{
			t[i].lc=v;
			t[i].fl=1;
			t[i].c=v*(l-r+1);
			t[i].c%=p;
		}
		pd(i,l,r);
		return;
	}
	pd(i,l,r);
	int mid=(l+r)>>1;
	if(mid>=s) c2(i<<1,l,mid,s,tt,v,type);
	if(mid<tt) c2(i<<1|1,mid+1,r,s,tt,v,type);
	
}
int main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i]>>c[i];
	}
	build(1,1,n);
//	for(int i=1;i<=n*2;i++)
//	{
//		cout<<i<<" "<<t[i].a<<" "<<t[i].b<<" "<<t[i].c<<"\n";
//	}
	cin>>m;
	int o,l,r,v;
	if(m<=50000)
	{
		while(m--)
		{
			cin>>o>>l>>r;
			if(o==1)
			{
				for(int i=l;i<=r;i++) a[i]+=b[i],a[i]%=p;
			}
			if(o==2)
			{
				for(int i=l;i<=r;i++) b[i]+=c[i],b[i]%=p;
			}
			if(o==3)
			{
				for(int i=l;i<=r;i++) c[i]+=a[i],c[i]%=p;
			}
			if(o==4){
				cin>>v;
				for(int i=l;i<=r;i++) a[i]+=v,a[i]%=p;
			} 
			if(o==5){
				cin>>v;
				for(int i=l;i<=r;i++) b[i]*=v,b[i]%=p;
			} 
			if(o==6){
				cin>>v;
				for(int i=l;i<=r;i++) c[i]=v;
			} 
			if(o==7)
			{
				long long ra=0,rb=0,rc=0;
				for(int i=l;i<=r;i++) {
					ra+=a[i],rb+=b[i],rc+=c[i];
					ra%=p,rb%=p,rc%=p;
				}
				cout<<ra<<" "<<rb<<" "<<rc<<"\n";
			}
		}
		
	}
	
	for(int i=1;i<=m;i++)
	{
		cin>>o>>l>>r;
		if(o>=4&&o<=6)
		{
			cin>>v;
			c2(1,1,n,l,r,v,o-3);
			//cout<<i<<"\n";
		}
		else if(o>=1&&o<=3)
		{
			c1(1,1,n,l,r,o);
			//cout<<i<<"\n";
		}
		else
		{
			ans.qa=ans.qb=ans.qc=0;
			q(1,1,n,l,r);
			cout<<ans.qa<<" "<<ans.qb<<" "<<ans.qc<<"\n";
		}
	}
//	for(int i=1;i<=n*2;i++)
//	{
//		cout<<i<<" "<<t[i].a<<" "<<t[i].b<<" "<<t[i].c<<"\n";
//	}	

	return 0;
} 
