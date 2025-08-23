#include<bits/stdc++.h>
using namespace std;
set<int>sx[50001],sy[50001];
int type,n,m,k,x[150001],y[150001],q,w,a,b,c,f;
void read(int &x)
{
	int f=1;char ch;
	while(ch=getchar(),!isdigit(ch))if(ch=='-')f=-1;x=ch-'0';
	while(ch=getchar(),isdigit(ch))x=x*10+ch-'0';x*=f; 
}
void change(int a,int b)
{
	sx[a].insert(b);
	sy[b].insert(a);
}
void query(int &a,int &b,int q)
{
	int f;
	if(a==0)f=1;
	else f=0;
	
	
	for(int i=1;i<=q;i++)
	{
		//cout<<i<<' '<<a<<' '<<b<<endl; 
		if(i%2==f)
		{
			set<int>::iterator s=sy[b].upper_bound(a);
			if(s!=sy[b].end())a=*s;
			else
			{
			a=n+1;
			return;
			}
		}
		else 
		{
			set<int>::iterator s=sx[a].upper_bound(b);
			if(s!=sx[a].end())b=*s;
			else
			{
				b=m+1;
				return;
			}
		}
		
	}
    
   
}
int main()
{
	freopen("corridor.in","r",stdin);
	freopen("corridor.out","w",stdout);
	cin>>type>>n>>m>>k;
	for(int i=1;i<=k;i++)
	{
		cin>>x[i]>>y[i];
		change(x[i],y[i]);
	}
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		cin>>w;
		if(w==1)
		{
			cin>>a>>b;
			change(a,b);
			f++;
		}
		else              
		{
			cin>>a>>b>>c;
			query(a,b,c);
			cout<<a<<' '<<b<<endl; 
		}
	}
} 
