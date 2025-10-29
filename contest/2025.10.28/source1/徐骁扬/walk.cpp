#include <bits/stdc++.h>
using namespace std;
int Qread()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return x;
}
int n,i,a;
long long f[6];//1 haven't started;2 in first even;3 in odd;4 in second even;5 finished 
int main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=Qread();
	for(i=1;i<=n;i++)
	{
		a=Qread();
		f[5]=min(min(f[1],f[3]),min(f[4],f[5]))+a;
		f[4]=min(f[3],f[4]);if(a&1) f[4]++;else if(a==0) f[4]+=2;
		f[3]=min(f[1],min(f[2],f[3]));if(!(a&1)) f[3]++;
		f[2]=min(f[1],f[2]);if(a&1) f[2]++;else if(a==0) f[2]+=2;
		f[1]=f[1]+a;
	}
	printf("%lld\n",min(f[1],min(f[2],min(f[3],min(f[4],f[5])))));
	return 0;
}
