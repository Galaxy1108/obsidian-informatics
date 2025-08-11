#include<bits/stdc++.h>
using namespace std;
long long n;
long long tick[150010];
long long am=0,bm=0,cm=0;
long long ans=0;
struct point
{
	long long a=0,b=0,c=0;
	long long can=0;
}e[160001];
bool cmp1(point x,point y)
{
	return x.a>y.a;
}
bool cmp2(point x,point y)
{
	return x.b>y.b;
}
bool cmp3(point x,point y)
{
	return x.c>y.c;
}
int main()
{
	freopen("battle.in","r",stdin);
	freopen("battle.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>e[i].a>>e[i].b>>e[i].c;
		am=max(am,e[i].a);
		bm=max(bm,e[i].b);
		cm=max(cm,e[i].c);
	}
	for(int i=1;i<=n;i++)
	{
		if(e[i].a==am)
		{
			tick[i]++;
		}
		if(e[i].b==bm)
		{
			tick[i]++;
		}
		if(e[i].c==cm)
		{
			tick[i]++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(tick[i]>1)
		{
			e[i].can=1;
		}
	}
	
	
	sort(e+1,e+n+1,cmp1);
	long long top=1;
	while(e[top].can)
	{
		top++;
	}
	ans+=e[top].a;
	e[top].can=1;
	
	
	sort(e+1,e+n+1,cmp2);
	top=1;
	while(e[top].can)
	{
		
		top++;
	}
	ans+=e[top].b;
	e[top].can=1;
	
	
	
	sort(e+1,e+n+1,cmp3);
	top=1;
	while(e[top].can)
	{
		top++;
	}
	ans+=e[top].c;
	
	
	
	if(ans==0) cout<<-1;
	else cout<<ans;
}
