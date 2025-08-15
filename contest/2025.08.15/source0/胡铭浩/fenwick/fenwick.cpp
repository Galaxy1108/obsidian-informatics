#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
inline ull read()
{
	ull x=0;
	char ch=cin.get();
	while(!isdigit(ch)) ch=cin.get();
	while(isdigit(ch)) {(x*=10)+=(ch^48);ch=cin.get();}
	return x;
} 
const int N = 1e7+9;
int n,q,op;
ull s1,s2,num1,num2;
ull sum[N];
inline int lowbit(int x) {return x&-x;} 
inline void add(int x,ull k) {for(int cnt=1;x<=n;x+=lowbit(x),++cnt) sum[x]+=cnt*k;} 
inline ull ask(int x) {ull res=0;for(;x;x-=lowbit(x)) res+=sum[x];return res;}
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
        if(num1>num2) swap(num1,num2);
    }
}
ull ans;
int main()
{
	ios::sync_with_stdio(0);cout.tie(0);
	freopen("fenwick.in","r",stdin);
    freopen("fenwick.out","w",stdout);
    n=read(),q=read(),s1=read(),s2=read();
   	for(register int i(1);i<=q;++i)
   	{
   		get_query();
		if(op==1) add(num1,num2);
		if(op==2) ans^=i*(ask(num2)-ask(num1-1));	
	}
	cout<<ans;
	return 0;
}
