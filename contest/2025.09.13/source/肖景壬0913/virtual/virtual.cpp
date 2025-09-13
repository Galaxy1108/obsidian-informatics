#include<bits/stdc++.h>
using namespace std;
int faa[4000005],lp,rp,apos[2000005],bsz[2000005],acnt,bcnt,n,q,x,y;
int aps,bps,ppa,ppb,fa1,fa2,fa3,fa4;
int aaa[2000005],bbb[2000005];
string str;
int find(int xx)
{
	return (xx==faa[xx]?xx:faa[xx]=find(faa[xx]));
}
void sol1()
{
	cin>>str;
	for(int i = 0; i < n; i++)
	{
		if(str[i]=='a')
		{
			acnt++;
			apos[acnt]=i+1;
		}
		else
		{
			bsz[acnt]++;
		}
	}
	for(int i = 1; i <= 2*n+3; i++)
	{
		faa[i]=i;
	}
	for(int i = 1; i <= acnt; i++)
	{
		if(i+lp-1>acnt)
		{
			break;
		}
		fa1=find(i),fa2=find(i+lp-1),fa3=find(n+2+i-1),fa4=(n+2+i+lp-1);
		faa[fa2]=fa1;
		if(bsz[i-1])
		{
			faa[fa3]=fa1;
		}
		if(bsz[i+lp-1])
		{
			faa[fa4]=fa1;
		}
	}
	cin>>q;
	for(int i = 1; i <= q; i++)
	{
		cin>>x>>y;
		if(x>y) swap(x,y);
		if(x==y)
		{
			cout<<"Yes\n";
			continue;
		}
		aps=upper_bound(apos+1,apos+acnt+1,x)-apos-1,bps=upper_bound(apos+1,apos+acnt+1,y)-apos-1;
		if(str[x-1]=='b')
		{
			aps+=(n+2);
		 } 
		if(str[y-1]=='b')
		{
			bps+=(n+2);
		}
		ppa=find(aps),ppb=find(bps);
		if(ppa==ppb)
		{
			cout<<"Yes\n";
		}
		else
		{
			cout<<"No\n";
		}
	}
	return;
}
void sol2()
{
	cin>>str;
	for(int i = 0; i < n; i++)
	{
		if(str[i]=='a')
		{
			aaa[i+1]=aaa[i]+1;
		}
		else
		{
			aaa[i+1]=aaa[i];
		}
	}
	for(int i = n-1; i >= 0; i--)
	{
		if(str[i]=='a')
		{
			bbb[i+1]=bbb[i+2]+1;
		}
		else
		{
			bbb[i+1]=bbb[i+2];
		}
	}
	cin>>q;
	for(int i = 1; i <= q; i++)
	{
		cin>>x>>y;
		if(x==y)
		{
			cout<<"Yes\n";
			continue;
		}
		if(x>y) swap(x,y);
		if((aaa[x]>=lp||bbb[x]>=lp)&&(aaa[y]>=lp||bbb[y]>=lp))
		{
			cout<<"Yes\n";
		}
		else
		{
			cout<<"No\n";
		}
	}
}
int main()
{
	freopen("virtual.in","r",stdin);
	freopen("virtual.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>lp>>rp;
	if(lp==rp) sol1();
	else sol2();
 } 
