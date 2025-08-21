#include <bits/stdc++.h>
#define N 5005
#define p 1000000007
#define int long long
using namespace std;
int n,a[N],x=1,y,c[N][N];
int qp(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1)res=(res*a)%p;
		a=(a*a)%p;
		b>>=1;
	}
	return res;
}
signed main()
{
	freopen("dice.in","r",stdin);
    freopen("dice.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],x=(x*a[i])%p;
    x=qp(x,p-2);//xÄæÔª
	sort(a+1,a+1+n);
	int lst=1,qs=1;
	for(int i=1;i<=a[n];i++)//Ã¶¾Ùmaxai 
	{
		if(i>a[lst])qs=(qs*a[lst])%p,lst++;
		y=(y+i*qs*(qp(i,n-lst+1)-qp(i-1,n-lst+1))%p)%p;
	}
	cout<<y*x%p;
	return 0;
}
