#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define Int __int128
#define signed int
//int mod=2147483647;
Int mod=9223372036854775808*2;
Int t[11000000],a[11000000];
Int n;
ull s1,s2;
ull op,num1,num2;
ull fread()
{
	Int x=0,w=1;char ch=getchar();
	while(ch<'0'||ch>'9') w=ch=='-'?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*w;
} 
ull my_rand()
{
    ull s3=s1,s4=s2;
    s1=s2^774527;
    s3^=(s3<<47)^(s3>>13);
    s2^=s3^(s4<<31)^(s4>>17);
    return s2+s4;
}
void get_query()
{
    op=my_rand()%2+1;
    if(op==1)
    {
        num1=my_rand()%n+1;
        num2=my_rand()%n+1;
    }
    else
    {
        num1=my_rand()%n+1;
        num2=my_rand()%n+1;
        if(num1>num2)
             swap(num1,num2);
    }
}
Int lowbit(Int x)
{
	return x&(-x);
}
void add2(Int pos,Int k)
{
	for(Int i=pos;i<=n;i+=lowbit(i))
	t[i]=(t[i]+k%mod)%mod;
}
void add1(Int pos,Int k)
{
	for(Int i=pos;i<=n;i+=lowbit(i))
	a[i]=(a[i]%mod+k%mod)%mod,add2(i,k);
}
Int ask(Int pos)
{
	Int ans=0;
	for(Int i=pos;i;i-=lowbit(i))
	ans=(ans+t[i])%mod;
	return ans;
}
//#undef ull
Int Q;
signed main()
{
    freopen("fenwick.in","r",stdin);
    freopen("fenwick.out","w",stdout);
	n=fread(),Q=fread(),s1=fread(),s2=fread();
	Int ans=0;
	unsigned long long fans;
	for(long long i=1;i<=Q;i++)
	{
		get_query();
//		long long opt,num11,num22;
//		cout<<op<<' '<<num1<<' '<<num2<<endl;
		if(op==1)
		{
			add1(num1,num2);
		}
		else
		{
			Int sum=(ask(num2)-ask(num1-1)+mod)%mod;
			long long ss=sum;
//			cout<<i<<' '<<ss<<endl;
			ans=ans^(sum*i)%mod;
		}
	}
	fans=ans%mod;
	cout<<fans;
    return 0;
}
