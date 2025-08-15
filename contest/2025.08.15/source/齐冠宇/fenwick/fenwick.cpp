#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
int n;
ull s1,s2;
ull my_rand()
{
    ull s3=s1,s4=s2;
    s1=s2^774527;
    s3^=(s3<<47)^(s3>>13);
    s2^=s3^(s4<<31)^(s4>>17);
    return s2+s4;
}
constexpr int N=1e7+5;
ull ans;
ull b[N];
inline int lowbit(int x){return x&-x;}
//inline void addb(ull x,ull k)
//{
//	while(x<=n)
//		b[x]+=k,x+=lowbit(x);
//}
inline void add(ull x,ull k)
{
	ull tim=k;
	while(x<=n)
		b[x]+=tim,tim+=k,x+=lowbit(x);
}
inline ull ask(ull x)
{
	ull res=0;
	while(x)
		res+=b[x],x-=lowbit(x);
	return res;
}
inline ull query(ull l,ull r)
{
	return ask(r)-ask(l-1);
}
void get_query(int &op,ull &num1,ull &num2)
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
int Q;
int main()
{
    freopen("fenwick.in","r",stdin);
    freopen("fenwick.out","w",stdout);
    scanf("%d%d%llu%llu",&n,&Q,&s1,&s2);
//    printf("2588154976231288790\n");
	for(int i=1;i<=Q;i++)
	{
		int op;
		ull x,y;
		get_query(op,x,y);
		if(op==1)
			add(x,y);
		else
			ans^=1ull*i*query(x,y);
	}
	printf("%llu",ans);
    return 0;
}
