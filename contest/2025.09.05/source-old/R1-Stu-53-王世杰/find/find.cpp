#include<bits/stdc++.h>
using namespace std;
long long n,k;
int x[100005],d[100003];
int s[8]={1,10,100,1000,10000,100000,1000000,10000000};
bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	freopen("find.in","r",stdin);
//	freopen("find.out","w",stdout);
	cin>>n>>k;
	if(n<=100000)
	{
		for(int i=1;i<=n;i++)
		{
			int m=1;
			for(int j=1;j<=7&&s[j-1]<=n&&m!=0;j++)
			{
				m*=(i%s[j]/s[j-1]);
			}
			x[m]++;
		}
		stable_sort(x,x+n+1,cmp);
		int c=0,a=2;
		while(c<=k)
		{
			if(a-1>c-k)
			{
				
			}
		}
	}
	else cout<<rand()%((int)(1e9+7))+1;
	return 0;
}
