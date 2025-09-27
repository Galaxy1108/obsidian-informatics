#include<bits/stdc++.h>
using namespace std;
inline int rd()
{
	int x=0; char s=getchar();
	while(!isdigit(s))s=getchar();
	while(isdigit(s))x=(x<<1)+(x<<3)+s-'0',s=getchar();
	return x;
}
int n,m;
int l1[100005],r1[100005];
int erl(int num)
{
	int l=1,r=n;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(l1[mid]<num)l=mid+1;
		else r=mid-1;
	}
	if(r==n)return n;
	return r+1;
}
int err(int num)
{
	int l=1,r=n;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(r1[mid]<num)l=mid+1;
		else r=mid-1;
	}
	if(r==m)return m;
	return r+1;
}
bool check(int mid)
{
	bool fufu[100005]={0};
	if(n>=m)
	{
		for(int i=m;i>=1;i--)
		{
			int s=erl(r1[i]);
			while(fufu[s]==1&&s>0)
			{
				s--;
			}
			if(s<1)
			{
				return 0;
			}
			if(fufu[s]==1||abs(l1[s]-r1[i])>mid)return 0;
			fufu[s]=1;
		}
	}
	else
	{
		for(int i=n;i>=1;i--)
		{
			int s=err(l1[i]);
			while(fufu[s]==1&&s>0)
			{
				s--;
			}
			if(s<1&&s>n)
			{
				return 0;
			}
			if(fufu[s]==1||abs(l1[i]-r1[s])>mid)return 0;
			fufu[s]=1;
		}
	}
	return 1;
}
int main()
{
	freopen("gloves.in","r",stdin);
	freopen("gloves.out","w",stdout);
	int maxl=0,minl=1e9,maxr=0,minr=1e9;
	n=rd();
	m=rd();
	for(int i=1;i<=n;i++)
	{
		int asdf;
		asdf=rd();
		maxl=max(maxl,asdf);
		minl=min(minl,asdf);
		l1[i]=asdf;
	}
	for(int i=1;i<=m;i++)
	{
		int asdf;
		asdf=rd();
		maxr=max(maxr,asdf);
		minr=min(minr,asdf);
		r1[i]=asdf;
	}
	sort(l1+1,l1+1+n);
	sort(r1+1,r1+1+m);
	int l=0,r=max(maxl-minr,maxr-minl);
	int funingna=r;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid))
		{
			r=mid-1;
		}
		else l=mid+1;
	}
	if(r==funingna)cout<<funingna;
	else cout<<r+1;
	return 0;
}
