/*
一道好题的代码可以长，但一定不是通过强行嵌套或者增加条件而让代码变长，
而是长得自然，让人感觉这个题的代码就应该是这么长。

opt4
pushdown opt1,2,3,4,5,6
a=a*v
opt5
pushdown opt1,2,3,4,5,6
b=b+v
opt6
pushdown opt1,2,3,4,5,6
c=v
opt7
q
*/
#include<bits/stdc++.h>
using namespace std;
#define XaoWa118 998244353
#define int long long
long long n,m,sa[500005],sb[500005],sc[500005],op,lll,rrr,vvv;
struct trip
{
	long long a,b,c;
};
trip anss;
struct mat
{
	long long num[5][5],n,m;
};
mat opt0,opt1,opt2,opt3,opt4,opt5,opt6,tmp; 
mat operator* (const mat& x,const mat& y)
{
	mat z;
	z.n=x.n;
	z.m=y.m; 
	for(int i = 1; i <= x.n; i++)
	{
		for(int j = 1; j <= y.m; j++)
		{
			z.num[i][j]=0;	
		}
	}
	for(int k = 1; k <= x.m; k++)
	{
		for(int i = 1; i <= x.n; i++)
		{
			for(int j = 1; j <= y.m; j++)
			{
				z.num[i][j]+=x.num[i][k]*y.num[k][j];
				z.num[i][j]%=XaoWa118;
			}
		}
	}
	return z;
}
mat operator% (const mat& x,const int& y)
{
	mat z;
	z.n=x.n;
	z.m=x.m;
	for(int i = 1; i <= x.n; i++)
	{
		for(int j = 1; j <= x.m; j++)
		{
			z.num[i][j]=x.num[i][j]%y;
		}
	}
	return z;
} 
struct seg_tree
{
	struct node
	{
	    long long l,r;
	    bool ischg;
	    mat opttot,ths;
	} t[1000005];
	void build(int p,int l,int r)
	{
	    t[p].l=l;
	    t[p].r=r;
	    t[p].ths.n=1;
		t[p].ths.m=4;
	    if(l==r)
	    {
	    	t[p].ischg=0;
	    	t[p].opttot=opt0;
	    	t[p].ths.num[1][1]=sa[l];
	    	t[p].ths.num[1][2]=sb[l];
	    	t[p].ths.num[1][3]=sc[l];
	    	t[p].ths.num[1][4]=1;
	        return;
	    }
	    int mid=(l+r)/2;
	    build(p*2,l,mid);
	    build(p*2+1,mid+1,r);
	    t[p].opttot=opt0;
	    t[p].ischg=0;
	    t[p].ths.num[1][1]=(t[p*2].ths.num[1][1]+t[p*2+1].ths.num[1][1])%XaoWa118;
	    t[p].ths.num[1][2]=(t[p*2].ths.num[1][2]+t[p*2+1].ths.num[1][2])%XaoWa118;
	    t[p].ths.num[1][3]=(t[p*2].ths.num[1][3]+t[p*2+1].ths.num[1][3])%XaoWa118;
	    t[p].ths.num[1][4]=(t[p*2].ths.num[1][4]+t[p*2+1].ths.num[1][4]);
	    return;
	}
	void pushup(int p)
	{
		t[p].ths.num[1][1]=(t[p*2].ths.num[1][1]+t[p*2+1].ths.num[1][1])%XaoWa118;
	    t[p].ths.num[1][2]=(t[p*2].ths.num[1][2]+t[p*2+1].ths.num[1][2])%XaoWa118;
	    t[p].ths.num[1][3]=(t[p*2].ths.num[1][3]+t[p*2+1].ths.num[1][3])%XaoWa118;
	    t[p].ths.num[1][4]=(t[p*2].ths.num[1][4]+t[p*2+1].ths.num[1][4]);
	    return;
	}
	void pushdown(int p)
	{
		if(t[p].ischg)
		{
			t[p*2].ischg=t[p*2+1].ischg=1;
			t[p*2].ths=(t[p*2].ths*t[p].opttot)%XaoWa118;
			t[p*2+1].ths=(t[p*2+1].ths*t[p].opttot)%XaoWa118;
			t[p*2].opttot=(t[p*2].opttot*t[p].opttot)%XaoWa118;
			t[p*2+1].opttot=(t[p*2+1].opttot*t[p].opttot)%XaoWa118;
			t[p].opttot=opt0;
			t[p].ischg=0;
		}
	    return;
	}
	void update_opt1(int p,int l,int r)
	{
	    if(t[p].l>=l&&t[p].r<=r)
	    {
	    	t[p].ischg=1;
	        t[p].opttot=(t[p].opttot*opt1)%XaoWa118;
	        t[p].ths.num[1][1]+=t[p].ths.num[1][2];
	        t[p].ths.num[1][1]%=XaoWa118;
	        return;
	    }
	    pushdown(p);
	    int mid=(t[p].l+t[p].r)/2;
	    if(l<=mid) update_opt1(p*2,l,r);
	    if(r>mid) update_opt1(p*2+1,l,r);
	    pushup(p);
	    return; 
	}
	void update_opt2(int p,int l,int r)
	{
	    if(t[p].l>=l&&t[p].r<=r)
	    {
	    	t[p].ischg=1;
	        t[p].opttot=(t[p].opttot*opt2)%XaoWa118;
	        t[p].ths.num[1][2]+=t[p].ths.num[1][3];
	        t[p].ths.num[1][2]%=XaoWa118;
	        return;
	    }
	    pushdown(p);
	    int mid=(t[p].l+t[p].r)/2;
	    if(l<=mid) update_opt2(p*2,l,r);
	    if(r>mid) update_opt2(p*2+1,l,r);
	    pushup(p);
	    return; 
	}
	void update_opt3(int p,int l,int r)
	{
	    if(t[p].l>=l&&t[p].r<=r)
	    {
	    	t[p].ischg=1;
	        t[p].opttot=(t[p].opttot*opt3)%XaoWa118;
	        t[p].ths.num[1][3]+=t[p].ths.num[1][1];
	        t[p].ths.num[1][3]%=XaoWa118;
	        return;
	    }
	    pushdown(p);
	    int mid=(t[p].l+t[p].r)/2;
	    if(l<=mid) update_opt3(p*2,l,r);
	    if(r>mid) update_opt3(p*2+1,l,r);
	    pushup(p);
	    return; 
	}
	void update_opt4(int p,int l,int r,int d)
	{
	    if(t[p].l>=l&&t[p].r<=r)
	    {
	    	opt4.num[4][1]=d;
	    	t[p].ischg=1;
	        t[p].opttot=(t[p].opttot*opt4)%XaoWa118;
	        t[p].ths.num[1][1]+=(t[p].r-t[p].l+1)*d;
	        t[p].ths.num[1][1]%=XaoWa118;
	        return;
	    }
	    pushdown(p);
	    int mid=(t[p].l+t[p].r)/2;
	    if(l<=mid) update_opt4(p*2,l,r,d);
	    if(r>mid) update_opt4(p*2+1,l,r,d);
	    pushup(p);
	    return; 
	}
	void update_opt5(int p,int l,int r,int d)
	{
	    if(t[p].l>=l&&t[p].r<=r)
	    {
	    	opt5.num[2][2]=d;
	    	t[p].ischg=1;
	        t[p].opttot=(t[p].opttot*opt5)%XaoWa118;
	        t[p].ths.num[1][2]*=d;
	        t[p].ths.num[1][2]%=XaoWa118;
	        return;
	    }
	    pushdown(p);
	    int mid=(t[p].l+t[p].r)/2;
	    if(l<=mid) update_opt5(p*2,l,r,d);
	    if(r>mid) update_opt5(p*2+1,l,r,d);
	    pushup(p);
	    return; 
	}
	void update_opt6(int p,int l,int r,int d)
	{
	    if(t[p].l>=l&&t[p].r<=r)
	    {
	    	opt6.num[4][3]=d;
	    	t[p].ischg=1;
	        t[p].opttot=(t[p].opttot*opt6)%XaoWa118;
	        t[p].ths.num[1][3]=(t[p].r-t[p].l+1)*d;
	        t[p].ths.num[1][3]%=XaoWa118;
	        return;
	    }
	    pushdown(p);
	    int mid=(t[p].l+t[p].r)/2;
	    if(l<=mid) update_opt6(p*2,l,r,d);
	    if(r>mid) update_opt6(p*2+1,l,r,d);
	    pushup(p);
	    return; 
	}
	trip query(int p,int l,int r)
	{
		//cout<<"ssddsfdsf"<<" "<<p<<" "<<l<<" "<<r<<endl;
	    if(t[p].l>=l&&t[p].r<=r)
	    {
	        return {t[p].ths.num[1][1],t[p].ths.num[1][2],t[p].ths.num[1][3]};
	    }
	    pushdown(p);
	    int mid=(t[p].l+t[p].r)/2;
	    trip res={0,0,0},tmp;
	    if(l<=mid)
	    {
	    	tmp=query(p*2,l,r);
	    	res.a+=tmp.a;
	    	res.b+=tmp.b;
	    	res.c+=tmp.c;
		}
	    if(r>mid)
	    {
	    	tmp=query(p*2+1,l,r);
	    	res.a+=tmp.a;
	    	res.b+=tmp.b;
	    	res.c+=tmp.c;
		}
		res.a%=XaoWa118;
	    res.b%=XaoWa118;
	    res.c%=XaoWa118;
		//cout<<"sdflkhkf"<<" "<<res.a<<" "<<res.b<<" "<<res.c<<endl;
	    return res;
	}
	void test(int p)
	{
		cout<<"id: "<<p<<endl;
		cout<<"a,b,c: "<<t[p].ths.num[1][1]<<" "<<t[p].ths.num[1][2]<<" "<<t[p].ths.num[1][3]<<endl;
		cout<<"l,r: "<<t[p].l<<" "<<t[p].r<<endl;
		//cout<<"islzt: "<<t[p].isopt<<endl;
		for(int i = 1; i <= 4; i++)
		{
			for(int j = 1; j <= 4; j++)
			{
				cout<<t[p].opttot.num[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}
} t;
signed main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	opt0.n=opt0.m=4;
	opt1.n=opt1.m=4;
	opt2.n=opt2.m=4;
	opt3.n=opt3.m=4;
	opt4.n=opt4.m=4;
	opt5.n=opt5.m=4;
	opt6.n=opt6.m=4;
	for(int i = 1; i <= 4; i++)
	{
		for(int j = 1; j <= 4; j++)
		{
			if(i==j) opt0.num[i][j]=1;
			else opt0.num[i][j]=0;
		}
	}
	for(int i = 1; i <= 4; i++)
	{
		for(int j = 1; j <= 4; j++)
		{
			if(i==j) opt4.num[i][j]=1;
			else opt4.num[i][j]=0;
		}
	}
	for(int i = 1; i <= 4; i++)
	{
		for(int j = 1; j <= 4; j++)
		{
			if(i==j) opt5.num[i][j]=1;
			else opt5.num[i][j]=0;
		}
	}
	for(int i = 1; i <= 4; i++)
	{
		for(int j = 1; j <= 4; j++)
		{
			if(i==j&&i!=3) opt6.num[i][j]=1;
			else opt6.num[i][j]=0;
		}
	}
	for(int i = 1; i <= 4; i++)
	{
		for(int j = 1; j <= 4; j++)
		{
			if(i==j||(i==2&&j==1)) opt1.num[i][j]=1;
			else opt1.num[i][j]=0;
		}
	}
	for(int i = 1; i <= 4; i++)
	{
		for(int j = 1; j <= 4; j++)
		{
			if(i==j||(i==3&&j==2)) opt2.num[i][j]=1;
			else opt2.num[i][j]=0;
		}
	}
	for(int i = 1; i <= 4; i++)
	{
		for(int j = 1; j <= 4; j++)
		{
			if(i==j||(i==1&&j==3)) opt3.num[i][j]=1;
			else opt3.num[i][j]=0;
		}
	}
	scanf("%lld",&n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%lld%lld%lld",&sa[i],&sb[i],&sc[i]);
	}
	t.build(1,1,n);
	scanf("%lld",&m);
	for(int i = 1; i <= m; i++)
	{
		scanf("%lld",&op);
		if(op==1)
		{
			scanf("%lld%lld",&lll,&rrr);
			t.update_opt1(1,lll,rrr);
		}
		else if(op==2)
		{
			scanf("%lld%lld",&lll,&rrr);
			t.update_opt2(1,lll,rrr);
		}
		else if(op==3)
		{
			scanf("%lld%lld",&lll,&rrr);
			t.update_opt3(1,lll,rrr);
		}
		else if(op==4)
		{
			scanf("%lld%lld%lld",&lll,&rrr,&vvv);
			t.update_opt4(1,lll,rrr,vvv);
		}
		else if(op==5)
		{
			scanf("%lld%lld%lld",&lll,&rrr,&vvv);
			t.update_opt5(1,lll,rrr,vvv);
		}
		else if(op==6)
		{
			scanf("%lld%lld%lld",&lll,&rrr,&vvv);
			t.update_opt6(1,lll,rrr,vvv);
		}
		else if(op==7)
		{
			scanf("%lld%lld",&lll,&rrr);
			anss=t.query(1,lll,rrr);
			printf("%lld %lld %lld\n",anss.a,anss.b,anss.c);
			//cout<<anss.a<<" "<<anss.b<<" "<<anss.c<<endl;
		}
		/*for(int i = 1; i <= 10; i++)
		{
			t.test(i);
		}*/
	}
} 
