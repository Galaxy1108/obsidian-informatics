#include<bits/stdc++.h>
using namespace std;
string s;
int d[3];
int maxn=0;
long long cnt=0;
int a[100500];
int n;
int main()
{
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		d[s[i]-'0']++;
	}
	for(int i=0;i<=2;i++)
	{
		if(d[i]>(s.size()+1)/2)
		{
			cout<<"-1";
			return 0;
		}
	}
	int n=s.size();
	for(int i=1;i<=n;i++)
	{
		a[i]=s[i-1]-'0';
	}
/*	for(int i=1;i<=n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;*/
	for(int i=1;i<=n;i++)
	{
		if(a[i]==a[i+1])
		{
			int cnt1;
			for(int j=i+2;j<=n;j++)
			{ 
				if(a[i+1]!=a[j]);
				{
//					cout<<a[i]<<" "<<a[j]<<endl;
					cnt1=j;
					break;
				}
			}
//			cout<<a[i]<<" "<<a[cnt1]<<endl;
			for(int j=cnt1;j>=i+2;j--)
			{
				int t=a[j];
				a[j]=a[j-1];
				a[j-1]=t;
				cnt++;
			}
		}
/*		for(int j=1;j<=n;j++)
		{
			cout<<a[j]<<" ";
		}
		cout<<i;
		cout<<endl;*/
	}
	for(int i=n;i>=1;i--)
	{
		if(a[i]==a[i-1])
		{
			int cnt1;
			for(int j=i-2;j>=1;j--)
			{
				if(a[j]!=a[i-1]&&a[i-1]!=a[j-1]&&a[i-1]!=a[j+1])
				{
					cnt1=j;
					break;
				}
			}
			for(int j=cnt1;j<=i-2;j++)
			{
				int t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
				cnt++;
			}
		}
	}
/*	for(int i=1;i<=n;i++)
	{
		cout<<a[i]<<" ";
	}*/
	cout<<cnt;
	return 0;
} 
