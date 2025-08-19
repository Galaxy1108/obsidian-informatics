#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
int main()
{
	freopen("gcd.in","r",stdin);
	freopen("gcd.out","w",stdout);
	int n;
	cin>>n;
	while(n--)
	{
		int a,b,c,d,k;
		cin>>a>>b>>c>>d>>k;
		int abcd=0;
		for(int i=a;i<=b;i++)
		{
			for(int j=c;j<=d;j++)
			{
				if(gcd(i,j)==k) abcd++;
			}
		}
		cout<<abcd<<endl;
	}
}
