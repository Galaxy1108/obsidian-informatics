#include<bits/stdc++.h>
#define int long long
//#pragma GCC optimize(2)
using namespace std;
const int mod=998244353;
const int mx=25e4+100;
struct tree
{
	int l,r;
	long long num[4],tag2[4];
}t[4*mx];
int n,a[mx],b[mx],c[mx];
int fread()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9') f=ch=='-'?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}
void update(int p)
{
	t[p].num[1]=t[p<<1].num[1]+t[p<<1|1].num[1];
	t[p].num[2]=t[p<<1].num[2]+t[p<<1|1].num[2];
	t[p].num[3]=t[p<<1].num[3]+t[p<<1|1].num[3];
	t[p].num[1]%=mod;
	t[p].num[2]%=mod;
	t[p].num[3]%=mod;
}
void build(int p,int l,int r)
{
	t[p].l=l,t[p].r=r;
	t[p].tag2[2]=1;
	if(l==r)
	{
		t[p].num[1]=a[l],t[p].num[2]=b[l],t[p].num[3]=c[l];
		return ;
	}
	int mid=(l+r)/2;
	build(p<<1,l,mid),build(p<<1|1,mid+1,r);
	update(p);
}
void pushdown(int p)
{
//	if(t[p].tag1[1])
//	{
//		t[p<<1].num[1]+=t[p<<1].num[2];
//		t[p<<1|1].num[1]+=t[p<<1|1].num[2];
//		t[p<<1].num[1]%=mod;
//		t[p<<1|1].num[1]%=mod;
//		t[p<<1].tag1[1]+=t[p].tag1[1];
//		t[p<<1|1].tag1[1]+=t[p].tag1[1];
//		t[p].tag1[1]=0;
//	}
//	if(t[p].tag1[2])
//	{
//		t[p<<1].num[2]+=t[p<<1].num[3];
//		t[p<<1|1].num[2]+=t[p<<1|1].num[3];
//		t[p<<1].num[2]%=mod;
//		t[p<<1|1].num[2]%=mod;
//		t[p<<1].tag1[2]+=t[p].tag1[2];
//		t[p<<1|1].tag1[2]+=t[p].tag1[2];
//		t[p].tag1[2]=0;
//	}
//	if(t[p].tag1[3])
//	{
//		t[p<<1].num[3]+=t[p<<1].num[1];
//		t[p<<1|1].num[3]+=t[p<<1|1].num[1];
//		t[p<<1].num[3]%=mod;
//		t[p<<1|1].num[3]%=mod;
//		t[p<<1].tag1[3]+=t[p].tag1[3];
//		t[p<<1|1].tag1[3]+=t[p].tag1[3];
//		t[p].tag1[3]=0;
//	}
	if(t[p].tag2[1])
	{
		t[p<<1].num[1]+=(t[p<<1].r-t[p<<1].l+1)*t[p].tag2[1]; 
		t[p<<1|1].num[1]+=(t[p<<1|1].r-t[p<<1|1].l+1)*t[p].tag2[1];
		t[p<<1].num[1]%=mod;
		t[p<<1|1].num[1]%=mod;
		t[p<<1].tag2[1]+=t[p].tag2[1]; 
		t[p<<1|1].tag2[1]+=t[p].tag2[1];
		t[p].tag2[1]=0; 
	}
	if(t[p].tag2[2]!=1)
	{
		t[p<<1].num[2]*=t[p].tag2[2];
		t[p<<1|1].num[2]*=t[p].tag2[2];
		t[p<<1].num[2]%=mod;
		t[p<<1|1].num[2]%=mod;
		t[p<<1].tag2[2]*=t[p].tag2[2];
		t[p<<1|1].tag2[2]*=t[p].tag2[2];
		t[p].tag2[2]=1;
	}
	if(t[p].tag2[3])
	{
		t[p<<1].num[3]=(t[p<<1].r-t[p<<1].l+1)*t[p].tag2[3];
		t[p<<1|1].num[3]=(t[p<<1|1].r-t[p<<1|1].l+1)*t[p].tag2[3];
		t[p<<1].num[3]%=mod;
		t[p<<1|1].num[3]%=mod;
		t[p<<1].tag2[3]=t[p].tag2[3];
		t[p<<1|1].tag2[3]=t[p].tag2[3];
		t[p].tag2[3]=0;
	}
//	t[p<<1].tag1[1]%=mod;
//	t[p<<1].tag1[2]%=mod;
//	t[p<<1].tag1[3]%=mod;
	t[p<<1].tag2[1]%=mod;
	t[p<<1].tag2[2]%=mod;
	t[p<<1].tag2[3]%=mod;
//	t[p<<1|1].tag1[1]%=mod;
//	t[p<<1|1].tag1[2]%=mod;
//	t[p<<1|1].tag1[3]%=mod;
	t[p<<1|1].tag2[1]%=mod;
	t[p<<1|1].tag2[2]%=mod;
	t[p<<1|1].tag2[3]%=mod;
}
//void change1(int p,int l,int r)
//{
//	pushdown(p);
//	if(t[p].l>=l&&t[p].r<=r)
//	{
//		t[p].num[1]+=t[p].num[2];
//		t[p].num[1]%=mod;
//		t[p].tag1[1]+=1;
//		return ;
//	}
//	int mid=(t[p].l+t[p].r)/2;
//	if(l<=mid) change1(p<<1,l,r);
//	if(r>mid) change1(p<<1|1,l,r);
//	update(p);
//}
//void change2(int p,int l,int r)
//{
//	pushdown(p);
//	if(t[p].l>=l&&t[p].r<=r)
//	{
//		t[p].num[2]+=t[p].num[3];
//		t[p].num[2]%=mod;
//		t[p].tag1[2]+=1;
//		return ;
//	}
//	int mid=(t[p].l+t[p].r)/2;
//	if(l<=mid) change2(p<<1,l,r);
//	if(r>mid) change2(p<<1|1,l,r);
//	update(p);
//}
//void change3(int p,int l,int r)
//{
//	pushdown(p);
//	if(t[p].l>=l&&t[p].r<=r)
//	{
//		t[p].num[3]+=t[p].num[1];
//		t[p].num[3]%=mod;
//		t[p].tag1[3]+=1;
//		return ;
//	}
//	int mid=(t[p].l+t[p].r)/2;
//	if(l<=mid) change3(p<<1,l,r);
//	if(r>mid) change3(p<<1|1,l,r);
//	update(p);
//}
void change4(int p,int l,int r,int v)
{
	if(t[p].l>=l&&t[p].r<=r)
	{
		t[p].num[1]+=(t[p].r-t[p].l+1)*v;
		t[p].num[1]%=mod;
		t[p].tag2[1]+=v;
		t[p].tag2[1]%=mod;
		return ;
	}
	pushdown(p);
	int mid=(t[p].l+t[p].r)/2;
	if(l<=mid) change4(p<<1,l,r,v);
	if(r>mid) change4(p<<1|1,l,r,v);
	update(p);
}
void change5(int p,int l,int r,int v)
{
	if(t[p].l>=l&&t[p].r<=r)
	{
		t[p].num[2]*=v;
		t[p].tag2[2]*=v;
		t[p].num[2]%=mod;
		t[p].tag2[2]%=mod;
		return ;
	}
	pushdown(p);
	int mid=(t[p].l+t[p].r)/2;
	if(l<=mid) change5(p<<1,l,r,v);
	if(r>mid) change5(p<<1|1,l,r,v);
	update(p);
}
void change6(int p,int l,int r,int v)
{
	if(t[p].l>=l&&t[p].r<=r)
	{
		t[p].num[3]=(t[p].r-t[p].l+1)*v;
		t[p].tag2[3]=v;
		t[p].num[3]%=mod;
		t[p].tag2[3]%=mod;
		return ;
	}
	pushdown(p);
	int mid=(t[p].l+t[p].r)/2;
	if(l<=mid) change6(p<<1,l,r,v);
	if(r>mid) change6(p<<1|1,l,r,v);
	update(p);
} 
long long ask1(int p,int l,int r)
{
	if(t[p].l>=l&&t[p].r<=r) return t[p].num[1];
	pushdown(p);
	int mid=(t[p].l+t[p].r)/2;
	long long ans=0;
	if(l<=mid) ans+=ask1(p<<1,l,r);
	ans%=mod;
	if(r>mid) ans+=ask1(p<<1|1,l,r);
	ans%=mod;
	return ans; 
}
long long ask2(int p,int l,int r)
{
	pushdown(p);
	if(t[p].l>=l&&t[p].r<=r) return t[p].num[2];
	int mid=(t[p].l+t[p].r)/2;
	long long ans=0;
	if(l<=mid) ans+=ask2(p<<1,l,r);
	ans%=mod;
	if(r>mid) ans+=ask2(p<<1|1,l,r);
	ans%=mod;
	return ans;
}
long long ask3(int p,int l,int r)
{
	if(t[p].l>=l&&t[p].r<=r) return t[p].num[3];
	pushdown(p);
	int mid=(t[p].l+t[p].r)/2;
	long long ans=0;
	if(l<=mid) ans+=ask3(p<<1,l,r);
	ans%=mod;
	if(r>mid) ans+=ask3(p<<1|1,l,r);
	ans%=mod;
	return ans;
}
signed main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
//	cout.tie(0);
	n=fread();
	for(int i=1;i<=n;i++)
	{
		a[i]=fread(),b[i]=fread(),c[i]=fread();
	}
	int m=fread();
	if(n<=1100&&m<=1100)
	{
		while(m--)
		{
			int opt=fread(),l=fread(),r=fread();
			if(opt==1)
			{
				for(int i=l;i<=r;i++)
				a[i]+=b[i],a[i]%=mod;
			}
			else if(opt==2)
			{
				for(int i=l;i<=r;i++)
				b[i]+=c[i],b[i]%=mod;
			}
			else if(opt==3)
			{
				for(int i=l;i<=r;i++)
				c[i]+=a[i],c[i]%mod;
			}
			else if(opt==4)
			{
				int v=fread();
				for(int i=l;i<=r;i++)
				a[i]+=v,a[i]%=mod; 
			}
			else if(opt==5)
			{
				int v=fread();
				for(int i=l;i<=r;i++)
				b[i]*=v,b[i]%=mod;
			}
			else if(opt==6)
			{
				int v=fread();
				for(int i=l;i<=r;i++)
				c[i]=v;
			}
			else
			{
				int ans1=0,ans2=0,ans3=0;
				for(int i=l;i<=r;i++)
				{
					ans1+=a[i];
					ans2+=b[i];
					ans3+=c[i];
					ans1%=mod,ans2%=mod,ans3%=mod;
				}
				cout<<ans1<<' '<<ans2<<' '<<ans3<<'\n';
			}
		}
	}
	else
	{
		build(1,1,n);
		while(m--)
		{
			int opt=fread(),l=fread(),r=fread();
//			if(opt==1)
//			{
//				change1(1,l,r);
//	//			cout<<"??????????";
//	//			break;
//			}
//			if(opt==2)
//			{
//				change2(1,l,r);
//			}
//			if(opt==3)
//			{
//				change3(1,l,r); 
//			} 
			if(opt<=3) break;
			if(opt==4)
			{
				int v=fread();
				change4(1,l,r,v);
			}
			if(opt==5)
			{
				int v=fread();
				change5(1,l,r,v);
			}
			if(opt==6)
			{
				int v=fread();
				change6(1,l,r,v);
			}
			if(opt==7)
			{
				cout<<ask1(1,l,r)<<' '<<ask2(1,l,r)<<' '<<ask3(1,l,r)<<'\n';
			}
	//		for(int i=1;i<=n;i++)
	//		cout<<ask1(1,i,i)<<' '<<ask2(1,i,i)<<' '<<ask3(1,i,i)<<endl;
		}
	}
	return 0;
}
/*
5
1 1 2
2 3 2
2 4 5
2 3 4
54 2 1
4
1 3 4
2 1 5
3 1 2
7 1 5
*/


