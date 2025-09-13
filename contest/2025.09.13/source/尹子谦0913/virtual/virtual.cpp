#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10; 
int n,lk,rk,pr[N],fa[N],to[N],A[N];
char s[N];
int q,l,r;
int find(int x)
{
	if(x!=fa[x]) return fa[x]=find(fa[x]);
	return x;
}
int main()
{
	freopen("virtual.in","r",stdin);
	freopen("virtual.out","w",stdout);
	cin>>n>>lk>>rk;
	cin>>s;
	cin>>q;
	for(int i=1;i<=n;i++)pr[i]=pr[i-1]+(s[i]=='a');
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=n;i++)
	{
		int l=i+1,r=n;
		while(l<=r)
		{
			int mid=l+r>>1;
			if(pr[mid]-pr[i-1]>=lk) r=mid-1;
			else l=mid+1;
		}
		int ll=l;
		l=i+1,r=n;
		while(l<=r)
		{
			int mid=l+r>>1;
			if(pr[mid]-pr[i-1]>rk) r=mid-1;
			else l=mid+1;
		}
		int rr=r;
		if(ll<=n&&rr<=n)
		{
			for(int j=ll;j<=rr;j++)
			{
				fa[find(j)]=find(i);
			} 
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>l>>r;
		if(find(l)==find(r)) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}


