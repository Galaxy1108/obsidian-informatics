#include<bits/stdc++.h>
using namespace std;
int n,anslt,n0,n1,n2;
string s;
void solve()
{
	int npos=0,anum=0,av=-1;
	while(true)
	{
		npos++;
		if(npos>n)break;
		if(npos==1)
		{
			anum++;
			av=s[1];
			continue;	
		}
		if(s[npos]==av)anum++;
		else
		{
			if(anum)
			{
				anslt+=(anum-1);
				for(int i=npos-1;i>=npos-anum+1;i--)swap(s[i],s[i+1]);
			}
			anum--;
		}
		if(anum==0)
		{
			anum=1;
			av=s[npos];
		}
	}
	anum=0;
	npos=n+1;
	while(true)
	{
		npos--;
		if(npos<1)break;
		if(npos==n)
		{
			anum++;
			av=s[n];
			continue;	
		}
		if(s[npos]==av)anum++;
		else
		{
			if(anum)
			{
				anslt+=(anum-1);
				for(int i=npos+1;i<=npos+anum-1;i++)swap(s[i],s[i-1]);
			}
			anum--;
		}
		if(anum==-1)
		{
			anum=1;
			av=s[npos];
		}
	}
	cout<<anslt;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>s;
	n=s.size(); 
	s='.'+s;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='0')n0++;
		if(s[i]=='1')n1++;
		if(s[i]=='2')n2++;
	}
	int st=(n+1)/2;
	if(n0>st||n1>st||n2>st)
	{
		cout<<-1;
		return 0;
	}
	solve();
	
	return 0;
} 
