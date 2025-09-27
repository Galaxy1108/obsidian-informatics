#include<bits/stdc++.h>
using namespace std;
int a[500],b[500];
string s;
queue<int>q;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>s;
	int n=s.size();
	int cnt0=0,cnt1=0,cnt2=0,k=0,ans=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='0')
			cnt0++;
		if(s[i]=='1')
			cnt1++;
		if(s[i]=='2')
			cnt2++;
		a[i+1]=s[i]-48;
	}
	if(cnt0*2-1>n||cnt1*2-1>n||cnt2*2-1>n)
	{
		cout<<"-1";
		return 0;
	}
	b[0]=-1;
	bool flag=0;
	for(int i=n;i>=1;i--)
	{
		if(a[i]!=b[k])
		{
			flag=1;
			b[++k]=a[i];
			int sum=0;
			if(!q.empty())
				sum=q.size();
			ans+=sum;
		}
		else
		{
			flag=0;
			q.push(a[i]);
		}
		if(flag)
		{
			while(!q.empty())
			{
				int x=q.front();
				if(x!=b[k])
				{
					b[++k]=x;
					q.pop();
				}
				else
					break;
			}
		}
	}
	int num=0;
	if(!q.empty())
		num=q.size();
	ans+=num;
	cout<<ans;
	return 0;
}
