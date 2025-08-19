#include<bits/stdc++.h>
using namespace std;
int gcd(int i,int j){return i%j==0?j:gcd(j,i%j);}
int n;
int main()
{
	freopen("gcd.in","r",stdin);
	freopen("gcd.out","w",stdout);
	cin>>n;
	while(n--)
	{
		int a,b,c,d,k,ans=0;
		cin>>a>>b>>c>>d>>k;
		for(int i=a;i<=b;i++)
			for(int j=c;j<=d;j++)
				if(gcd(i,j)==k)ans++;
		cout<<ans<<endl;
	}
	
	return 0;
} 
