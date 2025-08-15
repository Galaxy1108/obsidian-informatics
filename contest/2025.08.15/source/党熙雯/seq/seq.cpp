#include<bits/stdc++.h>
using namespace std;
map<string,int> ma;
const int mod=998244353;
const int mx=1e5+10;
int a[mx],b[mx];
int fread()
{
	int x=0,w=1;char ch=getchar();
	while(ch<'0'||ch>'9') w=ch=='-'?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*w;
 } 
int main()
{
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	int n=fread();
	string s=" ";
	for(int i=1;i<=n;i++)
	{
		a[i]=fread();
	}
	int m=fread();
	string ss=" ";
	int ans=0;
	for(int i=1;i<=m;i++)
	b[i]=fread(),s+=(char)(b[i]+'0');
//	cout<<s<<endl;
	for(int len=1;len<=n;len++)
	{
		for(int l=1,r=len;r<=n;l++,r++)
		{
			for(int i=l;i<=r;i++)
			{
				ss+=(char)(a[i]+'0');
			}
//			cout<<ss<<endl;
			if(!ma[ss]) 
			{
				if(ss<s)
				ans++;
				ans%=mod;
			}
			ss=" ";
		}
	}
	cout<<ans;
}
