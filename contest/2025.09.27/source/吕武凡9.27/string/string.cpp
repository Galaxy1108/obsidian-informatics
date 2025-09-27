#include<bits/stdc++.h>
using namespace std;
string str;
int n;
int a[410];
int s0=0,s1=0,s2=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>str;
	n=str.size();
	for(int i=1;i<=n;i++)
	{
		a[i]=str[i-1]-'0';
		if(a[i]==0)
		{
			s0++;
		}
		if(a[i]==1)
		{
			s1++;
		}
		if(a[i]==2)
		{
			s2++;
		}
	}
	if(s0+s1<s2-1||s0+s2<s1-1||s1+s2<s0-1)
	{
		cout<<-1<<endl;
		return 0;
	}
	int p=1;
	int ans=0;
	while(p<n)
	{
		if(a[p]==a[p+1])
		{
			int l=p+2;
			while(a[l]==a[p]&&l<=n)
			{
				l++;
			}
			ans+=l-p-1;
			int x=a[l];
			for(int i=l;i>=p+2;i--)
			{
				a[i]=a[i-1];
			}
			a[p+1]=x;
			p=p+2;
			continue;
		}
		if(a[p]!=a[p+1]&&a[p+1]==a[p+2]&&a[p-1]!=a[p+1])
		{
			ans++;
			swap(a[p],a[p+1]);
			p=p+2;
			continue;
		}
		p++;
	}
	cout<<ans<<endl;
}
