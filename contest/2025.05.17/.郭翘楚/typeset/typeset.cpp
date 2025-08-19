#include <bits/stdc++.h>
using namespace std;
int a[100005];
int b[100005];
int mi(int s)
{
	int sum=0;
	while(s%2==0)
	{
		s/=2;
		sum++;
	}
	return sum;
}
int main()
{
	freopen("typeset.in","r",stdin);
	freopen("typeset.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		memset(b,0,sizeof(b));
		int n,m;
		cin>>n>>m;
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			b[i]=mi(a[i]);
			if(b[i]>=m)
			{
				b[i]=m;
			}
			sum+=b[i];
		}
		sort(b+1,b+n+1);
		bool flg=false;
		for(int i=1;i<=n/2;i++)
		{
			if(b[i]+b[n-i+1]<m)
			{
				flg=1;
				cout<<"No"<<endl;
				break;
			}
		}
		if(flg)
		{
			continue;
		}
		if(sum*2-b[1]-b[2]>=m*(n-1))
		{
			cout<<"Yes"<<endl;
		}
		else
		{
			cout<<"No"<<endl;
		}
	}
	return 0;
}
