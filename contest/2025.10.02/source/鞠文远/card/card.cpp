#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,q,a1,a2,ary[N],aa[N],bb[N];
int getans()
{
	int la1=a1,la2=a2;
	int res=0;
	for(int i=1;i<=n;i++)aa[i]=bb[i]=0;
	int st=1;
	while(st<=n&&ary[st]==-1)st++;
	if(st>n)
	{
		if(!a1||!a2)return 0;
		else return 1;
	}
	int al=-1,ac=-1;
	if(st>1)al=st-1,ac=ary[st];
	int ed=n;
	while(ed>=1&&ary[ed]==-1)ed--;
	int bl=-1,bc=-1;
	if(ed<n)bl=n-ed,bc=ary[ed];
	int av=st,avc=ary[st];
	for(int i=st+1;i<=n;i++)
	{	
		if(ary[i]!=-1&&ary[i-1]!=-1)res+=(ary[i]!=ary[i-1]);
		if(ary[i]!=-1&&av!=i-1)
		{
			if(ary[i]==0&&avc==0)aa[i-av-1]++;
			else if(ary[i]==1&&avc==1)bb[i-av-1]++;
			else res++;
		}
		if(ary[i]!=-1)av=i,avc=ary[i];
	}
	for(int i=1;i<=n;i++)
	{
		while(aa[i]&&la1>=i)
		{
			aa[i]--;
			la1-=i;
		}
	}
	for(int i=1;i<=n;i++)
	{
		while(bb[i]&&la2>=i)
		{
			bb[i]--;
			la2-=i;
		}
	}
	if(al!=-1)
	{
		if(ac==0&&la1<al)res++;
		if(ac==1&&la2<al)res++;
	}
	if(bl!=-1)
	{
		if(bc==0&&la1<bl)res++;
		if(bc==1&&la2<bl)res++;
	}
	for(int i=1;i<=n;i++)
	{
		res+=(2*aa[i])+(2*bb[i]);
		aa[i]=bb[i]=0;
	}
	return res;
} 
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>q;
	for(int i=1,x;i<=n;i++)
	{
		cin>>x;
		if(x%2==0)a1++;
		else a2++;
	}
	memset(ary,0xff,sizeof(ary));
	for(int i=1,p,t;i<=m;i++)
	{
		cin>>p>>t;
		if(t%2==0)a1--;
		else a2--;
		ary[p]=t%2;
	}
	while(q--)
	{
		int op;
		cin>>op;
		if(op==1)
		{
			int p;
			cin>>p;
			if(ary[p]==0)a1++;
			else a2++;
			ary[p]=-1;
		}
		if(op==2)
		{
			int p,t;
			cin>>p>>t;
			if(t%2==0)a1--;
			else a2--;
			ary[p]=t%2;
		}
		cout<<getans()<<"\n";	
	}
	
	return 0;
} 
