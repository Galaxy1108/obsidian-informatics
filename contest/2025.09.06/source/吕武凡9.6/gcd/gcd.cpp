#include<bits/stdc++.h>
using namespace std;
int n;
int w;
int p[45],a[45];
int gcd(int x,int y)
{
	if(x<y)
	{
		swap(x,y);
	}
	if(y==0)
	{
		return x;
	}
	return gcd(y,x%y);
}
bool check(int x)
{
	if(x==0)
	{
		return 0;
	}
	int l=0;
	int prime[10001];
	int num[10001];
	int k=x;
	int k1=2;
	while(k!=1)
	{
		if(k%k1==0)
		{
			k/=k1;
			if(prime[l]==k1)
			{
				num[l]++;
			}
			else
			{
				l++;
				prime[l]=k1;
				num[l]=1;
			}
		}
		else
		{
			k1++;
		}
	}
	int j1=1,j2=1;
	while(j2<=w&&j1<=l)
	{
		if(prime[j1]!=p[j2])
		{
			j2++;
			continue;
		}
		else
		{
			if(num[j1]>a[j2])
			{
				return false;
			}
			else
			{
				j1++;
			}
		} 
	}
	if(j1<=l)
	{
		return false;
	}
	return true;
}
int main()
{
	cin>>n;
	cin>>w;
	p[1]=1;
	a[1]=1e9;
	w++;
	for(int i=2;i<=w;i++)
	{
		cin>>p[i]>>a[i];
	}
}
/*
100
3
2 2
3 3
5 3
*/
