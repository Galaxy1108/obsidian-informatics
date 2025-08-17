#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
int n,q;
ull s1,s2;
int a[10000005];
__int128 ans=0;
ull res[10000005];
ull p[10000005];
int len=0;
struct tree
{
	ull l,r,dat,add;
}s[4*10000005];
void pushup(int p)
{
	s[p].dat=s[p*2].dat+s[p*2+1].dat;
	return; 
} 
void addtag(int p,ull x)
{
	s[p].dat+=(s[p].r-s[p].l+1)*x;
	s[p].add+=x;
}
void pushdown(int p)
{
	if(s[p].add)
	{
		addtag(p*2,s[p].add);
		addtag(p*2+1,s[p].add);
		s[p].add=0;
	}
}
void build(int p,ull l,ull r)
{
	s[p].l=l;
	s[p].r=r;
	if(l==r)
	{
		s[p].dat=0;
		return;
	}
	ull mid=(l+r)/2;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	pushup(p);
}
void update(int p,int x,ull k)
{
	if(s[p].l==s[p].r)
	{
		addtag(p,k);
		return;
	}
	pushdown(p);
	int mid=(s[p].l+s[p].r)/2;
	if(mid>=x)
	{
		update(p*2,x,k);
	}
	else
	{
		update(p*2+1,x,k);
	}
	pushup(p);
	return;
}
ull query(int p,ull l,ull r)
{
	if(s[p].l>=l&&s[p].r<=r)
	{
		return s[p].dat;
	}
	pushdown(p);
	ull tot=0;
	ull mid=(s[p].l+s[p].r)/2;
	if(l<=mid)
	{
		tot+=query(p*2,l,r);
	}
	if(mid<r)
	{
		tot+=query(p*2+1,l,r);
	}
	return tot;
}
ull my_rand()
{
    ull s3=s1,s4=s2;
    s1=s2^774527;
    s3^=(s3<<47)^(s3>>13);
    s2^=s3^(s4<<31)^(s4>>17);
    return s2+s4;
}
void get_query(int &op,ull &num1,ull &num2)
{
    op=my_rand()%2+1;
    if(op==1)
    {
        num1=my_rand()%n+1;
        num2=my_rand()%n+1;
    }
    else
    {
        num1=my_rand()%n+1;
        num2=my_rand()%n+1;
        if(num1>num2)
             swap(num1,num2);
    }
    
}
//------------------------
ull lowbit(ull x)
{
	return x&(-x);
}
void add(ull x,ull k)
{
	for(;x<=n;x+=lowbit(x))
	{
		update(1,x,k);
		a[x]+=k;
	}
	return;
}
void ask(ull x,ull y,int id)
{
	if(x>y)
	{
		swap(x,y);
	}
	res[++len]=query(1,x,y);
	p[len]=id;
}
void write(__int128 a)
{
	if(a>=0&&a<=9)
	{
		putchar(a+'0');
		return;
	}
	write(a/10);
	write(a%10);
	return;
}
int main()
{
	freopen("fenwick.in","r",stdin);
	freopen("fenwick.out","w",stdout);
	cin>>n>>q>>s1>>s2;
	int op;
	ull num1,num2;
	build(1,1,n);
	for(int i=1;i<=q;i++)
	{
		get_query(op,num1,num2);
		if(op==1)
		{
			add(num1,num2);
		}
		if(op==2)
		{
			ask(num1,num2,i);
		}
	}
	for(int i=1;i<=len;i++)
	{
		ans^=p[i]*res[i];
	}
	write(ans);
}
