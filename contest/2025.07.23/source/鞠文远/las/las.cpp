#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int n,rec,ary[N],t[N],anslt[N],ansrt[N];
int getfd2(int x){return (x==n?1:x+1);}
int getnpos(int x){return (x==n?1:x+1);}
int getppos(int x){return (x==1?n:x-1);}
signed main()
{
	freopen("las.in","r",stdin);
	freopen("las.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>ary[i];
		ary[i]*=2;
	}
	for(int i=1;i<=n;i++)
	{
		if(ary[i]/2>=ary[getfd2(i)])
		{
			anslt[i]=i;
			ansrt[i]=1;
			t[i]++;
			rec=i;
		}
		else if(ary[getfd2(i)]/2>=ary[i])
		{
			anslt[i]=getfd2(i);
			ansrt[i]=1;
			t[getfd2(i)]++;
			rec=i;
		}
	}
	if(!rec)
	{
		for(int i=1;i<=n;i++)cout<<i<<" ";
		return 0;
	}
	int nowpos=rec;
	do
	{
		nowpos=getnpos(nowpos);
		if(ansrt[nowpos])continue;
		int f1=0,f2=0; 
		bool et1=0,et2=0;
		if(t[nowpos]==0)f1=ary[nowpos];
		else f1=ary[nowpos]/2,et1=1;
		if(t[getfd2(nowpos)]==0)f2=ary[getfd2(nowpos)];
		else f2=ary[getfd2(nowpos)]/2,et2=1;
		if(f2/2>f1)
		{
			anslt[nowpos]=getfd2(nowpos);
			t[getfd2(nowpos)]++;
		}
		else
		{
			anslt[nowpos]=nowpos;
			t[nowpos]++;
		}
	}
	while(nowpos!=rec);
	do
	{
		nowpos=getppos(nowpos);
		if(ansrt[nowpos])continue;
		int f1=0,f2=0; 
		bool et1=0,et2=0;
		t[anslt[nowpos]]--;
		if(t[nowpos]==0)f1=ary[nowpos];
		else f1=ary[nowpos]/2,et1=1;
		if(t[getfd2(nowpos)]==0)f2=ary[getfd2(nowpos)];
		else f2=ary[getfd2(nowpos)]/2,et2=1;
		if(f2>f1)
		{
			anslt[nowpos]=getfd2(nowpos);
			t[getfd2(nowpos)]++;
		}
		else
		{
			anslt[nowpos]=nowpos;
			t[nowpos]++;
		}
	}
	while(nowpos!=rec);
	for(int i=1;i<=n;i++)cout<<anslt[i]<<" ";
	
	return 0;
}
